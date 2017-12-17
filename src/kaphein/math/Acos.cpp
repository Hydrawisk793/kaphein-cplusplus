#include <cmath>
#include "kaphein/math/Acos.hpp"

namespace kaphein
{
namespace math
{
    float Acos<float>::operator ()(const float& value)
    {
        return std::acos(value);
    }

    double Acos<double>::operator ()(const double& value)
    {
        return std::acos(value);
    }

    long double Acos<long double>::operator ()(const long double& value)
    {
        return std::acos(value);
    }
}
}
