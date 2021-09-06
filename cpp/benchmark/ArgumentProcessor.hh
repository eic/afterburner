#ifndef G4E_ARGUMENTPROCESSOR_HH
#define G4E_ARGUMENTPROCESSOR_HH

#include <vector>
#include <string>


/** \file
 *  ArgumentProcessor manage users inputs on program start.
 *  By the arguments one means:
 *      1. Program arguments
 *      2. Environment variables
 *      3. Pipe (when implemented)
 *
 *  InputArguments is the result of work of ArgumentProcessor.
 *  InputArguments represents a set of ready to use parameters:
 *      1. Configure initialization
 *      2. Provide running aspects (verbosity, input, output)
 *      3. Info, what was set by user (macro PATH env, macros to run, input files (if given by command line)
 */


/// Program Configuration provided by arguments or environment variables
/// This class provides all needed dynamic information about flags and
/// environment variables provided by users
struct UserArguments
{
    std::string InputFileName;          /// List of all arguments which are not flags=values (macro file names, input file names, etc.)
    std::string OutputFileName;                     /// Desired output file(s) name (without suffix and extension)
    std::string BenchmarkName;                      /// Benchmark name
};


class ArgumentProcessor
{
public:

    static UserArguments Process(int argc, char **argv);

private:

    /// Processes both program arguments and environment variables to build the right ProgramArguments

    static std::string get_description();
};




#endif //G4E_ARGUMENTPROCESSOR_HH
