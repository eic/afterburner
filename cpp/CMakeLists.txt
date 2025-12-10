# EIC Afterburner Project
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(EICAfterburner VERSION 1.0.0 LANGUAGES CXX)

# C++ Standard
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    message(STATUS "${PROJECT_NAME}: Setting default C++ standard to ${CMAKE_CXX_STANDARD}")
endif()
message(STATUS "${PROJECT_NAME}: C++ standard: ${CMAKE_CXX_STANDARD}")

# Build options
option(HEPMC3_ROOTIO "Enable hepmc.root input and output (treeroot & root)" ON)
message(STATUS "${PROJECT_NAME}: HEPMC3_ROOTIO: ${HEPMC3_ROOTIO}")

# Required packages
find_package(HepMC3 REQUIRED)
message(STATUS "${PROJECT_NAME}: HepMC3 found - ${HEPMC3_INCLUDE_DIR}")

find_package(yaml-cpp REQUIRED)
message(STATUS "${PROJECT_NAME}: yaml-cpp found")

find_package(CLHEP REQUIRED)
message(STATUS "${PROJECT_NAME}: CLHEP found - ${CLHEP_INCLUDE_DIRS}")

find_package(GSL REQUIRED)
message(STATUS "${PROJECT_NAME}: GSL found")

# ROOT package
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS Core RIO Tree Hist)
message(STATUS "${PROJECT_NAME}: ROOT found - ${ROOT_VERSION}")

find_package(ZLIB)
if(ZLIB_FOUND)
    message(STATUS "${PROJECT_NAME}: ZLIB found - compressed file support enabled")
else()
    message(STATUS "${PROJECT_NAME}: ZLIB not found - compressed file support disabled")
endif()

# Installation settings
include(GNUInstallDirs)

# Subdirectories
add_subdirectory(afterburner)
add_subdirectory(abconv)
add_subdirectory(benchmark)

# Testing
enable_testing()