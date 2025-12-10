# Benchmark Library
set(TARGET_NAME "benchmark")
message(STATUS "=== ${TARGET_NAME} configuration ===")

# Source files
add_library(${TARGET_NAME} STATIC
    Histogrammer.hh
    Histogrammer.cc
)

# Include directories
target_include_directories(${TARGET_NAME}
    PRIVATE
        ../external/
)

# Link libraries
target_link_libraries(${TARGET_NAME}
    PRIVATE
        afterburner
        yaml-cpp::yaml-cpp
        HepMC3::HepMC3
        ROOT::Core
        ROOT::RIO
        ROOT::Tree
)

