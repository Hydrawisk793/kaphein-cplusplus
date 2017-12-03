#ifndef KARBONATOR_MATH_VECTOR_INL
#define KARBONATOR_MATH_VECTOR_INL

#include <utility>
#include "karbonator/DivideByZeroException.hpp"
#include "karbonator/NotImplementedMethodException.hpp"
#include "karbonator/UnsupportedMethodException.hpp"
#include "karbonator/math/Vector.hpp"
#include "karbonator/math/NumericTraits.hpp"
#include "Equal.hpp"
#include "IsZero.hpp"
#include "Sqrt.hpp"
#include "Atan2.hpp"

namespace karbonator
{
namespace math
{
    //template <typename E>
    //Vector<E>::Vector()
    //    : elements_()
    //{}
    //
    //template <typename E>
    //Vector<E>::Vector(const Vector<E>& o)
    //    : elements_(o.elements_)
    //{}
    //
    //template <typename E>
    //Vector<E>::Vector(Vector<E>&& o)
    //    : elements_(std::move(o.elements_))
    //{}
    
    template <typename E>
    Vector<E> Vector<E>::fill(SizeType elementCount, const E& src)
    {
        Vector<E> result;

        result.elements_ = std::move(collection::DynamicSizeArray<E>(elementCount));
        for(SizeType i = 0; i < elementCount; ++i) {
            result.elements_[i] = src;
        }

        return result;
    }

    template <typename E>
    Vector<E> Vector<E>::fromElements(const E* pElements, SizeType elementCount)
    {
        Vector<E> result(std::move(Vector<E>::fill(elementCount)));

        for(SizeType i = 0; i < elementCount; ++i) {
            result.elements_[i] = *pElements++;
        }

        return result;
    }
    
    template <typename E>
    Vector<E> Vector<E>::fromElements(const collection::DynamicSizeArray<E>& elements)
    {
        Vector<E> result;

        result.elements_ = elements;

        return result;
    }
    
    template <typename E>
    Vector<E> Vector<E>::fromElements(collection::DynamicSizeArray<E>&& elements)
    {
        Vector<E> result;

        result.elements_ = std::move(elements);

        return result;
    }
    
    //template <typename E>
    //Vector<E>& Vector<E>::operator =(const Vector<E>& rhs)
    //{
    //    if(this != &rhs) {
    //        elements_ = rhs.elements_;
    //    }

    //    return *this;
    //}
    //
    //template <typename E>
    //Vector<E>& Vector<E>::operator =(Vector<E>&& rhs)
    //{
    //    if(this != &rhs) {
    //        elements_ = std::move(rhs.elements_);
    //    }

    //    return *this;
    //}
    
    template <typename E>
    SizeType Vector<E>::getElementCount() const
    {
        return elements_.getElementCount();
    }
    
    template <typename E>
    const E& Vector<E>::operator [](SizeType index) const
    {
        return elements_[index];
    }
    
    template <typename E>
    E& Vector<E>::operator [](SizeType index)
    {
        return elements_[index];
    }
    
    template <typename E>
    const E& Vector<E>::at(SizeType index) const
    {
        return elements_.at(index);
    }
    
    template <typename E>
    E& Vector<E>::at(SizeType index)
    {
        return elements_.at(index);
    }
    
    template <typename E>
    Vector<E>& Vector<E>::set(SizeType index, const E& e)
    {
        elements_.set(index, e);

        return *this;
    }
    
    template <typename E>
    Vector<E>& Vector<E>::swapElements(SizeType lhsIndex, SizeType rhsIndex)
    {
        E temp = elements_[lhsIndex];
        elements_[lhsIndex] = elements_[rhsIndex];
        elements_[rhsIndex] = temp;

        return *this;
    }
    
    template <typename E>
    bool Vector<E>::isZero(const E& epsilon) const
    {
        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            if(!IsZero<E>()((*this)[i], epsilon)) {
                return false;
            }
        }

        return true;
    }
    
    template <typename E>
    bool Vector<E>::isNormalized(const E& epsilon) const
    {
        return Equal<E>()(squaredMagnitude(), NumericTraits<E>::zero, epsilon * epsilon);
    }
    
    template <typename E>
    bool Vector<E>::equals(const Vector<E>& rhs, const E& epsilon) const
    {
        const SizeType elementCount = getElementCount();
        if(elementCount != rhs.getElementCount()) {
            return false;
        }

        for(SizeType i = elementCount; i > 0; ) {
            --i;

            if(!Equal<E>()((*this)[i], rhs[i], epsilon)) {
                return false;
            }
        }

        return true;
    }
    
    template <typename E>
    bool operator ==(const Vector<E>& lhs, const Vector<E>& rhs)
    {
        return lhs.equals(rhs);
    }
    
    template <typename E>
    bool operator !=(const Vector<E>& lhs, const Vector<E>& rhs)
    {
        return !(lhs == rhs);
    }
    
    template <typename E>
    E Vector<E>::squaredMagnitude() const
    {
        return dot(*this);
    }
    
    template <typename E>
    E Vector<E>::magnitude() const
    {
        return Sqrt<E>()(squaredMagnitude());
    }
    
    template <typename E>
    bool Vector<E>::tryNormalize(const E& epsilon)
    {
        const E sqM = squaredMagnitude();
        if(IsZero<E>()(sqM, epsilon * epsilon)) {
            return false;
        }

        const E invM = NumericTraits<E>::one / Sqrt<E>()(sqM);
        (*this) *= invM;

        return true;
    }
    
    template <typename E>
    Vector<E>& Vector<E>::normalize(const E& epsilon)
    {
        if(!tryNormalize(epsilon)) {
            throw new DivideByZeroException();
        }

        return *this;
    }
    
    template <typename E>
    Vector<E> Vector<E>::normalized(const E& epsilon) const
    {
        return Vector<E>(*this).normalize(epsilon);
    }
    
    template <typename E>
    Vector<E>& Vector<E>::pointwiseAbsoluteAssign()
    {
        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            elements_[i] = Abs<E>()(elements_[i]);
        }

        return *this;
    }
    
    template <typename E>
    Vector<E> Vector<E>::pointwiseAbsolute() const
    {
        return Vector<E>(*this).pointwiseAbsoluteAssign();
    }

    /**
     *  TODO : Change the implementation. (Drop assignments.)
     */
    template <typename E>
    Vector<E> operator +(const Vector<E>& rhs)
    {
        Vector<E> result(*this);

        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            elements_[i] = +elements_[i];
        }

        return result;
    }

    /**
     *  TODO : Change the implementation. (Drop assignments.)
     */
    template <typename E>
    Vector<E> operator -(const Vector<E>& rhs)
    {
        Vector<E> result(*this);

        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            elements_[i] = -elements_[i];
        }

        return result;
    }

    //////////////////////////////////////////////////////////////////////
    
    template <typename E>
    E Vector<E>::dot(const Vector<E>& rhs) const
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);

        E sum = NumericTraits<E>::zero;
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            sum += elements_[i] * rhs.elements_[i];
        }

        return sum;
    }
    
    template <typename E>
    Vector<E> Vector<E>::project(const Vector<E>& axis, const E& epsilon) const
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, axis);

        const E sqrMag = axis.squaredMagnitude();
        if(IsZero<E>()(sqrMag, epsilon * epsilon)) {
            return Vector<E>::fromElements(elementCount);
        }

        return (dot(axis) / Sqrt<E>()(sqrMag)) * axis;
    }
    
    template <typename E>
    Vector<E> Vector<E>::projectOnPlane(const Vector<E>& normal, const E& epsilon) const
    {
        return (*this) - project(normal, epsilon);
    }
    
    template <typename E>
    Vector<E> Vector<E>::cross(const Vector<E>& rhs) const
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);

        switch(elementCount) {
        case 3:
        {
            const E resultValues[] = {
                ((*this)[1] * rhs[2] - (*this)[2] * rhs[1])
                , ((*this)[2] * rhs[0] - (*this)[0] * rhs[2])
                , ((*this)[0] * rhs[1] - (*this)[1] * rhs[0])
            };

            return Vector<E>::fromElements(resultValues, sizeof(resultValues) / sizeof(*resultValues));
        }
        //break;
        case 7:
            throw NotImplementedMethodException();
        //break;
        default:
            throw UnsupportedMethodException();
        }
    }
    
    template <typename E>
    Vector<E>& Vector<E>::pointwiseMultiplyAssign(const Vector<E>& rhs)
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            elements_[i] *= rhs.elements_[i];
        }

        return *this;
    }
    
    template <typename E>
    Vector<E> Vector<E>::pointwiseMultiply(const Vector<E>& rhs) const
    {
        return Vector<E>(*this).pointwiseMultiplyAssign(rhs);
    }
    
    template <typename E>
    Vector<E>& Vector<E>::pointwiseDivideAssign(const Vector<E>& rhs, const E& epsilon)
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            if(IsZero<E>()(rhs.elements_[i], epsilon)) {
                throw DivideByZeroException();
            }
            elements_[i] /= rhs.elements_[i];
        }

        return *this;
    }
    
    template <typename E>
    Vector<E> Vector<E>::pointwiseDivide(const Vector<E>& rhs, const E& epsilon) const
    {
        return Vector<E>(*this).pointwiseDivideAssign(rhs, epsilon);
    }
    
    template <typename E>
    Vector<E>& Vector<E>::operator +=(const Vector<E>& rhs)
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);

        for(SizeType i = elementCount; i > 0; ) {
            --i;

            elements_[i] += rhs.elements_[i];
        }

        return *this;
    }

    template <typename E>
    Vector<E> operator +(const Vector<E>& lhs, const Vector<E>& rhs)
    {
        return Vector<E>(lhs) += rhs;
    }
    
    template <typename E>
    Vector<E>& Vector<E>::operator -=(const Vector<E>& rhs)
    {
        const SizeType elementCount = getElementCount();
        Vector<E>::assertAreSizesSame(elementCount, rhs);

        for(SizeType i = elementCount; i > 0; ) {
            --i;

            elements_[i] -= rhs.elements_[i];
        }

        return *this;
    }

    template <typename E>
    Vector<E> operator -(const Vector<E>& lhs, const Vector<E>& rhs)
    {
        return Vector<E>(lhs) -= rhs;
    }
    
    template <typename E>
    Vector<E>& Vector<E>::operator *=(const E& scalar)
    {
        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            elements_[i] *= scalar;
        }

        return *this;
    }

    template <typename E>
    Vector<E> operator *(const Vector<E>& vector, const E& scalar)
    {
        return Vector<E>(vector) *= scalar;
    }

    template <typename E>
    Vector<E> operator *(const E& scalar, const Vector<E>& vector)
    {
        return vector * scalar;
    }
    
    template <typename E>
    Vector<E>& Vector<E>::divideAssign(const E& scalar, const E& epsilon)
    {
        if(IsZero<E>()(scalar, epsilon)) {
            throw DivideByZeroException();
        }

        const SizeType elementCount = getElementCount();
        for(SizeType i = elementCount; i > 0; ) {
            --i;

            elements_[i] /= scalar;
        }

        return *this;
    }

    template <typename E>
    Vector<E> Vector<E>::divide(const E& scalar, const E& epsilon) const
    {
        return Vector<E>(*this).divideAssign(scalar, epsilon);
    }

    template <typename E>
    Vector<E>& Vector<E>::operator /=(const E& scalar)
    {
        return divideAssign(scalar, NumericTraits<E>::epsilon);
    }

    template <typename E>
    Vector<E> operator /(const Vector<E>& vector, const E& scalar)
    {
        return Vector<E>(vector) /= scalar;
    }
    
    template <typename E>
    E Vector<E>::getSignedAngle(const Vector<E>& to, const Vector<E>& normal) const
    {
        const SizeType elementCount = getElementCount();
        if(elementCount != 3) {
            throw UnsupportedMethodException();
        }
        Vector<E>::assertAreSizesSame(elementCount, to);
        Vector<E>::assertAreSizesSame(elementCount, normal);

        const Vector<E> unitFrom = normalized();
        const Vector<E> unitTo = to.normalized();

        return Atan2<E>()(
            normal.normalized().dot(unitFrom.cross(unitTo)),
            unitFrom.dot(unitTo)
        );
    }
    
    template <typename E>
    const E* Vector<E>::getElementPointer() const
    {
        return elements_.getElementPointer();
    }

    template <typename E>
    void Vector<E>::assertAreSizesSame(const Vector<E>& rhs) const
    {
        Vector<E>::assertAreSizesSame(getElementCount(), rhs);
    }

    template <typename E>
    void Vector<E>::assertAreSizesSame(SizeType elementCount, const Vector<E>& rhs)
    {
        if(elementCount != rhs.getElementCount()) {
            throw false;
        }
    }
}
}

#endif
