#include <fstream>
#include <sstream>
#include <json_struct.h>

#include "AfterburnerConfig.hh"


JS_OBJ_EXT(AfterburnerConfig, beam_hor_variance, beam_ver_variance);

AfterburnerConfig AfterburnerConfig::load(const std::string &file_name) {
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

void AfterburnerConfig::save(const std::string &file_name, const AfterburnerConfig &config) {
    std::string pretty_json = JS::serializeStruct(config);
    std::ofstream out(file_name);
    out << pretty_json;
}
