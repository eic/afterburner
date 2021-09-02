cmake_minimum_required( VERSION 3.5 )
set(CMAKE_CXX_STANDARD 17)
project(EICAfterburnerLibrary LANGUAGES CXX)

message(STATUS "EIC Afterburner library" )

# find_package(CLHEP)

add_library(afterburner
        Afterburner.cc
        AfterburnerConfig.cc
        Smearer.cc)

target_include_directories(afterburner SYSTEM PRIVATE ${CLHEP_INCLUDE_DIRS} ${HEPMC3_INCLUDE_DIR} ../external/json_struct/)
target_link_libraries(afterburner ${CLHEP_LIBRARIES} ${HEPMC3_LIBRARIES} CLHEP)
target_compile_features(afterburner
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

#find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main

#target_link_libraries(tests PRIVATE Catch2WithMain)
#target_include_directories(tests SYSTEM PRIVATE ../catch/src/)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)
#target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)
