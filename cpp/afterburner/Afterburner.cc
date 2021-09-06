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

ab::Afterburner::Afterburner() : _smearer(1) {

    // Default configuration for IP6 From Jin:
    // https://github.com/eic/fun4all_macros/blob/3678b50f3d739aa4db08d69b0afb0177380adb9c/common/G4_Input.C#L116

    //25mrad x-ing as in EIC CDR
    const double EIC_hadron_crossing_angle = 25e-3;

    _cfg.beam_one.direction_theta = EIC_hadron_crossing_angle;   // beamA_theta
    _cfg.beam_one.direction_phi = 0;                             // beamA_phi
    _cfg.beam_two.direction_theta = M_PI;                        // beamB_theta
    _cfg.beam_two.direction_phi = 0;                             // beamB_phi

    // proton beam divergence horizontal & vertical, as in EIC CDR Table 1.1
    _cfg.beam_one.divergence_hor = 119e-6;
    _cfg.beam_one.divergence_ver = 119e-6;

    // electron beam divergence horizontal & vertical, as in EIC CDR Table 1.1
    _cfg.beam_two.divergence_hor = 211e-6;
    _cfg.beam_two.divergence_ver = 152e-6;

    // angular kick within a bunch as result of crab cavity
    // using an naive assumption of transfer matrix from the cavity to IP,
    // which is NOT yet validated with accelerator optics simulations!
    const double z_hadron_cavity = 52e2;  // CDR Fig 3.3
    const double z_e_cavity = 38e2;       // CDR Fig 3.2
    _cfg.beam_one.z_shift_hor = -EIC_hadron_crossing_angle / 2. / z_hadron_cavity;
    _cfg.beam_one.z_shift_ver = 0;
    _cfg.beam_two.z_shift_hor = -EIC_hadron_crossing_angle / 2. / z_e_cavity;
    _cfg.beam_two.z_shift_ver = 0;

    // calculate beam sigma width at IP  as in EIC CDR table 1.1
    const double sigma_p_h = sqrt(80 * 11.3e-7);
    const double sigma_p_v = sqrt(7.2 * 1.0e-7);
    const double sigma_p_l = 6;
    const double sigma_e_h = sqrt(45 * 20.0e-7);
    const double sigma_e_v = sqrt(5.6 * 1.3e-7);
    const double sigma_e_l = 2;

    // combine two beam gives the collision sigma in z
    const double collision_sigma_x = sigma_p_h * sigma_e_h / sqrt(sigma_p_h * sigma_p_h + sigma_e_h * sigma_e_h);   // x
    const double collision_sigma_y = sigma_p_v * sigma_e_v / sqrt(sigma_p_v * sigma_p_v + sigma_e_v * sigma_e_v);   // y
    const double collision_sigma_z = sqrt(sigma_p_l * sigma_p_l + sigma_e_l * sigma_e_l) / 2;
    const double collision_sigma_t = collision_sigma_z / 29.9792;  // speed of light in cm/ns

    _cfg.vertex_smear_width_x = collision_sigma_x;
    _cfg.vertex_smear_width_y = collision_sigma_y;
    _cfg.vertex_smear_width_z = collision_sigma_z;
    _cfg.vertex_smear_width_t = collision_sigma_t;

    /*
     * This configuration gives the next values:
     * AFTERBURNER CONFIGURATION
     * =========================
     * Vertex distribution width  x: 0.00671564, y: 0.000601655, z: 3.16228, t: 0.105482
     * Vertex distribution function  x: Gauss, y: Gauss, z: Gauss, t: Gauss
     * Beam direction: A  theta-phi = 0.025, 0
     * Beam direction: B  theta-phi = 3.14159, 0
     * Beam divergence: A X-Y = 0.000119, 0.000119
     * Beam divergence: B X-Y = 0.000211, 0.000152
     * Beam angle shift as linear function of longitudinal vertex position : A X-Y = -2.40385e-06, 0
     * Beam angle shift as linear function of longitudinal vertex position: B X-Y = -3.28947e-06, 0
     * =========================
     */
}

CLHEP::HepLorentzVector ab::Afterburner::move_vertex(const CLHEP::HepLorentzVector &init_vtx) {

    double x = init_vtx.x() + _smearer.smear(_cfg.vertex_shift_x, _cfg.vertex_smear_width_x, _cfg.vertex_smear_func_x);
    double y = init_vtx.y() + _smearer.smear(_cfg.vertex_shift_y, _cfg.vertex_smear_width_y, _cfg.vertex_smear_func_y);
    double z = init_vtx.z() + _smearer.smear(_cfg.vertex_shift_z, _cfg.vertex_smear_width_z, _cfg.vertex_smear_func_z);
    double t = init_vtx.t() + _smearer.smear(_cfg.vertex_shift_t, _cfg.vertex_smear_width_t, _cfg.vertex_smear_func_t);
    return CLHEP::HepLorentzVector {x, y, z, t};
}

/// function to convert spherical coordinate to Hep3Vector in x-y-z
CLHEP::Hep3Vector ab::Afterburner::spherical_to_cartesian(const double theta, const double phi) {
    return {sin(theta) * cos(phi),
            sin(theta) * sin(phi),
            cos(theta)};
}

// function to do angular shifts relative to central beam angle
CLHEP::Hep3Vector ab::Afterburner::smear_beam_divergence(const CLHEP::Hep3Vector &beam_dir, const ab::BeamConfig& beam_cfg, const double vtx_z) {

    // y direction in accelerator
    static const CLHEP::Hep3Vector accelerator_plane(0, 1, 0);

    // Horizontal
    double horizontal_angle = vtx_z * beam_cfg.z_shift_hor;                                     // horizontal angle 0
    horizontal_angle = _smearer.smear(horizontal_angle, beam_cfg.divergence_hor, SmearFuncs::Gauss);    // smear horizontal angle
    CLHEP::HepRotation x_smear_in_accelerator_plane(accelerator_plane, horizontal_angle);      // central horizontal angle shift

    // Vertical
    double vertical_angle =  vtx_z * beam_cfg.z_shift_ver;                                             // vertical angle 0
    vertical_angle = _smearer.smear(vertical_angle, beam_cfg.divergence_ver, SmearFuncs::Gauss);   // smear vertical angle
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
    result.vertex = move_vertex(init_vtx);
    const double init_vertex_z = result.vertex.z();

    // boost-rotation from beam angles
    const static CLHEP::Hep3Vector z_axis(0, 0, 1);



    CLHEP::Hep3Vector beamA_center = spherical_to_cartesian(_cfg.beam_one.direction_theta, _cfg.beam_one.direction_phi);
    CLHEP::Hep3Vector beamB_center = spherical_to_cartesian(_cfg.beam_two.direction_theta, _cfg.beam_two.direction_phi);

    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": " << endl;
        cout << "beamA_center = " << beamA_center << endl;
        cout << "beamB_center = " << beamB_center << endl;
    }

    assert(fabs(beamB_center.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());
    assert(fabs(beamB_center.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());

    if (beamA_center.dot(beamB_center) > -0.5) {
        cout << "PHHepMCGenHelper::process_event - WARNING -"
             << "Beam A and Beam B are not near back to back. "
             << "Please double check beam direction setting at set_beam_direction_theta_phi()."
             << "beamA_center = " << beamA_center << ","
             << "beamB_center = " << beamB_center << ","
             << " Current setting:";

        print();
    }



    CLHEP::Hep3Vector beamA_vec = smear_beam_divergence(beamA_center, _cfg.beam_one, init_vertex_z);
    CLHEP::Hep3Vector beamB_vec = smear_beam_divergence(beamB_center, _cfg.beam_two, init_vertex_z);

    if (m_verbosity) {
        cout << __PRETTY_FUNCTION__ << ": " << endl;
        cout << "beamA_vec = " << beamA_vec << endl;
        cout << "beamB_vec = " << beamB_vec << endl;
    }

    assert(fabs(beamA_vec.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());
    assert(fabs(beamB_vec.mag2() - 1) < CLHEP::Hep3Vector::getTolerance());

    // apply minimal beam energy shift rotation and boost
    CLHEP::Hep3Vector boost_axis = beamA_vec + beamB_vec;
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
    CLHEP::Hep3Vector beamDiffAxis = (beamA_vec - beamB_vec);
    if (beamDiffAxis.mag2() < CLHEP::Hep3Vector::getTolerance()) {
        cout << "PHHepMCGenHelper::process_event - Fatal error -"
             << "Beam A and Beam B are too close to each other in direction "
             << "Please double check beam direction and divergence setting. "
             << "beamA_vec = " << beamA_vec << ","
             << "beamB_vec = " << beamB_vec << ","
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
        CLHEP::Hep3Vector rotation_axis = (beamA_vec - beamB_vec).cross(z_axis);
        const double rotation_angle_to_z = acos(cos_rotation_angle_to_z);   // TODO back to -acos? 

        result.rotation = CLHEP::HepRotation(rotation_axis, rotation_angle_to_z);

        if (m_verbosity) {
            cout << __PRETTY_FUNCTION__ << ": has rotation " << endl;
        }
    }  //  if (boost_axis.mag2() > CLHEP::Hep3Vector::getTolerance())

    // rotate the collision vertex z direction to middle of the beam angles

    // the final longitudinal vertex smear axis
    CLHEP::Hep3Vector beamCenterDiffAxis = (beamA_center - beamB_center);
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

        CLHEP::Hep3Vector final_3vertex = rotation * init_3vertex;

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

    cout << "Vertex distribution width"
            "  x: " << _cfg.vertex_smear_width_x
         << ", y: " << _cfg.vertex_smear_width_y
         << ", z: " << _cfg.vertex_smear_width_z
         << ", t: " << _cfg.vertex_smear_width_t
         << endl;

    cout << "Vertex distribution function"
            "  x: " << smear_func_to_str(_cfg.vertex_smear_func_x)
         << ", y: " << smear_func_to_str(_cfg.vertex_smear_func_y)
         << ", z: " << smear_func_to_str(_cfg.vertex_smear_func_z)
         << ", t: " << smear_func_to_str(_cfg.vertex_smear_func_t)
         << endl;

    cout << "Beam direction: A  theta-phi = " << _cfg.beam_one.direction_theta
         << ", " << _cfg.beam_one.direction_phi << endl;
    cout << "Beam direction: B  theta-phi = " << _cfg.beam_two.direction_theta
         << ", " << _cfg.beam_two.direction_phi << endl;

    cout << "Beam divergence: A X-Y = " << _cfg.beam_one.divergence_hor
         << ", " << _cfg.beam_one.divergence_ver << endl;
    cout << "Beam divergence: B X-Y = " << _cfg.beam_two.divergence_hor
         << ", " << _cfg.beam_two.divergence_ver << endl;

    cout << "Beam angle shift as linear function of longitudinal vertex position : A X-Y = "
         << _cfg.beam_one.z_shift_hor
         << ", " << _cfg.beam_one.z_shift_ver << endl;
    cout << "Beam angle shift as linear function of longitudinal vertex position: B X-Y = "
         << _cfg.beam_two.z_shift_hor
         << ", " << _cfg.beam_two.z_shift_ver << endl;
    cout << "=========================\n";
}

