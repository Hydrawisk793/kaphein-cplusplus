#include <cmath>
#include "karbonator/math/Floor.hpp"

namespace karbonator
{
namespace math
{
    float Floor<float>::operator ()(const float& v)
    {
        return std::floor(v);
    }

    double Floor<double>::operator ()(const double& v)
    {
        return std::floor(v);
    }

    long double Floor<long double>::operator ()(const long double& v)
    {
        return std::floor(v);
    }
}
}
