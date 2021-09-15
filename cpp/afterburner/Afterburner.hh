#ifndef AB_AFTERBURNER
#define AB_AFTERBURNER

#include <cmath>
#include <string>
#include <utility>

#include <CLHEP/Vector/ThreeVector.h>
#include <CLHEP/Vector/LorentzVector.h>
#include <CLHEP/Vector/Boost.h>
#include <CLHEP/Vector/Rotation.h>

#include <gsl/gsl_rng.h>

#include "AfterburnerConfig.hh"
#include "Smearer.hh"

namespace ab{
    struct AfterburnerEventResult {
        CLHEP::HepBoost boost;
        CLHEP::HepRotation rotation;
        CLHEP::HepLorentzVector vertex;
    };

    /// This class sole function is to be returned from generate_vertx_with_bunch_interaction
    struct BunchInteractionResult {
        CLHEP::HepLorentzVector vertex;
        double bunch_one_z;
        double bunch_two_z;
    };

    /*!
     * \brief Afterburner provides service of DST upload of HepMC subevent, vertex assignment and random generator
     */
    class Afterburner
    {
    public:
        Afterburner();

        AfterburnerEventResult process_event();

        AfterburnerEventResult process_event(const CLHEP::HepLorentzVector &init_vtx);

        void print() const;

        void set_verbose(int v) { m_verbosity = v; }

        int verbose() const { return m_verbosity; }

        void set_config(ab::AfterburnerConfig config) {
            _cfg = config;
        }

        ab::AfterburnerConfig config() const {
            return _cfg;
        }

    private:
        /** verbosity */
        int m_verbosity = 0;

        AfterburnerConfig _cfg;
        Smearer _smearer;

        /** Converts from spherical theta-phi to cartesian vector */
        static CLHEP::Hep3Vector spherical_to_cartesian(double theta, double phi);

        /** Adds divergense and z kick smearing to a beam */
        CLHEP::Hep3Vector smear_beam_divergence(const CLHEP::Hep3Vector &beam_dir, const BeamConfig &beam_cfg, double vtx_z);

        CLHEP::HepLorentzVector move_vertex(const CLHEP::HepLorentzVector &init_vtx);

        double get_collision_width(const double widthA, const double widthB);

        ab::BunchInteractionResult generate_vertx_with_bunch_interaction(BeamConfig beam_one, BeamConfig beam_two);
    };
}

#endif /* AB_AFTERBURNER */
