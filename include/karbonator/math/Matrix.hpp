#ifndef KARBONATOR_MATH_MATRIX_HPP
#define KARBONATOR_MATH_MATRIX_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/collection/DynamicSizeArray.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    class Matrix
    {
    public:
        typedef E ElementType;

    public:
        Matrix();

        Matrix(const Matrix<E>& o);

        Matrix(Matrix<E>&& o);

        Matrix(SizeType rowCount, SizeType columnCount, const E& defaultValue = E());
        
        Matrix(const E* pElements, SizeType rowCount, SizeType columnCount);

        Matrix(const collection::DynamicSizeArray<E>& elements, SizeType rowCount, SizeType columnCount);

        Matrix(collection::DynamicSizeArray<E>&& elements, SizeType rowCount, SizeType columnCount);

        virtual ~Matrix();

        Matrix<E>& operator =(const Matrix<E>& rhs);

        Matrix<E>& operator =(Matrix<E>&& rhs);

    public:
        SizeType getRowCount() const;

        SizeType getColumnCount() const;

        SizeType getElementCount() const;

        const E& get(SizeType index) const;

        Matrix<E>& set(SizeType index, const E& e);

        Matrix<E>& set(SizeType index, E&& e);
        
        const E& get(SizeType r, SizeType c) const;

        Matrix<E>& set(SizeType r, SizeType c, const E& e);

        Matrix<E>& set(SizeType r, SizeType c, E&& e);

    public:
        Matrix<E> getRowVector(SizeType index) const;

        Matrix<E> getColumnVector(SizeType index) const;

    private:
        void assertIndexInRange(SizeType index) const;

        void assertRowIndexInRange(SizeType r) const;

        void assertColumnIndexInRange(SizeType r) const;

    private:
        SizeType rowCount_;

        SizeType columnCount_;

        collection::DynamicSizeArray<E> elements_;
    };
}
}

#include "karbonator/math/Matrix.inl"

#endif
