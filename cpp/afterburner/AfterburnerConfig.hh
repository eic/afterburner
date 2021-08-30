#ifndef EICAFTERBURNER_AFTERBURNERCONFIG_HH
#define EICAFTERBURNER_AFTERBURNERCONFIG_HH

#include <iostream>
#include "Smearer.hh"

namespace ab {

    struct BeamConfig {
        /// Beam direction theta phi
        double direction_theta = 0;
        double direction_phi = 0;

        //! Beam angle divergence in accelerator beam coordinate.
        //! First element is beamA, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to +z direction in the HepMC event generator's coordinate
        //! Second element is beamB, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to -z direction in the HepMC event generator's coordinate
        double divergence_hor = 0;
        double divergence_ver = 0;

        //! Central beam angle shift as linear function of longitudinal vertex position, d_shift/dz,
        //! which is used to represent leading order effect of crab cavity momentum kick on the beam bunch
        //! First element is beamA, in pair of dh/dz, dv/dz. BeamA is aimed to +z direction in the HepMC event generator's coordinate
        //! Second element is beamB, in pair of dh/dz, dv/dz. BeamA is aimed to -z direction in the HepMC event generator's coordinate
        double z_shift_hor = 0;
        double z_shift_ver = 0;
    };

    struct AfterburnerConfig {
        unsigned int random_seed = 1;

        /** Smearing function to use for initial vertex  smearing*/
        SmearFuncs vertex_smear_func_x = SmearFuncs::Gauss;
        SmearFuncs vertex_smear_func_y = SmearFuncs::Gauss;
        SmearFuncs vertex_smear_func_z = SmearFuncs::Gauss;
        SmearFuncs vertex_smear_func_t = SmearFuncs::Gauss;

        /** Smearing width (be it Gauss or Flat) */
        double vertex_smear_width_x = 0;
        double vertex_smear_width_y = 0;
        double vertex_smear_width_z = 0;
        double vertex_smear_width_t = 0;

        /** Vertex permanent shift (added in the beginning) */
        double vertex_shift_x = 0;
        double vertex_shift_y = 0;
        double vertex_shift_z = 0;
        double vertex_shift_t = 0;

        /// Beam A (one) configuration
        BeamConfig beam_one;

        /// Beam B (two) configuration
        BeamConfig beam_two;

        /// Load config from JSON file
        static AfterburnerConfig load(const std::string &file_name);

        /// Save config to JSON file
        static void save(const std::string &file_name,  const AfterburnerConfig &config);
    };
}
#endif //EICAFTERBURNER_AFTERBURNERCONFIG_HH
