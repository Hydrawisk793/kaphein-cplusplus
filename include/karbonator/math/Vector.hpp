#ifndef KARBONATOR_MATH_VECTOR_HPP
#define KARBONATOR_MATH_VECTOR_HPP

//#include <cstdarg>
#include "karbonator/collection/DynamicSizeArray.hpp"
#include "karbonator/math/NumericTraits.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    class Vector
    {
    public:
        //Vector();

        //Vector(const Vector<E>& o);

        //Vector(Vector<E>&& o);

        static Vector<E> fill(SizeType elementCount, const E& src = E());

        static Vector<E> fromElements(const E* pElements, SizeType elementCount);

        static Vector<E> fromElements(const collection::DynamicSizeArray<E>& elements);

        static Vector<E> fromElements(collection::DynamicSizeArray<E>&& elements);

        //Vector<E>& operator =(const Vector<E>& rhs);

        //Vector<E>& operator =(Vector<E>&& rhs);

    public:
        SizeType getElementCount() const;

        const E& operator [](SizeType index) const;

        E& operator [](SizeType index);

        const E& at(SizeType index) const;

        E& at(SizeType index);

        Vector<E>& set(SizeType index, const E& e);

        Vector<E>& swapElements(SizeType lhsIndex, SizeType rhsIndex);

    public:
        bool isZero(const E& epsilon = NumericTraits<E>::epsilon) const;
        
        bool isNormalized(const E& epsilon = NumericTraits<E>::epsilon) const;

        bool equals(const Vector<E>& rhs, const E& epsilon = NumericTraits<E>::epsilon) const;

        template <typename E>
        friend bool operator ==(const Vector<E>& lhs, const Vector<E>& rhs);

        template <typename E>
        friend bool operator !=(const Vector<E>& lhs, const Vector<E>& rhs);

    public:
        E squaredMagnitude() const;

        E magnitude() const;

        bool tryNormalize(const E& epsilon = NumericTraits<E>::epsilon);

        Vector<E>& normalize(const E& epsilon = NumericTraits<E>::epsilon);

        Vector<E> normalized(const E& epsilon = NumericTraits<E>::epsilon) const;

        Vector<E>& pointwiseAbsoluteAssign();

        Vector<E> pointwiseAbsolute() const;

        template <typename E>
        friend Vector<E> operator +(const Vector<E>& rhs);

        template <typename E>
        friend Vector<E> operator -(const Vector<E>& rhs);

    public:
        E dot(const Vector<E>& rhs) const;

        Vector<E> project(const Vector<E>& axis, const E& epsilon = NumericTraits<E>::epsilon) const;

        Vector<E> projectOnPlane(const Vector<E>& normal, const E& epsilon = NumericTraits<E>::epsilon) const;

        Vector<E> cross(const Vector<E>& rhs) const;

        Vector<E>& pointwiseMultiplyAssign(const Vector<E>& rhs);

        Vector<E> pointwiseMultiply(const Vector<E>& rhs) const;

        Vector<E>& pointwiseDivideAssign(const Vector<E>& rhs, const E& epsilon = NumericTraits<E>::epsilon);

        Vector<E> pointwiseDivide(const Vector<E>& rhs, const E& epsilon = NumericTraits<E>::epsilon) const;

        Vector<E>& operator +=(const Vector<E>& rhs);

        template <typename E>
        friend Vector<E> operator +(const Vector<E>& lhs, const Vector<E>& rhs);

        Vector<E>& operator -=(const Vector<E>& rhs);

        template <typename E>
        friend Vector<E> operator -(const Vector<E>& lhs, const Vector<E>& rhs);

        Vector<E>& operator *=(const E& scalar);

        template <typename E>
        friend Vector<E> operator *(const Vector<E>& vector, const E& scalar);

        template <typename E>
        friend Vector<E> operator *(const E& scalar, const Vector<E>& vector);

        Vector<E>& divideAssign(const E& scalar, const E& epsilon = NumericTraits<E>::epsilon);

        Vector<E> divide(const E& scalar, const E& epsilon = NumericTraits<E>::epsilon) const;

        Vector<E>& operator /=(const E& scalar);

        template <typename E>
        friend Vector<E> operator /(const Vector<E>& vector, const E& scalar);

    public:
        E getSignedAngle(const Vector<E>& to, const Vector<E>& normal) const;

    public:
        const E* getElementPointer() const;

    private:
        void assertAreSizesSame(const Vector<E>& rhs) const;

        static void assertAreSizesSame(SizeType elementCount, const Vector<E>& rhs);

    private:
        collection::DynamicSizeArray<E> elements_;
    };

    template class Vector<float>;

    template class Vector<double>;

    template class Vector<long double>;
}
}

#include "karbonator/math/Vector.inl"

#endif
