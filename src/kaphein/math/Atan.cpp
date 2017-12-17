#include <cmath>
#include "kaphein/math/Atan.hpp"

namespace kaphein
{
namespace math
{
    float Atan<float>::operator ()(const float& value)
    {
        return std::atan(value);
    }

    double Atan<double>::operator ()(const double& value)
    {
        return std::atan(value);
    }

    long double Atan<long double>::operator ()(const long double& value)
    {
        return std::atan(value);
    }
}
}
