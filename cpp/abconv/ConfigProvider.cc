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
    HepMC3::ConstGenParticlePtr hadron;
    HepMC3::ConstGenParticlePtr lepton;
    if(beam_particles[0]->momentum().e() > beam_particles[1]->momentum().e()) {
        hadron = beam_particles[0];
        lepton = beam_particles[1];
    }
    else {
        hadron = beam_particles[1];
        lepton = beam_particles[0];
    }

    return ab::EicConfigurator::config(hadron->momentum().e(), lepton->momentum().e(), beam_config);
}

ab::AfterburnerConfig ab::convert::ConfigProvider::from_preset_name(const string &name) {
    return ab::EicConfigurator::from_string(name);
}

ab::AfterburnerConfig ab::convert::ConfigProvider::from_user_args(UserArguments arg) {
    auto reader = ab::convert::generate_reader(arg.InputFormat, arg.InputFileName);

    if(arg.preset_name == "0") {
        return from_hepmc_file(reader, ab::EicBeamPresets::HighDivergence);
    }

    if(arg.preset_name == "1") {
        return from_hepmc_file(reader, ab::EicBeamPresets::HighAcceptance);
    }

    if(arg.preset_name == "2") {
        return from_hepmc_file(reader, ab::EicBeamPresets::ElectronAurum);
    }

    // If it is not 0, 1, or 2, it is a manual config
    return from_preset_name(arg.preset_name);
}
