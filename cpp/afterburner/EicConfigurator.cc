#include "EicConfigurator.hh"
#include <cmath>
#include <CLHEP/Units/SystemOfUnits.h>

using namespace CLHEP;


ab::AfterburnerConfig ab::EicConfigurator::config_eau_110x18() {
    ab::AfterburnerConfig cfg;
    
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


ab::AfterburnerConfig ab::EicConfigurator::config_eau_110x10() {
    ab::AfterburnerConfig cfg;
    
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



ab::AfterburnerConfig ab::EicConfigurator::config_eau_110x5() {
    ab::AfterburnerConfig cfg;
    
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


ab::AfterburnerConfig ab::EicConfigurator::config_eau_41x5() {
    ab::AfterburnerConfig cfg;
    

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



ab::AfterburnerConfig ab::EicConfigurator::config_hiacc_41x5() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hiacc_100x5() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hiacc_100x10() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hiacc_275x10() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hiacc_275x18() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hidiv_41x5() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hidiv_100x5() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hidiv_100x10() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hidiv_275x10() {
    ab::AfterburnerConfig cfg;
    
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

ab::AfterburnerConfig ab::EicConfigurator::config_hidiv_275x18() {
    ab::AfterburnerConfig cfg;
    
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


ab::AfterburnerConfig ab::EicConfigurator::config(double hadron_energy, double lepton_energy, ab::EicBeamConfigs beam_preset) {
    using namespace std;

    int had_e = (int)round(hadron_energy);
    int lep_e = (int)round(lepton_energy);

    if(had_e != 275 && had_e!= 110 && had_e != 100 && had_e!=41) {
        cerr << (int)had_e << " is not a valid Hadron Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 110, 100, and 41" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }

    if(lep_e != 18 && lep_e != 10 && lep_e!=5) {
        cout << (int) lep_e << " is not a valid Lepton Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Lepton energy setting is incorrect");
    }

    return config(static_cast<ab::EicBeamEnergies>(had_e), static_cast<ab::EicBeamEnergies>(lep_e), beam_preset);
}


ab::AfterburnerConfig ab::EicConfigurator::config(ab::EicBeamEnergies hadron, ab::EicBeamEnergies lepton, ab::EicBeamConfigs beam_preset) {
    using namespace std;

    // Ensure Beam Energies Correspond to Those Presented in CDR
    if(hadron != EicBeamEnergies::E275GeV && hadron != EicBeamEnergies::E110GeV && hadron != EicBeamEnergies::E100GeV && hadron != EicBeamEnergies::E41GeV) {
        cerr << (int)hadron << " is not a valid Hadron Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 110, 100, and 41" << endl;
        throw std::invalid_argument("Hadron energy setting is incorrect");
    }

    if(lepton != EicBeamEnergies::E18GeV && lepton != EicBeamEnergies::E10GeV && lepton != EicBeamEnergies::E5GeV) {
        cout << (int) lepton << " is not a valid Lepton Beam Energy!!" << endl;
        cout << "Valid Energies are 18, 10, and 5" << endl;
        throw std::invalid_argument("Lepton energy setting is incorrect");
    }

    // High Divergence setting
    if(beam_preset == EicBeamConfigs::HighDivergence) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return config_hidiv_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return config_hidiv_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return config_hidiv_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return config_hidiv_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return config_hidiv_41x5();
    }

    // High acceptance settings
    if(beam_preset == EicBeamConfigs::HighAcceptance) {
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E18GeV) return config_hiacc_275x18();
        if(hadron == EicBeamEnergies::E275GeV && lepton == EicBeamEnergies::E10GeV) return config_hiacc_275x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E10GeV) return config_hiacc_100x10();
        if(hadron == EicBeamEnergies::E100GeV && lepton == EicBeamEnergies::E5GeV)  return config_hiacc_100x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return config_hiacc_41x5();
    }

    if(beam_preset == EicBeamConfigs::ElectronAurum) {
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E18GeV) return config_eau_110x18();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E10GeV) return config_eau_110x10();
        if(hadron == EicBeamEnergies::E110GeV && lepton == EicBeamEnergies::E5GeV)  return config_eau_110x5();
        if(hadron == EicBeamEnergies::E41GeV  && lepton == EicBeamEnergies::E5GeV)  return config_eau_41x5();
    }

    cout << (int)lepton << "x" << (int)hadron << " is not a valid energy combination!!" << endl;
    cout << "Valid (ep) Combinations are 18x275, 10x275, 10x100, 5x100, and 5x41" << endl;
    cout << "Valid (eA) Combinations are 18x110, 10x110, 5x110, and 5x41" << endl;
    throw std::invalid_argument("Ion beams energy combination ");
}


