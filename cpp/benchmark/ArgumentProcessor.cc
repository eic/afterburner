#include <vector>
#include <string>

#include <CLI/CLI.hpp>

#include "ArgumentProcessor.hh"


UserArguments ArgumentProcessor::Process(int argc, char **argv)
{
    UserArguments result;                                          // This function result
    CLI::App app{mAppDescription};

    std::string optOutputName("g4e_output");
    std::vector<std::string> optAllFiles;
    app.add_option("-o,--output", optOutputName, "Base name for Output files");
    app.add_option("files", optAllFiles, "Input files. ");

    // Parse everything
    try {
        app.parse(argc, argv);
    } catch(const CLI::ParseError &e) {
        app.exit(e);
        throw;
    }

    // Input files (macros and data files)
    result.AllFileNames = optAllFiles;

     // Output file name:
    result.OutputBaseName = optOutputName;

    return result;
}

std::string ArgumentProcessor::mAppDescription =
        "EIC Afterburner benchmarks";

