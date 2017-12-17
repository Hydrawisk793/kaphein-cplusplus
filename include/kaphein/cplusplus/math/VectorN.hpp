#ifndef KAPHEIN_MATH_VECTORN_HPP
#define KAPHEIN_MATH_VECTORN_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#if KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
    #include <initializer_list>
#endif
#include "kaphein/cplusplus/math/NumericTraits.hpp"

namespace kaphein
{
namespace math
{
    template <typename E, SizeType N>
    class VectorN
    {
    public:
        typedef E ElementType;
        
    #if KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED > 0
        static constexpr SizeType dimensionCount = N;
    #else
        enum
        {
            dimensionCount = N
        };
    #endif

    public:
        static const VectorN<E, N> zero;

        static const VectorN<E, N> one;

        //typedef VectorN<VectorN<E, N>, N> BaseVectorArrayType;

        //static const BaseVectorArrayType bases;

    private:
        //static BaseVectorArrayType createBases();
        static VectorN<E, N> fromValues(const E* pValues, SizeType valueCount);

        static VectorN<E, N> fromAxis(SizeType axis);

        static VectorN<E, N> fill(const E& scalar);

    public:
    #if KAPHEIN_PP_DEFAULTED_AND_DELETED_FUNCTIONS_SUPPORTED > 0
        VectorN() = default;

        VectorN(const VectorN<E, N>& source) = default;
    #endif

    #if KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
        VectorN(std::initializer_list<E> list);
    #endif

    public:
        const E& operator [](SizeType index) const;

        E& operator [](SizeType index);

        const E& get(SizeType index) const;

        E& get(SizeType index);

        void set(SizeType index, const E& e);

        void swapElements(SizeType lhsIndex, SizeType rhsIndex);

    public:
        bool isZero(const E & epsilon = NumericTraits<E>::epsilon) const;

        bool isNormalized(const E & epsilon = NumericTraits<E>::epsilon) const;

        bool equals(const VectorN<E, N>& rhs, const E & epsilon = NumericTraits<E>::epsilon) const;

        template <typename E, SizeType N>
        friend bool operator ==(const VectorN<E, N>& lhs, const VectorN<E, N>& rhs);

        template <typename E, SizeType N>
        friend bool operator !=(const VectorN<E, N>& lhs, const VectorN<E, N>& rhs);

    public:
        E squaredMagnitude() const;

        E magnitude() const;

        bool tryNormalize(const E& epsilon = NumericTraits<E>::epsilon);

        VectorN<E, N>& normalize(const E& epsilon = NumericTraits<E>::epsilon);

        VectorN<E, N> normalized(const E& epsilon = NumericTraits<E>::epsilon) const;

        VectorN<E, N>& pointwiseAbsoluteAssign();

        VectorN<E, N> pointwiseAbsolute() const;

        template <typename E, SizeType N>
        friend VectorN<E, N> operator +(const VectorN<E, N>& rhs);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator -(const VectorN<E, N>& rhs);

    public:
        E dot(const VectorN<E, N>& rhs) const;

        VectorN<E, N> project(const VectorN<E, N>& axis, const E& epsilon = NumericTraits<E>::epsilon) const;

        VectorN<E, N> projectOnPlane(const VectorN<E, N>& normal, const E& epsilon = NumericTraits<E>::epsilon) const;

        //VectorN<E, N> cross(const VectorN<E, N>& rhs) const;

        VectorN<E, N>& pointwiseMultiplyAssign(const VectorN<E, N>& rhs);

        VectorN<E, N> pointwiseMultiply(const VectorN<E, N>& rhs) const;

        VectorN<E, N>& pointwiseDivideAssign(const VectorN<E, N>& rhs, const E& epsilon = NumericTraits<E>::epsilon);

        VectorN<E, N> pointwiseDivide(const VectorN<E, N>& rhs, const E& epsilon = NumericTraits<E>::epsilon) const;

        VectorN<E, N>& operator +=(const VectorN<E, N>& rhs);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator +(const VectorN<E, N>& lhs, const VectorN<E, N>& rhs);

        VectorN<E, N>& operator -=(const VectorN<E, N>& rhs);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator -(const VectorN<E, N>& lhs, const VectorN<E, N>& rhs);

        VectorN<E, N>& operator *=(const E& scalar);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator *(const VectorN<E, N>& vector, const E& scalar);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator *(const E& scalar, const VectorN<E, N>& vector);

        VectorN<E, N>& divideAssign(const E& scalar, const E& epsilon = NumericTraits<E>::epsilon);

        VectorN<E, N> divide(const E& scalar, const E& epsilon = NumericTraits<E>::epsilon) const;

        VectorN<E, N>& operator /=(const E& scalar);

        template <typename E, SizeType N>
        friend VectorN<E, N> operator /(const VectorN<E, N>& vector, const E& scalar);

    public:
        //E getSignedAngle(const VectorN<E, N>& to, const VectorN<E, N>& normal) const;

    public:
        const E* getElementPointer() const;

        E* getElementPointer();

    private:
        E elements_[N];
    };
    
    template <typename E, SizeType N>
    class NumericTraits< VectorN<E, N> >
    {
        static const VectorN<E, N> zero;

        static const VectorN<E, N> one;

        static const VectorN<E, N> epsilon;
    };
}
}

#ifndef KAPHEIN_CPPCLI
    #include "VectorN.inl"
#endif

#endif
