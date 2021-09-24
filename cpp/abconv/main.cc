
// System and external libraries
#include <functional>

#include <HepMC3/Print.h>

#include <yaml-cpp/yaml.h>

// Afterburner and benchmarks
#include <afterburner/Afterburner.hh>
#include <benchmark/Histogrammer.hh>
#include <CLI/Error.hpp>

// ABConvert includes
#include "ArgumentProcessor.hh"
#include "FileFormats.hh"
#include "Converter.hh"


/// Hello world!
int main(int argc, char** argv)
{
    using namespace HepMC3;

    // Process user inputs
    UserArguments arg;
    try {
        arg = ArgumentProcessor::Process(argc, argv);
    }
    catch(CLI::CallForHelp& ex) {
        return EXIT_SUCCESS;
    }

    // IO files
    auto reader = ab::convert::generate_reader(arg.InputFormat, arg.InputFileName);
    auto writer = ab::convert::generate_writer(arg.OutputFormat, arg.OutputEventFileName);

    // Histogram creating tool
    Histogrammer hst(arg.OutputHistFileName);
    std::function<void(HepMC3::GenEvent&)> plotting_callback = nullptr;
    if(arg.PlottingEnabled) {
        hst.initialize();
        plotting_callback = [&hst](HepMC3::GenEvent &event) {hst.process_event(event);};  // This is called each event
    }

    // Afterburner instance
    std::shared_ptr<ab::Afterburner> afterburner;
    if(arg.AfterburnerEnabled) {
        std::cout<<"Afterburner is ENABLED\n";
        afterburner = std::make_shared<ab::Afterburner>();
        afterburner->print();                                       // Print afterburner configuation
    } else {
        std::cout<<"Afterburner is DISABLED\n";
    }

    // Configure converter
    ab::abconv::Converter conv(reader, writer, afterburner);
    conv.set_events_limit(arg.EventProcessLimit);
    conv.set_first_event_number(arg.StartEventIndex);
    conv.set_last_event_number(arg.EndEventIndex);
    conv.set_after_process_callback(plotting_callback);
    conv.set_exit_on_ca(arg.ExitOnCrossingAngle);

    // CONVERT!!!
    conv.convert();

    // Close / finalize
    // should be autohandled if(arg.PlottingEnabled) hst.finalize();
    if (reader)  reader->close();
    if (writer)  writer->close();

    return EXIT_SUCCESS;
}
