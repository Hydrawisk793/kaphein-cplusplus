#include <cmath>
#include "karbonator/math/Ceil.hpp"

namespace karbonator
{
namespace math
{
    float Ceil<float>::operator ()(const float& v) {
        return std::ceil(v);
    }

    double Ceil<double>::operator ()(const double& v) {
        return std::ceil(v);
    }

    long double Ceil<long double>::operator ()(const long double& v) {
        return std::ceil(v);
    }
}
}
