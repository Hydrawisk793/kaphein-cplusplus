#ifndef KARBONATOR_MATH_CEIL_HPP
#define KARBONATOR_MATH_CEIL_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Ceil {
        E operator ()(const E& v) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Ceil<float> {
        float operator ()(const float& v);
    };

    template <>
    struct Ceil<double> {
        double operator ()(const double& v);
    };

    template <>
    struct Ceil<long double> {
        long double operator ()(const long double& v);
    };
}
}

#endif
