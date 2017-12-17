#include <cmath>
#include "kaphein/cplusplus/math/Atan2.hpp"

namespace kaphein
{
namespace math
{
    float Atan2<float>::operator ()(const float& y, const float& x)
    {
        return std::atan2f(y, x);
    }

    double Atan2<double>::operator ()(const double& y, const double& x)
    {
        return std::atan2(y, x);
    }

    long double Atan2<long double>::operator ()(const long double& y, const long double& x)
    {
        return std::atan2(y, x);
    }
}
}
