//
// Created by romanov on 8/30/21.
//

#ifndef EICAFTERBURNER_SMEARER_HH
#define EICAFTERBURNER_SMEARER_HH

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

//! supported function distributions
enum VTXFUNC
        {
    //! uniform distribution with half width set via set_vertex_distribution_width()
    Uniform,
    //! normal distribution with sigma width set via set_vertex_distribution_width()
    Gaus
        };

class Smearer {

public:

    [[nodiscard]] gsl_rng *get_random_generator() const
    {
        return RandomGenerator;
    }

    ~Smearer() {
        gsl_rng_free(RandomGenerator);
    }

    Smearer(unsigned int seed) {
        RandomGenerator = gsl_rng_alloc(gsl_rng_mt19937);
        gsl_rng_set(RandomGenerator, seed);
    }


    double smear(const double position, const double width, VTXFUNC dist) const;

    gsl_rng *RandomGenerator;
};


#endif //EICAFTERBURNER_SMEARER_HH
