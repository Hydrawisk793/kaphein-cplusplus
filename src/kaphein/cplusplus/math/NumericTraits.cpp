#include "kaphein/cplusplus/math/NumericTraits.hpp"

namespace kaphein
{
namespace math
{
    const float NumericTraits<float>::zero = 0.0f;

    const float NumericTraits<float>::one = 1.0f;

    const float NumericTraits<float>::epsilon = 1e-6f;

    const double NumericTraits<double>::zero = 0.0;

    const double NumericTraits<double>::one = 1.0;

    const double NumericTraits<double>::epsilon = 1e-6;

    const long double NumericTraits<long double>::zero = 0.0l;

    const long double NumericTraits<long double>::one = 1.0l;

    const long double NumericTraits<long double>::epsilon = 1e-6l;
}
}
