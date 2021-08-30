#include <cassert>
#include <cmath>
#include <iostream>
#include <map>

#include <CLHEP/Vector/Boost.h>
#include <CLHEP/Vector/LorentzRotation.h>
#include <CLHEP/Vector/LorentzVector.h>
#include <CLHEP/Vector/Rotation.h>
#include <CLHEP/Vector/ThreeVector.h>

#include "Afterburner.h"

Afterburner::Afterburner() : _smearer(1) {

}

CLHEP::HepLorentzVector Afterburner::move_vertex(const CLHEP::HepLorentzVector &init_vtx) {

    double x = init_vtx.x() + _smearer.smear(_cfg._vertex_x, _cfg._vertex_width_x, _cfg._vertex_func_x);
    double y = init_vtx.y() + _smearer.smear(_cfg._vertex_y, _cfg._vertex_width_y, _cfg._vertex_func_y);
    double z = init_vtx.z() + _smearer.smear(_cfg._vertex_z, _cfg._vertex_width_z, _cfg._vertex_func_z);
    double t = init_vtx.t() + _smearer.smear(_cfg._vertex_t, _cfg._vertex_width_t, _cfg._vertex_func_t);
    return CLHEP::HepLorentzVector {x, y, z, t};
}

/// function to convert spherical coordinate to Hep3Vector in x-y-z
CLHEP::Hep3Vector Afterburner::spherical_to_cartesian(const double theta, const double phi) {
    return {sin(theta) * cos(phi),
            sin(theta) * sin(phi),
            cos(theta)};
}

// function to do angular shifts relative to central beam angle
CLHEP::Hep3Vector Afterburner::smear_beam_divergence(const CLHEP::Hep3Vector &beam_dir, const BeamConfig& beam_cfg, const double vtx_z) {

    // y direction in accelerator
    static const CLHEP::Hep3Vector accelerator_plane(0, 1, 0);

    // Horizontal
    double horizontal_angle = vtx_z * beam_cfg.z_kick_hor;                                     // horizontal angle 0
    horizontal_angle = _smearer.smear(horizontal_angle, beam_cfg.divergence_hor, Gaus);    // smear horizontal angle
    CLHEP::HepRotation x_smear_in_accelerator_plane(accelerator_plane, horizontal_angle);      // central horizontal angle shift

    // Vertical
    double vertical_angle =  vtx_z * beam_cfg.angular_z_coefficient_v;                          // vertical angle 0
    vertical_angle = _smearer.smear(vertical_angle, beam_cfg.angular_divergence_v, Gaus);   // smear vertical angle
    auto out_accelerator_plane = accelerator_plane.cross(beam_dir);                             // vertical out acc plane
    CLHEP::HepRotation y_smear_out_accelerator_plane(out_accelerator_plane, vertical_angle);    // central vertical angle shift

    // Resulting
    return y_smear_out_accelerator_plane * x_smear_in_accelerator_plane * beam_dir;
}

//! move vertex in translation,boost,rotation according to vertex settings
AfterburnerEventResult Afterburner::process_event(const CLHEP::HepLorentzVector &init_vtx) {
    using namespace std;

    if (m_verbosity) {
        print();
    }

    AfterburnerEventResult result;

    // now handle the collision vertex first, in the head-on collision frame
    // this is used as input to the Crab angle correction
    result.vertex = move_vertex(init_vtx);
    const double init_vertex_longitudinal = result.vertex.z();

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



    CLHEP::Hep3Vector beamA_vec = smear_beam_divergence(beamA_center, _cfg.beam_one, init_vertex_longitudinal);
    CLHEP::Hep3Vector beamB_vec = smear_beam_divergence(beamB_center, _cfg.beam_two, init_vertex_longitudinal);

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
        const double rotation_angle_to_z = -acos(cos_rotation_angle_to_z);

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




void Afterburner::print() const {
    using namespace std;
    static std::map <VTXFUNC, string> vtxfunc = {{VTXFUNC::Uniform, "Uniform"}, {VTXFUNC::Gaus,    "Gaus"}};

    cout << "Vertex distribution width"
            "  x: " << _cfg._vertex_width_x
         << ", y: " << _cfg._vertex_width_y
         << ", z: " << _cfg._vertex_width_z
         << ", t: " << _cfg._vertex_width_t
         << endl;

    cout << "Vertex distribution function"
            "  x: " << vtxfunc[_cfg._vertex_func_x]
         << ", y: " << vtxfunc[_cfg._vertex_func_y]
         << ", z: " << vtxfunc[_cfg._vertex_func_z]
         << ", t: " << vtxfunc[_cfg._vertex_func_t]
         << endl;

    cout << "Beam direction: A  theta-phi = " << _cfg.beam_one.direction_theta
         << ", " << _cfg.beam_one.direction_phi << endl;
    cout << "Beam direction: B  theta-phi = " << _cfg.beam_two.direction_theta
         << ", " << _cfg.beam_two.direction_phi << endl;

    cout << "Beam divergence: A X-Y = " << _cfg.beam_one.divergence_hor
         << ", " << _cfg.beam_one.angular_divergence_v << endl;
    cout << "Beam divergence: B X-Y = " << _cfg.beam_two.divergence_hor
         << ", " << _cfg.beam_two.angular_divergence_v << endl;

    cout << "Beam angle shift as linear function of longitudinal vertex position : A X-Y = "
         << _cfg.beam_one.z_kick_hor
         << ", " << _cfg.beam_one.angular_z_coefficient_v << endl;
    cout << "Beam angle shift as linear function of longitudinal vertex position: B X-Y = "
         << _cfg.beam_two.z_kick_hor
         << ", " << _cfg.beam_two.angular_z_coefficient_v << endl;
}
