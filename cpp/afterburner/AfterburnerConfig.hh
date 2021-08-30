#ifndef EICAFTERBURNER_AFTERBURNERCONFIG_HH
#define EICAFTERBURNER_AFTERBURNERCONFIG_HH

#include <iostream>
#include "Smearer.hh"

struct BeamConfig {
    double direction_theta = 0;
    double direction_phi = 0;

    //! Beam angle divergence in accelerator beam coordinate.
    //! First element is beamA, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to +z direction in the HepMC event generator's coordinate
    //! Second element is beamB, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to -z direction in the HepMC event generator's coordinate
    double divergence_hor = 0;
    double angular_divergence_v = 0;

    //! Central beam angle shift as linear function of longitudinal vertex position, d_shift/dz,
    //! which is used to represent leading order effect of crab cavity momentum kick on the beam bunch
    //! First element is beamA, in pair of dh/dz, dv/dz. BeamA is aimed to +z direction in the HepMC event generator's coordinate
    //! Second element is beamB, in pair of dh/dz, dv/dz. BeamA is aimed to -z direction in the HepMC event generator's coordinate
    double z_kick_hor = 0;
    double angular_z_coefficient_v = 0;
};

struct AfterburnerConfig {

    /// Beam horizontal variance
    double beam_hor_variance = 0;
    double beam_ver_variance = 0;

    unsigned int random_seed = 1;

    VTXFUNC _vertex_func_x = Gaus;
    VTXFUNC _vertex_func_y = Gaus;
    VTXFUNC _vertex_func_z = Gaus;
    VTXFUNC _vertex_func_t = Gaus;

    double _vertex_width_x = 0;
    double _vertex_width_y = 0;
    double _vertex_width_z = 0;
    double _vertex_width_t = 0;

    double _vertex_x = 0;
    double _vertex_y = 0;
    double _vertex_z = 0;
    double _vertex_t = 0;

    /// Beam A (one) configuration
    BeamConfig beam_one;

    /// Beam B (two) configuration
    BeamConfig beam_two;



    /// Load config from JSON file
    static AfterburnerConfig load(const std::string &file_name);

    /// Save config to JSON file
    static void save(const std::string &file_name,  const AfterburnerConfig &config);
};


#endif //EICAFTERBURNER_AFTERBURNERCONFIG_HH
