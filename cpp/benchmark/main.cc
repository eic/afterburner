// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2019 The HepMC collaboration (see AUTHORS for details)
//
/// @example convert_example.cc
/// @brief Utility to convert between different types of event records
///
#include "HepMC3/Print.h"
#include "HepMC3/Reader.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/WriterHEPEVT.h"

#include <CLHEP/Vector/LorentzVector.h>
#include <CLHEP/Vector/EulerAngles.h>

#include "ArgumentProcessor.hh"

#include <afterburner/Afterburner.hh>
#include <afterburner/AfterburnerConfig.hh>

#include "yaml-cpp/yaml.h"
#include "Histogrammer.hh"


void convert_hepmc3_file(const std::string &input_file_name,
                         const std::string &output_file_name,
                         ab::Afterburner& afterburner,
                         const std::function<void(HepMC3::GenEvent&)>& callback=nullptr,
                         ulong events_limit = 0,
                         bool ab_off = false,
                         int verbosity = 0,
                         int first_event_number = 0,
                         int last_event_number = 0,
                         int print_each_events_parsed = 1000)
{
    using namespace HepMC3;

    long int events_parsed = 0;

    // HepMC files open
    auto input_file = std::make_shared<ReaderAsciiHepMC2>(input_file_name);
    auto output_file=std::make_shared<WriterAscii>(output_file_name);

    // Event loop
    while( !input_file->failed() ) {
        GenEvent evt(Units::GEV, Units::MM);
        input_file->read_event(evt);
        if (input_file->failed()) {
            printf("End of file reached. events_parsed: %i Exit.\n", events_parsed);
            break;
        }
        if (evt.event_number() < first_event_number) continue;
        if (last_event_number && evt.event_number() > last_event_number) continue;
        evt.set_run_info(input_file->run_info());

        if (verbosity) {
            cout << fixed;
            std::cout << "************\nORIGIN EVENT\n************\n";
            Print::content(cout, evt);
        }

        evt.set_units(Units::GEV, Units::CM);

        if (!ab_off)
        {
            // Run afterburner calculation
            auto ab_result = afterburner.process_event();

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
            if(verbosity) {
                std::cout << "************\nAFTER ROTATION\n************\n";
                Print::content(evt);
            }

            // Boost
            auto boost = ab_result.boost.boostVector();
            evt.boost(FourVector(boost.x(), boost.y(), boost.z(), 0));

            if(verbosity) {
                std::cout << "************\nAFTER BOOST\n************\n";
                Print::content(evt);
            }


            // Translate
            auto vtx = ab_result.vertex;
            evt.shift_position_to(FourVector(vtx.x(), vtx.y(), vtx.z(), vtx.t()));
            if(verbosity) {
                std::cout << "************\nAFTER TRANSLATION\n************\n";
                Print::content(evt);
            }
        }

        if(callback) {
            callback(evt);
        }

        //Note the difference between ROOT and Ascii readers.
        // The former read GenRunInfo before first event and the later at the same time as first event.
        output_file->write_event(evt);

        evt.clear();
        ++events_parsed;
        if(events_parsed%print_each_events_parsed == 0 ) printf("Events parsed: %li\n", events_parsed);
        if(events_limit && events_parsed >= events_limit ) {
            printf("Event limit reached:->events_parsed(%li) >= events_limit(%li)<-. Exit.\n",events_parsed , events_limit);
            break;
        }
    }

    if (input_file)   input_file->close();
    if (output_file)  output_file->close();
}

int main(int argc, char** argv)
{
    using namespace HepMC3;

    // Process user inputs
    ArgumentProcessor arg_processor;
    auto arguments = arg_processor.Process(argc, argv);

    // Afterburner instance
    ab::Afterburner afterburner;

    if(arguments.BenchmarkName == "crossing") {
        // Only crossing angle benchmark

        ab::AfterburnerConfig cfg;
        //25mrad x-ing as in EIC CDR
        const double EIC_hadron_crossing_angle = 25e-3;

        cfg.beam_one.direction_theta = EIC_hadron_crossing_angle;   // beamA_theta
        cfg.beam_one.direction_phi = 0;                             // beamA_phi
        cfg.beam_two.direction_theta = M_PI;                        // beamB_theta
        cfg.beam_two.direction_phi = 0;                             // beamB_phi

        cfg.beam_one.divergence_hor = 0;
        cfg.beam_one.divergence_ver = 0;
        cfg.beam_two.divergence_hor = 0;
        cfg.beam_two.divergence_ver = 0;

        cfg.beam_one.z_shift_hor = 0;
        cfg.beam_one.z_shift_ver = 0;
        cfg.beam_two.z_shift_hor = 0;
        cfg.beam_two.z_shift_ver = 0;

        cfg.vertex_smear_width_x = 0;
        cfg.vertex_smear_width_y = 0;
        cfg.vertex_smear_width_z = 0;
        cfg.vertex_smear_width_t = 0;

        cfg.use_beam_bunch_sim = false;

        afterburner.set_config(cfg);
    }
    else if(arguments.BenchmarkName == "plots") {

    }
    else
    {
        // Default configuration benchmark
        // Nothing is here as everything is setup by default
    }

    Histogrammer hst(arguments.OutputFileName + ".root");
    hst.initialize();

    afterburner.print();
    convert_hepmc3_file(arguments.InputFileName,
                        arguments.OutputFileName,
                        afterburner,
                        [&hst](HepMC3::GenEvent &event) {hst.process_event(event);},
                        arguments.EventProcessLimit,
                        arguments.NoAfterburner);
    hst.finalize();

    return EXIT_SUCCESS;
}
