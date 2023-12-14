#include <HepMC3/Reader.h>
#include "HepMC3/Print.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/Reader.h"
#include "HepMC3/ReaderAsciiHepMC2.h"
#include "HepMC3/WriterAsciiHepMC2.h"
#include "HepMC3/ReaderAscii.h"
#include "HepMC3/WriterAscii.h"
#include "HepMC3/WriterHEPEVT.h"
#include "HepMC3/WriterPlugin.h"
#include "HepMC3/ReaderHEPEVT.h"
#include "HepMC3/ReaderLHEF.h"
#include "HepMC3/ReaderPlugin.h"
#include "HepMC3/ReaderFactory.h"
#include "WriterDOT.h"
#include "FileFormats.hh"

#ifdef HEPMC3_ROOTIO
#include "HepMC3/ReaderRoot.h"
#include "HepMC3/WriterRoot.h"
#include "HepMC3/ReaderRootTree.h"
#include "HepMC3/WriterRootTree.h"
#endif

#ifdef HEPMCCONVERT_EXTENSION_GZ
#include "ReaderGZ.h"
#endif

std::shared_ptr<HepMC3::Reader> ab::convert::generate_reader(FileFormats format, const std::string &file_name) {
    using namespace HepMC3;

    if(FileFormats::autodetect == format) {
        auto reader = HepMC3::deduce_reader(file_name);
        if(!reader) {
            throw std::runtime_error("Unable to create HepMC3Reader. Probably no file exists or it is not accessible.");
        }
        return reader;
    }

    switch (format)
    {
        case FileFormats::hepmc2:
            return std::make_shared<ReaderAsciiHepMC2>(file_name);
        case FileFormats::hepmc3:
            return std::make_shared<ReaderAscii>(file_name);
        case FileFormats::hpe:
            return std::make_shared<ReaderHEPEVT>(file_name);
        case FileFormats::lhef:
            return std::make_shared<ReaderLHEF>(file_name);
        case FileFormats::gz:
            #ifdef HEPMCCONVERT_EXTENSION_GZ
                return std::make_shared<ReaderGZ>(file_name);
            #else
                throw std::runtime_error("Format gzip is not supported. You need to recompile this pacakge");
            #endif
        case FileFormats::treeroot:
            #ifdef HEPMC3_ROOTIO
                return std::make_shared<ReaderRootTree>(file_name);
            #else
                throw std::runtime_error("Format HepMC3RootTree is not supported. You need to recompile this package");
            #endif
        case FileFormats::root:
            #ifdef HEPMC3_ROOTIO
                return std::make_shared<ReaderRoot>(file_name);
            #else
                throw std::runtime_error("Format HepMC3Root is not supported. You need to recompile this package");
            #endif
        default:
            throw std::runtime_error("Unable to create HepMC3Reader for the given format");
    }
}

ab::convert::FileFormats ab::convert::parse_file_format(const std::string& format_str) {
    static std::unordered_map<std::string, FileFormats> format_map;
    if(format_map.empty()) {
        format_map["auto"] = FileFormats::autodetect;
        format_map["hepmc2"] = FileFormats::hepmc2;
        format_map["hepmc3"] = FileFormats::hepmc3;
        format_map["hpe"] = FileFormats::hpe;
        format_map["root"] = FileFormats::root;
        format_map["treeroot"] = FileFormats::treeroot;
        format_map["lhef"] = FileFormats::lhef;
        format_map["dump"] = FileFormats::dump;
        format_map["dot"] = FileFormats::dot;
        format_map["gz"] = FileFormats::gz;
        format_map["plugin"] = FileFormats::plugin;
        format_map["none"] = FileFormats::none;
    }
    return format_map[format_str];
}


std::shared_ptr<HepMC3::Writer> ab::convert::generate_writer(FileFormats format, const std::string &file_name) {
    using namespace HepMC3;

    switch (format)
    {
        case FileFormats::hepmc2:
            return std::make_shared<WriterAsciiHepMC2>(file_name);
        case FileFormats::hepmc3:
            return std::make_shared<WriterAscii>(file_name);
        case FileFormats::treeroot:
            #ifdef HEPMC3_ROOTIO
                return std::make_shared<WriterRootTree>(file_name);
            #else
                throw std::runtime_error("Format HepMC3RootTree is not supported. You need to recompile this package");
            #endif
        case FileFormats::root:
            #ifdef HEPMC3_ROOTIO
                return std::make_shared<WriterRoot>(file_name);
            #else
                throw std::runtime_error("Format HepMC3Root is not supported. You need to recompile this package");
            #endif
        case FileFormats::dot:
            return std::make_shared<WriterDOT>(file_name);
        case FileFormats::none:
            return nullptr;
        default:
            throw std::runtime_error("Unable to create HepMC3::Writer for the given format");
    }
}

std::shared_ptr<HepMC3::Reader> ab::convert::generate_reader(const string &str_format, const string &file_name) {
    auto format = parse_file_format(str_format);
    return generate_reader(format, file_name);
}

std::shared_ptr<HepMC3::Writer> ab::convert::generate_writer(const string &str_format, const string &file_name) {
    auto format = parse_file_format(str_format);
    return generate_writer(format, file_name);
}
