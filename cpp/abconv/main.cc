
// System and external libraries
#include <functional>

#include <HepMC3/Print.h>

#include <TFile.h>

#include <yaml-cpp/yaml.h>

// Afterburner and benchmarks
#include <afterburner/Afterburner.hh>
#include <benchmark/Histogrammer.hh>
#include <CLI/Error.hpp>

// ABConvert includes
#include "ArgumentProcessor.hh"
#include "FileFormats.hh"
#include "Converter.hh"
#include "ConfigProvider.hh"


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
    auto root_file = std::make_shared<TFile>(arg.OutputHistFileName.c_str(), "RECREATE");

    Histogrammer before_hst(root_file, "before");
    Histogrammer after_hst(root_file, "after");
    std::function<void(HepMC3::GenEvent&)> plot_prior_callback = nullptr;
    std::function<void(HepMC3::GenEvent&)> plot_after_callback = nullptr;
    if(arg.PlottingEnabled) {
        before_hst.initialize();
        after_hst.initialize();
        plot_prior_callback = [&before_hst](HepMC3::GenEvent &event) {before_hst.process_event(event);};  // This is called each event
        plot_after_callback = [&after_hst](HepMC3::GenEvent &event) {after_hst.process_event(event);};  // This is called each event
    }

    // Afterburner instance
    std::shared_ptr<ab::Afterburner> afterburner;
    if(arg.AfterburnerEnabled) {
        std::cout<<"Afterburner is ENABLED\n";
        afterburner = std::make_shared<ab::Afterburner>();

        // Check how to configure the afterburner
        auto ab_config = ab::convert::ConfigProvider::from_user_args(arg);
        afterburner->set_config(ab_config);
    } else {
        std::cout<<"Afterburner is DISABLED\n";
    }

    // Configure converter
    ab::abconv::Converter conv(reader, writer, afterburner);
    conv.set_events_limit(arg.EventProcessLimit);
    conv.set_first_event_number(arg.StartEventIndex);
    conv.set_last_event_number(arg.EndEventIndex);
    conv.set_prior_process_callback(plot_prior_callback);
    conv.set_after_process_callback(plot_after_callback);
    conv.set_exit_on_ca(arg.ExitOnCrossingAngle);

    // CONVERT!!!
    conv.convert();

    // Close / finalize
    // should be autohandled if(arg.PlottingEnabled) hst.finalize();
    if (reader)  reader->close();
    if (writer)  writer->close();
    if(root_file) {
        root_file->Write();
        root_file->Close();
    }

    return EXIT_SUCCESS;
}
