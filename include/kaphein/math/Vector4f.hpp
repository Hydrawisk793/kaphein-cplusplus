#ifndef KAPHEIN_MATH_VECTOR4F_HPP
#define KAPHEIN_MATH_VECTOR4F_HPP

#ifndef KAPHEIN_CPPCLI
#include <initializer_list>
#endif
#include "kaphein/pp/basic.hpp"
#include "kaphein/math/Epsilon.hpp"
#include "kaphein/math/VectorN.hpp"

namespace kaphein {
namespace math {
    class Vector4f final
        : public VectorN<float, 4>
    {
    public:
        typedef VectorN<
            ElementType
            , dimensionCount
        > VectorNType;

    public:
        static const Vector4f zero;

        static const Vector4f one;

    public:
        Vector4f() = default;

        Vector4f(
            const Vector4f & source
        ) = default;

        Vector4f(
            const VectorNType & vectorN
        );

        Vector4f(
            const ElementType * pElements
        );

        #ifndef KAPHEIN_CPPCLI
        Vector4f(
            std::initializer_list<ElementType> list
        );
        #endif

        Vector4f(
            const ElementType & x
            , const ElementType & y
            , const ElementType & z
            , const ElementType & w
        );

        Vector4f & operator =(
            const Vector4f & rhs
        ) = default;

    public:
        Vector4f normalized(
            const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector4f & normalize(
            const ElementType & epsilon = Epsilon<ElementType>()
        );

        Vector4f & pointwiseAbsoluteAssign();
        
        Vector4f pointwiseAbsolute() const;

        friend Vector4f operator +(
            const Vector4f & rhs
        );
        
        friend Vector4f operator -(
            const Vector4f & rhs
        );

    public:
        Vector4f project(
            const Vector4f & axis
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector4f projectOnPlane(
            const Vector4f & normal
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector4f & pointwiseMultiplyAssign(
            const Vector4f & rhs
        );
        
        Vector4f pointwiseMultiply(
            const Vector4f & rhs
        ) const;
        
        Vector4f & pointwiseDivideAssign(
            const Vector4f & rhs
        );
        
        Vector4f pointwiseDivide(
            const Vector4f & rhs
        ) const;

        Vector4f & operator +=(
            const Vector4f & rhs
        );

        friend Vector4f operator +(
            const Vector4f & lhs
            , const Vector4f & rhs
        );
        
        Vector4f & operator -=(
            const Vector4f & rhs
        );

        friend Vector4f operator -(
            const Vector4f & lhs
            , const Vector4f & rhs
        );
        
        Vector4f & operator *=(
            const ElementType & scalar
        );

        friend Vector4f operator *(
            const Vector4f & vector
            , const ElementType & scalar
        );
        
        friend Vector4f operator *(
            const ElementType & scalar
            , const Vector4f & vector
        );
        
        Vector4f & operator /=(
            const ElementType & scalar
        );

        friend Vector4f operator /(
            const Vector4f & vector
            , const ElementType & scalar
        );
    };
}
}

#endif
