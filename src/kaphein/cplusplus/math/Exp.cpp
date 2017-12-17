#include <cmath>
#include "kaphein/cplusplus/math/Exp.hpp"

namespace kaphein
{
namespace math
{
    float Exp<float>::operator ()(const float& v)
    {
        return std::expf(v);
    }

    double Exp<double>::operator ()(const double& v)
    {
        return std::exp(v);
    }

    long double Exp<long double>::operator ()(const long double& v)
    {
        return std::expl(v);
    }
}
}
