#ifndef KAPHEIN_MATH_VECTOR2I4_HPP
#define KAPHEIN_MATH_VECTOR2I4_HPP

#include <cstdint>
#include "kaphein/pp/basic.hpp"
#include "kaphein/math/VectorN.hpp"

namespace kaphein
{
namespace math
{
    class Vector2i4
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
