#include <string>
#include <cassert>
#include <stdexcept>
#include <map>

#include "Smearer.hh"

ab::Smearer::Smearer(unsigned int seed) :
    m_generator(gsl_rng_alloc(gsl_rng_mt19937))
{
    gsl_rng_set(m_generator.get(), seed);
}

double ab::Smearer::smear(const double position, const double width, SmearFuncs dist) const {
    assert(width >= 0);

    double res = position;

    if (width == 0)
        return res;

    if (dist == SmearFuncs::Uniform) {
        return (position - width) + 2 * gsl_rng_uniform_pos(m_generator.get()) * width;
    }

    if (dist == SmearFuncs::Gauss) {
        return position + gsl_ran_gaussian(m_generator.get(), width);
    }

    std::string err_msg = "Unknown vertex function";
    throw std::runtime_error(err_msg);
}

double ab::Smearer::gauss(double mean, double width) const {
    return mean + gsl_ran_gaussian(m_generator.get(), width);
}

double ab::Smearer::gauss(double width) const {
    return gsl_ran_gaussian(m_generator.get(), width);
}


std::string ab::smear_func_to_str(ab::SmearFuncs smear_func) {
    static std::map <SmearFuncs, std::string> funcs_str_map = {{ab::SmearFuncs::Uniform, "Uniform"}, {ab::SmearFuncs::Gauss, "Gauss"}};
    return funcs_str_map[smear_func];
}
