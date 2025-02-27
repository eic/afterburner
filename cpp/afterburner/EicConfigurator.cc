#include "EicConfigurator.hh"
#include <cmath>
#include <CLHEP/Units/SystemOfUnits.h>

using namespace CLHEP;

// ------------------------------------------------------------------
// ========================== IP 6 ==================================
// ------------------------------------------------------------------
ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eRu_115x10() {
    ab::AfterburnerConfig cfg;

    //Same settings as for e+Au 10x110 GeV/n - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam hadron is
    //      is the active nucleon in the interaction.

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 216e-6;
    cfg.hadron_beam.divergence_ver = 274e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eCu_115x10() {
    ab::AfterburnerConfig cfg;

    //Same settings as for e+Au 10x110 GeV/n - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam hadron is
    //      is the active nucleon in the interaction.

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 216e-6;
    cfg.hadron_beam.divergence_ver = 274e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eHe3_166x10() {

    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam hadron is
    //      is the active nucleon in the interaction.

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 118e-6;
    cfg.lepton_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 940;
    cfg.hadron_beam.beta_star_ver = 85;
    cfg.lepton_beam.beta_star_hor = 1430;
    cfg.lepton_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eD_130x10() {
    
    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam hadron is
    //      is the active nucleon in the interaction.

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 118e-6;
    cfg.lepton_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 940;
    cfg.hadron_beam.beta_star_ver = 85;
    cfg.lepton_beam.beta_star_hor = 1430;
    cfg.lepton_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_ep_130x10() {
    
    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 118e-6;
    cfg.lepton_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 940;
    cfg.hadron_beam.beta_star_ver = 85;
    cfg.lepton_beam.beta_star_hor = 1430;
    cfg.lepton_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_ep_250x10() {

    //Same settings as for e+p 10x275 GeV - no official numbers exist
    //update numbers when available

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 65e-6;
    cfg.hadron_beam.divergence_ver = 65e-6;
    cfg.lepton_beam.divergence_hor = 116e-6;
    cfg.lepton_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 2650;
    cfg.hadron_beam.beta_star_ver = 240;
    cfg.lepton_beam.beta_star_hor = 1490;
    cfg.lepton_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 11 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 218e-6;
    cfg.hadron_beam.divergence_ver = 379e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 37e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 410;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 43.2 * nm;
    cfg.hadron_beam.rms_emittance_ver = 5.8 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 0.6 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 216e-6;
    cfg.hadron_beam.divergence_ver = 274e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 215e-6;
    cfg.hadron_beam.divergence_ver = 275e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 185e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 60;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    //βcrabm1300/500/200beta function at crab cavity,
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 275e-6;
    cfg.hadron_beam.divergence_ver = 377e-6;
    cfg.lepton_beam.divergence_hor = 81e-6;
    cfg.lepton_beam.divergence_ver = 136e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 3070;
    cfg.lepton_beam.beta_star_ver = 110;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 68.1 * nm;
    cfg.hadron_beam.rms_emittance_ver = 5.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 11.6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 380e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 44 * nm;
    cfg.hadron_beam.rms_emittance_ver = 10 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7.5 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_100x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 140e-6;
    cfg.lepton_beam.divergence_ver = 140e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 72;
    cfg.lepton_beam.beta_star_hor = 1030;
    cfg.lepton_beam.beta_star_ver = 92;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 26 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_100x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 118e-6;
    cfg.lepton_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 940;
    cfg.hadron_beam.beta_star_ver = 85;
    cfg.lepton_beam.beta_star_hor = 1430;
    cfg.lepton_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_275x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 65e-6;
    cfg.hadron_beam.divergence_ver = 65e-6;
    cfg.lepton_beam.divergence_hor = 116e-6;
    cfg.lepton_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 2650;
    cfg.hadron_beam.beta_star_ver = 240;
    cfg.lepton_beam.beta_star_hor = 1490;
    cfg.lepton_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 11 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_275x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 65e-6;
    cfg.hadron_beam.divergence_ver = 65e-6;
    cfg.lepton_beam.divergence_hor = 89e-6;
    cfg.lepton_beam.divergence_ver = 82e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 4170;
    cfg.hadron_beam.beta_star_ver = 380;
    cfg.lepton_beam.beta_star_hor = 3060;
    cfg.lepton_beam.beta_star_ver = 300;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 17.6 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1.6 * nm;
    cfg.lepton_beam.rms_emittance_hor = 24 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 380e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 44 * nm;
    cfg.hadron_beam.rms_emittance_ver = 10 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7.5 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_100x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 206e-6;
    cfg.hadron_beam.divergence_ver = 206e-6;
    cfg.lepton_beam.divergence_hor = 160e-6;
    cfg.lepton_beam.divergence_ver = 160e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 610;
    cfg.hadron_beam.beta_star_ver = 55;
    cfg.lepton_beam.beta_star_hor = 780;
    cfg.lepton_beam.beta_star_ver = 71;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 26 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_100x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 220e-6;
    cfg.lepton_beam.divergence_hor = 145e-6;
    cfg.lepton_beam.divergence_ver = 105e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 630;
    cfg.hadron_beam.beta_star_ver = 57;
    cfg.lepton_beam.beta_star_hor = 960;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_275x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 119e-6;
    cfg.hadron_beam.divergence_ver = 119e-6;
    cfg.lepton_beam.divergence_hor = 211e-6;
    cfg.lepton_beam.divergence_ver = 152e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 72;
    cfg.lepton_beam.beta_star_hor = 450;
    cfg.lepton_beam.beta_star_ver = 56;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 11.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_275x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 150e-6;
    cfg.hadron_beam.divergence_ver = 150e-6;
    cfg.lepton_beam.divergence_hor = 202e-6;
    cfg.lepton_beam.divergence_ver = 187e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 590;
    cfg.lepton_beam.beta_star_ver = 57;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 18e-6;
    cfg.hadron_beam.rms_emittance_ver = 1.6e-6;
    cfg.lepton_beam.rms_emittance_hor = 24e-6;
    cfg.lepton_beam.rms_emittance_ver = 2e-6;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;
    return cfg;
}

// ------------------------------------------------------------------
// ========================== IP 8 ==================================
// ------------------------------------------------------------------

ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 218e-6;
    cfg.hadron_beam.divergence_ver = 379e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 37e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 410;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 43.2 * nm;
    cfg.hadron_beam.rms_emittance_ver = 5.8 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 0.6 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 216e-6;
    cfg.hadron_beam.divergence_ver = 274e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 215e-6;
    cfg.hadron_beam.divergence_ver = 275e-6;
    cfg.lepton_beam.divergence_hor = 102e-6;
    cfg.lepton_beam.divergence_ver = 185e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 910;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 1930;
    cfg.lepton_beam.beta_star_ver = 60;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 42.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2  * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]


    //βcrabm1300/500/200beta function at crab cavity,
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 275e-6;
    cfg.hadron_beam.divergence_ver = 377e-6;
    cfg.lepton_beam.divergence_hor = 81e-6;
    cfg.lepton_beam.divergence_ver = 136e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 40;
    cfg.lepton_beam.beta_star_hor = 3070;
    cfg.lepton_beam.beta_star_ver = 110;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 68.1 * nm;
    cfg.hadron_beam.rms_emittance_ver = 5.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 11.6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 380e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 44 * nm;
    cfg.hadron_beam.rms_emittance_ver = 10 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7.5 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_100x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 140e-6;
    cfg.lepton_beam.divergence_ver = 140e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 72;
    cfg.lepton_beam.beta_star_hor = 1030;
    cfg.lepton_beam.beta_star_ver = 92;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 26 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_100x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 180e-6;
    cfg.hadron_beam.divergence_ver = 180e-6;
    cfg.lepton_beam.divergence_hor = 118e-6;
    cfg.lepton_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 940;
    cfg.hadron_beam.beta_star_ver = 85;
    cfg.lepton_beam.beta_star_hor = 1430;
    cfg.lepton_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_275x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 65e-6;
    cfg.hadron_beam.divergence_ver = 65e-6;
    cfg.lepton_beam.divergence_hor = 116e-6;
    cfg.lepton_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 2650;
    cfg.hadron_beam.beta_star_ver = 240;
    cfg.lepton_beam.beta_star_hor = 1490;
    cfg.lepton_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 11 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_275x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 65e-6;
    cfg.hadron_beam.divergence_ver = 65e-6;
    cfg.lepton_beam.divergence_hor = 89e-6;
    cfg.lepton_beam.divergence_ver = 82e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 4170;
    cfg.hadron_beam.beta_star_ver = 380;
    cfg.lepton_beam.beta_star_hor = 3060;
    cfg.lepton_beam.beta_star_ver = 300;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 17.6 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1.6 * nm;
    cfg.lepton_beam.rms_emittance_hor = 24 * nm;
    cfg.lepton_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 380e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 900;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 1960;
    cfg.lepton_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 44 * nm;
    cfg.hadron_beam.rms_emittance_ver = 10 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7.5 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_100x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 206e-6;
    cfg.hadron_beam.divergence_ver = 206e-6;
    cfg.lepton_beam.divergence_hor = 160e-6;
    cfg.lepton_beam.divergence_ver = 160e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 610;
    cfg.hadron_beam.beta_star_ver = 55;
    cfg.lepton_beam.beta_star_hor = 780;
    cfg.lepton_beam.beta_star_ver = 71;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 26 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.3 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_100x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 220e-6;
    cfg.lepton_beam.divergence_hor = 145e-6;
    cfg.lepton_beam.divergence_ver = 105e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 630;
    cfg.hadron_beam.beta_star_ver = 57;
    cfg.lepton_beam.beta_star_hor = 960;
    cfg.lepton_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 30 * nm;
    cfg.hadron_beam.rms_emittance_ver = 2.7 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 7 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_275x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;                 // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 119e-6;
    cfg.hadron_beam.divergence_ver = 119e-6;
    cfg.lepton_beam.divergence_hor = 211e-6;
    cfg.lepton_beam.divergence_ver = 152e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 72;
    cfg.lepton_beam.beta_star_hor = 450;
    cfg.lepton_beam.beta_star_ver = 56;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 11.3 * nm;
    cfg.hadron_beam.rms_emittance_ver = 1 * nm;
    cfg.lepton_beam.rms_emittance_hor = 20 * nm;
    cfg.lepton_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_275x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;                 // Crossing angle in vertical plane [rad]

    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 150e-6;
    cfg.hadron_beam.divergence_ver = 150e-6;
    cfg.lepton_beam.divergence_hor = 202e-6;
    cfg.lepton_beam.divergence_ver = 187e-6;

    // Beam beta star [mm]
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 71;
    cfg.lepton_beam.beta_star_hor = 590;
    cfg.lepton_beam.beta_star_ver = 57;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 18e-6;
    cfg.hadron_beam.rms_emittance_ver = 1.6e-6;
    cfg.lepton_beam.rms_emittance_hor = 24e-6;
    cfg.lepton_beam.rms_emittance_ver = 2e-6;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 6 * cm;
    cfg.lepton_beam.rms_bunch_length = 0.9 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::config(double hadron_energy, double lepton_energy, ab::EicBeamPresets beam_preset) {
    using namespace std;

    int had_e = (int)round(hadron_energy);
    int lep_e = (int)round(lepton_energy);

    // Approximate energies so it tolerate some spread
    if(hadron_energy > 270 && hadron_energy < 280) had_e = 275;
    if(hadron_energy > 245 && hadron_energy < 255) had_e = 250;
    if(hadron_energy > 161 && hadron_energy < 171) had_e = 166;
    if(hadron_energy > 125 && hadron_energy < 135) had_e = 130;
    if(hadron_energy > 105 && hadron_energy < 115) had_e = 110;
    if(hadron_energy > 95  && hadron_energy < 105) had_e = 100;
    if(hadron_energy > 37  && hadron_energy < 44) had_e = 41;

    if(lepton_energy > 15 && lepton_energy < 21) lep_e = 18;
    if(lepton_energy > 7  && lepton_energy < 13) lep_e = 10;
    if(lepton_energy > 3  && lepton_energy < 7) lep_e = 5;

    if(had_e != 275 && had_e != 250 && had_e != 166 && had_e != 130 && had_e != 110 && had_e != 100 && had_e != 41) {
        cerr << (int)had_e << " is not a valid Hadron Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 250, 166, 130, 110, 100, and 41" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }

    if(lep_e != 18 && lep_e != 10 && lep_e!=5) {
        cout << (int) lep_e << " is not a valid Lepton Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Lepton energy setting is incorrect");
    }

    return config(static_cast<ab::EicBeamEnergies>(had_e), static_cast<ab::EicBeamEnergies>(lep_e), beam_preset);
}


ab::AfterburnerConfig ab::EicConfigurator::config(ab::EicBeamEnergies hadron, ab::EicBeamEnergies lepton, ab::EicBeamPresets beam_preset) {
    using namespace std;

    // Ensure Beam Energies Correspond to Those Presented in CDR OR EIC early-science
    if(hadron != EicBeamEnergies::E275GeV && hadron != EicBeamEnergies::E250GeV && hadron != EicBeamEnergies::E166GeV && hadron != EicBeamEnergies::E130GeV && 
       hadron != EicBeamEnergies::E115GeV && hadron != EicBeamEnergies::E110GeV && hadron != EicBeamEnergies::E100GeV && hadron != EicBeamEnergies::E41GeV) {
        cerr << (int)hadron << " is not a valid Hadron Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 250, 166, 130, 115, 110, 100, and 41" << endl;
        throw std::invalid_argument("Hadron energy setting is incorrect");
    }

    if(lepton != EicBeamEnergies::E18GeV && lepton != EicBeamEnergies::E10GeV && lepton != EicBeamEnergies::E5GeV) {
        cout << (int) lepton << " is not a valid Lepton Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Lepton energy setting is incorrect");
    }

    // High Divergence setting
    if(beam_preset == EicBeamPresets::Ip6HighDivergence) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip6_hidiv_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip6_hidiv_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip6_hidiv_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_hidiv_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_hidiv_41x5();
    }

    // High acceptance settings
    if(beam_preset == EicBeamPresets::Ip6HighAcceptance) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip6_hiacc_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip6_hiacc_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip6_hiacc_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_hiacc_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_hiacc_41x5();
    }

    if(beam_preset == EicBeamPresets::Ip6ElectronAurum) {
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip6_eau_110x18();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip6_eau_110x10();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_eau_110x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip6_eau_41x5();
    }

    // High Divergence setting
    if(beam_preset == EicBeamPresets::Ip8HighDivergence) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip8_hidiv_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip8_hidiv_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip8_hidiv_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_hidiv_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_hidiv_41x5();
    }

    // High acceptance settings
    if(beam_preset == EicBeamPresets::Ip8HighAcceptance) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip8_hiacc_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip8_hiacc_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip8_hiacc_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_hiacc_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_hiacc_41x5();
    }

    if(beam_preset == EicBeamPresets::Ip8ElectronAurum) {
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E18GeV) return preset_ip8_eau_110x18();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E10GeV) return preset_ip8_eau_110x10();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_eau_110x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return preset_ip8_eau_41x5();
    }

    cout << (int)lepton << "x" << (int)hadron << " is not a valid energy combination!!" << endl;
    cout << "Valid (ep) Combinations are 18x275, 10x275, 10x100, 5x100, and 5x41" << endl;
    cout << "Additional (ep) Combinations are 10x250, 10x130, but are approximate" << endl;
    cout << "eHe3 10x166 GeV/n and eD 10x130 GeV/n are valid, and approximate" << endl;
    cout << "Valid (eA) Combinations are 18x110, 10x115 (Cu, Ru), 10x110, 5x110, and 5x41" << endl;
    throw std::invalid_argument("Ion beams energy combination ");
}

ab::AfterburnerConfig ab::EicConfigurator::from_string(const std::string &name) {
    if(name == "ip6_eRu_115x10")   return preset_ip6_eRu_115x10();
    if(name == "ip6_eCu_115x10")   return preset_ip6_eCu_115x10();
    if(name == "ip6_eHe3_166x10")  return preset_ip6_eHe3_166x10();
    if(name == "ip6_eD_130x10")    return preset_ip6_eD_130x10();
    if(name == "ip6_ep_130x10")    return preset_ip6_ep_130x10();
    if(name == "ip6_ep_250x10")    return preset_ip6_ep_250x10();
    if(name == "ip6_eau_110x18")   return preset_ip6_eau_110x18();
    if(name == "ip6_eau_110x10")   return preset_ip6_eau_110x10();
    if(name == "ip6_eau_110x5")    return preset_ip6_eau_110x5();
    if(name == "ip6_eau_41x5")     return preset_ip6_eau_41x5();
    if(name == "ip6_hiacc_41x5")   return preset_ip6_hiacc_41x5();
    if(name == "ip6_hiacc_100x5")  return preset_ip6_hiacc_100x5();
    if(name == "ip6_hiacc_100x10") return preset_ip6_hiacc_100x10();
    if(name == "ip6_hiacc_275x10") return preset_ip6_hiacc_275x10();
    if(name == "ip6_hiacc_275x18") return preset_ip6_hiacc_275x18();
    if(name == "ip6_hidiv_41x5")   return preset_ip6_hidiv_41x5();
    if(name == "ip6_hidiv_100x5")  return preset_ip6_hidiv_100x5();
    if(name == "ip6_hidiv_100x10") return preset_ip6_hidiv_100x10();
    if(name == "ip6_hidiv_275x10") return preset_ip6_hidiv_275x10();
    if(name == "ip6_hidiv_275x18") return preset_ip6_hidiv_275x18();
    if(name == "ip8_eau_110x18")   return preset_ip8_eau_110x18();
    if(name == "ip8_eau_110x10")   return preset_ip8_eau_110x10();
    if(name == "ip8_eau_110x5")    return preset_ip8_eau_110x5();
    if(name == "ip8_eau_41x5")     return preset_ip8_eau_41x5();
    if(name == "ip8_hiacc_41x5")   return preset_ip8_hiacc_41x5();
    if(name == "ip8_hiacc_100x5")  return preset_ip8_hiacc_100x5();
    if(name == "ip8_hiacc_100x10") return preset_ip8_hiacc_100x10();
    if(name == "ip8_hiacc_275x10") return preset_ip8_hiacc_275x10();
    if(name == "ip8_hiacc_275x18") return preset_ip8_hiacc_275x18();
    if(name == "ip8_hidiv_41x5")   return preset_ip8_hidiv_41x5();
    if(name == "ip8_hidiv_100x5")  return preset_ip8_hidiv_100x5();
    if(name == "ip8_hidiv_100x10") return preset_ip8_hidiv_100x10();
    if(name == "ip8_hidiv_275x10") return preset_ip8_hidiv_275x10();
    if(name == "ip8_hidiv_275x18") return preset_ip8_hidiv_275x18();

    std::string message = "Invalid configuration name. Name: '" + name + "' is not supported";
    throw std::invalid_argument(message);
}


