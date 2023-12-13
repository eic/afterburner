# building examples
#------------------
project(EICAfterburner)
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)
include_directories(${PROJECT_SOURCE_DIR}/include )

option(HEPMC3_ROOTIO "Enable hepmc.root input and output (treeroot & root)" ON)

#This is needed for standalone compilation
#find_package(HepMC3 REQUIRED)
#
#message(STATUS "HEPMC3_INCLUDE_DIR: ${HEPMC3_INCLUDE_DIR}")
#message(STATUS "HEPMC3_LIBRARIES: ${HEPMC3_LIBRARIES}")
#include_directories(${HEPMC3_INCLUDE_DIR})
#include(GNUInstallDirs)
#include(CheckCXXCompilerFlag)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    message(STATUS "CMAKE_CXX_STANDARD is not defined and is set BY Default)")
    set(CMAKE_CXX_STANDARD 17)   # C++17 in ATHENA by default
endif()
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD} (By Default)")

add_subdirectory(afterburner)
add_subdirectory(benchmark)
add_subdirectory(abconv)


enable_testing()

