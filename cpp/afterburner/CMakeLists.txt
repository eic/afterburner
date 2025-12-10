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
        ${CLHEP_INCLUDE_DIRS}
        ${HEPMC3_INCLUDE_DIR}
    PRIVATE
        ../external/json_struct/
)

# Link libraries
target_link_libraries(${TARGET_NAME}
    PUBLIC
        ${CLHEP_LIBRARIES}
        ${HEPMC3_LIBRARIES}
    PRIVATE
        GSL::gsl
)
