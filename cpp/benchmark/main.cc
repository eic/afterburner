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
#include "HepMC3/WriterAsciiHepMC2.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/WriterHEPEVT.h"
#include "HepMC3/ReaderFactory.h"

#include "ArgumentProcessor.hh"

#include <afterburner/Afterburner.hh>
#include <afterburner/AfterburnerConfig.hh>

void convert_hepmc3_file(const std::string &input_file_name, const std::string &output_file_name, const ab::Afterburner &afterburner)
{
    using namespace HepMC3;

    int first_event_number = 0;     // TODO move to arguments
    int last_event_number = 0;      // TODO move to arguments
    int events_parsed = 0;
    int print_each_events_parsed = 100;
    int events_limit = 0;

    // HepMC files open
    auto input_file = std::make_shared<ReaderAscii>(input_file_name);
    auto output_file=std::make_shared<WriterAscii>(output_file_name);

    // Event loop
    while( !input_file->failed() )
    {
        GenEvent evt(Units::GEV,Units::MM);
        input_file->read_event(evt);
        if( input_file->failed() )  {
            printf("End of file reached. Exit.\n");
            break;
        }
        if (evt.event_number()<first_event_number) continue;
        if (last_event_number && evt.event_number()>last_event_number) continue;
        evt.set_run_info(input_file->run_info());

        //Note the difference between ROOT and Ascii readers.
        // The former read GenRunInfo before first event and the later at the same time as first event.
        output_file->write_event(evt);

        evt.clear();
        ++events_parsed;
        if( events_parsed%print_each_events_parsed == 0 ) printf("Events parsed: %li\n",events_parsed);
        if( events_limit && events_parsed >= events_limit ) {
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
    afterburner.print();

    convert_hepmc3_file(arguments.AllFileNames[0], arguments.OutputBaseName + ".hepmc", afterburner);

    return EXIT_SUCCESS;
}
