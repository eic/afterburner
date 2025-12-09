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
    //Note: these settings assume BeAGLE-like input, where the beam ion is
    //      is the active nucleon in the interaction.

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 216e-6;
    cfg.ion_beam.divergence_ver = 274e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eCu_115x10() {
    ab::AfterburnerConfig cfg;

    //Same settings as for e+Au 10x110 GeV/n - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam ion is
    //      is the active nucleon in the interaction.

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 216e-6;
    cfg.ion_beam.divergence_ver = 274e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eHe3_166x10() {

    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam ion is
    //      is the active nucleon in the interaction.

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 118e-6;
    cfg.electron_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 940;
    cfg.ion_beam.beta_star_ver = 85;
    cfg.electron_beam.beta_star_hor = 1430;
    cfg.electron_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eD_130x10() {
    
    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available
    //Note: these settings assume BeAGLE-like input, where the beam ion is
    //      is the active nucleon in the interaction.

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 118e-6;
    cfg.electron_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 940;
    cfg.ion_beam.beta_star_ver = 85;
    cfg.electron_beam.beta_star_hor = 1430;
    cfg.electron_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_ep_130x10() {
    
    //Same settings as for e+p 10x100 GeV - no official numbers exist
    //update numbers when available

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 118e-6;
    cfg.electron_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 940;
    cfg.ion_beam.beta_star_ver = 85;
    cfg.electron_beam.beta_star_hor = 1430;
    cfg.electron_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_ep_250x10() {

    //Same settings as for e+p 10x275 GeV - no official numbers exist
    //update numbers when available

    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 65e-6;
    cfg.ion_beam.divergence_ver = 65e-6;
    cfg.electron_beam.divergence_hor = 116e-6;
    cfg.electron_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 2650;
    cfg.ion_beam.beta_star_ver = 240;
    cfg.electron_beam.beta_star_hor = 1490;
    cfg.electron_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 11 * nm;
    cfg.ion_beam.rms_emittance_ver = 1 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 218e-6;
    cfg.ion_beam.divergence_ver = 379e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 37e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 410;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 43.2 * nm;
    cfg.ion_beam.rms_emittance_ver = 5.8 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 0.6 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 216e-6;
    cfg.ion_beam.divergence_ver = 274e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_110x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 215e-6;
    cfg.ion_beam.divergence_ver = 275e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 185e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 60;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 2  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_eau_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    //βcrabm1300/500/200beta function at crab cavity,
    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 275e-6;
    cfg.ion_beam.divergence_ver = 377e-6;
    cfg.electron_beam.divergence_hor = 81e-6;
    cfg.electron_beam.divergence_ver = 136e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 3070;
    cfg.electron_beam.beta_star_ver = 110;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 68.1 * nm;
    cfg.ion_beam.rms_emittance_ver = 5.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 11.6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 380e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 44 * nm;
    cfg.ion_beam.rms_emittance_ver = 10 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7.5 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_100x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 140e-6;
    cfg.electron_beam.divergence_ver = 140e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 72;
    cfg.electron_beam.beta_star_hor = 1030;
    cfg.electron_beam.beta_star_ver = 92;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 26 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_100x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 118e-6;
    cfg.electron_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 940;
    cfg.ion_beam.beta_star_ver = 85;
    cfg.electron_beam.beta_star_hor = 1430;
    cfg.electron_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_275x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 65e-6;
    cfg.ion_beam.divergence_ver = 65e-6;
    cfg.electron_beam.divergence_hor = 116e-6;
    cfg.electron_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 2650;
    cfg.ion_beam.beta_star_ver = 240;
    cfg.electron_beam.beta_star_hor = 1490;
    cfg.electron_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 11 * nm;
    cfg.ion_beam.rms_emittance_ver = 1 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hiacc_275x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 65e-6;
    cfg.ion_beam.divergence_ver = 65e-6;
    cfg.electron_beam.divergence_hor = 89e-6;
    cfg.electron_beam.divergence_ver = 82e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 4170;
    cfg.ion_beam.beta_star_ver = 380;
    cfg.electron_beam.beta_star_hor = 3060;
    cfg.electron_beam.beta_star_ver = 300;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 17.6 * nm;
    cfg.ion_beam.rms_emittance_ver = 1.6 * nm;
    cfg.electron_beam.rms_emittance_hor = 24 * nm;
    cfg.electron_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_41x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 380e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 44 * nm;
    cfg.ion_beam.rms_emittance_ver = 10 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7.5 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_100x5() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 206e-6;
    cfg.ion_beam.divergence_ver = 206e-6;
    cfg.electron_beam.divergence_hor = 160e-6;
    cfg.electron_beam.divergence_ver = 160e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 610;
    cfg.ion_beam.beta_star_ver = 55;
    cfg.electron_beam.beta_star_hor = 780;
    cfg.electron_beam.beta_star_ver = 71;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 26 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_100x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 220e-6;
    cfg.electron_beam.divergence_hor = 145e-6;
    cfg.electron_beam.divergence_ver = 105e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 630;
    cfg.ion_beam.beta_star_ver = 57;
    cfg.electron_beam.beta_star_hor = 960;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_275x10() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 119e-6;
    cfg.ion_beam.divergence_ver = 119e-6;
    cfg.electron_beam.divergence_hor = 211e-6;
    cfg.electron_beam.divergence_ver = 152e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 72;
    cfg.electron_beam.beta_star_hor = 450;
    cfg.electron_beam.beta_star_ver = 56;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 11.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 1 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip6_hidiv_275x18() {
    ab::AfterburnerConfig cfg;

    // Crossing angle
    cfg.crossing_angle_hor = 25e-3;          // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 100e-6;         // Crossing angle in vertical plane [rad]
    
    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 150e-6;
    cfg.ion_beam.divergence_ver = 150e-6;
    cfg.electron_beam.divergence_hor = 202e-6;
    cfg.electron_beam.divergence_ver = 187e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 590;
    cfg.electron_beam.beta_star_ver = 57;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 18e-6;
    cfg.ion_beam.rms_emittance_ver = 1.6e-6;
    cfg.electron_beam.rms_emittance_hor = 24e-6;
    cfg.electron_beam.rms_emittance_ver = 2e-6;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;
    return cfg;
}

// ------------------------------------------------------------------
// ========================== IP 8 ==================================
// ------------------------------------------------------------------

ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 218e-6;
    cfg.ion_beam.divergence_ver = 379e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 37e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 410;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 43.2 * nm;
    cfg.ion_beam.rms_emittance_ver = 5.8 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 0.6 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 216e-6;
    cfg.ion_beam.divergence_ver = 274e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 92e-6;

    // Beam beta star [mm] [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_110x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 215e-6;
    cfg.ion_beam.divergence_ver = 275e-6;
    cfg.electron_beam.divergence_hor = 102e-6;
    cfg.electron_beam.divergence_ver = 185e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 910;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 1930;
    cfg.electron_beam.beta_star_ver = 60;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 42.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 2  * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_eau_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]


    //βcrabm1300/500/200beta function at crab cavity,
    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 275e-6;
    cfg.ion_beam.divergence_ver = 377e-6;
    cfg.electron_beam.divergence_hor = 81e-6;
    cfg.electron_beam.divergence_ver = 136e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 40;
    cfg.electron_beam.beta_star_hor = 3070;
    cfg.electron_beam.beta_star_ver = 110;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 68.1 * nm;
    cfg.ion_beam.rms_emittance_ver = 5.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 11.6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 380e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 44 * nm;
    cfg.ion_beam.rms_emittance_ver = 10 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7.5 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_100x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 140e-6;
    cfg.electron_beam.divergence_ver = 140e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 72;
    cfg.electron_beam.beta_star_hor = 1030;
    cfg.electron_beam.beta_star_ver = 92;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 26 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_100x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 180e-6;
    cfg.ion_beam.divergence_ver = 180e-6;
    cfg.electron_beam.divergence_hor = 118e-6;
    cfg.electron_beam.divergence_ver = 86e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 940;
    cfg.ion_beam.beta_star_ver = 85;
    cfg.electron_beam.beta_star_hor = 1430;
    cfg.electron_beam.beta_star_ver = 180;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_275x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 65e-6;
    cfg.ion_beam.divergence_ver = 65e-6;
    cfg.electron_beam.divergence_hor = 116e-6;
    cfg.electron_beam.divergence_ver = 84e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 2650;
    cfg.ion_beam.beta_star_ver = 240;
    cfg.electron_beam.beta_star_hor = 1490;
    cfg.electron_beam.beta_star_ver = 190;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 11 * nm;
    cfg.ion_beam.rms_emittance_ver = 1 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hiacc_275x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 65e-6;
    cfg.ion_beam.divergence_ver = 65e-6;
    cfg.electron_beam.divergence_hor = 89e-6;
    cfg.electron_beam.divergence_ver = 82e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 4170;
    cfg.ion_beam.beta_star_ver = 380;
    cfg.electron_beam.beta_star_hor = 3060;
    cfg.electron_beam.beta_star_ver = 300;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 17.6 * nm;
    cfg.ion_beam.rms_emittance_ver = 1.6 * nm;
    cfg.electron_beam.rms_emittance_hor = 24 * nm;
    cfg.electron_beam.rms_emittance_ver = 2 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_41x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 200000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 380e-6;
    cfg.electron_beam.divergence_hor = 101e-6;
    cfg.electron_beam.divergence_ver = 129e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 900;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 1960;
    cfg.electron_beam.beta_star_ver = 210;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 44 * nm;
    cfg.ion_beam.rms_emittance_ver = 10 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 3.5 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7.5 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_100x5() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 206e-6;
    cfg.ion_beam.divergence_ver = 206e-6;
    cfg.electron_beam.divergence_hor = 160e-6;
    cfg.electron_beam.divergence_ver = 160e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 610;
    cfg.ion_beam.beta_star_ver = 55;
    cfg.electron_beam.beta_star_hor = 780;
    cfg.electron_beam.beta_star_ver = 71;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 26 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.3 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.8 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_100x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;             // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 500000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 220e-6;
    cfg.ion_beam.divergence_ver = 220e-6;
    cfg.electron_beam.divergence_hor = 145e-6;
    cfg.electron_beam.divergence_ver = 105e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 630;
    cfg.ion_beam.beta_star_ver = 57;
    cfg.electron_beam.beta_star_hor = 960;
    cfg.electron_beam.beta_star_ver = 120;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 30 * nm;
    cfg.ion_beam.rms_emittance_ver = 2.7 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 7 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_275x10() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;                 // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 119e-6;
    cfg.ion_beam.divergence_ver = 119e-6;
    cfg.electron_beam.divergence_hor = 211e-6;
    cfg.electron_beam.divergence_ver = 152e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 72;
    cfg.electron_beam.beta_star_hor = 450;
    cfg.electron_beam.beta_star_ver = 56;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 11.3 * nm;
    cfg.ion_beam.rms_emittance_ver = 1 * nm;
    cfg.electron_beam.rms_emittance_hor = 20 * nm;
    cfg.electron_beam.rms_emittance_ver = 1.3 * nm;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.7 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::preset_ip8_hidiv_275x18() {
    ab::AfterburnerConfig cfg;

    cfg.crossing_angle_hor = -35e-3;            // Crossing angle in horizontal plane [rad]
    cfg.crossing_angle_ver = 0;                 // Crossing angle in vertical plane [rad]

    cfg.ion_beam.beta_crab_hor = 1300000.0;
    cfg.electron_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.ion_beam.divergence_hor = 150e-6;
    cfg.ion_beam.divergence_ver = 150e-6;
    cfg.electron_beam.divergence_hor = 202e-6;
    cfg.electron_beam.divergence_ver = 187e-6;

    // Beam beta star [mm]
    cfg.ion_beam.beta_star_hor = 800;
    cfg.ion_beam.beta_star_ver = 71;
    cfg.electron_beam.beta_star_hor = 590;
    cfg.electron_beam.beta_star_ver = 57;

    // RMS emittance
    cfg.ion_beam.rms_emittance_hor = 18e-6;
    cfg.ion_beam.rms_emittance_ver = 1.6e-6;
    cfg.electron_beam.rms_emittance_hor = 24e-6;
    cfg.electron_beam.rms_emittance_ver = 2e-6;

    // RMS bunch length
    cfg.ion_beam.rms_bunch_length = 6 * cm;
    cfg.electron_beam.rms_bunch_length = 0.9 * cm;
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::config(HepMC3::ConstGenParticlePtr ion, HepMC3::ConstGenParticlePtr electron, ab::EicBeamPresets beam_preset) {
    using namespace std;

    float ion_energy      = ion->momentum().e();
    float electron_energy = electron->momentum().e();

    int ion_e = 0;
    int electron_e = 0;

    // Approximate energies so it tolerate some spread
    if(ion_energy > 270 && ion_energy < 280) ion_e = 275;
    if(ion_energy > 245 && ion_energy < 255) ion_e = 250;
    if(ion_energy > 161 && ion_energy < 171) ion_e = 166;
    if(ion_energy > 125 && ion_energy < 135) ion_e = 130;
    if(ion_energy > 105 && ion_energy < 115) ion_e = 110;
    if(ion_energy > 95  && ion_energy < 105) ion_e = 100;
    if(ion_energy > 37  && ion_energy < 44) ion_e = 41;

    if(electron_energy > 15 && electron_energy < 21) electron_e = 18;
    if(electron_energy > 7  && electron_energy < 13) electron_e = 10;
    if(electron_energy > 3  && electron_energy < 7)  electron_e = 5;

    if(ion_e != 275 && ion_e != 250 && ion_e != 166 && ion_e != 130 && ion_e != 110 && ion_e != 100 && ion_e != 41) {
        cerr << (int)ion_e << " is not a valid ion Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 250, 166, 130, 110, 100, and 41" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }

    if(electron_e != 18 && electron_e != 10 && electron_e!=5) {
        cout << (int) electron_e << " is not a valid Electron Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Electron energy setting is incorrect");
    }

    ab::AfterburnerConfig cfg = config(static_cast<ab::EicBeamEnergies>(ion_e), static_cast<ab::EicBeamEnergies>(electron_e), beam_preset);
    cfg.ion_beam.energy      = ion_e;
    cfg.electron_beam.energy = electron_e;
    
    cfg.ion_beam.pdg         = ion->pid();
    cfg.electron_beam.pdg    = electron->pid();
    
    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::config(ab::EicBeamEnergies ion, ab::EicBeamEnergies electron, ab::EicBeamPresets beam_preset) {
    using namespace std;

    // Ensure Beam Energies Correspond to Those Presented in CDR OR EIC early-science
    if(ion != EicBeamEnergies::E275GeV && ion != EicBeamEnergies::E250GeV && ion != EicBeamEnergies::E166GeV && ion != EicBeamEnergies::E130GeV && 
       ion != EicBeamEnergies::E115GeV && ion != EicBeamEnergies::E110GeV && ion != EicBeamEnergies::E100GeV && ion != EicBeamEnergies::E41GeV) {
        cerr << (int)ion << " is not a valid Ion Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 250, 166, 130, 115, 110, 100, and 41" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }

    if(electron != EicBeamEnergies::E18GeV && electron != EicBeamEnergies::E10GeV && electron != EicBeamEnergies::E5GeV) {
        cout << (int) electron << " is not a valid Electron Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Electron energy setting is incorrect");
    }

    // High Divergence setting
    if(beam_preset == EicBeamPresets::Ip6HighDivergence) {
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E18GeV) return preset_ip6_hidiv_275x18();
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E10GeV) return preset_ip6_hidiv_275x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E10GeV) return preset_ip6_hidiv_100x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip6_hidiv_100x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip6_hidiv_41x5();
    }

    // High acceptance settings
    if(beam_preset == EicBeamPresets::Ip6HighAcceptance) {
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E18GeV) return preset_ip6_hiacc_275x18();
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E10GeV) return preset_ip6_hiacc_275x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E10GeV) return preset_ip6_hiacc_100x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip6_hiacc_100x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip6_hiacc_41x5();
    }

    if(beam_preset == EicBeamPresets::Ip6ElectronAurum) {
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E18GeV) return preset_ip6_eau_110x18();
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E10GeV) return preset_ip6_eau_110x10();
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip6_eau_110x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip6_eau_41x5();
    }

    // High Divergence setting
    if(beam_preset == EicBeamPresets::Ip8HighDivergence) {
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E18GeV) return preset_ip8_hidiv_275x18();
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E10GeV) return preset_ip8_hidiv_275x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E10GeV) return preset_ip8_hidiv_100x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip8_hidiv_100x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip8_hidiv_41x5();
    }

    // High acceptance settings
    if(beam_preset == EicBeamPresets::Ip8HighAcceptance) {
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E18GeV) return preset_ip8_hiacc_275x18();
        if(ion == EicBeamEnergies::E275GeV && electron == EicBeamEnergies::E10GeV) return preset_ip8_hiacc_275x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E10GeV) return preset_ip8_hiacc_100x10();
        if(ion == EicBeamEnergies::E100GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip8_hiacc_100x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip8_hiacc_41x5();
    }

    if(beam_preset == EicBeamPresets::Ip8ElectronAurum) {
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E18GeV) return preset_ip8_eau_110x18();
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E10GeV) return preset_ip8_eau_110x10();
        if(ion == EicBeamEnergies::E110GeV && electron == EicBeamEnergies::E5GeV)  return preset_ip8_eau_110x5();
        if(ion == EicBeamEnergies::E41GeV  && electron == EicBeamEnergies::E5GeV)  return preset_ip8_eau_41x5();
    }

    cout << (int)electron << "x" << (int)ion << " is not a valid energy combination!!" << endl;
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


