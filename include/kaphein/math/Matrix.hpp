#ifndef KAPHEIN_MATH_MATRIX_HPP
#define KAPHEIN_MATH_MATRIX_HPP

#include "kaphein/pp/basic.hpp"
#include "kaphein/memory/DefaultAllocator.hpp"
#include "kaphein/collection/Vector.hpp"

namespace kaphein
{
namespace math
{
    template <
        typename E
        , typename A = memory::DefaultAllocator<E>
    >
    class Matrix
    {
    public:
        typedef E ElementType;

    public:
        Matrix();

        Matrix(const Matrix<E, A>& o);

        Matrix(Matrix<E, A>&& o);

        Matrix(SizeType rowCount, SizeType columnCount, const E& defaultValue = E());
        
        Matrix(const E* pElements, SizeType rowCount, SizeType columnCount);

        Matrix(const collection::Vector<E, A>& elements, SizeType rowCount, SizeType columnCount);

        Matrix(collection::Vector<E, A>&& elements, SizeType rowCount, SizeType columnCount);

        virtual ~Matrix();

        Matrix<E, A>& operator =(const Matrix<E, A>& rhs);

        Matrix<E, A>& operator =(Matrix<E, A>&& rhs);

    public:
        SizeType getRowCount() const;

        SizeType getColumnCount() const;

        SizeType getElementCount() const;

        Matrix<E, A>& resize(SizeType rowCount, SizeType columnCount);
        
        Matrix<E, A>& resize(SizeType rowCount, SizeType columnCount, const E& e);

        Matrix<E, A>& clear();

    public:
        const E& get(SizeType index) const;

        E& get(SizeType index);

        Matrix<E, A>& set(SizeType index, const E& e);

        Matrix<E, A>& set(SizeType index, E&& e);
        
        const E& get(SizeType r, SizeType c) const;

        E& get(SizeType r, SizeType c);

        Matrix<E, A>& set(SizeType r, SizeType c, const E& e);

        Matrix<E, A>& set(SizeType r, SizeType c, E&& e);

    public:
        Matrix<E, A> getRowVector(SizeType index) const;

        Matrix<E, A> getColumnVector(SizeType index) const;

    public:
        const E* getElementPointer() const;

        E* getElementPointer();

    private:
        void assertIndexInRange(SizeType index) const;

        void assertRowIndexInRange(SizeType r) const;

        void assertColumnIndexInRange(SizeType r) const;

    private:
        SizeType rowCount_;

        SizeType columnCount_;

        collection::Vector<E, A> elements_;
    };
}
}

#include "kaphein/math/Matrix.inl"

#endif
