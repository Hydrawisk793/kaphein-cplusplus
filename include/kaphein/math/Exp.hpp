#ifndef KAPHEIN_MATH_EXP_HPP
#define KAPHEIN_MATH_EXP_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Exp
    {
        E operator ()(const E& value) {
            throw UnsupportedMethodException();
        }
    };

    template <>
    struct Exp<float>
    {
        float operator ()(const float& v);
    };

    template <>
    struct Exp<double>
    {
        double operator ()(const double& v);
    };

    template <>
    struct Exp<long double>
    {
        long double operator ()(const long double& v);
    };
}
}

#endif
