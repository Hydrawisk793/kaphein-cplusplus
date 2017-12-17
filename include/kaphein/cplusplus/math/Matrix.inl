#ifndef KAPHEIN_MATH_MATRIX_INL
#define KAPHEIN_MATH_MATRIX_INL

#include <utility>
#include <cstdlib>
#include <cstring>
#include "kaphein/cplusplus/IndexOutOfRangeException.hpp"
#include "kaphein/cplusplus/InvalidArgumentException.hpp"
#include "kaphein/cplusplus/math/Matrix.hpp"

namespace kaphein
{
namespace math
{
    template <typename E, typename A>
    Matrix<E, A>::Matrix()
        : rowCount_(0)
        , columnCount_(0)
        , elements_(getElementCount())
    {}

    template <typename E, typename A>
    Matrix<E, A>::Matrix(const Matrix<E, A>& o)
        : rowCount_(o.rowCount_)
        , columnCount_(o.columnCount_)
        , elements_(o.elements_)
    {}

    template <typename E, typename A>
    Matrix<E, A>::Matrix(Matrix<E, A>&& o)
        : rowCount_(std::move(o.rowCount_))
        , columnCount_(std::move(o.columnCount_))
        , elements_(std::move(o.elements_))
    {}

    template <typename E, typename A>
    Matrix<E, A>::Matrix(SizeType rowCount, SizeType columnCount, const E& defaultValue)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(getElementCount(), defaultValue)
    {}
    
    template <typename E, typename A>
    Matrix<E, A>::Matrix(const E* pElements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(pElements, getElementCount())
    {}
    
    template <typename E, typename A>
    Matrix<E, A>::Matrix(const collection::Vector<E, A>& elements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(elements)
    {
        if(getElementCount() != elements.getElementCount()) {
            throw InvalidArgumentException();
        }
    }

    template <typename E, typename A>
    Matrix<E, A>::Matrix(collection::Vector<E, A>&& elements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(std::move(elements))
    {
        if(getElementCount() != elements.getElementCount()) {
            throw InvalidArgumentException();
        }
    }

    template <typename E, typename A>
    Matrix<E, A>::~Matrix()
    {}
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::operator =(const Matrix<E, A>& rhs)
    {
        if(this != &rhs) {
            rowCount_ = rhs.rowCount_;
            columnCount_ = rhs.columnCount_;
            elements_ = rhs.elements_;
        }

        return *this;
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::operator =(Matrix<E, A>&& rhs)
    {
        if(this != &rhs) {
            rowCount_ = std::move(rhs.rowCount_);
            columnCount_ = std::move(rhs.columnCount_);
            elements_ = std::move(rhs.elements_);
        }

        return *this;
    }

    template <typename E, typename A>
    SizeType Matrix<E, A>::getRowCount() const
    {
        return rowCount_;
    }
    
    template <typename E, typename A>
    SizeType Matrix<E, A>::getColumnCount() const
    {
        return columnCount_;
    }
    
    template <typename E, typename A>
    SizeType Matrix<E, A>::getElementCount() const
    {
        return getRowCount() * getColumnCount();
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::resize(SizeType rowCount, SizeType columnCount)
    {
        rowCount_ = rowCount;
        columnCount_ = columnCount;
        elements_.resize(getElementCount());
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::resize(SizeType rowCount, SizeType columnCount, const E& e)
    {
        rowCount_ = rowCount;
        columnCount_ = columnCount;
        elements_.resize(getElementCount(), e);

        return *this;
    }

    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::clear()
    {
        rowCount_ = 0;
        columnCount_ = 0;
        elements_.clear();
        
        return *this;
    }

    template <typename E, typename A>
    const E& Matrix<E, A>::get(SizeType index) const
    {
        assertIndexInRange(index);

        return elements_[index];
    }

    template <typename E, typename A>
    E& Matrix<E, A>::get(SizeType index)
    {
        return const_cast<E&>(const_cast<const Matrix<E,A>*>(this)->get(index));
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::set(SizeType index, const E& e)
    {
        assertIndexInRange(index);

        elements_[index] = e;

        return *this;
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::set(SizeType index, E&& e)
    {
        assertIndexInRange(index);

        elements_[index] = std::move(e);

        return *this;
    }
    
    template <typename E, typename A>
    const E& Matrix<E, A>::get(SizeType r, SizeType c) const
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        return elements_[r * columnCount_ + c];
    }

    template <typename E, typename A>
    E& Matrix<E, A>::get(SizeType r, SizeType c)
    {
        return const_cast<E&>(const_cast<const Matrix<E,A>*>(this)->get(r, c));
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::set(SizeType r, SizeType c, const E& e)
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        elements_[r * columnCount_ + c] = e;

        return *this;
    }
    
    template <typename E, typename A>
    Matrix<E, A>& Matrix<E, A>::set(SizeType r, SizeType c, E&& e)
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        elements_[r * columnCount_ + c] = std::move(e);

        return *this;
    }

    template <typename E, typename A>
    Matrix<E, A> Matrix<E, A>::getRowVector(SizeType index) const
    {
        assertRowIndexInRange(index);

        //TODO : 구현
        return Maxtrix<E>(1, columnCount_);
    }

    template <typename E, typename A>
    Matrix<E, A> Matrix<E, A>::getColumnVector(SizeType index) const
    {
        assertColumnIndexInRange(index);

        //TODO : 구현
        return Maxtrix<E>(rowCount_, 1);
    }

    template <typename E, typename A>
    const E* Matrix<E, A>::getElementPointer() const
    {
        return elements_.getElementPointer();
    }

    template <typename E, typename A>
    E* Matrix<E, A>::getElementPointer()
    {
        return elements_.getElementPointer();
    }

    template <typename E, typename A>
    void Matrix<E, A>::assertIndexInRange(SizeType index) const
    {
        if(index >= getElementCount()) {
            throw IndexOutOfRangeException();
        }
    }
    
    template <typename E, typename A>
    void Matrix<E, A>::assertRowIndexInRange(SizeType r) const
    {
        if(r >= rowCount_) {
            throw IndexOutOfRangeException();
        }
    }
    
    template <typename E, typename A>
    void Matrix<E, A>::assertColumnIndexInRange(SizeType c) const
    {
        if(c >= columnCount_) {
            throw IndexOutOfRangeException();
        }
    }
}
}

#endif
