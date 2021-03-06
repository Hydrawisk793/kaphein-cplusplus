#ifndef KAPHEIN_MATH_ASIN_HPP
#define KAPHEIN_MATH_ASIN_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Asin
    {
        E operator ()(const E& value) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Asin<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct Asin<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct Asin<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
