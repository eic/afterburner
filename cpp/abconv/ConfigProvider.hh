#ifndef EICAFTERBURNER_CONFIGPROVIDER_HH
#define EICAFTERBURNER_CONFIGPROVIDER_HH

#include <afterburner/AfterburnerConfig.hh>
#include <afterburner/EicConfigurator.hh>
#include <HepMC3/Reader.h>
#include "ArgumentProcessor.hh"

namespace ab {
    namespace convert {
        class ConfigProvider {
        public:

            /**
             * From user args object
             * @param arg user arg
             * @return afterburner convig
             */
            static ab::AfterburnerConfig from_user_args(UserArguments arg);

            /**
             * Automatically read hepmc file beam energies and creates AfterburnerConfiguration
             * @param reader Hepmc reader with the input data
             * @param beam_config ab::EicBeamConfigs
             * @return Resulting ab::AfterburnerConfi
             */
            static ab::AfterburnerConfig from_hepmc_file(const std::shared_ptr<HepMC3::Reader>& reader, ab::EicBeamPresets beam_config);

            /**
             * Returns ab::AfterburnerConfig from string config like "ip6_hidiv_275x18"
             * @param name config name
             * @return
             */
            static ab::AfterburnerConfig from_preset_name(const std::string& name);
        };
    }
}

#endif //EICAFTERBURNER_CONFIGPROVIDER_HH
