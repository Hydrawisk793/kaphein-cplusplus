#ifndef KAPHEIN_MATH_VECTORN_INL
#define KAPHEIN_MATH_VECTORN_INL

#include "kaphein/cplusplus/DivideByZeroException.hpp"
#include "kaphein/cplusplus/UnsupportedMethodException.hpp"
#include "kaphein/cplusplus/utility/UnrolledLoop.hpp"
#include "Sqrt.hpp"
#include "Equal.hpp"
#include "IsZero.hpp"
//#include "Atan2.hpp"
//#include "BinaryVectorCross.hpp"
#include "VectorN.hpp"

namespace kaphein
{
namespace math
{
    template <typename E, SizeType N>
    const VectorN<E, N> VectorN<E, N>::zero = VectorN<E, N>::fill(NumericTraits<E>::zero);

    template <typename E, SizeType N>
    const VectorN<E, N> VectorN<E, N>::one = VectorN<E, N>::fill(NumericTraits<E>::one);

    //template <typename E, SizeType N>
    //typename const VectorN<E, N>::BaseVectorArrayType VectorN<E, N>::bases = VectorN<E, N>::createBases();

    //template <typename E, SizeType N>
    //typename VectorN<E, N>::BaseVectorArrayType VectorN<E, N>::createBases()
    //{
    //    BaseVectorArrayType newBases;

    //    utility::UnrolledLoop<N>::step(
    //        [&] (SizeType r) {
    //            newBases[r] = zero;
    //            
    //            utility::UnrolledLoop<N>::step(
    //                [&] (SizeType c) {
    //                    newBases[r][c] = static_cast<E>(1);
    //                }
    //            );
    //        }
    //    );

    //    return newBases;
    //}

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::fromValues(const E* pValues, SizeType valueCount)
    {
        if(valueCount >= VectorN<E, N>::dimensionCount) {
            throw false;
        }

        VectorN<E, N> vector = VectorN<E, N>();

        for(SizeType i = 0; i < VectorN<E, N>::dimensionCount; ++i) {
            vector.elements_[i] = *pValues++;
        }

        return vector;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::fromAxis(SizeType axis)
    {
        VectorN<E, N> vector;

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {vector.elements_[r1] = NumericTraits<E>::zero;}
        );

        vector.elements_[axis] = static_cast<E>(1);

        return vector;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::fill(const E& scalar)
    {
        VectorN<E, N> vector;

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {vector.elements_[r1] = scalar;}
        );

        return vector;
    }

#if KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED > 0
    template <typename E, SizeType N>
    VectorN<E, N>::VectorN(std::initializer_list<E> list)
    {
        auto iter = std::begin(list);

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {elements_[r1] = *iter++;}
        );
    }
#endif

    template <typename E, SizeType N>
    const E& VectorN<E, N>::operator [](SizeType index) const
    {
        return elements_[index];
    }

    template <typename E, SizeType N>
    E& VectorN<E, N>::operator [](SizeType index)
    {
        return const_cast<E&>(const_cast<const VectorN<E, N>*>(this)->operator [](index));
    }

    template <typename E, SizeType N>
    const E& VectorN<E, N>::get(SizeType index) const
    {
        return (*this)[index];
    }

    template <typename E, SizeType N>
    E& VectorN<E, N>::get(SizeType index)
    {
        return const_cast<E&>(const_cast<const VectorN<E, N>*>(this)->get(index));
    }

    template <typename E, SizeType N>
    void VectorN<E, N>::set(SizeType index, const E& scalar)
    {
        (*this)[index] = scalar;
    }

    template <typename E, SizeType N>
    void VectorN<E, N>::swapElements(SizeType lhsIndex, SizeType rhsIndex)
    {
        const E lhsClone = elements_[lhsIndex];
        elements_[lhsIndex] = elements_[rhsIndex];
        elements_[rhsIndex] = lhsClone;
    }

    template <typename E, SizeType N>
    bool VectorN<E, N>::equals(const VectorN<E, N>& rhs, const E& epsilon) const
    {
        return (*this - rhs).isZero(epsilon);
    }

    template <typename E, SizeType N>
    bool VectorN<E, N>::isZero(const E& epsilon) const
    {
        return IsZero<E>()(squaredMagnitude(), epsilon * epsilon);
    }

    template <typename E, SizeType N>
    bool VectorN<E, N>::isNormalized(const E& epsilon) const
    {
        return Equal<E>()(squaredMagnitude(), static_cast<E>(1), epsilon * epsilon);
    }

    template <typename E, SizeType N>
    bool operator ==(
        const VectorN<E, N>& lhs
        , const VectorN<E, N>& rhs
    )
    {
        return lhs.equals(rhs);
    }

    template <typename E, SizeType N>
    bool operator !=(
        const VectorN<E, N>& lhs
        , const VectorN<E, N>& rhs
    )
    {
        return !(lhs == rhs);
    }

    template <typename E, SizeType N>
    E VectorN<E, N>::squaredMagnitude() const
    {
        return dot(*this);
    }

    template <typename E, SizeType N>
    E VectorN<E, N>::magnitude() const
    {
        return Sqrt<E>()(squaredMagnitude());
    }

    template <typename E, SizeType N>
    bool VectorN<E, N>::tryNormalize(
        const E& epsilon/* = defaultEpsilon*/
    )
    {
        const E sqrMag = squaredMagnitude();
        const bool result = !IsZero<E>()(sqrMag, epsilon * epsilon);
        if(result) {
            (*this) /= Sqrt<E>()(sqrMag);
        }

        return result;
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::normalize(
        const E& epsilon// = NumericTraits<E>::epsilon
    )
    {
        if(!tryNormalize(epsilon)) {
            utility::UnrolledLoop<N>::step(
                [&] (SizeType index) {
                    elements_[index] = NumericTraits<E>::zero;
                }
            );
        }

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::normalized(
        const E& epsilon// = NumericTraits<E>::epsilon
    ) const
    {
        return VectorN<E, N>(*this).normalize(epsilon);
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::pointwiseAbsoluteAssign()
    {
        utility::UnrolledLoop<N>::step([&] (SizeType index) {
            elements_[index] = Abs<E>()(elements_[index]);
        });

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::pointwiseAbsolute() const
    {
        return VectorN<E, N>(*this).pointwiseAbsoluteAssign();
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator +(const VectorN<E, N>& rhs)
    {
        VectorN<E, N> result(rhs);

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {result.elements_[r1] = +result.elements_[r1];}
        );

        return result;
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator -(const VectorN<E, N>& rhs)
    {
        VectorN<E, N> result(rhs);

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {result.elements_[r1] = -result.elements_[r1];}
        );

        return result;
    }

    template <typename E, SizeType N>
    E VectorN<E, N>::dot(const VectorN<E, N>& rhs) const
    {
        E result = NumericTraits<E>::zero;

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {result += (elements_[r1] * rhs.elements_[r1]);}
        );

        return result;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::project(
        const VectorN<E, N>& axis,
        const E& epsilon
    ) const
    {
        const E sqrMag = axis.squaredMagnitude();
        if(IsZero<E>()(sqrMag, epsilon * epsilon)) {
            return VectorN<E, N>::zero;
        }

        return (dot(axis) / Sqrt<E>()(sqrMag)) * axis;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::projectOnPlane(
        const VectorN<E, N>& normal,
        const E& epsilon/* = NumericTraits<E>::epsilon*/
    ) const
    {
        return (*this) - project(normal, epsilon);
    }

    //template <typename T, SizeType N>
    //VectorN<T, N> VectorN<T, N>::cross(
    //    const VectorN<T, N>& rhs
    //) const
    //{
    //    return BinaryVectorCross<T, N>()(*this, rhs);
    //}

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::pointwiseMultiplyAssign(const VectorN<E, N>& rhs)
    {
        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                elements_[index] *= rhs.elements_[index];
            }
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::pointwiseMultiply(const VectorN<E, N>& rhs) const
    {
        return VectorN<E, N>(*this).pointwiseMultiplyAssign(rhs);
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::pointwiseDivideAssign(const VectorN<E, N>& rhs, const E& epsilon)
    {
        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                if(IsZero<E>()(rhs.elements_[index], epsilon)) {
                    throw DivideByZeroException();
                }

                elements_[index] /= rhs.elements_[index];
            }
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::pointwiseDivide(const VectorN<E, N>& rhs, const E& epsilon) const
    {
        return VectorN<E, N>(*this).pointwiseDivideAssign(rhs, epsilon);        
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::operator +=(const VectorN<E, N>& rhs)
    {
        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {elements_[r1] += rhs.elements_[r1];}
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator +(
        const VectorN<E, N>& lhs
        , const VectorN<E, N>& rhs
    )
    {
        return VectorN<E, N>(lhs) += rhs;
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::operator -=(const VectorN<E, N>& rhs)
    {
        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {elements_[r1] -= rhs.elements_[r1];}
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator -(
        const VectorN<E, N>& lhs
        , const VectorN<E, N>& rhs
    )
    {
        return VectorN<E, N>(lhs) -= rhs;
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::operator *=(const E& scalar)
    {
        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {elements_[r1] *= scalar;}
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator *(
        const VectorN<E, N>& vector
        , const E& scalar
    )
    {
        return VectorN<E, N>(vector) *= scalar;
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator *(
        const E& scalar
        , const VectorN<E, N>& vector
    )
    {
        return vector * scalar;
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::divideAssign(const E& scalar, const E& epsilon)
    {
        if(IsZero<E>()(scalar, epsilon * epsilon)) {
            throw DivideByZeroException();
        }

        utility::UnrolledLoop<N>::step(
            [&] (SizeType r1) {elements_[r1] /= scalar;}
        );

        return *this;
    }

    template <typename E, SizeType N>
    VectorN<E, N> VectorN<E, N>::divide(const E& scalar, const E& epsilon) const
    {
        return VectorN<E, N>(*this).divideAssign(scalar, epsilon);
    }

    template <typename E, SizeType N>
    VectorN<E, N>& VectorN<E, N>::operator /=(const E& scalar)
    {
        return divideAssign(scalar, NumericTraits<E>::epsilon);
    }

    template <typename E, SizeType N>
    VectorN<E, N> operator /(
        const VectorN<E, N>& vector
        , const E& scalar
    )
    {
        return VectorN<E, N>(vector) /= scalar;
    }

    //template <typename E, SizeType N>
    //E VectorN<E, N>::getSignedAngle(
    //    const VectorN<E, N>& to
    //    , const VectorN<E, N>& normal
    //) const
    //{
    //    const VectorN<E, N> unitFrom = normalized();
    //    const VectorN<E, N> unitTo = to.normalized();

    //    return Atan2<E>()(
    //        normal.normalized().dot(unitFrom.cross(unitTo)),
    //        unitFrom.dot(unitTo)
    //    );
    //}

    template <typename E, SizeType N>
    const E* VectorN<E, N>::getElementPointer() const
    {
        return elements_;
    }

    template <typename E, SizeType N>
    E* VectorN<E, N>::getElementPointer()
    {
        return const_cast<E*>(const_cast<const VectorN<E, N>*>(this)->getElementPointer());
    }

    template <typename E, SizeType N>
    const VectorN<E, N> NumericTraits< VectorN<E, N> >::zero = VectorN<E, N>::zero;

    template <typename E, SizeType N>
    const VectorN<E, N> NumericTraits< VectorN<E, N> >::one = VectorN<E, N>::one;

    template <typename E, SizeType N>
    const VectorN<E, N> NumericTraits< VectorN<E, N> >::epsilon = VectorN<E, N>::epsilon;
}
}

#endif
