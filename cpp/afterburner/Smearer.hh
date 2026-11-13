//
// Created by romanov on 8/30/21.
//

#ifndef EICAFTERBURNER_SMEARER_HH
#define EICAFTERBURNER_SMEARER_HH

#include <memory>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

namespace ab {
    //! supported function distributions
    enum class SmearFuncs
    {
        /** uniform distribution with half width set via set_vertex_distribution_width() */
        Uniform,

        /** normal distribution with sigma width set via set_vertex_distribution_width() */
        Gauss
    };

    /** Random numbers of the beam effects: every draw comes from one GSL Mersenne Twister (mt19937) sequence */
    class Smearer {

    public:

        /** Allocates the generator and seeds it */
        explicit Smearer(unsigned int seed);

        /** Restarts the random sequence from this seed */
        void set_seed(unsigned int seed);

        /** position plus a random offset: Gauss with sigma = width, or Uniform within ±width.
         *  width 0 returns position and draws nothing */
        double smear(double position, double width, SmearFuncs dist=SmearFuncs::Gauss) const;

        /** Gaussian random number with this mean and sigma = width */
        double gauss(double mean, double width) const;

        /** Gaussian random number with mean 0 and sigma = width */
        double gauss(double width) const;

    private:
        /** Generator state; each draw advances it. Freed with gsl_rng_free: gsl_rng_alloc allocates with malloc */
        std::unique_ptr<gsl_rng, decltype(&gsl_rng_free)> _generator;
    };

    /// SmearFunc-s to std::string conversion
    std::string smear_func_to_str(ab::SmearFuncs smear_func);
}


#endif //EICAFTERBURNER_SMEARER_HH
