//
// Created by romanov on 10/27/21.
//

#include <HepMC3/GenEvent.h>
#include <HepMC3/GenParticle.h>
#include "ConfigProvider.hh"
#include "FileFormats.hh"

ab::AfterburnerConfig
ab::convert::ConfigProvider::from_hepmc_file(const std::shared_ptr<HepMC3::Reader>& reader, ab::EicBeamPresets beam_config) {

    HepMC3::GenEvent evt;
    reader->read_event(evt);
    if (reader->failed()) {
        printf("Reader is in failed state. Couldn't open the file or the file is empty\n");
    }

    // Select beam particles
    HepMC3::ConstGenParticles beam_particles;
    for(auto& prt: evt.particles()) {
        if(prt->status() == 4) {
            beam_particles.push_back(prt);
        }
    }

    HepMC3::ConstGenParticlePtr ion;
    HepMC3::ConstGenParticlePtr electron;
    
    if(beam_particles[0]->pid()==11) {
        electron = beam_particles[0];
        ion      = beam_particles[1];
    }
    else if(beam_particles[1]->pid()==11) {
        electron = beam_particles[1];
	ion      = beam_particles[0];        
    }
    else {
      std::cerr << "No electron found in the two beam particles" << std::endl;
      throw std::invalid_argument("No electron found");
    }

    return ab::EicConfigurator::config(ion, electron, beam_config);
}

ab::AfterburnerConfig ab::convert::ConfigProvider::from_preset_name(const string &name) {
    return ab::EicConfigurator::from_string(name);
}

ab::AfterburnerConfig ab::convert::ConfigProvider::from_user_args(UserArguments arg) {
    auto reader = ab::convert::generate_reader(arg.InputFormat, arg.InputFileName);

    if(arg.preset_name == "0") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip6HighDivergence);
    }

    if(arg.preset_name == "1") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip6HighAcceptance);
    }

    if(arg.preset_name == "2") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip6ElectronAurum);
    }

    if(arg.preset_name == "3") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip8HighDivergence);
    }

    if(arg.preset_name == "4") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip8HighAcceptance);
    }

    if(arg.preset_name == "5") {
        return from_hepmc_file(reader, ab::EicBeamPresets::Ip8ElectronAurum);
    }

    // If it is not 0, 1, or 2, it is a manual config
    return from_preset_name(arg.preset_name);
}
