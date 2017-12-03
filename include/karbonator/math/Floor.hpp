#ifndef KARBONATOR_MATH_FLOOR_HPP
#define KARBONATOR_MATH_FLOOR_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/UnsupportedMethodException.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    struct Floor {
        E operator ()(const E& v) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Floor<float> {
        float operator ()(const float& v);
    };

    template <>
    struct Floor<double> {
        double operator ()(const double& v);
    };

    template <>
    struct Floor<long double> {
        long double operator ()(const long double& v);
    };
}
}

#endif
