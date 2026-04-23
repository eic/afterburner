#include "YamlConfigFile.hh"
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

namespace fs = std::filesystem;

std::string ab::YamlConfigFile::get_config_dir() {
    // Check for environment variable first
    const char* env_dir = std::getenv("AFTERBURNER_BEAM_CONFIGS_DIR");
    if (env_dir != nullptr) {
        return std::string(env_dir);
    }
    
    // Try multiple possible locations relative to current working directory
    // Note: These are relative paths, so behavior depends on where the executable is run from.
    // For production use, it's recommended to set AFTERBURNER_BEAM_CONFIGS_DIR environment variable
    // to an absolute path to the beam_configs directory.
    std::vector<std::string> possible_paths = {
        "beam_configs",
        "../beam_configs",
        "../../beam_configs",
        "../share/afterburner/beam_configs",
        "share/afterburner/beam_configs"
    };
    
    for (const auto& path : possible_paths) {
        if (fs::exists(path) && fs::is_directory(path)) {
            return path;
        }
    }
    
    // If none found, return the default
    return "beam_configs";
}

ab::AfterburnerConfig ab::YamlConfigFile::parse_yaml_file(const std::string& filepath) {
    ab::AfterburnerConfig cfg;
    
    try {
        YAML::Node config = YAML::LoadFile(filepath);
        
        // Parse crossing angles
        if (config["crossing_angle"]) {
            if (config["crossing_angle"]["horizontal"]) {
                cfg.crossing_angle_hor = config["crossing_angle"]["horizontal"].as<double>();
            }
            if (config["crossing_angle"]["vertical"]) {
                cfg.crossing_angle_ver = config["crossing_angle"]["vertical"].as<double>();
            }
        }
        
        // Parse ion beam configuration
        if (config["ion_beam"]) {
            auto ion = config["ion_beam"];
            if (ion["beta_crab_horizontal"]) {
                cfg.ion_beam.beta_crab_hor = ion["beta_crab_horizontal"].as<double>();
            }
            if (ion["divergence_horizontal"]) {
                cfg.ion_beam.divergence_hor = ion["divergence_horizontal"].as<double>();
            }
            if (ion["divergence_vertical"]) {
                cfg.ion_beam.divergence_ver = ion["divergence_vertical"].as<double>();
            }
            if (ion["beta_star_horizontal"]) {
                cfg.ion_beam.beta_star_hor = ion["beta_star_horizontal"].as<double>();
            }
            if (ion["beta_star_vertical"]) {
                cfg.ion_beam.beta_star_ver = ion["beta_star_vertical"].as<double>();
            }
            if (ion["rms_emittance_horizontal"]) {
                cfg.ion_beam.rms_emittance_hor = ion["rms_emittance_horizontal"].as<double>();
            }
            if (ion["rms_emittance_vertical"]) {
                cfg.ion_beam.rms_emittance_ver = ion["rms_emittance_vertical"].as<double>();
            }
            if (ion["rms_bunch_length"]) {
                cfg.ion_beam.rms_bunch_length = ion["rms_bunch_length"].as<double>();
            }
        }
        
        // Parse electron beam configuration
        if (config["electron_beam"]) {
            auto electron = config["electron_beam"];
            if (electron["beta_crab_horizontal"]) {
                cfg.electron_beam.beta_crab_hor = electron["beta_crab_horizontal"].as<double>();
            }
            if (electron["divergence_horizontal"]) {
                cfg.electron_beam.divergence_hor = electron["divergence_horizontal"].as<double>();
            }
            if (electron["divergence_vertical"]) {
                cfg.electron_beam.divergence_ver = electron["divergence_vertical"].as<double>();
            }
            if (electron["beta_star_horizontal"]) {
                cfg.electron_beam.beta_star_hor = electron["beta_star_horizontal"].as<double>();
            }
            if (electron["beta_star_vertical"]) {
                cfg.electron_beam.beta_star_ver = electron["beta_star_vertical"].as<double>();
            }
            if (electron["rms_emittance_horizontal"]) {
                cfg.electron_beam.rms_emittance_hor = electron["rms_emittance_horizontal"].as<double>();
            }
            if (electron["rms_emittance_vertical"]) {
                cfg.electron_beam.rms_emittance_ver = electron["rms_emittance_vertical"].as<double>();
            }
            if (electron["rms_bunch_length"]) {
                cfg.electron_beam.rms_bunch_length = electron["rms_bunch_length"].as<double>();
            }
        }
        
    } catch (const YAML::Exception& e) {
        std::string error_msg = "Error parsing YAML file '" + filepath + "': " + e.what();
        throw std::runtime_error(error_msg);
    }
    
    return cfg;
}

ab::AfterburnerConfig ab::YamlConfigFile::load_config(const std::string& config_name) {
    std::string config_dir = get_config_dir();
    std::string filepath = config_dir + "/" + config_name + ".yaml";
    
    if (!fs::exists(filepath)) {
        std::string error_msg = "Configuration file not found: " + filepath;
        throw std::runtime_error(error_msg);
    }
    
    auto cfg = parse_yaml_file(filepath);
    cfg.name = config_name;
    
    return cfg;
}
