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
    /// The transform of one head-on event into the crossing frame: first `rotation`, then `boost`, applied to every
    /// momentum and vertex four-position (p_crossing = boost * (rotation * p_head_on)); then the event is moved to
    /// `vertex`.
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

        /// ion_beam_velocity and electron_beam_velocity are |p|/E of the head-on input's beams along +z and -z. The
        /// transform puts beams of these velocities exactly onto the smeared beam directions; the overloads above
        /// take 1 (massless beams).
        AfterburnerEventResult process_event(const CLHEP::HepLorentzVector &init_vtx, double ion_beam_velocity, double electron_beam_velocity);

        /// The Lorentz transform that takes a head-on event (beam of velocity ion_beam_velocity along +z, beam of
        /// velocity electron_beam_velocity along -z) to beams flying along ion_dir and electron_dir: a rotation of
        /// +z onto the head-on beam axis, then a boost perpendicular to that axis. Both beam energies grow by the
        /// boost's gamma.
        static void crossing_transform(const CLHEP::Hep3Vector &ion_dir,
                                       const CLHEP::Hep3Vector &electron_dir,
                                       double ion_beam_velocity,
                                       double electron_beam_velocity,
                                       CLHEP::HepBoost &boost,
                                       CLHEP::HepRotation &rotation);

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
        Smearer _smear;

        /** Converts from spherical theta-phi to cartesian vector */
        static CLHEP::Hep3Vector spherical_to_cartesian(double theta, double phi);

        /** Adds divergense and z kick smearing to a beam */


        CLHEP::HepLorentzVector move_vertex(const CLHEP::HepLorentzVector &init_vtx);

        double get_collision_width(double widthA, double widthB);



        CLHEP::Hep3Vector
        smear_beam_divergence(const CLHEP::Hep3Vector &beam_dir,
                              const BeamConfig &beam_cfg,
                              const double vtx_z,
                              const double crab_hor,
                              const double crab_ver);

        BunchInteractionResult generate_vertx_with_bunch_interaction();
    };
}

#endif /* AB_AFTERBURNER */
