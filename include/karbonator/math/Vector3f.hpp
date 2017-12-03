#ifndef KARBONATOR_MATH_VECTOR3F_HPP
#define KARBONATOR_MATH_VECTOR3F_HPP

#ifndef KARBONATOR_CPPCLI
#include <initializer_list>
#endif
#include "karbonator/pp/basic.hpp"
#include "karbonator/math/Epsilon.hpp"
#include "karbonator/math/VectorN.hpp"

namespace karbonator
{
namespace math
{
    class KARBONATOR_PP_DLL_API Vector3f final
        : public VectorN<float, 3>
    {
    public:
        typedef VectorN<ElementType, dimensionCount> VectorNType;

    public:
        static const Vector3f zero;

        static const Vector3f one;

    public:
        Vector3f() = default;

        Vector3f
        (
            const Vector3f & source
        ) = default;

        Vector3f
        (
            const VectorNType & vectorN
        );

        Vector3f
        (
            const ElementType * pElements
        );

        #ifndef KARBONATOR_CPPCLI
        Vector3f
        (
            std::initializer_list<ElementType> list
        );
        #endif

        Vector3f
        (
            const ElementType & x
            , const ElementType & y
            , const ElementType & z
        );

        Vector3f & operator =
        (
            const Vector3f & rhs
        ) = default;

    public:
        Vector3f normalized
        (
            const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector3f & normalize
        (
            const ElementType & epsilon = Epsilon<ElementType>()
        );

        Vector3f & pointwiseAbsoluteAssign();
        
        Vector3f pointwiseAbsolute() const;

        friend KARBONATOR_PP_DLL_API Vector3f operator +
        (
            const Vector3f & rhs
        );
        
        friend KARBONATOR_PP_DLL_API Vector3f operator -
        (
            const Vector3f & rhs
        );

    public:
        Vector3f project
        (
            const Vector3f & axis
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector3f projectOnPlane
        (
            const Vector3f & normal
            , const ElementType & epsilon = Epsilon<ElementType>()
        ) const;

        Vector3f cross
        (
            const Vector3f & rhs
        ) const;

        Vector3f & pointwiseMultiplyAssign
        (
            const Vector3f & rhs
        );
        
        Vector3f pointwiseMultiply
        (
            const Vector3f & rhs
        ) const;
        
        Vector3f & pointwiseDivideAssign
        (
            const Vector3f & rhs
        );
        
        Vector3f pointwiseDivide
        (
            const Vector3f & rhs
        ) const;

        Vector3f & operator +=
        (
            const Vector3f & rhs
        );

        friend KARBONATOR_PP_DLL_API Vector3f operator +
        (
            const Vector3f & lhs
            , const Vector3f & rhs
        );
        
        Vector3f & operator -=
        (
            const Vector3f & rhs
        );

        friend KARBONATOR_PP_DLL_API Vector3f operator -
        (
            const Vector3f & lhs
            , const Vector3f & rhs
        );
        
        Vector3f & operator *=
        (
            const ElementType & scalar
        );

        friend KARBONATOR_PP_DLL_API Vector3f operator *
        (
            const Vector3f & vector
            , const ElementType & scalar
        );
        
        friend KARBONATOR_PP_DLL_API Vector3f operator *
        (
            const ElementType & scalar
            , const Vector3f & vector
        );
        
        Vector3f & operator /=
        (
            const ElementType & scalar
        );

        friend KARBONATOR_PP_DLL_API Vector3f operator /
        (
            const Vector3f & vector
            , const ElementType & scalar
        );
    };
}
}

#endif
