#include <vector>
#include <string>

#include <CLI/CLI.hpp>

#include "ArgumentProcessor.hh"


UserArguments ArgumentProcessor::Process(int argc, char **argv)
{
    UserArguments result;                                          // This function result
    CLI::App app{get_description()};

    std::string optOutputName("ab_output.hepmc");
    std::vector<std::string> optAllFiles;
    std::string benchmarkName("default");

    app.add_option("-o,--output", optOutputName, "Base name for Output files");
    app.add_option("-b,--benchmark", benchmarkName, "Benchmark name: default, crossing");
    app.add_option("input file", optAllFiles, "Input file");

    // Parse everything
    try {
        app.parse(argc, argv);
        if(optAllFiles.empty()) {
            throw std::runtime_error("Please, provide an input file");
        }
    } catch(const CLI::ParseError &e) {
        app.exit(e);
        throw;
    }

    // Input files (macros and data files)
    result.InputFileName = optAllFiles[0];

     // Output file name:
    result.OutputFileName = optOutputName;

    result.BenchmarkName = benchmarkName;
    return result;
}

std::string ArgumentProcessor::get_description() {
    return "EIC Afterburner benchmarks";
}


