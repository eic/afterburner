#ifndef EICAFTERBURNER_EICCONFIGURATOR_HH
#define EICAFTERBURNER_EICCONFIGURATOR_HH

#include "AfterburnerConfig.hh"

namespace ab {
    enum class EicBeamPresets {
        HighDivergence=1, // High Divergence Config - CDR Table 3.3
        HighAcceptance=2, // High Acceptance Config - CDR Table 3.4
        ElectronAurum=3   // eA Config - CDR Table 3.5
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
        static AfterburnerConfig config_eau_41x5();
        static AfterburnerConfig config_eau_110x5();
        static AfterburnerConfig config_eau_110x10();
        static AfterburnerConfig config_eau_110x18();
        static AfterburnerConfig config_hiacc_41x5();
        static AfterburnerConfig config_hiacc_100x5();
        static AfterburnerConfig config_hiacc_100x10();
        static AfterburnerConfig config_hiacc_275x10();
        static AfterburnerConfig config_hiacc_275x18();
        static AfterburnerConfig config_hidiv_41x5();
        static AfterburnerConfig config_hidiv_100x5();
        static AfterburnerConfig config_hidiv_100x10();
        static AfterburnerConfig config_hidiv_275x10();
        static AfterburnerConfig config_hidiv_275x18();
        static AfterburnerConfig from_string(const std::string& name);

        static AfterburnerConfig config(double hadron_energy, double lepton_energy, EicBeamPresets beam_preset);
        static AfterburnerConfig config(EicBeamEnergies hadron, EicBeamEnergies lepton, EicBeamPresets beam_preset);

    private:

    };
}


#endif //EICAFTERBURNER_EICCONFIGURATOR_HH
