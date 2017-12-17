#ifndef KAPHEIN_MATH_MATRIXNXN_HPP
#define KAPHEIN_MATH_MATRIXNXN_HPP

#include <initializer_list>
#include <cstddef>
#include "kaphein/cplusplus/pp/basic.hpp"
#include "kaphein/cplusplus/utility/UnrolledLoop.hpp"
#include "Zero.hpp"
#include "One.hpp"
#include "Equal.hpp"
#include "Epsilon.hpp"
#include "VectorN.hpp"
#include "SingularMatrixException.hpp" 

namespace kaphein {
namespace math {
    template <typename E, std::size_t N>
    class KAPHEIN_PP_DLL_API_TEMPLATE MatrixNxN {
    public:
        typedef E ElementType;

        typedef std::size_t SizeType;

        static constexpr SizeType dimensionCount = N;

        static constexpr SizeType rowCount = N;

        static constexpr SizeType columnCount = N;

        static constexpr SizeType elementCount = rowCount * columnCount;

        typedef VectorN<
            ElementType
            , columnCount
        > VectorType;

        static const MatrixNxN<E, N> zero;

        static const MatrixNxN<E, N> identity;

    private:
        static MatrixNxN<E, N> createIdentityMatrix();

        static bool trySolveUpperTriangularMatrixEquation(
            const MatrixNxN<E, N> & u
            , VectorType & x
            , const VectorType & b
            , const E & epsilon = Epsilon<E>()
        );

        static bool trySolveLowerTriangularMatrixEquation(
            const MatrixNxN<E, N> & l
            , VectorType & x
            , const VectorType & b
            , const E & epsilon = Epsilon<E>()
        );

        static const E determinantOfTriangularMatrix(
            const MatrixNxN<E, N> & triangularMatrix
        );

    public:
        MatrixNxN() = default;

        MatrixNxN(
            const MatrixNxN<E, N> & source
        ) = default;

        MatrixNxN(
            const E & scalar
        );

        MatrixNxN(
            const E elements []
        );

        MatrixNxN(
            std::initializer_list<E> elements
        );

        MatrixNxN(
            std::initializer_list<VectorType> rowVectors
        );

        ~MatrixNxN() = default;

        MatrixNxN<E, N> & operator =(
            const MatrixNxN<E, N> & rhs
        ) = default;

    public:
        const VectorType & getRowVector(
            SizeType index
        ) const;

        VectorType & getRowVector(
            SizeType index
        );

        void setRowVector(
            SizeType index
            , const VectorType & newRowVector
        );

        const VectorType getColumnVector(
            SizeType index
        ) const;

        void setColumnVector(
            SizeType index
            , const VectorType & newColumnVector
        );

        const VectorType & operator [](
            SizeType index
        ) const;

        VectorType & operator [](
            SizeType index
        );

        void swapRows(
            SizeType lhsIndex
            , SizeType rhsIndex
        );

        void swapColumns(
            SizeType lhsIndex
            , SizeType rhsIndex
        );

    public:
        bool equals(
            const MatrixNxN<E, N> & rhs
            , const E & epsilon = Epsilon<E>()
        ) const;

        bool isZero(
            const E & epsilon = Epsilon<E>()
        ) const;

        bool isSingular(
            const E & epsilon = Epsilon<E>()
        ) const;

        template <typename E, std::size_t N>
        friend bool operator ==(
            const MatrixNxN<E, N> & lhs
            , const MatrixNxN<E, N> & rhs
        );
        
        template <typename E, std::size_t N>
        friend bool operator !=(
            const MatrixNxN<E, N> & lhs
            , const MatrixNxN<E, N> & rhs
        );

    public:
        const MatrixNxN<E, N> transpose() const;

        const E trace() const;

        const E determinant(
            const E & epsilon = Epsilon<E>()
        ) const;

        bool tryInvert(
            MatrixNxN<E, N> & inverseOut
            , const E & epsilon = Epsilon<E>()
        ) const;

        const MatrixNxN<E, N> invert(
            const E & epsilon = Epsilon<E>()
        ) const;

        bool decomposeIntoLu(
            MatrixNxN<E, N> & l
            , MatrixNxN<E, N> & u
            , const E & epsilon = Epsilon<E>()
        ) const;

        bool decomposeIntoLuWithPivoting(
            MatrixNxN<E, N> & p
            , MatrixNxN<E, N> & l
            , MatrixNxN<E, N> & u
            , const E & epsilon = Epsilon<E>()
        ) const;

        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator +(
            const MatrixNxN<E, N> & rhs
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator -(
            const MatrixNxN<E, N> & rhs
        );

    public:
        MatrixNxN<E, N> & operator +=(
            const MatrixNxN<E, N> & rhs
        );

        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator +(
            const MatrixNxN<E, N> & lhs, const MatrixNxN<E, N> & rhs
        );

        MatrixNxN<E, N> & operator -=(
            const MatrixNxN<E, N> & rhs
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator -(
            const MatrixNxN<E, N> & lhs, const MatrixNxN<E, N> & rhs
        );

        MatrixNxN<E, N> & operator *=(
            const MatrixNxN<E, N> & rhs
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator *(
            const MatrixNxN<E, N> & lhs
            , const MatrixNxN<E, N> & rhs
        );

        MatrixNxN<E, N> & operator *=(
            const E & scalar
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator *(
            const MatrixNxN<E, N> & matrix
            , const E & scalar
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator *(
            const E & scalar
            , const MatrixNxN<E, N> & matrix
        );
        
        template <typename E, std::size_t N>
        friend const VectorType operator *(
            const VectorType & vector
            , const MatrixNxN<E, N> & matrix
        );

        MatrixNxN<E, N> & operator /=(
            const E & scalar
        );
        
        template <typename E, std::size_t N>
        friend const MatrixNxN<E, N> operator /(
            const MatrixNxN<E, N> & matrix
            , const E & scalar
        );

    public:
        explicit operator const E *() const;

    private:
        void permute(
            MatrixNxN<E, N> & p
        );

    private:
        union {
            E elements_ [elementCount];
            VectorType rowVectors_ [N];
        };
    };
}
}

namespace kaphein {
namespace math {
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> MatrixNxN<E, N>::zero;

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> MatrixNxN<E, N>::identity = MatrixNxN<E, N>::createIdentityMatrix();

    template <typename E, std::size_t N>
    MatrixNxN<E, N> MatrixNxN<E, N>::createIdentityMatrix() {
        MatrixNxN<E, N> newIdentity;

        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                newIdentity.rowVectors_[index][index] = One<E>();
            }
        );

        return newIdentity;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::trySolveUpperTriangularMatrixEquation(
        const MatrixNxN<E, N> & u
        , VectorType & x
        , const VectorType & b
        , const E & epsilon/* = Epsilon<T>()*/
    ) {
        for(SizeType r1 = 0, i = (N - 1); r1 < N; ++r1, --i) {
            if(Equal<E>()(u[i][i], Zero<E>(), epsilon)) {
                return false;
            }

            E sum = Zero<E>();
            for(SizeType j = i + 1; j < N; ++j) {
                sum += u[i][j] * x[j];
            }

            x[i] = (b[i] - sum) * (One<E>()/u[i][i]);
        }

        return true;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::trySolveLowerTriangularMatrixEquation(
        const MatrixNxN<E, N> & l
        , VectorType & x
        , const VectorType & b
        , const E & epsilon/* = Epsilon<T>()*/
    ) {
        for(SizeType i = 0; i < N; ++i) {
            if(Equal<E>()(l[i][i], Zero<E>(), epsilon)) {
                return false;
            }

            E sum = Zero<E>();
            for(SizeType j = 0; j < i; ++j) {
                sum += l[i][j] * x[j];
            }

            x[i] = (b[i] - sum) * (One<E>()/l[i][i]);
        }

        return true;
    }

    template <typename E, std::size_t N>
    const E MatrixNxN<E, N>::determinantOfTriangularMatrix(
        const MatrixNxN<E, N> & triangularMatrix
    ) {
        E determinant = One<E>();

        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                determinant *= triangularMatrix[index][index];
            }
        );

        return determinant;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N>::MatrixNxN(
        const E & scalar
    ) {
        utility::UnrolledLoop<elementCount>::step(
            [&] (SizeType index) {
                elements_[index] = scalar;
            }
        );
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N>::MatrixNxN(
        const E elements []
    ) {
        utility::UnrolledLoop<elementCount>::step(
            [&] (SizeType index) {
                elements_[index] = elements[index];
            }
        );
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N>::MatrixNxN(
        std::initializer_list<E> elements
    ) {
        auto iter = std::begin(elements);

        utility::UnrolledLoop<elementCount>::step(
            [&] (SizeType index) {
                elements_[index] = *iter++;
            }
        );
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N>::MatrixNxN(
        std::initializer_list<VectorType> rowVectors
    ) {
        auto iter = std::begin(rowVectors);

        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                rowVectors_[index] = *iter++;
            }
        );
    }

    template <typename E, std::size_t N>
    const typename MatrixNxN<E, N>::VectorType & MatrixNxN<E, N>::getRowVector(
        SizeType index
    ) const {
        return rowVectors_[index];
    }

    template <typename E, std::size_t N>
    typename MatrixNxN<E, N>::VectorType & MatrixNxN<E, N>::getRowVector(
        SizeType index
    ) {
        return const_cast<VectorType &>(const_cast<const MatrixNxN<E, N> *>(this)->getRowVector(index));
    }

    template <typename E, std::size_t N>
    void MatrixNxN<E, N>::setRowVector(
        SizeType index
        , const VectorType & newRowVector
    ) {
        rowVectors_[index] = newRowVector;
    }

    template <typename E, std::size_t N>
    typename const MatrixNxN<E, N>::VectorType MatrixNxN<E, N>::getColumnVector(
        SizeType index
    ) const {
        VectorType columnVector;

        utility::UnrolledLoop<rowCount>::step(
            [&] (SizeType r) {
                columnVector[r] = rowVectors_[r][index];
            }
        );

        return columnVector;
    }

    template <typename E, std::size_t N>
    void MatrixNxN<E, N>::setColumnVector(
        SizeType index
        , const VectorType & newColumnVector
    ) {
        utility::UnrolledLoop<rowCount>::step(
            [&] (SizeType r) {
                rowVectors_[r][index] = newColumnVector[r];
            }
        );
    }

    template <typename E, std::size_t N>
    typename const MatrixNxN<E, N>::VectorType & MatrixNxN<E, N>::operator [](
        SizeType index
    ) const {
        return rowVectors_[index];
    }

    template <typename E, std::size_t N>
    typename MatrixNxN<E, N>::VectorType & MatrixNxN<E, N>::operator [](
        SizeType index
    ) {
        return const_cast<VectorType &>(const_cast<const MatrixNxN<E, N> *>(this)->operator [](index));
    }

    template <typename E, std::size_t N>
    void MatrixNxN<E, N>::swapRows(
        SizeType lhsIndex
        , SizeType rhsIndex
    ) {
        const VectorType lhsClone = rowVectors_[lhsIndex];
        rowVectors_[lhsIndex] = rowVectors_[rhsIndex];
        rowVectors_[rhsIndex] = lhsClone;
    }

    template <typename E, std::size_t N>
    void MatrixNxN<E, N>::swapColumns(
        SizeType lhsIndex
        , SizeType rhsIndex
    ) {
        const VectorType lhsClone = getColumnVector(lhsIndex);
        setColumnVector(lhsIndex, getColumnVector(rhsIndex));
        setColumnVector(rhsIndex, lhsClone);
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::equals(
        const MatrixNxN<E, N> & rhs
        , const E & epsilon// = Epsilon<E>()
    ) const {
        for(SizeType r1 = 0; r1 < N; ++r1) {
            if(!Equal<E>()(elements_[r1], rhs.elements_[r1], epsilon)) {
                return false;
            }
        }

        return true;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::isZero(
        const E & epsilon// = Epsilon<E>()
    ) const {
        for(SizeType r1 = 0; r1 < N; ++r1) {
            if(!Equal<E>()(elements_[r1], Zero<E>(), epsilon)) {
                return false;
            }
        }

        return true;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::isSingular(
        const E & epsilon// = Epsilon<E>()
    ) const {
        MatrixNxN<E, N> l, u;

        return decomposeIntoLu(l, u, epsilon);
    }

    template <typename E, std::size_t N>
    bool operator ==(
        const MatrixNxN<E, N> & lhs
        , const MatrixNxN<E, N> & rhs
    ) {
        return lhs.equals(rhs);
    }

    template <typename E, std::size_t N>
    bool operator !=(
        const MatrixNxN<E, N> & lhs
        , const MatrixNxN<E, N> & rhs
    ) {
        return !(lhs == rhs);
    }

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> MatrixNxN<E, N>::transpose() const {
        MatrixNxN<E, N> tm;

        utility::UnrolledLoop<columnCount>::step(
            [&] (SizeType c) {
                tm.setColumnVector(c, rowVectors_[c]);
            }
        );

        return tm;
    }

    template <typename E, std::size_t N>
    const E MatrixNxN<E, N>::trace() const {
        E trace = Zero<E>();

        utility::UnrolledLoop<N>::step(
            [&] (SizeType index) {
                trace += rowVectors_[index][index];
            }
        );

        return trace;
    }

    template <typename E, std::size_t N>
    const E MatrixNxN<E, N>::determinant(
        const E & epsilon// = Epsilon<E>()
    ) const {
        MatrixNxN<E, N> l, u;
        if(decomposeIntoLu(l, u, epsilon)) {
            return MatrixNxN<E, N>::determinantOfTriangularMatrix(l) * MatrixNxN<E, N>::determinantOfTriangularMatrix(u);
        }

        return Zero<E>();
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::tryInvert(
        MatrixNxN<E, N> & inverseOut
        , const E & epsilon// = Epsilon<E>()
    ) const {
        MatrixNxN<E, N> p, l, u;
        if(!decomposeIntoLuWithPivoting(p, l, u, epsilon)) {
            return false;
        }

        //Solve LUx = P => Ld = P and Ux = d.
        VectorType d, x;
        for(SizeType c = 0; c < N; ++c) {
            if(!MatrixNxN<E, N>::trySolveLowerTriangularMatrixEquation(l, d, p.getColumnVector(c), epsilon)) {
                return false;
            }

            if(!MatrixNxN<E, N>::trySolveUpperTriangularMatrixEquation(u, x, d, epsilon)) {
                return false;
            }

            inverseOut.setColumnVector(c, x);
        }

        return true;
    }

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> MatrixNxN<E, N>::invert(
        const E & epsilon// = Epsilon<E>()
    ) const {
        MatrixNxN<E, N> inverse;
        if(!tryInvert(inverse, epsilon)) {
            throw SingularMatrixException();
        }

        return inverse;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::decomposeIntoLu(
        MatrixNxN<E, N> & l
        , MatrixNxN<E, N> & u
        , const E & epsilon// = Epsilon<E>()
    ) const {
        l = MatrixNxN<E, N>::identity;
        u = MatrixNxN<E, N>::zero;

        for(SizeType i = 0; i < N; ++i) {
            for(SizeType j = i; j < N; ++j) {
                E sum = Zero<E>();
                for(SizeType k = 0; k < i; ++k) {
                    sum += l.rowVectors_[i][k] * u.rowVectors_[k][j];
                }
                u.rowVectors_[i][j] = rowVectors_[i][j] - sum;
            }

            for(SizeType j = i; j < N; ++j) {
                E sum = Zero<E>();
                for(SizeType k = 0; k < i; ++k) {
                    sum += l.rowVectors_[j][k] * u.rowVectors_[k][i];
                }

                if(Equal<E>()(u.rowVectors_[i][i], Zero<E>(), epsilon)) {
                    return false;
                }
                l.rowVectors_[j][i] = (rowVectors_[j][i] - sum) * (1/u.rowVectors_[i][i]);
            }
        }

        return true;
    }

    template <typename E, std::size_t N>
    bool MatrixNxN<E, N>::decomposeIntoLuWithPivoting(
        MatrixNxN<E, N> & p
        , MatrixNxN<E, N> & l
        , MatrixNxN<E, N> & u
        , const E & epsilon// = Epsilon<E>()
    ) const {
        MatrixNxN<E, N> permutedMatrix(*this);
        permutedMatrix.permute(p);
        return permutedMatrix.decomposeIntoLu(l, u, epsilon);
    }

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator +(
        const MatrixNxN<E, N> & rhs
    ) {
        MatrixNxN<E, N> result(rhs);

        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (typename MatrixNxN<E, N>::SizeType r1) {
                result.elements_[r1] = +result.elements_[r1];
            }
        );

        return result;
    }

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator -(
        const MatrixNxN<E, N> & rhs
    ) {
        MatrixNxN<E, N> result(rhs);

        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (typename MatrixNxN<E, N>::SizeType r1) {
                result.elements_[r1] = -result.elements_[r1];
            }
        );

        return result;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N> & MatrixNxN<E, N>::operator +=(
        const MatrixNxN<E, N> & rhs
    ) {
        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (SizeType r1) {
                elements_[r1] += rhs.elements_[r1];
            }
        );

        return *this;
    }

    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator +(
        const MatrixNxN<E, N> & lhs
        , const MatrixNxN<E, N> & rhs
    ) {
        return MatrixNxN<E, N>(lhs) += rhs;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N> & MatrixNxN<E, N>::operator -=(
        const MatrixNxN<E, N> & rhs
    ) {
        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (SizeType r1) {
                elements_[r1] -= rhs.elements_[r1];
            }
        );

        return *this;
    }
    
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator -(
        const MatrixNxN<E, N> & lhs
        , const MatrixNxN<E, N> & rhs
    ) {
        return MatrixNxN<E, N>(lhs) -= rhs;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N> & MatrixNxN<E, N>::operator *=(
        const MatrixNxN<E, N> & rhs
    ) {
        utility::UnrolledLoop<MatrixNxN<E, N>::rowCount>::step(
            [&] (SizeType r) {
                VectorN<E, MatrixNxN<E, N>::columnCount> rowVector = rowVectors_[r];

                utility::UnrolledLoop<MatrixNxN<E, N>::columnCount>::step(
                    [&] (SizeType c) {
                        rowVectors_[r][c] = rowVector.dot(rhs.getColumnVector(c));
                    }
                );
            }
        );

        return *this;
    }
    
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator *(
        const MatrixNxN<E, N> & lhs
        , const MatrixNxN<E, N> & rhs
    ) {
        return MatrixNxN<E, N>(lhs) *= rhs;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N> & MatrixNxN<E, N>::operator *=(
        const E & scalar
    ) {
        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (SizeType r1) {
                elements_[r1] *= scalar;
            }
        );

        return *this;
    }
    
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator *(
        const MatrixNxN<E, N> & matrix
        , const E & scalar
    ) {
        return MatrixNxN<E, N>(matrix) *= scalar;
    }
    
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator *(
        const E & scalar
        , const MatrixNxN<E, N> & matrix
    ) {
        return matrix * scalar;
    }

    template <typename E, std::size_t N>
    typename const MatrixNxN<E, N>::VectorType operator *(
        typename const MatrixNxN<E, N>::VectorType & vector
        , const MatrixNxN<E, N> & matrix
    ) {
        typename MatrixNxN<E, N>::VectorType result;

        utility::UnrolledLoop<MatrixNxN<E, N>::columnCount>::step(
            [&] (typename MatrixNxN<E, N>::SizeType index) {
                result[index] = vector.dot(matrix.getColumnVector(index));
            }
        );

        return result;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N> & MatrixNxN<E, N>::operator /=(
        const E & scalar
    ) {
        utility::UnrolledLoop<MatrixNxN<E, N>::elementCount>::step(
            [&] (SizeType r1) {
                elements_[r1] /= scalar;
            }
        );

        return *this;
    }
    
    template <typename E, std::size_t N>
    const MatrixNxN<E, N> operator /(
        const MatrixNxN<E, N> & matrix
        , const E & scalar
    ) {
        return MatrixNxN<E, N>(matrix) /= scalar;
    }

    template <typename E, std::size_t N>
    MatrixNxN<E, N>::operator const E *() const {
        return elements_;
    }

    template <typename E, std::size_t N>
    void MatrixNxN<E, N>::permute(
        MatrixNxN<E, N> & p
    ) {
        p = MatrixNxN<E, N>::identity;

        SizeType pivotRowIndices [N];
        for(SizeType i = 0; i < N; ++i) {
            E max = Abs<E>()(rowVectors_[i][i]);
            pivotRowIndices[i] = i;
            for(SizeType j = i + 1; j < N; ++j) {
                const E columnValue = Abs<E>()(rowVectors_[j][i]);
                if(max < columnValue) {
                    max = columnValue;
                    pivotRowIndices[i] = j;
                }
            }

            if(pivotRowIndices[i] != i) {
                const VectorType temp = rowVectors_[i];
                rowVectors_[i] = rowVectors_[pivotRowIndices[i]];
                rowVectors_[pivotRowIndices[i]] = temp;

                const VectorType temp2 = p[i];
                p[i] = p[pivotRowIndices[i]];
                p[pivotRowIndices[i]] = temp2;
            }
        }
    }
}
}

#endif
