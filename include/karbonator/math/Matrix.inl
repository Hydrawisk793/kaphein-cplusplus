#ifndef KARBONATOR_MATH_MATRIX_INL
#define KARBONATOR_MATH_MATRIX_INL

#include <utility>
#include <cstdlib>
#include <cstring>
#include "karbonator/IndexOutOfRangeException.hpp"
#include "karbonator/InvalidArgumentException.hpp"
#include "karbonator/math/Matrix.hpp"

namespace karbonator
{
namespace math
{
    template <typename E>
    Matrix<E>::Matrix()
        : rowCount_(0)
        , columnCount_(0)
        , elements_(getElementCount())
    {}

    template <typename E>
    Matrix<E>::Matrix(const Matrix<E>& o)
        : rowCount_(o.rowCount_)
        , columnCount_(o.columnCount_)
        , elements_(o.elements_)
    {}

    template <typename E>
    Matrix<E>::Matrix(Matrix<E>&& o)
        : rowCount_(std::move(o.rowCount_))
        , columnCount_(std::move(o.columnCount_))
        , elements_(std::move(o.elements_))
    {}

    template <typename E>
    Matrix<E>::Matrix<E>(SizeType rowCount, SizeType columnCount, const E& defaultValue)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(getElementCount(), defaultValue)
    {}
    
    template <typename E>
    Matrix<E>::Matrix(const E* pElements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(pElements, getElementCount())
    {}
    
    template <typename E>
    Matrix<E>::Matrix(const collection::DynamicSizeArray<E>& elements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(elements)
    {
        if(getElementCount() != elements.getElementCount()) {
            throw InvalidArgumentException();
        }
    }

    template <typename E>
    Matrix<E>::Matrix(collection::DynamicSizeArray<E>&& elements, SizeType rowCount, SizeType columnCount)
        : rowCount_(rowCount)
        , columnCount_(columnCount)
        , elements_(std::move(elements))
    {
        if(getElementCount() != elements.getElementCount()) {
            throw InvalidArgumentException();
        }
    }

    template <typename E>
    Matrix<E>::~Matrix()
    {}
    
    template <typename E>
    Matrix<E>& Matrix<E>::operator =(const Matrix<E>& rhs)
    {
        if(this != &rhs) {
            rowCount_ = rhs.rowCount_;
            columnCount_ = rhs.columnCount_;
            elements_ = rhs.elements_;
        }

        return *this;
    }
    
    template <typename E>
    Matrix<E>& Matrix<E>::operator =(Matrix<E>&& rhs)
    {
        if(this != &rhs) {
            rowCount_ = std::move(rhs.rowCount_);
            columnCount_ = std::move(rhs.columnCount_);
            elements_ = std::move(rhs.elements_);
        }

        return *this;
    }

    template <typename E>
    SizeType Matrix<E>::getRowCount() const
    {
        return rowCount_;
    }
    
    template <typename E>
    SizeType Matrix<E>::getColumnCount() const
    {
        return columnCount_;
    }
    
    template <typename E>
    SizeType Matrix<E>::getElementCount() const
    {
        return getRowCount() * getColumnCount();
    }

    template <typename E>
    const E& Matrix<E>::get(SizeType index) const
    {
        assertIndexInRange(index);

        return elements_[index];
    }
    
    template <typename E>
    Matrix<E>& Matrix<E>::set(SizeType index, const E& e)
    {
        assertIndexInRange(index);

        elements_[index] = e;

        return *this;
    }
    
    template <typename E>
    Matrix<E>& Matrix<E>::set(SizeType index, E&& e)
    {
        assertIndexInRange(index);

        elements_[index] = std::move(e);

        return *this;
    }
    
    template <typename E>
    const E& Matrix<E>::get(SizeType r, SizeType c) const
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        return elements_[r * columnCount_ + c];
    }
    
    template <typename E>
    Matrix<E>& Matrix<E>::set(SizeType r, SizeType c, const E& e)
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        elements_[r * columnCount_ + c] = e;

        return *this;
    }
    
    template <typename E>
    Matrix<E>& Matrix<E>::set(SizeType r, SizeType c, E&& e)
    {
        assertRowIndexInRange(r);
        assertColumnIndexInRange(c);

        elements_[r * columnCount_ + c] = std::move(e);

        return *this;
    }

    template <typename E>
    Matrix<E> Matrix<E>::getRowVector(SizeType index) const
    {
        assertRowIndexInRange(index);

        //TODO : 구현
        return Maxtrix<E>(1, columnCount_);
    }

    template <typename E>
    Matrix<E> Matrix<E>::getColumnVector(SizeType index) const
    {
        assertColumnIndexInRange(index);

        //TODO : 구현
        return Maxtrix<E>(rowCount_, 1);
    }

    template <typename E>
    void Matrix<E>::assertIndexInRange(SizeType index) const
    {
        if(index >= getElementCount()) {
            throw IndexOutOfRangeException();
        }
    }
    
    template <typename E>
    void Matrix<E>::assertRowIndexInRange(SizeType r) const
    {
        if(r >= rowCount_) {
            throw IndexOutOfRangeException();
        }
    }
    
    template <typename E>
    void Matrix<E>::assertColumnIndexInRange(SizeType c) const
    {
        if(c >= columnCount_) {
            throw IndexOutOfRangeException();
        }
    }
}
}

#endif
