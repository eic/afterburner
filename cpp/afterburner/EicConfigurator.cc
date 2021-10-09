#include "EicConfigurator.hh"
#include <cmath>

void ab::EicConfigurator::set_beam_direction(ab::AfterburnerConfig& config, const double crossing_angle = 25e-3) {
    config.hadron_beam.direction_theta = crossing_angle;
    config.hadron_beam.direction_phi = 0;
    config.lepton_beam.direction_theta = M_PI;
    config.lepton_beam.direction_phi = 0;
}



ab::AfterburnerConfig ab::EicConfigurator::config_ea_18x110() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::config_ea_10x110() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;

    return cfg;
}



ab::AfterburnerConfig ab::EicConfigurator::config_ea_5x110() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;

    return cfg;
}


ab::AfterburnerConfig ab::EicConfigurator::config_ea_5x41() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);

    //βcrabm1300/500/200beta function at crab cavity,
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
}



ab::AfterburnerConfig ab::EicConfigurator::config_hi_acc_5x41() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_acc_5x100() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_acc_10x100() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_acc_10x275() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_acc_18x275() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor;
    cfg.hadron_beam.divergence_ver;
    cfg.lepton_beam.divergence_hor;
    cfg.lepton_beam.divergence_ver;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;

    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_div_5x41() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 200000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 380e-6;
    cfg.lepton_beam.divergence_hor = 101e-6;
    cfg.lepton_beam.divergence_ver = 129e-6;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_div_5x100() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 206e-6;
    cfg.hadron_beam.divergence_ver = 206e-6;
    cfg.lepton_beam.divergence_hor = 160e-6;
    cfg.lepton_beam.divergence_ver = 160e-6;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_div_10x100() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 500000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 220e-6;
    cfg.hadron_beam.divergence_ver = 220e-6;
    cfg.lepton_beam.divergence_hor = 145e-6;
    cfg.lepton_beam.divergence_ver = 105e-6;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_div_10x275() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 119e-6;
    cfg.hadron_beam.divergence_ver = 119e-6;
    cfg.lepton_beam.divergence_hor = 211e-6;
    cfg.lepton_beam.divergence_ver = 152e-6;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor;
    cfg.hadron_beam.beta_star_ver;
    cfg.lepton_beam.beta_star_hor;
    cfg.lepton_beam.beta_star_ver;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor;
    cfg.hadron_beam.rms_emittance_ver;
    cfg.lepton_beam.rms_emittance_hor;
    cfg.lepton_beam.rms_emittance_ver;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length;
    cfg.lepton_beam.rms_bunch_length;
    return cfg;
}

ab::AfterburnerConfig ab::EicConfigurator::config_hi_div_18x275() {
    ab::AfterburnerConfig cfg;
    set_beam_direction(cfg);
    cfg.hadron_beam.beta_crab_hor = 1300000.0;
    cfg.lepton_beam.beta_crab_hor = 150000.0;

    // Beam divergence
    cfg.hadron_beam.divergence_hor = 150e-6;
    cfg.hadron_beam.divergence_ver = 150e-6;
    cfg.lepton_beam.divergence_hor = 202e-6;
    cfg.lepton_beam.divergence_ver = 187e-6;

    // Beam beta star
    cfg.hadron_beam.beta_star_hor = 800;
    cfg.hadron_beam.beta_star_ver = 72;
    cfg.lepton_beam.beta_star_hor = 590;
    cfg.lepton_beam.beta_star_ver = 57;

    // RMS emittance
    cfg.hadron_beam.rms_emittance_hor = 18e-6;
    cfg.hadron_beam.rms_emittance_ver = 1.6e-6;
    cfg.lepton_beam.rms_emittance_hor = 24e-6;
    cfg.lepton_beam.rms_emittance_ver = 2e-6;

    // RMS bunch length
    cfg.hadron_beam.rms_bunch_length = 60;
    cfg.lepton_beam.rms_bunch_length = 9;
    return cfg;
}

void ab::EicConfigurator::validate_config(ab::EicBeamEnergies ion,
                                                  ab::EicBeamEnergies lepton,
                                                  ab::EicBeamConfigs config) {
    using namespace std;

    // Ensure Beam Energies Correspond to Those Presented in CDR
    if(ion != EicBeamEnergies::E275GeV
       && ion != EicBeamEnergies::E110GeV
       && ion != EicBeamEnergies::E100GeV
       && ion != EicBeamEnergies::E41GeV)
    {
        cerr << (int)ion << " is not a valid Hadron Beam Energy!!" << endl;
        cerr << "Valid Energies are 275.0, 110.0, 100.0, and 41.0" << endl;
        cerr << "Turning off all beam effects" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }
    if(lepton != EicBeamEnergies::E18GeV
       && lepton != EicBeamEnergies::E10GeV
       && lepton != EicBeamEnergies::E_5_GeV)
    {
        cout << (int) lepton << " is not a valid Lepton Beam Energy!!" << endl;
        cout << "Valid Energies are 18.0, 10.0, and 5.0" << endl;
        throw std::invalid_argument("Ion energy setting is incorrect");
    }

    // Ensure Beam Energy Combinations Correspond to Those Presented in CDR
    bool is_wrong_combination = false;
    if(ion == EicBeamEnergies::E275GeV && (lepton != EicBeamEnergies::E18GeV && lepton != EicBeamEnergies::E10GeV)) {
        is_wrong_combination = true;
    }

    if(ion == EicBeamEnergies::E110GeV && (lepton != EicBeamEnergies::E18GeV && lepton != EicBeamEnergies::E10GeV && lepton != EicBeamEnergies::E_5_GeV))
    {
        is_wrong_combination = true;
    }

    if(ion == EicBeamEnergies::E100GeV && (lepton != EicBeamEnergies::E10GeV && lepton != EicBeamEnergies::E_5_GeV))
    {
        is_wrong_combination = true;
    }
    if(ion == EicBeamEnergies::E41GeV && lepton != EicBeamEnergies::E_5_GeV)
    {
        is_wrong_combination = true;
    }

    if(is_wrong_combination) {
        cout << (int)lepton << "x" << (int)ion << " is not a valid energy combination!!" << endl;
        cout << "Valid (ep) Combinations are 18x275, 10x275, 10x100, 5x100, and 5x41" << endl;
        cout << "Valid (eA) Combinations are 18x110, 10x110, 5x110, and 5x41" << endl;
        throw std::invalid_argument("Ion beams energy combination ");
    }
}

ab::AfterburnerConfig ab::EicConfigurator::config(ab::EicBeamEnergies hadron_energy,
                                          ab::EicBeamEnergies lepton_energy,
                                          ab::EicBeamConfigs mDivAcc) {
    using namespace std;
    validate_config(hadron_energy, lepton_energy, mDivAcc);

    // Assign Crab Beta Functions for Different Beam Energies [mm] (CDR Tab 3.3 & 3.4 and Elke)
//    cfg.hadron_beam.beta_crab_hor = 0.;
//    if((int)hadron_energy == 275) hadron_beta_crab_hor = 1300000.0;
//    if((int)hadron_energy == 110) hadron_beta_crab_hor = 500000.0; // Estimate
//    if((int)hadron_energy == 100) hadron_beta_crab_hor = 500000.0;
//    if((int)hadron_energy == 41) hadron_beta_crab_hor = 200000.0;
//
//    cfg.lepton_beam.beta_crab_hor = 0.;
//    if((int)lepton_energy == 18) lepton_beta_crab_hor = 150000.0;
//    if((int)lepton_energy == 10) lepton_beta_crab_hor = 150000.0;
//    if((int)lepton_energy == 5) lepton_beta_crab_hor = 150000.0;

    // Beta star in [mm] for different energies and configs
    double hadron_beta_star_hor = 0.; // In horizontal direction
    double hadron_beta_star_ver = 0.; // In vertical direction

    if(mDivAcc == EicBeamConfigs::HiDivergence) // High Divergence Config - CDR Table 3.3
    {
        if((int)hadron_energy == 275) hadron_beta_star_hor = 800.0;
        if((int)hadron_energy == 100 && (int)lepton_energy == 10.0) hadron_beta_star_hor = 630.0; // For root[s] = 63.2
        if((int)hadron_energy == 100 && (int)lepton_energy == 5.0) hadron_beta_star_hor = 610.0; // For root[s] = 44.7
        if((int)hadron_energy == 41) hadron_beta_star_hor = 900.0;
    }
    if(mDivAcc == EicBeamConfigs::HiAcceptance) // High Acceptance Config - CDR Table 3.4
    {
        if((int)hadron_energy == 275 && (int)lepton_energy == 18) hadron_beta_star_hor = 4170.0; // For root[s] = 140.7
        if((int)hadron_energy == 275 && (int)lepton_energy == 10) hadron_beta_star_hor = 2650.0; // For root[s] = 104.9
        if((int)hadron_energy == 100 && (int)lepton_energy == 10) hadron_beta_star_hor = 940.0; // For root[s] = 63.2
        if((int)hadron_energy == 100 && (int)lepton_energy == 5) hadron_beta_star_hor = 800.0; // For root[s] = 44.7
        if((int)hadron_energy == 41 && (int)lepton_energy == 5) hadron_beta_star_hor = 900.0; // For root[s] = 28.6
    }
    if(mDivAcc == EicBeamConfigs::ElectronAurum) // eA Config - CDR Table 3.5
    {
        if((int)hadron_energy == 110) hadron_beta_star_hor = 910.0;
        if((int)hadron_energy == 41) hadron_beta_star_hor = 900.0;
    }



    double betaStarLep = 0.;
    if(mDivAcc == EicBeamConfigs::HiDivergence) // High Divergence Config - CDR Table 3.3
    {
        if((int)lepton_energy == 18) betaStarLep = 590.0;
        if((int)lepton_energy == 10 && (int)hadron_energy == 275) betaStarLep = 450.0;  // For root[s] = 104.9
        if((int)lepton_energy == 10 && (int)hadron_energy == 100) betaStarLep = 960.0;  // For root[s] = 63.2
        if((int)lepton_energy == 5 && (int)hadron_energy == 100) betaStarLep = 780.0;  // For root[s] = 44.7
        if((int)lepton_energy == 5 && (int)hadron_energy == 41) betaStarLep = 1960.0; // For root[s] = 28.6
    }
    if(mDivAcc == EicBeamConfigs::HiAcceptance) // High Acceptance Config - CDR Table 3.4
    {
        if((int)lepton_energy == 18) betaStarLep = 3060.0;
        if((int)lepton_energy == 10 && (int)hadron_energy == 275) betaStarLep = 1490.0; // For root[s] = 104.9
        if((int)lepton_energy == 10 && (int)hadron_energy == 100) betaStarLep = 1430.0; // For root[s] = 63.2
        if((int)lepton_energy == 5 && (int)hadron_energy == 100) betaStarLep = 1030.0; // For root[s] = 44.7
        if((int)lepton_energy == 5 && (int)hadron_energy == 41) betaStarLep = 1960.0; // For root[s] = 28.6
    }
    if(mDivAcc == EicBeamConfigs::ElectronAurum)
    {
        if((int)lepton_energy == 18) betaStarLep = 1960.0;
        if((int)lepton_energy == 10) betaStarLep = 1930.0;
        if((int)lepton_energy == 5 && (int) hadron_energy == 110) betaStarLep = 1930.0;
        if((int)lepton_energy == 5 && (int) hadron_energy == 41) betaStarLep = 3070.0;
    }

    // Set different values depending on energy
    double hadronBL;  //mm
    double leptonBL;  //mm
    if((int)hadron_energy == 275) hadronBL = 60.0;
    if((int)hadron_energy == 110) hadronBL = 70.0;
    if((int)hadron_energy == 100) hadronBL = 70.0;
    if((int)hadron_energy == 41 && mDivAcc != EicBeamConfigs::ElectronAurum) hadronBL = 75.0;
    if((int)hadron_energy == 41 && mDivAcc == EicBeamConfigs::ElectronAurum) hadronBL = 116.0; // for eA
    if((int)lepton_energy == 18) leptonBL = 9.0;
    if((int)lepton_energy == 10) leptonBL = 7.0;
    if((int)lepton_energy == 5) leptonBL = 7.0;

    // Pretty print the configuration
    cout<<"Hadron bunch length: "<<hadronBL<<" [mm]\n";
    cout<<"Lepton bunch length: "<<leptonBL<<" [mm]\n";
    cout << "Hadron beta star   : " << hadron_beta_star_hor << " [mm]\n";

    const double crossing_angle = 25e-3;
    AfterburnerConfig result;

}


