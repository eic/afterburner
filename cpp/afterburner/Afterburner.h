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


struct AfterburnerEventResult {
    CLHEP::HepBoost boost;
    CLHEP::HepRotation rotation;
    CLHEP::HepLorentzVector vertex;
};

/*!
 * \brief Afterburner provides service of DST upload of HepMC subevent, vertex assignment and random generator
 */
class Afterburner
{
 public:
  Afterburner();

  AfterburnerEventResult process_event(const CLHEP::HepLorentzVector &init_vtx);

  void print() const;

  void set_verbose(int v) { m_verbosity = v; }

  int verbose() const { return m_verbosity; }

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


};

#endif /* AB_AFTERBURNER */
