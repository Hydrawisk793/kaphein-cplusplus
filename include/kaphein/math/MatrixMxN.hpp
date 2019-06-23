#ifndef KAPHEIN_MATH_MATRIXMXN_HPP
#define KAPHEIN_MATH_MATRIXMXN_HPP

#include "kaphein/pp/basic.hpp"
#include "VectorN.hpp"

namespace kaphein
{
namespace math
{
    template <typename E, SizeType M, SizeType N>
    class MatrixMxN final
    {
    public:
        typedef E ElementType;

        typedef VectorN<E, N> RowVectorType;

        typedef VectorN<E, M> ColumnVectorType;

    #if KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED > 0
        static constexpr SizeType rowCount = M;

        static constexpr SizeType columnCount = N;

        static constexpr SizeType elementCount = M * N;
    #else
        enum
        {
            rowCount = M,
            columnCount = N,
            elementCount = M * N
        };
    #endif

    public:
        MatrixMxN();

        MatrixMxN(const MatrixMxN<E, M, N> & source);

        MatrixMxN(const E & scalar);

        MatrixMxN(
            const E values []
        );

        ~MatrixMxN() = default;

        MatrixMxN<E, M, N> & operator =(
            const MatrixMxN<E, M, N> & rhs
        ) = default;

    public:
        const VectorN<E, N> & getRowVector(
            SizeType index
        ) const;

        VectorN<E, N> & getRowVector(
            SizeType index
        );

        void setRowVector(
            SizeType index
            , const VectorN<E, N> & newRowVector
        );

        const VectorN<E, N> & operator [](
            SizeType index
        ) const;

        VectorN<E, N> & operator [](
            SizeType index
        );

        const VectorN<E, M> getColumnVector(
            SizeType index
        ) const;

        void setColumnVector(
            SizeType index
            , const VectorN<E, M> & newColumnVector
        );

    public:
        bool equals(
            const MatrixMxN<E, M, N> & rhs
            , const E & epsilon = Epsilon<E>()
        ) const;

        bool isZero(
            const E & epsilon = Epsilon<E>()
        ) const;

        bool operator ==(
            const MatrixMxN<E, M, N> & rhs
        ) const;

        bool operator !=(
            const MatrixMxN<E, M, N> & rhs
        ) const;

    public:
        const MatrixMxN<E, N, M> transpose() const;

        const MatrixMxN<E, M, N> operator +() const;

        const MatrixMxN<E, M, N> operator -() const;

    public:

        MatrixMxN<E, M, N> & operator +=(const MatrixMxN<E, M, N> & rhs);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator +(const MatrixMxN<E, M, N> & lhs, const MatrixMxN<E, M, N> & rhs);

        MatrixMxN<E, M, N> & operator -=(const MatrixMxN<E, M, N> & rhs);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator -(const MatrixMxN<E, M, N> & lhs, const MatrixMxN<E, M, N> & rhs);

        MatrixMxN<E, M, N> & operator *=(const E & scalar);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator *(const MatrixMxN<E, M, N> & matrix, const E & scalar);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator *(const E & scalar, const MatrixMxN<E, M, N> & matrix);

        template <typename E, SizeType L, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, L, N> operator *(const MatrixMxN<E, L, M> & lhs, const MatrixMxN<E, M, N> & rhs);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator /(const MatrixMxN<E, M, N> & matrix, const E & scalar);

        MatrixMxN<E, M, N> & operator /=(const E & scalar);

        template <typename E, SizeType M, SizeType N>
        friend_TEMPLATE const MatrixMxN<E, M, N> operator %(const MatrixMxN<E, M, N> & matrix, const E & scalar);

        MatrixMxN<E, M, N> & operator %=(const E & scalar);

    private:
        union {
            E elements [M*N];
            VectorN<E, N> rowVectors [M];
        };
    };
}
}

#include "MatrixMxN.inl"

#endif
