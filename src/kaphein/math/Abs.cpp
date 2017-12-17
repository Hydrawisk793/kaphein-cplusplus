#include <cmath>
#include "kaphein/math/Abs.hpp"

namespace kaphein
{
namespace math
{
    float Abs<float>::operator ()(const float& value)
    {
        return std::abs(value);
    }

    double Abs<double>::operator ()(const double& value)
    {
        return std::abs(value);
    }

    long double Abs<long double>::operator ()(const long double& value)
    {
        return std::abs(value);
    }
}
}
