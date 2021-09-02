// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2019 The HepMC collaboration (see AUTHORS for details)
//
/// @example convert_example.cc
/// @brief Utility to convert between different types of event records
///
#include "HepMC3/Print.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/Reader.h"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMC3/WriterAsciiHepMC2.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/WriterHEPEVT.h"
#include "HepMC3/WriterPlugin.h"
#include "HepMC3/ReaderHEPEVT.h"
#include "HepMC3/ReaderLHEF.h"
#include "HepMC3/ReaderPlugin.h"
#include "HepMC3/ReaderFactory.h"

#include "ArgumentProcessor.hh"

int main(int argc, char** argv)
{
    using namespace HepMC3;
    
    ArgumentProcessor arg_processor;
    auto arguments = arg_processor.Process(argc, argv);
    auto input_file = std::make_shared<ReaderAscii>(arguments.AllFileNames[0]);
    auto output_file=std::make_shared<WriterAscii>(arguments.OutputBaseName + ".hepmc");

    while( !input_file->failed() )
    {
        GenEvent evt(Units::GEV,Units::MM);
        input_file->read_event(evt);
        if( input_file->failed() )  {
            printf("End of file reached. Exit.\n");
            break;
        }
        if (evt.event_number()<first_event_number) continue;
        if (evt.event_number()>last_event_number) continue;
        evt.set_run_info(input_file->run_info());

        //Note the difference between ROOT and Ascii readers.
        // The former read GenRunInfo before first event and the later at the same time as first event.
        if (!ignore_writer)
        {
            if (output_file)
            {
                output_file->write_event(evt);
            }
            else
            {
                Print::content(evt);
            }
        }
        evt.clear();
        ++events_parsed;
        if( events_parsed%print_each_events_parsed == 0 ) printf("Events parsed: %li\n",events_parsed);
        if( events_parsed >= events_limit ) {
            printf("Event limit reached:->events_parsed(%li) >= events_limit(%li)<-. Exit.\n",events_parsed , events_limit);
            break;
        }
    }

    if (input_file)   input_file->close();
    if (output_file)  output_file->close();
    return EXIT_SUCCESS;
}
