#ifndef KAPHEIN_MATH_MATRIXMXN_INL
#define KAPHEIN_MATH_MATRIXMXN_INL

#include "kaphein/utility/UnrolledLoop.hpp"
#include "MatrixMxN.hpp"

namespace kaphein
{
namespace math
{
    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N>::MatrixMxN()
    {
        
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N>::MatrixMxN(const MatrixMxN<E, M, N> & source)
    {
        
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N>::MatrixMxN(const E & scalar)
    {
        for(SizeType i = 0; i < elementCount; ++i) {
            elements[i] = scalar;
        }
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N>::MatrixMxN(
        const E values []
    ) {
        for(SizeType i = 0; i < elementCount; ++i) {
            elements[i] = values[i];
        }
    }

    template <typename E, SizeType M, SizeType N>
    const VectorN<E, N> & MatrixMxN<E, M, N>::getRowVector(
        SizeType index
    ) const {
        return rowVectors[index];
    }

    template <typename E, SizeType M, SizeType N>
    VectorN<E, N> & MatrixMxN<E, M, N>::getRowVector(
        SizeType index
    ) {
        return rowVectors[index];
    }

    template <typename E, SizeType M, SizeType N>
    void MatrixMxN<E, M, N>::setRowVector(
        SizeType index
        , const VectorN<E, N> & newRowVector
    ) {
        rowVectors[index] = newRowVector;
    }

    template <typename E, SizeType M, SizeType N>
    const VectorN<E, N> & MatrixMxN<E, M, N>::operator [](
        SizeType index
    ) const {
        return rowVectors[index];
    }

    template <typename E, SizeType M, SizeType N>
    VectorN<E, N> & MatrixMxN<E, M, N>::operator [](
        SizeType index
    ) {
        return const_cast<RowVectorType &>(const_cast<const MatrixMxN<E, M, N> *>(this)->operator [](index));
    }

    template <typename E, SizeType M, SizeType N>
    const VectorN<E, M> MatrixMxN<E, M, N>::getColumnVector(SizeType index) const {
        VectorN<E, M> columnVector;

        for(SizeType r = 0; r < M; ++r) {
            columnVector[r] = rowVectors[r][index];
        }

        return columnVector;
    }

    template <typename E, SizeType M, SizeType N>
    void MatrixMxN<E, M, N>::setColumnVector(SizeType index, const VectorN<E, M> & newColumnVector) {
        for(SizeType r = 0; r < M; ++r) {
            rowVectors[r][index] = newColumnVector[r];
        }
    }

    template <typename E, SizeType M, SizeType N>
    bool MatrixMxN<E, M, N>::equals(
        const MatrixMxN<E, M, N> & rhs
        , const E & epsilon = Epsilon<E>()
    ) const {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                if(!Math<E>::equals(rowVectors[r][c], rhs.rowVectors[r][c], epsilon)) {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename E, SizeType M, SizeType N>
    bool MatrixMxN<E, M, N>::isZero(
        const E & epsilon = Epsilon<E>()
    ) const {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                if(!Equal<E>()(rowVectors[r][c], Zero<E>(), epsilon)) {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename E, SizeType M, SizeType N>
    bool MatrixMxN<E, M, N>::operator ==(
        const MatrixMxN<E, M, N> & rhs
    ) const {
        return equals(rhs);
    }
    
    template <typename E, SizeType M, SizeType N>
    bool MatrixMxN<E, M, N>::operator !=(
        const MatrixMxN<E, M, N> & rhs
    ) const {
        return !(*this == rhs);
    }

    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, N, M> MatrixMxN<E, M, N>::transpose() const {
        MatrixMxN<E, N, M> tm;

        for(SizeType c = 0; c < M; ++c) {
            tm.setColumnVector(c, rowVectors[c]);
        }

        return tm;
    }

    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> MatrixMxN<E, M, N>::operator +() const {
        MatrixMxN<E, M, N> result(*this);

        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                result[r][c] = +result[r][c];
            }
        }

        return result;
    }

    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> MatrixMxN<E, M, N>::operator -() const {
        MatrixMxN<E, M, N> result(*this);

        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                result[r][c] = -result[r][c];
            }
        }

        return result;
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N> & MatrixMxN<E, M, N>::operator +=(const MatrixMxN<E, M, N> & rhs) {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                rowVectors[r][c] += rhs.rowVectors[r][c];
            }
        }

        return *this;
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N> & MatrixMxN<E, M, N>::operator -=(const MatrixMxN<E, M, N> & rhs) {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                rowVectors[r][c] -= rhs.rowVectors[r][c];
            }
        }

        return *this;
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N> & MatrixMxN<E, M, N>::operator *=(const E & scalar) {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                rowVectors[r][c] *= scalar;
            }
        }

        return *this;
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N> & MatrixMxN<E, M, N>::operator /=(const E & scalar) {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                rowVectors[r][c] /= scalar;
            }
        }

        return *this;
    }

    template <typename E, SizeType M, SizeType N>
    MatrixMxN<E, M, N> & MatrixMxN<E, M, N>::operator %=(const E & scalar) {
        for(SizeType r = 0; r < M; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                rowVectors[r][c] %= scalar;
            }
        }

        return *this;
    }

    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator +(const MatrixMxN<E, M, N> & lhs, const MatrixMxN<E, M, N> & rhs) {
        return MatrixMxN<E, M, N>(lhs) += rhs;
    }
    
    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator -(const MatrixMxN<E, M, N> & lhs, const MatrixMxN<E, M, N> & rhs) {
        return MatrixMxN<E, M, N>(lhs) -= rhs;
    }
    
    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator *(const MatrixMxN<E, M, N> & matrix, const E & scalar) {
        return MatrixMxN<E, M, N>(matrix) *= scalar;
    }
    
    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator *(const E & scalar, const MatrixMxN<E, M, N> & matrix) {
        return matrix * scalar;
    }

    template <typename E, SizeType L, SizeType M, SizeType N>
    const MatrixMxN<E, L, N> operator *(const MatrixMxN<E, L, M> & lhs, const MatrixMxN<E, M, N> & rhs) {
        MatrixMxN<E, L, N> result;

        for(SizeType r = 0; r < L; ++r) {
            for(SizeType c = 0; c < N; ++c) {
                result[r][c] = lhs[r].dot(rhs.getColumnVector(c));
            }
        }

        return result;
    }

    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator /(const MatrixMxN<E, M, N> & matrix, const E & scalar) {
        return MatrixMxN<E, M, N>(matrix) /= scalar;
    }
    
    template <typename E, SizeType M, SizeType N>
    const MatrixMxN<E, M, N> operator %(const MatrixMxN<E, M, N> & matrix, const E & scalar) {
        return MatrixMxN<E, M, N>(matrix) %= scalar;
    }
}
}

#endif
