#ifndef EICAFTERBURNER_EICCONFIGURATOR_HH
#define EICAFTERBURNER_EICCONFIGURATOR_HH

#include "AfterburnerConfig.hh"

namespace ab {
    enum class EicBeamConfigs {
        HiDivergence=1, // High Divergence Config - CDR Table 3.3
        HiAcceptance=2, // High Acceptance Config - CDR Table 3.4
        ElectronAurum=3 // eA Config - CDR Table 3.5
    };

    enum class EicBeamEnergies {
        E_5_GeV = 5,
        E10GeV = 10,
        E18GeV = 18,
        E41GeV = 41,
        E100GeV = 100,
        E110GeV = 110,
        E275GeV = 275
    };

    class EicConfigurator {
    public:
        static AfterburnerConfig config_ea_5x41();
        static AfterburnerConfig config_ea_5x110();
        static AfterburnerConfig config_ea_10x110();
        static AfterburnerConfig config_ea_18x110();
        static AfterburnerConfig config_hi_acc_5x41();
        static AfterburnerConfig config_hi_acc_5x100();
        static AfterburnerConfig config_hi_acc_10x100();
        static AfterburnerConfig config_hi_acc_10x275();
        static AfterburnerConfig config_hi_acc_18x275();
        static AfterburnerConfig config_hi_div_5x41();
        static AfterburnerConfig config_hi_div_5x100();
        static AfterburnerConfig config_hi_div_10x100();
        static AfterburnerConfig config_hi_div_10x275();
        static AfterburnerConfig config_hi_div_18x275();

    private:
        void validate_config(EicBeamEnergies ion_energy, EicBeamEnergies lepton_energy, EicBeamConfigs config);
        AfterburnerConfig config(EicBeamEnergies hadron_energy, EicBeamEnergies lepton_energy, EicBeamConfigs config);

        static void set_beam_direction(AfterburnerConfig &config, double crossing_angle);
    };
}


#endif //EICAFTERBURNER_EICCONFIGURATOR_HH
