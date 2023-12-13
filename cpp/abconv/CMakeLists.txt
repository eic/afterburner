# Project introduction and basic defines
cmake_minimum_required( VERSION 3.5 )
project(AbConv LANGUAGES CXX)

# Target name to be used everywhere below. Correspond to executable name
set(TARGET_NAME "abconv")
message(STATUS "=== ${TARGET_NAME} configuration ==")

# C++ standard to use (controlled with -DCPP_STANDARD flag)
if(NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 11)
	message(STATUS "${TARGET_NAME}: Setting default to ${CMAKE_CXX_STANDARD}")
endif()
message(STATUS "${TARGET_NAME}: CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

# abconv executable
add_executable(${TARGET_NAME}
		main.cc

		ArgumentProcessor.cc
		ArgumentProcessor.hh

		Converter.cc
		Converter.hh

		FileFormats.cc
		FileFormats.hh

		WriterDOT.cc
		WriterDOT.h

		ConfigProvider.cc
		ConfigProvider.hh
		)

# == REQUIRED LIBRARIES ==

# HepMC3 library (required!)
find_package(HepMC3 REQUIRED)
message(STATUS "${TARGET_NAME}: HEPMC3_LIBRARIES ${HEPMC3_LIBRARIES}")
message(STATUS "${TARGET_NAME}: HEPMC3_INCLUDE_DIR ${HEPMC3_INCLUDE_DIR}")

# Yaml-cpp for configs!
find_package(yaml-cpp REQUIRED)

# CLHEP package
find_package(CLHEP)
if(NOT CLHEP_FOUND)
	set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Modules ${CMAKE_MODULE_PATH} )
	find_package(CLHEP REQUIRED)
endif()

target_include_directories(${TARGET_NAME} PRIVATE ../external/ ../ ../benchmark ${HEPMC3_INCLUDE_DIR} ${YAML_CPP_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} afterburner ${HEPMC3_LIBRARIES} ${YAML_CPP_LIBRARIES} benchmark)
target_compile_definitions(${TARGET_NAME} PRIVATE ${basic_defines} )


# === OPTIONAL LIBS ===

# CERN Rooooooot
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS Core RIO Tree Hist)

if(ROOT_FOUND)
        target_include_directories(${TARGET_NAME} PRIVATE SYSTEM ${ROOT_INCLUDE_DIRS})
	target_link_libraries(${TARGET_NAME} ROOT::Core ROOT::RIO ROOT::Tree ROOT::Hist)
endif()

# ZLib
find_package(ZLIB)
if(ZLIB_FOUND)
	message(STATUS "${TARGET_NAME}: zlib found. Compressed files support enabled. ${ZLIB_INCLUDE_DIR} ${ZLIB_LIBRARIES} ")
	target_include_directories(${TARGET_NAME} PRIVATE SYSTEM ${ZLIB_INCLUDE_DIR})
	target_sources(${TARGET_NAME} PRIVATE gzstream.C)
	target_link_libraries(${TARGET_NAME} ${ZLIB_LIBRARIES})
	target_compile_definitions(${TARGET_NAME} PRIVATE ABCONV_EXTENSION_GZ=1)
elseif()
	message(STATUS "EIC Afterburner: zlib not found. Compressed files support disabled.")
endif()

if(HEPMC3_ROOTIO)
  	target_compile_definitions(${TARGET_NAME} PRIVATE HEPMC3_ROOTIO)
else()
	message(STATUS "EIC Afterburner: HEPMC3_ROOTIO=OFF. hepmc.root files support disabled.")
endif()


# installs
install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})


