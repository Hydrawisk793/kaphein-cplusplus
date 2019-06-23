#ifndef KAPHEIN_MATH_COS_HPP
#define KAPHEIN_MATH_COS_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Cos
    {
        E operator ()(const E& radian)
        {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Cos<float>
    {
        float operator ()(const float& radian);
    };

    template <>
    struct Cos<double>
    {
        double operator ()(const double& radian);
    };

    template <>
    struct Cos<long double>
    {
        long double operator ()(const long double& radian);
    };
}
}

#endif
