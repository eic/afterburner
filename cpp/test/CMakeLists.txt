message(STATUS "Catch2 unit testing" )

find_package(Catch2 REQUIRED)

add_executable(tests test_catch.cpp test_config.cpp)
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

target_link_libraries(tests PUBLIC afterburner PRIVATE Catch2::Catch2)
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR})
add_compile_definitions(AB_TEST_DIRECTORY="${CMAKE_CURRENT_LIST_DIR}")
add_compile_definitions(HAVE_YAML=1)
