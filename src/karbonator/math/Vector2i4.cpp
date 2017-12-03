#include "karbonator/math/Vector2i4.hpp"

namespace karbonator
{
namespace math
{
    Vector2i4::Vector2i4()
        : VectorN<Vector2i4::ElementType, Vector2i4::dimensionCount>()
    {}

    Vector2i4::Vector2i4(const Vector2i4& o)
        : VectorN<Vector2i4::ElementType, Vector2i4::dimensionCount>(o)
    {}

    Vector2i4::Vector2i4(const ElementType* pElements, std::size_t elementCount)
        : VectorN<Vector2i4::ElementType, Vector2i4::dimensionCount>()
    {
        if(elementCount > Vector2i4::dimensionCount) {
            throw false;
        }

        for(SizeType i = 0; i < elementCount; ++i) {
            set(i, pElements[i]);
        }
    }

    Vector2i4::Vector2i4(const ElementType& x, const ElementType& y)
        : VectorN<Vector2i4::ElementType, Vector2i4::dimensionCount>()
    {
        set(0, x);
        set(1, y);
    }

    Vector2i4& Vector2i4::operator =(const Vector2i4& rhs)
    {
        VectorN<Vector2i4::ElementType, Vector2i4::dimensionCount>::operator =(rhs);

        return *this;
    }
}
}
