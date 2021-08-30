// 010-TestCase.cpp
// And write tests in the same file:
#include "catch.hpp"
#include <afterburner/AfterburnerConfig.hh>
#include <fstream>
#include <iostream>

using namespace Catch;

TEST_CASE( "Save and load the afterburner config", "[ab-config]" ) {
    AfterburnerConfig config = {5, 6};
    AfterburnerConfig::save("test_ab_save.json", config);
    auto config2 = AfterburnerConfig::load("test_ab_save.json");
    REQUIRE(config.beam_hor_variance == Catch::Approx(config2.beam_hor_variance));
    REQUIRE(config.beam_ver_variance == Catch::Approx(config2.beam_ver_variance));
}

TEST_CASE( "Load incomplete config", "[ab-config]" ) {
    auto file_name = std::string(AB_TEST_DIRECTORY) + "/partial_config.json";
    auto config = AfterburnerConfig::load(file_name);
    REQUIRE(config.beam_hor_variance == Catch::Approx( 6 ));


//
//
//    // Read
//    {
//        std::ifstream reader(file_name);
//        std::stringstream buffer;
//        buffer << reader.rdbuf();
//        auto json = buffer.str();
//
//        AfterburnerConfig config2;
//        JS::ParseContext parseContext(json);
//        if (parseContext.parseTo(config2) != JS::Error::NoError)
//        {
//            std::string errorStr = parseContext.makeErrorString();
//            throw std::runtime_error(errorStr);
//        }
//        REQUIRE(config2.beam_hor_variance == Catch::Approx( 6 ));
//    }

}



