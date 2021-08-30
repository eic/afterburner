#include <fstream>
#include <sstream>
#include <json_struct.h>

#include "AfterburnerConfig.hh"

using namespace ab;

//JS_OBJ_EXT(ab::BeamConfig, direction_theta, direction_phi, divergence_hor, divergence_ver, z_shift_hor, z_shift_ver);
JS_OBJ_EXT(ab::BeamConfig, direction_theta);
JS_OBJ_EXT(AfterburnerConfig, random_seed);
//JS_OBJ_EXT(AfterburnerConfig,
//           random_seed,
//           vertex_smear_func_x,
//           vertex_smear_func_y,
//           vertex_smear_func_z,
//           vertex_smear_func_t,
//           vertex_smear_width_x,
//           vertex_smear_width_y,
//           vertex_smear_width_z,
//           vertex_smear_width_t,
//           vertex_shift_x,
//           vertex_shift_y,
//           vertex_shift_z,
//           vertex_shift_t,
////           beam_one,
////           beam_two,
//           );

ab::AfterburnerConfig ab::AfterburnerConfig::load(const std::string &file_name) {
    std::ifstream reader(file_name);
    if(!reader.good()) {
        std::string errorStr = "Can't open file: '" + file_name + "'";
        throw std::runtime_error(errorStr);
    }

    std::stringstream buffer;
    buffer << reader.rdbuf();
    auto json = buffer.str();

    AfterburnerConfig config;
    JS::ParseContext parseContext(json);
    if (parseContext.parseTo(config) != JS::Error::NoError)
    {
        std::string errorStr = parseContext.makeErrorString();
        throw std::runtime_error(errorStr);
    }

    return config;
}

void ab::AfterburnerConfig::save(const std::string &file_name, const AfterburnerConfig &config) {
    std::string pretty_json = JS::serializeStruct(config);
    std::ofstream out(file_name);
    out << pretty_json;
}
