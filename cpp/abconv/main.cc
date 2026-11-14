
// System and external libraries
#include <functional>

#include <HepMC3/Print.h>

#include <TFile.h>

#include <yaml-cpp/yaml.h>

// Afterburner and benchmarks
#include <afterburner/Afterburner.hh>
#include <benchmark/Histogrammer.hh>

// ABConvert includes
#include "ArgumentProcessor.hh"
#include "FileFormats.hh"
#include "Converter.hh"
#include "ConfigProvider.hh"


int main(int argc, char** argv)
{
    using namespace HepMC3;

    // Process user inputs (exits on --help, --version and argument errors)
    UserArguments arg = ArgumentProcessor::process(argc, argv);

    // IO files
    auto reader = ab::convert::generate_reader(arg.input_format, arg.input_file_name);
    auto writer = ab::convert::generate_writer(arg.output_format, arg.output_event_file_name);


    // Histogram creating tool
    auto root_file = std::make_shared<TFile>(arg.output_hist_file_name.c_str(), "RECREATE");

    Histogrammer before_hst(root_file, "before");
    Histogrammer after_hst(root_file, "after");
    std::function<void(HepMC3::GenEvent&)> plot_prior_callback = nullptr;
    std::function<void(HepMC3::GenEvent&)> plot_after_callback = nullptr;
    if(arg.plotting_enabled) {
        before_hst.initialize();
        after_hst.initialize();
        plot_prior_callback = [&before_hst](HepMC3::GenEvent &event) {before_hst.process_event(event);};  // This is called each event
        plot_after_callback = [&after_hst](HepMC3::GenEvent &event) {after_hst.process_event(event);};  // This is called each event
    }

    // Afterburner instance
    std::shared_ptr<ab::Afterburner> afterburner;
    if(arg.afterburner_enabled) {
        std::cout<<"Afterburner is ENABLED\n";
        afterburner = std::make_shared<ab::Afterburner>();

        // Check how to configure the afterburner
        auto ab_config = ab::convert::ConfigProvider::from_user_args(arg);
        ab_config.random_seed = arg.random_seed;
        afterburner->set_config(ab_config);
        if(!arg.random_seed_given) {
            std::cout << "Random seed " << arg.random_seed << " was drawn for this run; --seed " << arg.random_seed << " reproduces it\n";
        }
    } else {
        std::cout<<"Afterburner is DISABLED\n";
    }

    // Configure converter
    ab::abconv::Converter conv(reader, writer, afterburner);
    conv.set_events_limit(arg.event_process_limit);
    conv.set_first_event_number(arg.start_event_index);
    conv.set_last_event_number(arg.end_event_index);
    conv.set_prior_process_callback(plot_prior_callback);
    conv.set_after_process_callback(plot_after_callback);
    conv.set_exit_on_ca(arg.exit_on_crossing_angle);

    // CONVERT!!!
    conv.convert();

    // Close / finalize
    // should be autohandled if(arg.plotting_enabled) hst.finalize();
    if (reader)  reader->close();
    if (writer)  writer->close();
    if(root_file) {
        root_file->Write();
        root_file->Close();
    }

    return EXIT_SUCCESS;
}
