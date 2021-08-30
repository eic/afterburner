/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "convert_example"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "convert_example"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION "3.1"
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief print help and exit help description.  */
  char * input_format_arg;	/**< @brief Input format.  */
  char * input_format_orig;	/**< @brief Input format original value given at command line.  */
  const char *input_format_help; /**< @brief Input format help description.  */
  char * output_format_arg;	/**< @brief Output format.  */
  char * output_format_orig;	/**< @brief Output format original value given at command line.  */
  const char *output_format_help; /**< @brief Output format help description.  */
  char ** extensions_arg;	/**< @brief Extensions, in a form extension=value, could be passed to readers/writers.  */
  char ** extensions_orig;	/**< @brief Extensions, in a form extension=value, could be passed to readers/writers original value given at command line.  */
  unsigned int extensions_min; /**< @brief Extensions, in a form extension=value, could be passed to readers/writers's minimum occurreces */
  unsigned int extensions_max; /**< @brief Extensions, in a form extension=value, could be passed to readers/writers's maximum occurreces */
  const char *extensions_help; /**< @brief Extensions, in a form extension=value, could be passed to readers/writers help description.  */
  long events_limit_arg;	/**< @brief Limit of events to read from input (default='100000000').  */
  char * events_limit_orig;	/**< @brief Limit of events to read from input original value given at command line.  */
  const char *events_limit_help; /**< @brief Limit of events to read from input help description.  */
  long first_event_number_arg;	/**< @brief Lowest allowed event number (default='-100000000').  */
  char * first_event_number_orig;	/**< @brief Lowest allowed event number original value given at command line.  */
  const char *first_event_number_help; /**< @brief Lowest allowed event number help description.  */
  long last_event_number_arg;	/**< @brief Highest allowed event number (default='100000000').  */
  char * last_event_number_orig;	/**< @brief Highest allowed event number original value given at command line.  */
  const char *last_event_number_help; /**< @brief Highest allowed event number help description.  */
  long print_every_events_parsed_arg;	/**< @brief Frequency of parsing information printouts (default='100').  */
  char * print_every_events_parsed_orig;	/**< @brief Frequency of parsing information printouts original value given at command line.  */
  const char *print_every_events_parsed_help; /**< @brief Frequency of parsing information printouts help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int input_format_given ;	/**< @brief Whether input-format was given.  */
  unsigned int output_format_given ;	/**< @brief Whether output-format was given.  */
  unsigned int extensions_given ;	/**< @brief Whether extensions was given.  */
  unsigned int events_limit_given ;	/**< @brief Whether events-limit was given.  */
  unsigned int first_event_number_given ;	/**< @brief Whether first-event-number was given.  */
  unsigned int last_event_number_given ;	/**< @brief Whether last-event-number was given.  */
  unsigned int print_every_events_parsed_given ;	/**< @brief Whether print-every-events-parsed was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief the description string of the program */
extern const char *gengetopt_args_info_description;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * print the help
 */
void cmdline_parser_print_help(void);
/**
 * print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);

extern const char *cmdline_parser_input_format_values[];  /**< @brief Possible values for input-format. */
extern const char *cmdline_parser_output_format_values[];  /**< @brief Possible values for output-format. */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
