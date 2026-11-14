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
    std::string input_file_name;          ///< Input events file (the positional argument)
    std::string input_format;             ///< -i: auto, hepmc2, hepmc3, hpe, lhef, gz, treeroot, root
    std::string output_base_name;         ///< -o: output file name without extension; the files add their own
    std::string output_format;            ///< -f: hepmc3, treeroot, root, hepmc2, dot, none
    std::string output_event_file_name;   ///< Events file: output_base_name + the extension of output_format
    std::string output_hist_file_name;    ///< Validation plots file: output_base_name + .hist.root
    bool plotting_enabled;                ///< Fill the validation plots (false with --plot-off)
    bool afterburner_enabled;             ///< Apply the afterburner (false with --ab-off)
    unsigned long event_process_limit;    ///< -l: stop after this number of processed events; 0: no limit

    long start_event_index;               ///< -s: skip events with a smaller event number
    long end_event_index;                 ///< -e: stop after the event with this event number; 0: no limit
    bool exit_on_crossing_angle;          ///< --exit-ca: exit if the input already has a crossing angle > 1 mrad
    std::string preset_name;              ///< -p: 0-5 (beam energies read from the input) or a preset name
    unsigned int random_seed;             ///< Seed of the beam effects: from --seed, or drawn at random
    bool random_seed_given;               ///< True when the seed came from --seed

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
