#include <string>
#include <cassert>

#include "Smearer.hh"

double Smearer::smear(const double position, const double width, VTXFUNC dist) const {
    assert(width >= 0);

    double res = position;

    if (width == 0)
        return res;

    if (dist == Uniform) {
        return (position - width) + 2 * gsl_rng_uniform_pos(RandomGenerator) * width;
    }

    if (dist == Gaus) {
        return position + gsl_ran_gaussian(RandomGenerator, width);
    }

    std::string err_msg = "Unknown vertex function";
    throw std::runtime_error(err_msg);
}
