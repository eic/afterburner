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

    class Smearer {

    public:

        explicit Smearer(unsigned int seed);

        double smear(double position, double width, SmearFuncs dist=SmearFuncs::Gauss) const;

        double gauss(double mean, double width) const;

        double gauss(double width) const;

    private:
        std::unique_ptr<gsl_rng> m_generator;
    };

    /// SmearFunc-s to std::string conversion
    std::string smear_func_to_str(ab::SmearFuncs smear_func);
}


#endif //EICAFTERBURNER_SMEARER_HH
