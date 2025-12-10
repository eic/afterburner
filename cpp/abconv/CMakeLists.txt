# Abconv Executable
set(TARGET_NAME "abconv")
message(STATUS "=== ${TARGET_NAME} configuration ===")

# Source files
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
    YamlConfigFile.cc
    YamlConfigFile.hh
)

# Include directories
target_include_directories(${TARGET_NAME}
    PRIVATE
        ../external/
        ../benchmark
)

# Link libraries
target_link_libraries(${TARGET_NAME}
    PRIVATE
        afterburner
        benchmark
        yaml-cpp::yaml-cpp
        HepMC3::HepMC3
        ROOT::Core
        ROOT::RIO
        ROOT::Tree
        ROOT::Hist
)

# ZLIB support (optional)
if(ZLIB_FOUND)
    message(STATUS "${TARGET_NAME}: Compressed file support enabled")
    target_sources(${TARGET_NAME} PRIVATE gzstream.C gzstream.h)
    target_link_libraries(${TARGET_NAME} PRIVATE ZLIB::ZLIB)
    target_compile_definitions(${TARGET_NAME} PRIVATE ABCONV_EXTENSION_GZ=1)
endif()

# HepMC3 ROOT I/O support
if(HEPMC3_ROOTIO)
    target_compile_definitions(${TARGET_NAME} PRIVATE HEPMC3_ROOTIO)
endif()

# Installation
install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})