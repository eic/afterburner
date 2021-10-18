#include <vector>
#include <string>

#include <CLI/CLI.hpp>

#include "ArgumentProcessor.hh"
#include "afterburner/EicConfigurator.hh"


UserArguments ArgumentProcessor::Process(int argc, char **argv)
{
    UserArguments result;                                          // This function result
    CLI::App app{get_description()};

    std::string output_base_name("ab_output.hepmc");
    std::vector<std::string> optAllFiles;
    std::string config_file="0";
    bool ab_off = false;
    bool plot_off = false;
    bool check_ca = false;
    ulong process_limit = 0;
    std::string input_format = "auto";
    std::string output_format = "hepmc3";
    long ev_start = 0;
    long ev_end = 0;

    app.add_option("-o,--output", output_base_name, "Base name for Output files ((!) no extension)");
    app.add_option("-c,--config", config_file, "0: High divergence[default], 1: High acceptance, 2: eAu");
    app.add_option("-i, --in-format", input_format, "Input format: auto [default], hepmc2, hepmc3, hpe, lhef, gz, treeroot, root");
    app.add_option("-f, --out-format", output_format, "Output format: hepmc3 [default], hepmc2, dot, none (no events file is saved)");

    app.add_option("-s, --ev-start", ev_start, "Start event index (all previous are skipped)");
    app.add_option("-e, --ev-end", ev_end, "End event index (end processing after this event)");
    app.add_option("-l, --limit", process_limit, "Limit number of events to process. (Shutdown after this number of parsed events).");

    app.add_flag("--ab-off", ab_off, "No afterburner is applied");
    app.add_flag("--plot-off", plot_off, "Don't produce validation plots");
    app.add_flag("--exit-ca", check_ca, "Check existing crossing angle and exit if CA>1mrad");
    app.set_version_flag("-v, --version", "0.1.1");

    app.add_option("input file", optAllFiles, "Input file");

    // Parse everything
    try {
        app.parse(argc, argv);
        if(optAllFiles.empty()) {
            throw std::runtime_error("Please, provide an input file");
        }
    } catch(const CLI::ParseError &e) {
        exit(app.exit(e));
    }



    // Input files (macros and data files)
    result.InputFileName = optAllFiles[0];
    result.InputFormat = input_format;

     // Output file name:
    result.OutputBaseName = output_base_name;
    result.OutputFormat = output_format;

    // Manage output events-file and root-file name
    if("hepmc2" == output_format || "hepmc3" == output_format) {
        result.OutputEventFileName = result.OutputBaseName + ".hepmc";
    } else {
        result.OutputEventFileName = result.OutputBaseName + "." + result.OutputFormat;
    }

    // Plots output
    result.OutputHistFileName = result.OutputBaseName + ".hist.root";
    result.PlottingEnabled = !plot_off;

    // Does afterburner off at all?
    result.AfterburnerEnabled = !ab_off;

    // Limit on number of processed events
    result.EventProcessLimit = process_limit;
    result.StartEventIndex = ev_start;
    result.EndEventIndex = ev_end;
    result.ExitOnCrossingAngle = check_ca;

    ab::EicBeamConfigs config;
    bool is_predefined_config=false;
    if(config_file == "0") {
        config = ab::EicBeamConfigs::HighDivergence;
        is_predefined_config= true;
    }
    if(config_file == "1") {
        config = ab::EicBeamConfigs::HighAcceptance;
        is_predefined_config=true;
    }
    if(config_file == "2") {
        config = ab::EicBeamConfigs::ElectronAurum;
        is_predefined_config=true;
    }
    result.IsPredefinedConfig=is_predefined_config;
    result.PredefinedConfig=config;

    return result;
}

std::string ArgumentProcessor::get_description() {
    return "EIC Afterburner. \n\n Process HepMC2/3 and other compatible files adding crossing angle and beam effects.\n";
}


