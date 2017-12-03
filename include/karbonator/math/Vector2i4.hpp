#ifndef KARBONATOR_MATH_VECTOR2I4_HPP
#define KARBONATOR_MATH_VECTOR2I4_HPP

#include <cstdint>
#include "karbonator/pp/basic.hpp"
#include "karbonator/math/VectorN.hpp"

namespace karbonator
{
namespace math
{
    class KARBONATOR_PP_DLL_API Vector2i4
        : public VectorN<std::int32_t, 2>
    {
    public:
        Vector2i4();

        Vector2i4(const Vector2i4& o);

        Vector2i4(const ElementType* pElements, std::size_t elementCount);

        Vector2i4(const ElementType& x, const ElementType& y);

    public:
        Vector2i4& operator =(const Vector2i4& rhs);
    };
}
}

#endif
