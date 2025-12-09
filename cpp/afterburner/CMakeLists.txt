# Afterburner Library
set(TARGET_NAME "afterburner")
message(STATUS "=== ${TARGET_NAME} configuration ===")

# Source files
add_library(${TARGET_NAME} STATIC
    Afterburner.cc
    Afterburner.hh
    AfterburnerConfig.hh
    EicConfigurator.cc
    EicConfigurator.hh
    Smearer.cc
    Smearer.hh
)

# Include directories
target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
    PRIVATE
        ../external/json_struct/
)

# Link libraries
target_link_libraries(${TARGET_NAME}
    PRIVATE
        ${CLHEP_LIBRARIES}
        ${HEPMC3_LIBRARIES}
        GSL::gsl
)
