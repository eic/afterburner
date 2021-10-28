#include <cassert>
#include <cmath>
#include <iostream>
#include <map>

#include <CLHEP/Vector/Boost.h>
#include <CLHEP/Vector/LorentzRotation.h>
#include <CLHEP/Vector/LorentzVector.h>
#include <CLHEP/Vector/Rotation.h>
#include <CLHEP/Vector/ThreeVector.h>

#include "Afterburner.hh"


static void RotY(double theta, double xin, double yin, double zin, double *xout, double *yout, double *zout) {

    *xout = xin*cos(theta) + zin*sin(theta);
    *yout = yin;
    *zout = zin*cos(theta) - xin*sin(theta);
}


static void RotXY(double theta, double phi, double xin, double yin, double zin, double *xout, double *yout, double *zout) {

    *xout = xin*cos(theta) + zin*sin(theta);
    *yout = xin*sin(phi)*sin(theta) + yin*cos(phi) - zin*sin(phi)*cos(theta);
    *zout = yin*sin(phi) - xin*cos(phi)*sin(theta) + zin*cos(phi)*cos(theta);
}


ab::Afterburner::Afterburner() : _smear(1) {}

CLHEP::HepLorentzVector ab::Afterburner::move_vertex(const CLHEP::HepLorentzVector &init_vtx) {

    double x = init_vtx.x() + _smear.smear(_cfg.vertex_shift_x, _cfg.vertex_smear_width_x, _cfg.vertex_smear_func);
    double y = init_vtx.y() + _smear.smear(_cfg.vertex_shift_y, _cfg.vertex_smear_width_y, _cfg.vertex_smear_func);
    double z = init_vtx.z() + _smear.smear(_cfg.vertex_shift_z, _cfg.vertex_smear_width_z, _cfg.vertex_smear_func);
    double t = init_vtx.t() + _smear.smear(_cfg.vertex_shift_t, _cfg.vertex_smear_width_t, _cfg.vertex_smear_func);
    return CLHEP::HepLorentzVector {x, y, z, t};
}

//! use m_beam_bunch_width to calculate horizontal and vertical collision width
//! \param[in] hv_index 0: horizontal. 1: vertical
//! https://github.com/eic/documents/blob/d06b5597a0a89dcad215bab50fe3eefa17a097a5/reports/general/Note-Simulations-BeamEffects.pdf
double ab::Afterburner::get_collision_width(const double widthA, const double widthB)
{
    return widthA * widthB / sqrt(widthA * widthA + widthB * widthB);
}


//! generate vertx with bunch interaction according to
//! https://github.com/eic/documents/blob/d06b5597a0a89dcad215bab50fe3eefa17a097a5/reports/general/Note-Simulations-BeamEffects.pdf
//! \return pair of bunch local z position for beam A and beam B
ab::BunchInteractionResult ab::Afterburner::generate_vertx_with_bunch_interaction()
{
    using namespace std;

    // Set particle positions
    double hadron_z = _smear.gauss(_cfg.hadron_beam.rms_bunch_length);
    double lepton_z = _smear.gauss(_cfg.lepton_beam.rms_bunch_length);
    double crossing_angle = _cfg.crossing_angle;

    double had_bunch_rms_hor = sqrt(_cfg.hadron_beam.beta_star_hor * _cfg.hadron_beam.rms_emittance_hor);
    double had_bunch_rms_ver = sqrt(_cfg.hadron_beam.beta_star_ver * _cfg.hadron_beam.rms_emittance_ver);
    double lep_bunch_rms_hor = sqrt(_cfg.lepton_beam.beta_star_hor * _cfg.lepton_beam.rms_emittance_hor);
    double lep_bunch_rms_ver = sqrt(_cfg.lepton_beam.beta_star_ver * _cfg.lepton_beam.rms_emittance_ver);
    double sigma_hor = get_collision_width(had_bunch_rms_hor, lep_bunch_rms_hor);
    double sigma_ver = get_collision_width(had_bunch_rms_ver, lep_bunch_rms_ver);

    // Find Collision time, z position of collision, z position of center of hadron bunch at collision time and x position of collision
    // Quantities are found via a system of parametric equations
    // Z position of colliding hadron as a function of time: Z_h = Cos(0.5*theta_c)*t + Z_h_offset (Z_h_offset = distance from center of bunch)
    // Z position of colliding lepton as a function of time: Z_l = -Cos(0.5*theta_c)*t + Z_l_offset
    // Collision time when Z_h = Z_l -> t_int = (Z_l_offset - Z_h_offset)/(2*Cos(0.5*theta_c))
    // Z position of collision: Z_int = (Z_l_offset + Z_h_offset)/2
    // Z position of center of hadron bunch a collision time - this gives x position of collision via relation x = z*Tan(0.5*theta_c)
    // Z_bunch_int = Cos(0.5*theta_c)*t_int
    // X_int = Z_bunch_int * Tan(0.5*theta_c)

    double c_c = cos(crossing_angle/2.0);
    double s_c = sin(crossing_angle/2.0);
    double t_c = tan(crossing_angle/2.0);

    double t_int = (lepton_z - hadron_z)/(2.0*c_c);
    double z_int = (lepton_z + hadron_z)/2.0;
    double z_bunch_int = c_c*t_int;
    double x_int = z_bunch_int*t_c;

    // x_int is the x position of collision assuming the colliding particles are in the center of the bunch. Sample random x position according to x-width of bunches. x_int is then an offset to this. Get y position as well.

    double y_int = 0.;
    if(abs(sigma_hor) > 1e-9)
    {
        x_int += _smear.gauss(sigma_hor);
    }

    if(abs(sigma_ver) > 1e-9)
    {
        y_int += _smear.gauss(sigma_ver);
    }

    // We now have the x-y-z position of the collision in the accelerator frame, but we want it in the detector frame. Rotate by 0.5*theta_c to get to accelerator frame

    double tmpVtxX, tmpVtxY, tmpVtxZ;
    tmpVtxX = tmpVtxY = tmpVtxZ = 0.;

    RotY(crossing_angle/2.0,x_int,y_int,z_int,&tmpVtxX,&tmpVtxY,&tmpVtxZ);

    CLHEP::Hep3Vector collision_center(tmpVtxX, tmpVtxY, tmpVtxZ);
    ab::BunchInteractionResult result;
    result.vertex.set(collision_center, t_int);
    result.bunch_one_z = hadron_z;
    result.bunch_two_z = lepton_z;

//
//    //  const static CLHEP::Hep3Vector z_axis(0, 0, 1);
//    const static CLHEP::Hep3Vector y_axis(0, 1, 0);
//
//    // the final longitudinal vertex smear axis
//    CLHEP::Hep3Vector beamCenterDiffAxis = (beamA_center - beamB_center);
//    assert(beamCenterDiffAxis.mag() > CLHEP::Hep3Vector::getTolerance());
//    beamCenterDiffAxis = beamCenterDiffAxis / beamCenterDiffAxis.mag();
//
//    CLHEP::Hep3Vector vec_crossing = beamA_center - 0.5 * (beamA_center - beamB_center);
//
//    CLHEP::Hep3Vector vec_longitudinal_collision = beamCenterDiffAxis * (hadron_z + lepton_z) / 2.;
//    double ct_collision = 0.5 * (-hadron_z + lepton_z) / beamCenterDiffAxis.dot(beamA_center);
//    double t_collision = ct_collision ;//* CLHEP::mm / CLHEP::c_light / CLHEP::ns;
//    CLHEP::Hep3Vector vec_crossing_collision = ct_collision * vec_crossing;  // shift of collision to crossing direction
//
//    CLHEP::Hep3Vector horizontal_axis = y_axis.cross(beamCenterDiffAxis);
//    assert(horizontal_axis.mag() > CLHEP::Hep3Vector::getTolerance());
//    horizontal_axis = horizontal_axis.unit();
//
//    CLHEP::Hep3Vector vertical_axis = beamCenterDiffAxis.cross(horizontal_axis);
//    assert(vertical_axis.mag() > CLHEP::Hep3Vector::getTolerance());
//    vertical_axis = vertical_axis.unit();
//
//
//
//
//    double bunch_x = _smear.smear(0, sigma_hor);
//    CLHEP::Hep3Vector vec_horizontal_collision_vertex_smear = horizontal_axis * bunch_x;
//
//    double bunch_y = _smear.smear(0, sigma_ver);
//    CLHEP::Hep3Vector vec_vertical_collision_vertex_smear = vertical_axis * bunch_y;
//
//    CLHEP::Hep3Vector vec_collision_vertex =
//            vec_horizontal_collision_vertex_smear +
//            vec_vertical_collision_vertex_smear +  //
//            vec_crossing_collision + vec_longitudinal_collision;
//
//    ab::BunchInteractionResult result;
//    result.vertex.set(vec_collision_vertex, t_collision);
//    result.bunch_one_z = hadron_z;
//    result.bunch_two_z = lepton_z;
//
//
//    if (m_verbosity)
//    {
//        cout << __PRETTY_FUNCTION__
//             << ":\n  "
//             << "bunch_one_z = " << result.bunch_one_z << ", "
//             << "bunch_two_z = " << result.bunch_two_z<< ", "
//             << "cos(theta/2) = " << beamCenterDiffAxis.dot(beamA_center) << ",\n  "
//
//             << "beamCenterDiffAxis = " << beamCenterDiffAxis << ", "
//             << "vec_crossing = " << vec_crossing << ", "
//             << "horizontal_axis = " << horizontal_axis << ", "
//             << "vertical_axis = " << vertical_axis << ",\n  "
//
//             << "vec_longitudinal_collision = " << vec_longitudinal_collision << ", "
//             << "vec_crossing_collision = " << vec_crossing_collision << ", "
//             << "vec_vertical_collision_vertex_smear = " << vec_vertical_collision_vertex_smear << ", "
//             << "vec_horizontal_collision_vertex_smear = " << vec_horizontal_collision_vertex_smear << ",\n "
//
//             << "vec_collision_vertex = " << vec_collision_vertex << ",\n  "
//
//             << "ct_collision = " << ct_collision << ", "
//             << "t_collision = " << t_collision << ", "
//             << endl;
//    }

    return result;
}

/// function to convert spherical coordinate to Hep3Vector in x-y-z
CLHEP::Hep3Vector ab::Afterburner::spherical_to_cartesian(const double theta, const double phi) {
    return {sin(theta) * cos(phi),
            sin(theta) * sin(phi),
            cos(theta)};
}

// function to do angular shifts relative to central beam angle
CLHEP::Hep3Vector ab::Afterburner::smear_beam_divergence(const CLHEP::Hep3Vector &beam_dir, const ab::BeamConfig& beam_cfg, const double vtx_z, const double crab_hor, const double crab_ver) {

    // y direction in accelerator
    static const CLHEP::Hep3Vector accelerator_plane(0, 1, 0);

    // Horizontal
    double horizontal_angle = vtx_z * crab_hor;                                     // horizontal angle 0
    horizontal_angle = _smear.smear(horizontal_angle, beam_cfg.divergence_hor, SmearFuncs::Gauss);    // smear horizontal angle
    CLHEP::HepRotation x_smear_in_accelerator_plane(accelerator_plane, horizontal_angle);      // central horizontal angle shift


    // Vertical
    /*
    // Calculate angular deflection
    double crabAngHad = ((mXAngle/2.0)*hadronPartPos)/(TMath::Sqrt(betaCrabHad*betaStarHad));
    double crabAngLep = ((mXAngle/2.0)*leptonPartPos)/(TMath::Sqrt(betaCrabLep*betaStarLep));

    // Calculate Magnitude of Px kick
    double crabKickHad = (mIonBeamEnergy + tmpPzA)*TMath::Sin(crabAngHad);
    double crabKickLep = (-1.0)*(mLeptonBeamEnergy + tmpPzB)*TMath::Sin(crabAngLep); //

    // Rotate Momentum Kick into Detector Frame
    double tmpVertPxA, tmpVertPyA, tmpVertPzA;
    double tmpVertPxB, tmpVertPyB, tmpVertPzB;
    tmpVertPxA = tmpVertPyA = tmpVertPzA = tmpVertPxB = tmpVertPyB = tmpVertPzB = 0.;

    RotY(mXAngle/2.0,crabKickHad,0.,0.,&tmpVertPxA,&tmpVertPyA,&tmpVertPzA);
    RotY(mXAngle/2.0,crabKickLep,0.,0.,&tmpVertPxB,&tmpVertPyB,&tmpVertPzB)
    */

    double vertical_angle =  -vtx_z * crab_ver;                                             // vertical angle 0
    vertical_angle = _smear.smear(vertical_angle, beam_cfg.divergence_ver, SmearFuncs::Gauss);   // smear vertical angle
    auto out_accelerator_plane = accelerator_plane.cross(beam_dir);                             // vertical out acc plane
    CLHEP::HepRotation y_smear_out_accelerator_plane(out_accelerator_plane, vertical_angle);    // central vertical angle shift

    // Resulting
    return y_smear_out_accelerator_plane * x_smear_in_accelerator_plane * beam_dir;
}


ab::AfterburnerEventResult ab::Afterburner::process_event() {
    return process_event(CLHEP::HepLorentzVector(0,0,0,0));
}

//! move vertex in translation,boost,rotation according to vertex settings
ab::AfterburnerEventResult ab::Afterburner::process_event(const CLHEP::HepLorentzVector &init_vtx) {
    using namespace std;

    if (m_verbosity) {
        print();
    }

    AfterburnerEventResult result;

    // now handle the collision vertex first, in the head-on collision frame
    // this is used as input to the Crab angle correction
    double bunch_one_z;
    double bunch_two_z;
    if (_cfg.use_beam_bunch_sim)
    {
        // bunch interaction simulation
        auto bunch_interaction = generate_vertx_with_bunch_interaction();
        result.vertex = bunch_interaction.vertex;
        bunch_one_z = bunch_interaction.bunch_one_z;
        bunch_two_z = bunch_interaction.bunch_two_z;
    }
    else
    {
        // vertex distribution simulation
        // now handle the collision vertex first, in the head-on collision frame
        // this is used as input to the Crab angle correction
        result.vertex = move_vertex(init_vtx);
        bunch_one_z = bunch_two_z = result.vertex.z();
    }

    // boost-rotation from beam angles
    const static CLHEP::Hep3Vector z_axis(0, 0, 1);
    const static CLHEP::Hep3Vector y_axis(0, 1, 0);

    //CLHEP::Hep3Vector ideal_hadron_dir = spherical_to_cartesian(_cfg.hadron_beam.direction_theta, _cfg.hadron_beam.direction_phi);
    //CLHEP::Hep3Vector ideal_lepton_dir = spherical_to_cartesian(_cfg.lepton_beam.direction_theta, _cfg.lepton_beam.direction_phi);
    CLHEP::Hep3Vector ideal_lepton_dir(0, 0, -1);
    CLHEP::Hep3Vector ideal_hadron_dir = CLHEP::Hep3Vector(z_axis).rotateY(_cfg.crossing_angle).rotateX(_cfg.crossing_angle_ver);

    //double crossing_angle = acos(ideal_hadron_dir.unit().dot(-ideal_lepton_dir.unit()));

    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": " << endl;
        cout << "ideal_hadron_dir = " << ideal_hadron_dir << endl;
        cout << "ideal_lepton_dir = " << ideal_lepton_dir << endl;
        cout << "crossing_angle_hor   = " << _cfg.crossing_angle << endl;
        cout << "crossing_angle_ver   = " << _cfg.crossing_angle_ver << endl;
    }

    assert(fabs(ideal_hadron_dir.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());
    assert(fabs(ideal_lepton_dir.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());

    if (ideal_hadron_dir.dot(ideal_lepton_dir) > -0.5) {
        cout << "PHHepMCGenHelper::process_event - WARNING -"
             << "Beam A and Beam B are not near back to back. "
             << "Please double check beam direction setting at set_beam_direction_theta_phi()."
             << "beamA_center = " << ideal_hadron_dir << ","
             << "beamB_center = " << ideal_lepton_dir << ","
             << " Current setting:";

        print();
    }

    // Calculate angular deflection
    double hadron_crab_hor = _cfg.crossing_angle/2.0/sqrt(_cfg.hadron_beam.beta_crab_hor * _cfg.hadron_beam.beta_star_hor);
    double hadron_crab_ver = 0;

    double lepton_crab_hor = _cfg.crossing_angle/2.0/sqrt(_cfg.lepton_beam.beta_crab_hor * _cfg.lepton_beam.beta_star_hor);
    double lepton_crab_ver = 0;

    CLHEP::Hep3Vector real_hadron_dir = smear_beam_divergence(ideal_hadron_dir, _cfg.hadron_beam, bunch_one_z, hadron_crab_hor, hadron_crab_ver);
    CLHEP::Hep3Vector real_lepton_dir = smear_beam_divergence(ideal_lepton_dir, _cfg.lepton_beam, bunch_two_z, lepton_crab_hor, lepton_crab_ver);

    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": " << endl;
        cout << "beamA_vec = " << real_hadron_dir << endl;
        cout << "beamB_vec = " << real_lepton_dir << endl;
    }

    assert(fabs(real_hadron_dir.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());
    assert(fabs(real_lepton_dir.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());

    // apply minimal beam energy shift rotation and boost
    CLHEP::Hep3Vector boost_axis = real_hadron_dir + real_lepton_dir;
    if (boost_axis.mag2() > CLHEP::Hep3Vector::getTolerance()) {
        //non-zero boost

        // split the boost to half for each beam for minimal beam  energy shift
        result.boost = CLHEP::HepBoost(0.5 * boost_axis);

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": non-zero boost " << endl;
        }
    }  //    if (cos_rotation_angle> CLHEP::Hep3Vector::getTolerance())
    else {
        result.boost = CLHEP::HepBoost(CLHEP::Hep3Vector(0, 0, 0));
        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": zero boost " << endl;
        }
    }

    //rotation to collision to along z-axis with beamA pointing to +z
    CLHEP::Hep3Vector beamDiffAxis = (real_hadron_dir - real_lepton_dir);
    if (beamDiffAxis.mag2() < CLHEP::Hep3Vector::getTolerance()) {
        cout << "PHHepMCGenHelper::process_event - Fatal error -"
             << "Beam A and Beam B are too close to each other in direction "
             << "Please double check beam direction and divergence setting. "
             << "real_hadron_dir = " << real_hadron_dir << ","
             << "real_lepton_dir = " << real_lepton_dir << ","
             << " Current setting:";

        print();

        throw std::runtime_error("Beam A and Beam B are too close to each other in direction ");
    }

    beamDiffAxis = beamDiffAxis / beamDiffAxis.mag();
    double cos_rotation_angle_to_z = beamDiffAxis.dot(z_axis);
    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": check rotation ";
        cout << "cos_rotation_angle_to_z= " << cos_rotation_angle_to_z << endl;
    }

    if (1 - cos_rotation_angle_to_z < CLHEP::Hep3Vector::getTolerance()) {
        //no rotation

        result.rotation = CLHEP::HepRotation(z_axis, 0);

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": no rotation " << endl;
        }
    } else if (cos_rotation_angle_to_z + 1 < CLHEP::Hep3Vector::getTolerance()) {
        // you got beam flipped
        result.rotation = CLHEP::HepRotation(CLHEP::Hep3Vector(0, 1, 0), M_PI);
        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": reverse beam direction " << endl;
        }
    } else {
        // need a rotation
        CLHEP::Hep3Vector rotation_axis = (real_hadron_dir - real_lepton_dir).cross(z_axis);
        const double rotation_angle_to_z = acos(cos_rotation_angle_to_z);   // TODO back to -acos?

        result.rotation = CLHEP::HepRotation(rotation_axis, rotation_angle_to_z);

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": has rotation " << endl;
        }
    }  //  if (boost_axis.mag2() > CLHEP::Hep3Vector::getTolerance())

    // rotate the collision vertex z direction to middle of the beam angles

    // the final longitudinal vertex smear axis
    CLHEP::Hep3Vector beamCenterDiffAxis = (ideal_hadron_dir - ideal_lepton_dir);
    beamCenterDiffAxis = beamCenterDiffAxis / beamCenterDiffAxis.mag();

    double cos_rotation_center_angle_to_z = beamCenterDiffAxis.dot(z_axis);

    if (1 - fabs(cos_rotation_center_angle_to_z) < CLHEP::Hep3Vector::getTolerance()) {
        // new axis is basically beam axis

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__
                 << ": collision longitudinal axis is very close to z-axis. No additional rotation of vertexes: "
                 << "cos_rotation_center_angle_to_z = " << cos_rotation_center_angle_to_z
                 << endl;
        }
    } else {
        // need a rotation
        CLHEP::Hep3Vector rotation_axis = beamCenterDiffAxis.cross(z_axis);
        const double rotation_angle_to_z = -acos(cos_rotation_center_angle_to_z);
        const CLHEP::HepRotation rotation(rotation_axis, rotation_angle_to_z);


        CLHEP::Hep3Vector init_3vertex(
                result.vertex.x(),
                result.vertex.y(),
                result.vertex.z());

        CLHEP::Hep3Vector final_3vertex = init_3vertex;//rotation * init_3vertex;

        result.vertex = CLHEP::HepLorentzVector(
                final_3vertex.x(),
                final_3vertex.y(),
                final_3vertex.z(),
                result.vertex.t());

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__
                 << ": collision longitudinal axis is rotated: "
                 << "cos_rotation_center_angle_to_z = " << cos_rotation_center_angle_to_z << ", "
                 << "rotation_axis = " << rotation_axis << ", "
                 << "init_3vertex = " << init_3vertex << ", "
                 << "final_3vertex = " << final_3vertex << ", "
                 << endl;
        }
    }


    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": final boost rotation shift of the collision" << endl;
    }
    return result;
}




void ab::Afterburner::print() const {
    using namespace std;

    cout << "AFTERBURNER CONFIGURATION\n";
    cout << "=========================\n";

    cout << "Crossing angle hor: " << _cfg.crossing_angle << endl;
    cout << "Crossing angle ver: " << _cfg.crossing_angle_ver << endl;

    cout << "Vertex distribution width"
            "  x: " << _cfg.vertex_smear_width_x
         << ", y: " << _cfg.vertex_smear_width_y
         << ", z: " << _cfg.vertex_smear_width_z
         << ", t: " << _cfg.vertex_smear_width_t
         << endl;

    cout << "Vertex distribution function: " << smear_func_to_str(_cfg.vertex_smear_func) << endl;
    cout << "Vertex simulation is: " << (_cfg.use_beam_bunch_sim ? string("on") : std::string("off")) << endl;
    cout << "Hadron beam:\n";
    cout << "   rms emittance   : hor = " << _cfg.hadron_beam.rms_emittance_hor << ", ver = " << _cfg.hadron_beam.rms_emittance_ver << endl;
    cout << "   beta star       : hor = " << _cfg.hadron_beam.beta_star_hor << ", ver = " << _cfg.hadron_beam.beta_star_ver << endl;
    cout << "   beta crab       : hor = " << _cfg.hadron_beam.beta_crab_hor << endl;
    cout << "   rms bunch length: " << _cfg.hadron_beam.rms_bunch_length << endl;

    cout << "Lepton beam:\n";
    cout << "   rms emittance   : hor = " << _cfg.lepton_beam.rms_emittance_hor << ", ver = " << _cfg.lepton_beam.rms_emittance_ver << endl;
    cout << "   beta star       : hor = " << _cfg.lepton_beam.beta_star_hor << ", ver = " << _cfg.lepton_beam.beta_star_ver << endl;
    cout << "   beta crab       : hor = " << _cfg.lepton_beam.beta_crab_hor << endl;
    cout << "   rms bunch length: " << _cfg.lepton_beam.rms_bunch_length << endl;

    cout << "=========================\n";
}

