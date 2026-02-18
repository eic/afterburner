#include "EicConfigurator.hh"
#include "YamlConfigFile.hh"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

ab::AfterburnerConfig ab::EicConfigurator::config(HepMC3::ConstGenParticlePtr ion, HepMC3::ConstGenParticlePtr electron, ab::EicBeamPresets beam_preset) {
    float ion_energy      = ion->momentum().e();
    float electron_energy = electron->momentum().e();

    int ion_e = 0;
    int electron_e = 0;

    // Approximate energies so it tolerate some spread
    if(ion_energy > 270 && ion_energy < 280) ion_e = 275;
    if(ion_energy > 245 && ion_energy < 255) ion_e = 250;
    if(ion_energy > 161 && ion_energy < 171) ion_e = 166;
    if(ion_energy > 125 && ion_energy < 135) ion_e = 130;
    if(ion_energy > 112 && ion_energy < 118) ion_e = 115;
    if(ion_energy > 105 && ion_energy < 115) ion_e = 110;
    if(ion_energy > 95  && ion_energy < 105) ion_e = 100;
    if(ion_energy > 37  && ion_energy < 44) ion_e = 41;

    if(electron_energy > 15 && electron_energy < 21) electron_e = 18;
    if(electron_energy > 7  && electron_energy < 13) electron_e = 10;
    if(electron_energy > 3  && electron_energy < 7)  electron_e = 5;

    if(ion_e != 275 && ion_e != 250 && ion_e != 166 && ion_e != 130 && ion_e != 115 && ion_e != 110 && ion_e != 100 && ion_e != 41) {
        cerr << (int)ion_e << " is not a valid ion Beam Energy!!" << endl;
        cerr << "Valid Energies are 275, 250, 166, 130, 115, 110, 100, and 41" << endl;
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

    // Build configuration name from preset and energies
    std::string config_name;
    std::string ip_str;
    std::string profile_str;
    
    // Determine IP and profile from beam preset
    switch(beam_preset) {
        case EicBeamPresets::Ip6HighDivergence:
            ip_str = "ip6";
            profile_str = "hidiv";
            break;
        case EicBeamPresets::Ip6HighAcceptance:
            ip_str = "ip6";
            profile_str = "hiacc";
            break;
        case EicBeamPresets::Ip6ElectronAurum:
            ip_str = "ip6";
            profile_str = "eau";
            break;
        case EicBeamPresets::Ip8HighDivergence:
            ip_str = "ip8";
            profile_str = "hidiv";
            break;
        case EicBeamPresets::Ip8HighAcceptance:
            ip_str = "ip8";
            profile_str = "hiacc";
            break;
        case EicBeamPresets::Ip8ElectronAurum:
            ip_str = "ip8";
            profile_str = "eau";
            break;
        default:
            throw std::invalid_argument("Unknown beam preset");
    }
    
    // Special cases for certain ion types
    if (ion == EicBeamEnergies::E115GeV && electron == EicBeamEnergies::E10GeV) {
        // Cu or Ru - we have specific configs for these
        // Using eRu config as default (eCu config also available with same naming pattern)
        config_name = ip_str + "_eRu_" + std::to_string((int)ion) + "x" + std::to_string((int)electron);
    } else if (ion == EicBeamEnergies::E166GeV && electron == EicBeamEnergies::E10GeV) {
        config_name = ip_str + "_eHe3_" + std::to_string((int)ion) + "x" + std::to_string((int)electron);
    } else if (ion == EicBeamEnergies::E130GeV && electron == EicBeamEnergies::E10GeV) {
        config_name = ip_str + "_eD_" + std::to_string((int)ion) + "x" + std::to_string((int)electron);
    } else if (ion == EicBeamEnergies::E250GeV && electron == EicBeamEnergies::E10GeV) {
        config_name = ip_str + "_ep_" + std::to_string((int)ion) + "x" + std::to_string((int)electron);
    } else {
        // Standard naming: ip{6|8}_{profile}_{ion}x{electron}
        config_name = ip_str + "_" + profile_str + "_" + std::to_string((int)ion) + "x" + std::to_string((int)electron);
    }
    
    return from_string(config_name);
}

ab::AfterburnerConfig ab::EicConfigurator::from_string(const std::string &name) {
    // Load configuration from YAML file
    return ab::YamlConfigFile::load_config(name);
}
