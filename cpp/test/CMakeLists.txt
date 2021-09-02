cmake_minimum_required( VERSION 3.5 )
set(CMAKE_CXX_STANDARD 17)
project(Catch2Examples LANGUAGES CXX)

message(STATUS "Catch2 unit testing" )

add_executable(tests test_catch.hh test_config.hh catch.cc)
target_compile_features(tests
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

target_link_libraries(tests afterburner)
target_include_directories(tests PRIVATE ../external/)
add_compile_definitions(AB_TEST_DIRECTORY="${CMAKE_CURRENT_LIST_DIR}")
add_compile_definitions(HAVE_YAML=1)

#find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main

#target_link_libraries(tests PRIVATE Catch2WithMain)
#target_include_directories(tests SYSTEM PRIVATE ../catch/src/)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)
#target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)
