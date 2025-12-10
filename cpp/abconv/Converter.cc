//
// Created by romanov on 9/17/21 (birthday!).
//

#include <cmath>
#include <utility>
#include <inttypes.h>

#include <HepMC3/GenEvent.h>
#include <HepMC3/Print.h>

#include <CLHEP/Vector/EulerAngles.h>
#include "Converter.hh"
#include "afterburner/EicConfigurator.hh"

ab::abconv::Converter::Converter(std::shared_ptr<HepMC3::Reader> reader,
                                 std::shared_ptr<HepMC3::Writer> writer,
                                 std::shared_ptr<ab::Afterburner> afterburner):
        _reader(std::move(reader)), _writer(std::move(writer)), _afterburner(std::move(afterburner))
{
}

void ab::abconv::Converter::convert() {
    using namespace HepMC3;

    uint64_t events_processed = 0;
    // HepMC files open

    // Event loop
    while( !_reader->failed() ) {
        GenEvent evt;
        _reader->read_event(evt);
        if (_reader->failed()) {
            printf("End of file reached. Events processed: %" PRIu64 " Exit.\n", events_processed);
            break;
        }
        if (evt.event_number() < _first_event_number) continue;

        if (_last_event_number && evt.event_number() > _last_event_number) break;

        if(0 == events_processed) {
            // The first event, determine beams configuration
            bool must_exit = check_beams_setup(evt);
            if(must_exit) return;

            // Have to copy run info from existing hepmc
            auto run_info = _reader->run_info();

            // Autodetect afterburner config if we have afterburner
            if(_afterburner) {
                // Print AB configuration and add it to RunInfo
                _afterburner->print();

                // Copy afterburner data to run info
                ab_config_to_run_info(run_info, _afterburner->config());
            }
            else {
                // set afterburner is not used to run info
                run_info->add_attribute("ab_afterburner_is_used", std::make_shared<BoolAttribute>(false));
            }

            // save updated run info
            evt.set_run_info(run_info);
        }

        if (_verbose) {
            cout << fixed;
            std::cout << "************\nORIGIN EVENT\n************\n";
            Print::content(cout, evt);
        }

        evt.set_units(Units::GEV, Units::MM);
        if(_prior_process_callback) {
            _prior_process_callback(evt);
        }

        if (_afterburner)
        {
            // Run afterburner calculation
            auto ab_result = _afterburner->process_event();

            // Boost
            auto boost = ab_result.boost.boostVector();
            evt.boost(FourVector(boost.x(), boost.y(), boost.z(), 0));

            if(_verbose) {
                std::cout << "************\nAFTER BOOST\n************\n";
                Print::content(evt);
            }

            // Rotate
            auto axis = ab_result.rotation.axis();
            auto euler = ab_result.rotation.eulerAngles();

            // Instead of using HepMC rotate, we just rotate particle momentum-s (vertex rotation is done in the AB)
            for (const auto& p: evt.particles())
            {
                FourVector mom=p->momentum();

                CLHEP::Hep3Vector tmp(mom.x(), mom.y(), mom.z());
                tmp = tmp.rotate(ab_result.rotation.eulerAngles());

                FourVector temp(tmp.x(),tmp.y(),tmp.z(),mom.e());
                p->set_momentum(temp);
            }
            if(_verbose) {
                std::cout << "************\nAFTER ROTATION\n************\n";
                Print::content(evt);
            }


            // Translate
            auto vtx = ab_result.vertex;
            evt.shift_position_to(FourVector(vtx.x(), vtx.y(), vtx.z(), vtx.t()));
            if(_verbose) {
                std::cout << "************\nAFTER TRANSLATION\n************\n";
                Print::content(evt);
            }
        }

        if(_after_process_callback) {
            _after_process_callback(evt);
        }

        //Note the difference between ROOT and Ascii readers.
        // The former read GenRunInfo before first event and the later at the same time as first event.
        if(_writer) {
            _writer->write_event(evt);
        }

        evt.clear();
        ++events_processed;
        print_processed_events(events_processed);

        if(_events_limit && events_processed >= _events_limit ) {
            printf("Event limit reached:-> Events processed: %" PRIu64 " >= Events_limit: %" PRIu64 "\n", events_processed , _events_limit);
            break;
        }
    }
}



void ab::abconv::Converter::print_processed_events(uint64_t count) {

    uint64_t div = 10000;
    if(!count) return;
    if(count < 20000) div = 5000;
    if(count < 5000) div = 1000;


    if(count % div == 0 ) printf("Events parsed: %" PRIu64 "\n", count);
}


bool ab::abconv::Converter::check_beams_setup(const HepMC3::GenEvent& event) {

    HepMC3::ConstGenParticles beam_particles = get_beam_particles(event);

    // Check particles
    if(beam_particles.size() != 2) {
        std::stringstream msg("Input file should have exactly 2 beam particles (status code = 4). File has ");
        msg<<beam_particles.size();
        throw std::runtime_error(msg.str());
    }

    auto mom_one = beam_particles[0]->momentum();
    auto mom_two = beam_particles[1]->momentum();
    auto pdg_one = beam_particles[0]->pdg_id();
    auto pdg_two = beam_particles[1]->pdg_id();
    if(mom_one.length() < 1e-9) throw std::runtime_error("Beam one particle momentum is too close to 0 (|p| < 1e-9)");
    if(mom_two.length() < 1e-9) throw std::runtime_error("Beam two particle momentum is too close to 0 (|p| < 1e-9)");


    printf("Initial beam particles (before afterburner):\n");
    printf("   pdg: %d   p: %.1f, %.1f, %.1f   e:%.1f\n", pdg_one, mom_one.x(), mom_one.y(), mom_one.z(), mom_one.e());
    printf("   pdg: %d   p: %.1f, %.1f, %.1f   e:%.1f\n", pdg_two, mom_two.x(), mom_two.y(), mom_two.z(), mom_two.e());
    double one_dot_two = mom_one.x()*mom_two.x() + mom_one.y()*mom_two.y() + mom_one.z()*mom_two.z();
    double crossing_angle = std::acos(one_dot_two / (mom_one.length() * mom_two.length())) - M_PI;
    printf("   crossing angle: %.0f [mrad]\n", crossing_angle * 1000);
    printf("=========================\n");

    if(_exit_on_ca && fabs(crossing_angle)>0.001) {
        printf("(!) Existing crossing angle > 1mrad and --exit-ca flag is used. Exiting\n");
        return true;
    }

    return false;
}

HepMC3::ConstGenParticles ab::abconv::Converter::get_beam_particles(const HepMC3::GenEvent &event) const {
    HepMC3::ConstGenParticles beam_particles;
    // Select beam particles
    for(auto& prt: event.particles()) {
        if(prt->status() == 4) {
            beam_particles.push_back(prt);
        }
    }
    return beam_particles;
}

void ab::abconv::Converter::ab_config_to_run_info(const std::shared_ptr<HepMC3::GenRunInfo>& run_info, ab::AfterburnerConfig cfg) {
    using namespace HepMC3;  

    run_info->add_attribute("ab_afterburner_is_used",   std::make_shared<BoolAttribute>(true));
    run_info->add_attribute("afterburner_config_name",  std::make_shared<StringAttribute>(cfg.name));

    run_info->add_attribute("ion_beam_energy",          std::make_shared<DoubleAttribute>(cfg.ion_beam.energy));
    run_info->add_attribute("electron_beam_energy",     std::make_shared<DoubleAttribute>(cfg.electron_beam.energy));

    run_info->add_attribute("ion_beam_pdg",             std::make_shared<IntAttribute>(cfg.ion_beam.pdg));
    run_info->add_attribute("electron_beam_pdg",        std::make_shared<IntAttribute>(cfg.electron_beam.pdg));

    run_info->add_attribute("ab_crossing_angle",        std::make_shared<DoubleAttribute>(cfg.crossing_angle_hor));
    run_info->add_attribute("ab_use_beam_bunch_sim",    std::make_shared<BoolAttribute>(cfg.use_beam_bunch_sim));

    run_info->add_attribute("ab_ion_divergence_hor",    std::make_shared<DoubleAttribute>(cfg.ion_beam.divergence_hor));
    run_info->add_attribute("ab_ion_divergence_ver",    std::make_shared<DoubleAttribute>(cfg.ion_beam.divergence_ver));
    run_info->add_attribute("ab_ion_beta_crab_hor",     std::make_shared<DoubleAttribute>(cfg.ion_beam.beta_crab_hor));
    run_info->add_attribute("ab_ion_beta_star_hor",     std::make_shared<DoubleAttribute>(cfg.ion_beam.beta_star_hor));
    run_info->add_attribute("ab_ion_beta_star_ver",     std::make_shared<DoubleAttribute>(cfg.ion_beam.beta_star_ver));
    run_info->add_attribute("ab_ion_rms_emittance_hor", std::make_shared<DoubleAttribute>(cfg.ion_beam.rms_emittance_hor));
    run_info->add_attribute("ab_ion_rms_emittance_ver", std::make_shared<DoubleAttribute>(cfg.ion_beam.rms_emittance_ver));
    run_info->add_attribute("ab_ion_rms_bunch_length",  std::make_shared<DoubleAttribute>(cfg.ion_beam.rms_bunch_length));

    run_info->add_attribute("ab_electron_divergence_hor",    std::make_shared<DoubleAttribute>(cfg.electron_beam.divergence_hor));
    run_info->add_attribute("ab_electron_divergence_ver",    std::make_shared<DoubleAttribute>(cfg.electron_beam.divergence_ver));
    run_info->add_attribute("ab_electron_beta_crab_hor",     std::make_shared<DoubleAttribute>(cfg.electron_beam.beta_crab_hor));
    run_info->add_attribute("ab_electron_beta_star_hor",     std::make_shared<DoubleAttribute>(cfg.electron_beam.beta_star_hor));
    run_info->add_attribute("ab_electron_beta_star_ver",     std::make_shared<DoubleAttribute>(cfg.electron_beam.beta_star_ver));
    run_info->add_attribute("ab_electron_rms_emittance_hor", std::make_shared<DoubleAttribute>(cfg.electron_beam.rms_emittance_hor));
    run_info->add_attribute("ab_electron_rms_emittance_ver", std::make_shared<DoubleAttribute>(cfg.electron_beam.rms_emittance_ver));
    run_info->add_attribute("ab_electron_rms_bunch_length",  std::make_shared<DoubleAttribute>(cfg.electron_beam.rms_bunch_length));
}

