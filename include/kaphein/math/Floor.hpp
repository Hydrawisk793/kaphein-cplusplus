#ifndef KAPHEIN_MATH_FLOOR_HPP
#define KAPHEIN_MATH_FLOOR_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
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
