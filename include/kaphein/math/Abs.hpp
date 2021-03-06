#ifndef KAPHEIN_MATH_ABS_HPP
#define KAPHEIN_MATH_ABS_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/UnsupportedMethodException.hpp"
#include "NumericTraits.hpp"

namespace kaphein
{
namespace math
{
    template <typename E>
    struct Abs
    {
        E operator ()(const E& value)
        {
            return (value < NumericTraits<E>::zero ? -value : value);
        }
    };

    template <>
    struct Abs<float>
    {
        float operator ()(const float& value);
    };

    template <>
    struct Abs<double>
    {
        double operator ()(const double& value);
    };

    template <>
    struct Abs<long double>
    {
        long double operator ()(const long double& value);
    };
}
}

#endif
