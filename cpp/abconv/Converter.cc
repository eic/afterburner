//
// Created by romanov on 9/17/21 (birthday!).
//

#include <cmath>
#include <utility>

#include <HepMC3/GenEvent.h>
#include <HepMC3/Print.h>

#include <CLHEP/Vector/EulerAngles.h>
#include "Converter.hh"


void ab::abconv::Converter::convert() {
    using namespace HepMC3;

    long int events_processed = 0;

    // HepMC files open


    // Event loop
    while( !_reader->failed() ) {
        GenEvent evt;
        _reader->read_event(evt);
        if (_reader->failed()) {
            printf("End of file reached. Events processed: %i Exit.\n", events_processed);
            break;
        }
        if (evt.event_number() < _first_event_number) continue;

        if (_last_event_number && evt.event_number() > _last_event_number) continue;
        evt.set_run_info(_reader->run_info());

        if(0 == events_processed) {
            // The first event, determine beams configuration
            get_beams_setup(evt);

        }

        if (_verbose) {
            cout << fixed;
            std::cout << "************\nORIGIN EVENT\n************\n";
            Print::content(cout, evt);
        }

        evt.set_units(Units::GEV, Units::CM);

        if (_afterburner)
        {
            // Run afterburner calculation
            auto ab_result = _afterburner->process_event();

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

            // Boost
            auto boost = ab_result.boost.boostVector();
            evt.boost(FourVector(boost.x(), boost.y(), boost.z(), 0));

            if(_verbose) {
                std::cout << "************\nAFTER BOOST\n************\n";
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

        if(_ap_callback) {
            _ap_callback(evt);
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
            printf("Event limit reached:-> Events processed: %li >= Events_limit: %li\n", events_processed , _events_limit);
            break;
        }
    }
}

ab::abconv::Converter::Converter(std::shared_ptr<HepMC3::Reader> reader,
                                 std::shared_ptr<HepMC3::Writer> writer,
                                 std::shared_ptr<ab::Afterburner> afterburner):
    _reader(std::move(reader)), _writer(std::move(writer)), _afterburner(std::move(afterburner))
{

}

void ab::abconv::Converter::print_processed_events(long count) {

    long div = 10000;
    if(!count) return;
    if(count < 20000) div = 5000;
    if(count < 5000) div = 1000;


    if(count % div == 0 ) printf("Events parsed: %li\n", count);
}

void ab::abconv::Converter::get_beams_setup(const HepMC3::GenEvent& event) {

    std::vector<std::shared_ptr<const HepMC3::GenParticle>> beam_particles;

    // Select beam particles
    for(auto& prt: event.particles()) {
        if(prt->status() == 4) {
            beam_particles.push_back(prt);
        }
    }

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
    double cangle = std::acos(one_dot_two/(mom_one.length()*mom_two.length())) - M_PI;
    printf("   crossing angle: %.0f [mrad]\n", cangle*1000);
    printf("=========================\n");
}


