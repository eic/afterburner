#ifndef EICAFTERBURNER_EICCONFIGURATOR_HH
#define EICAFTERBURNER_EICCONFIGURATOR_HH

#include "AfterburnerConfig.hh"

namespace ab {
    enum class EicBeamPresets {
        Ip6HighDivergence=1, // IP8 High Divergence Config - CDR Table 3.3
        Ip6HighAcceptance=2, // IP8 High Acceptance Config - CDR Table 3.4
        Ip6ElectronAurum=3,  // IP8 eA Config - CDR Table 3.5
        Ip8HighDivergence=4, // IP6 (temporary) High Divergence Config - CDR Table 3.3
        Ip8HighAcceptance=5, // IP6 (temporary) High Acceptance Config - CDR Table 3.4
        Ip8ElectronAurum=6   // IP6 (temporary) eA Config - CDR Table 3.5
    };

    enum class EicBeamEnergies {
        E5GeV = 5,
        E10GeV = 10,
        E18GeV = 18,
        E41GeV = 41,
        E100GeV = 100,
        E110GeV = 110,
        E275GeV = 275
    };

    class EicConfigurator {
    public:
        static AfterburnerConfig preset_ip6_eau_41x5();
        static AfterburnerConfig preset_ip6_eau_110x5();
        static AfterburnerConfig preset_ip6_eau_110x10();
        static AfterburnerConfig preset_ip6_eau_110x18();
        static AfterburnerConfig preset_ip6_hiacc_41x5();
        static AfterburnerConfig preset_ip6_hiacc_100x5();
        static AfterburnerConfig preset_ip6_hiacc_100x10();
        static AfterburnerConfig preset_ip6_hiacc_275x10();
        static AfterburnerConfig preset_ip6_hiacc_275x18();
        static AfterburnerConfig preset_ip6_hidiv_41x5();
        static AfterburnerConfig preset_ip6_hidiv_100x5();
        static AfterburnerConfig preset_ip6_hidiv_100x10();
        static AfterburnerConfig preset_ip6_hidiv_275x10();
        static AfterburnerConfig preset_ip6_hidiv_275x18();
        static AfterburnerConfig preset_ip8_eau_41x5();
        static AfterburnerConfig preset_ip8_eau_110x5();
        static AfterburnerConfig preset_ip8_eau_110x10();
        static AfterburnerConfig preset_ip8_eau_110x18();
        static AfterburnerConfig preset_ip8_hiacc_41x5();
        static AfterburnerConfig preset_ip8_hiacc_100x5();
        static AfterburnerConfig preset_ip8_hiacc_100x10();
        static AfterburnerConfig preset_ip8_hiacc_275x10();
        static AfterburnerConfig preset_ip8_hiacc_275x18();
        static AfterburnerConfig preset_ip8_hidiv_41x5();
        static AfterburnerConfig preset_ip8_hidiv_100x5();
        static AfterburnerConfig preset_ip8_hidiv_100x10();
        static AfterburnerConfig preset_ip8_hidiv_275x10();
        static AfterburnerConfig preset_ip8_hidiv_275x18();
        static AfterburnerConfig from_string(const std::string& name);

        static AfterburnerConfig config(double hadron_energy, double lepton_energy, EicBeamPresets beam_preset);
        static AfterburnerConfig config(EicBeamEnergies hadron, EicBeamEnergies lepton, EicBeamPresets beam_preset);

    private:

    };
}


#endif //EICAFTERBURNER_EICCONFIGURATOR_HH
