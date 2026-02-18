#ifndef EICAFTERBURNER_YAMLCONFIGFILE_HH
#define EICAFTERBURNER_YAMLCONFIGFILE_HH

#include <string>
#include <afterburner/AfterburnerConfig.hh>

namespace ab {

class YamlConfigFile {
public:
    /**
     * Load beam configuration from a YAML file
     * @param config_name Name of the configuration (e.g., "ip6_hidiv_275x18")
     * @return AfterburnerConfig loaded from YAML file
     */
    static AfterburnerConfig load_config(const std::string& config_name);

    /**
     * Get the directory path where beam config YAML files are stored
     * @return Path to beam configs directory
     */
    static std::string get_config_dir();

private:
    /**
     * Parse YAML file and populate AfterburnerConfig
     * @param filepath Full path to YAML file
     * @return Populated AfterburnerConfig
     */
    static AfterburnerConfig parse_yaml_file(const std::string& filepath);
};

}

#endif //EICAFTERBURNER_YAMLCONFIGFILE_HH
