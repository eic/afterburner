#ifndef EICAFTERBURNER_FILEFORMATS_HH
#define EICAFTERBURNER_FILEFORMATS_HH

#include <unordered_map>

namespace ab{
    namespace convert{
        enum class FileFormats{
            autodetect,
            hepmc2,
            hepmc3,
            hpe ,
            root,
            treeroot ,
            lhef,
            dump,
            dot,
            gz,
            plugin,
            none
        };


        /// Parses a string to FileFormats enum
        FileFormats parse_file_format(const std::string& format_str);

        /// Creates the correct HepMC3::Reader out of FileFormats::format and file name
        std::shared_ptr<HepMC3::Reader> generate_reader(FileFormats format, const std::string &file_name);

        std::shared_ptr<HepMC3::Writer> generate_writer(FileFormats format, const std::string &file_name);


    }
}
#endif //EICAFTERBURNER_FILEFORMATS_HH
