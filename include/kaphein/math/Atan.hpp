#ifndef KAPHEIN_MATH_ATAN_HPP
#define KAPHEIN_MATH_ATAN_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Atan
    {
        E operator ()(const E& value)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Atan<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct Atan<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct Atan<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
