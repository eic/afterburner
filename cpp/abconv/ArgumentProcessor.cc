#include <vector>
#include <string>
#include <random>
#include <limits>

#include <CLI/CLI.hpp>

#include "ArgumentProcessor.hh"
#include "afterburner/EicConfigurator.hh"


UserArguments ArgumentProcessor::process(int argc, char **argv)
{
    UserArguments result;                                          // This function result
    CLI::App app{get_description()};

    std::string output_base_name("ab_output");
    std::vector<std::string> opt_all_files;
    std::string preset="0";
    bool ab_off = false;
    bool plot_off = false;
    bool check_ca = false;
    unsigned long process_limit = 0;
    std::string input_format = "auto";
    std::string output_format = "treeroot";
    long ev_start = 0;
    long ev_end = 0;
    unsigned int seed = 0;

    app.add_option("-o, --output", output_base_name, "Base name for Output files ((!) no extension)");
    app.add_option("-p, --preset", preset, "0: IP6 High divergence[default], 1: IP6 High acceptance, 2: IP6 eAu; 3: IP8 Hight divergence..., More - see below");
    app.add_option("-i, --in-format", input_format, "Input format: auto [default], hepmc2, hepmc3, hpe, lhef, gz, treeroot, root");
    app.add_option("-f, --out-format", output_format, "Output format: hepmc3, treeroot [default], root, hepmc2, dot, none (no events file is saved)");

    app.add_option("-s, --ev-start", ev_start, "Start event index (all previous are skipped)");
    app.add_option("-e, --ev-end", ev_end, "End event index (end processing after this event)");
    app.add_option("-l, --limit", process_limit, "Limit number of events to process. (Shutdown after this number of parsed events).");
    auto seed_option = app.add_option("--seed", seed, "Random seed of the beam effects. Default: drawn at random, printed and stored in the output run info (ab_random_seed); pass that value to reproduce a file");

    app.add_flag("--ab-off", ab_off, "No afterburner is applied");
    app.add_flag("--plot-off", plot_off, "Don't produce validation plots");
    app.add_flag("--exit-ca", check_ca, "Check existing crossing angle and exit if CA>1mrad");
    app.set_version_flag("-v, --version", "0.1.3");

    app.add_option("input file", opt_all_files, "Input file");

    app.footer(get_footer());

    // Parse everything
    try {
        app.parse(argc, argv);
        if(opt_all_files.empty()) {
            throw std::runtime_error("Please, provide an input file");
        }
    } catch(const CLI::ParseError &e) {
        exit(app.exit(e));
    }

    // Input files (macros and data files)
    result.input_file_name = opt_all_files[0];
    result.input_format = input_format;

     // Output file name:
    result.output_base_name = output_base_name;
    result.output_format = output_format;

    // Manage output events-file and root-file name
    if("hepmc2" == output_format || "hepmc3" == output_format) {
        result.output_event_file_name = result.output_base_name + ".hepmc";
    } else if("root" == output_format || "treeroot" == output_format) {
        result.output_event_file_name = result.output_base_name + ".hepmc3.tree.root";
    } else {
        result.output_event_file_name = result.output_base_name + "." + result.output_format;
    }

    // Plots output
    result.output_hist_file_name = result.output_base_name + ".hist.root";
    result.plotting_enabled = !plot_off;

    // Does afterburner off at all?
    result.afterburner_enabled = !ab_off;

    // Limit on number of processed events
    result.event_process_limit = process_limit;
    result.start_event_index = ev_start;
    result.end_event_index = ev_end;
    result.exit_on_crossing_angle = check_ca;


    // Beam preset name
    result.preset_name = preset;

    // Beam effects seed. A fixed default would give every input file the same sequence of vertices and beam
    // kicks, so without --seed each run draws its own. Drawn from 1 to 2^31-1: 0 is GSL's alias of 4357.
    result.random_seed_given = seed_option->count() > 0;
    if(!result.random_seed_given) {
        std::random_device entropy;
        seed = std::uniform_int_distribution<unsigned int>(1, std::numeric_limits<int>::max())(entropy);
    }
    result.random_seed = seed;

    return result;
}

std::string ArgumentProcessor::get_description() {
    return "EIC Afterburner. \n\n Process HepMC2/3 and other compatible files adding crossing angle and beam effects.\n";
}

std::string ArgumentProcessor::get_footer() {
    return "-p,--preset flag, values [0,1,2] set config and auto determine energy from source file: \n"
           "  0: IP6, High divergence, auto read energy [default], \n"
           "  1: IP6, High acceptance, auto read energy\n"
           "  2: IP6, eAu, auto read energy\n"
           "  3: IP8, High divergence, auto read energy [default], \n"
           "  4: IP8, High acceptance, auto read energy\n"
           "  5: IP8, eAu, auto read energy\n"
           "The other options sets energy settings manually, not checking the source file:\n"
           "  ip6_hidiv_41x5, ip6_hidiv_100x5, ip6_hidiv_100x10, ip6_hidiv_275x10, ip6_hidiv_275x18\n"
           "  ip6_hiacc_41x5, ip6_hiacc_100x5, ip6_hiacc_100x10, ip6_hiacc_275x10, ip6_hiacc_275x18\n"
           "  ip6_eau_41x5,   ip6_eau_110x5,   ip6_eau_110x10,   ip6_eau_110x18\n"
           "  ip8_hidiv_41x5, ip8_hidiv_100x5, ip8_hidiv_100x10, ip8_hidiv_275x10, ip8_hidiv_275x18\n"
           "  ip8_hiacc_41x5, ip8_hiacc_100x5, ip8_hiacc_100x10, ip8_hiacc_275x10, ip8_hiacc_275x18\n"
           "  ip8_eau_41x5,   ip8_eau_110x5,   ip8_eau_110x10,   ip8_eau_110x18\n"
           "Example of manual configuration setting: \n"
           "  abconv -p ip6_hidiv_100x5 source_file.hepmc\n";
}
