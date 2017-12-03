#ifndef KARBONATOR_MATH_VECTOR2F_HPP
#define KARBONATOR_MATH_VECTOR2F_HPP

#ifndef KARBONATOR_CPPCLI
#include <initializer_list>
#endif
#include "karbonator/pp/basic.hpp"
#include "karbonator/math/Epsilon.hpp"
#include "karbonator/math/VectorN.hpp"

namespace karbonator {
namespace math {
    class KARBONATOR_PP_DLL_API Vector2f final
        : public VectorN<float, 2>
    {
    public:
        typedef VectorN<
            ElementType
            , dimensionCount
        > VectorNType;

    public:
        static const Vector2f zero;

        static const Vector2f one;

    public:
        Vector2f() = default;

        Vector2f(
            const Vector2f & source
        ) = default;

        Vector2f(
            const VectorNType & vectorN
        );

        Vector2f(
            const ElementType * pElements
        );

        #ifndef KARBONATOR_CPPCLI
        Vector2f(
            std::initializer_list<ElementType> list
        );
        #endif

        Vector2f(
            const ElementType & x
            , const ElementType & y
        );

        Vector2f & operator =(
            const Vector2f & rhs
        ) = default;

    public:
        Vector2f normalized(
            const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector2f & normalize(
            const ElementType & epsilon = Epsilon<ElementType>()
        );

        Vector2f & pointwiseAbsoluteAssign();
        
        Vector2f pointwiseAbsolute() const;

        friend KARBONATOR_PP_DLL_API Vector2f operator +(
            const Vector2f & rhs
        );
        
        friend KARBONATOR_PP_DLL_API Vector2f operator -(
            const Vector2f & rhs
        );

    public:
        Vector2f project(
            const Vector2f & axis
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector2f projectOnPlane(
            const Vector2f & normal
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector2f & pointwiseMultiplyAssign(
            const Vector2f & rhs
        );
        
        Vector2f pointwiseMultiply(
            const Vector2f & rhs
        ) const;
        
        Vector2f & pointwiseDivideAssign(
            const Vector2f & rhs
        );
        
        Vector2f pointwiseDivide(
            const Vector2f & rhs
        ) const;

        Vector2f & operator +=(
            const Vector2f & rhs
        );

        friend KARBONATOR_PP_DLL_API Vector2f operator +(
            const Vector2f & lhs
            , const Vector2f & rhs
        );
        
        Vector2f & operator -=(
            const Vector2f & rhs
        );

        friend KARBONATOR_PP_DLL_API Vector2f operator -(
            const Vector2f & lhs
            , const Vector2f & rhs
        );
        
        Vector2f & operator *=(
            const ElementType & scalar
        );

        friend KARBONATOR_PP_DLL_API Vector2f operator *(
            const Vector2f & vector
            , const ElementType & scalar
        );
        
        friend KARBONATOR_PP_DLL_API Vector2f operator *(
            const ElementType & scalar
            , const Vector2f & vector
        );
        
        Vector2f & operator /=(
            const ElementType & scalar
        );

        friend KARBONATOR_PP_DLL_API Vector2f operator /(
            const Vector2f & vector
            , const ElementType & scalar
        );
    };
}
}

#endif
