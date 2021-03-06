#ifndef KAPHEIN_MATH_TAN_HPP
#define KAPHEIN_MATH_TAN_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Tan
    {
        E operator ()(const E& radian)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Tan<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct Tan<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct Tan<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
