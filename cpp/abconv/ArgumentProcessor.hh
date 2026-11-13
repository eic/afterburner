#ifndef G4E_ARGUMENTPROCESSOR_HH
#define G4E_ARGUMENTPROCESSOR_HH

#include <vector>
#include <string>
#include <afterburner/EicConfigurator.hh>



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
    std::string input_file_name;          /// List of all arguments which are not flags=values (macro file names, input file names, etc.)
    std::string input_format;             /// One of: hepmc2, hepmc3, hpe, lhef, gz, treeroot, root
    std::string output_base_name;         /// Desired output file(s) name (without suffix and extension)
    std::string output_format;            /// Output format, one of:
    std::string output_event_file_name;   /// hepmc2, hepmc3, dot, none
    std::string output_hist_file_name;    /// Exact file name for histograms file
    bool plotting_enabled;                /// Don't produce validation plots
    bool afterburner_enabled;             /// Switch off afterburner
    unsigned long event_process_limit;    /// Limit on processed events. Will shut down after this number of events processed

    long start_event_index;               /// Start event index (all skipped before that)
    long end_event_index;                 /// End event index (stop after that)
    bool exit_on_crossing_angle;          /// Check existing crossing angle and exit if CA>1mrad
    std::string preset_name;              /// Predefined config to use
    unsigned int random_seed;             /// Seed of the beam effects: from --seed, or drawn at random
    bool random_seed_given;               /// True when the seed came from --seed

};


class ArgumentProcessor
{
public:

    static UserArguments process(int argc, char **argv);

private:

    /// Processes both program arguments and environment variables to build the right ProgramArguments

    static std::string get_description();

    static std::string get_footer();
};




#endif //G4E_ARGUMENTPROCESSOR_HH
