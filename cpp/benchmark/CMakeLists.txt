cmake_minimum_required( VERSION 3.5 )
set(CMAKE_CXX_STANDARD 17)
project(Catch2Examples LANGUAGES CXX)

message(STATUS "BENCHMARKS" )
find_package(HepMC3 REQUIRED)
find_package(yaml-cpp REQUIRED)
message(STATUS "BENCHMARKS HEPMC3_LIBRARIES ${HEPMC3_LIBRARIES}")
message(STATUS "BENCHMARKS HEPMC3_INCLUDE_DIR ${HEPMC3_INCLUDE_DIR}")

find_package(CLHEP)
if(NOT CLHEP_FOUND)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Modules ${CMAKE_MODULE_PATH} )
    find_package(CLHEP REQUIRED)
endif()


add_executable(benchmark ArgumentProcessor.hh ArgumentProcessor.cc main.cc)
target_compile_features(benchmark
        PUBLIC
        cxx_alignas
        cxx_alignof
        cxx_attributes
        cxx_auto_type
        cxx_constexpr
        cxx_defaulted_functions
        cxx_deleted_functions
        cxx_final
        cxx_lambdas
        cxx_noexcept
        cxx_override
        cxx_range_for
        cxx_rvalue_references
        cxx_static_assert
        cxx_strong_enums
        cxx_trailing_return_types
        cxx_unicode_literals
        cxx_user_literals
        cxx_variable_templates
        cxx_variadic_macros
        )

target_include_directories(benchmark PRIVATE ../external/ ../ ${HEPMC3_INCLUDE_DIR} ${YAML_CPP_INCLUDE_DIRS})
target_link_libraries(benchmark afterburner ${HEPMC3_LIBRARIES} ${YAML_CPP_LIBRARIES} HepMC3)
