#ifndef EICAFTERBURNER_AFTERBURNERCONFIG_HH
#define EICAFTERBURNER_AFTERBURNERCONFIG_HH

#include <iostream>
#include "Smearer.hh"

namespace ab {

    struct BeamConfig {

        //! Beam angle divergence in accelerator beam coordinate.
        //! First element is beamA, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to +z direction in the HepMC event generator's coordinate
        //! Second element is beamB, in pair of Gaussian Sigma_H Sigma_V. BeamA is aimed to -z direction in the HepMC event generator's coordinate
        double divergence_hor = 0;
        double divergence_ver = 0;

        //! Central beam angle shift as linear function of longitudinal vertex position, d_shift/dz,
        //! which is used to represent leading order effect of crab cavity momentum kick on the beam bunch
        //! First element is beamA, in pair of dh/dz, dv/dz. BeamA is aimed to +z direction in the HepMC event generator's coordinate
        //! Second element is beamB, in pair of dh/dz, dv/dz. BeamA is aimed to -z direction in the HepMC event generator's coordinate
        // double z_shift_ver = 0;
        double beta_crab_hor = 0;

        double beta_star_hor = 0;
        double beta_star_ver = 0;

        double rms_emittance_hor = 0;
        double rms_emittance_ver = 0;
        double rms_bunch_length = 0;
    };

    struct AfterburnerConfig {

        /**
         * Crossing angle in horizontal plane [rad]
         */
        double crossing_angle = 25e-3;

        /**
         * Crossing angle in vertical plane
         */
        double crossing_angle_ver = 100e-6;

        unsigned int random_seed = 1;

        // Use beam bunch simulation
        bool use_beam_bunch_sim = true;

        /** Smearing function to use for initial vertex  smearing
         * (!) These fields relevant only if use_beam_bunch_sim = FALSE
         * */
        SmearFuncs vertex_smear_func = SmearFuncs::Gauss;

        /** Smearing width (be it Gauss or Flat)
         *  (!) These fields relevant only if use_beam_bunch_sim = FALSE
         * */
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
        BeamConfig hadron_beam;

        /// Beam B (two) configuration
        BeamConfig lepton_beam;
    };
}
#endif //EICAFTERBURNER_AFTERBURNERCONFIG_HH
