/*
 *  Copyright (c) Hydrawisk793
 *  All rights reserved.
 *
 *  This code is licensed under the MIT License.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files(the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions :
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef KAPHEIN_COLLECTION_VECTOR_INL
#define KAPHEIN_COLLECTION_VECTOR_INL

#include <utility>
#include <new>
#include "kaphein/RangeException.hpp"
#include "kaphein/IndexOutOfRangeException.hpp"
#include "kaphein/collection/ContainerUnderflowException.hpp"
#include "kaphein/collection/Vector.hpp"

namespace kaphein
{
namespace collection
{
    template <typename E, typename A>
    Vector<E, A>::Vector(A allocator)
        : pStart_(nullptr)
        , pEnd_(nullptr)
        , pTop_(nullptr)
        , allocator_(allocator)
    {
        constructContainer(Vector<E, A>::defaultCapacity);

        pTop_ = pStart_;
    }

    template <typename E, typename A>
    Vector<E, A>::Vector(const Vector<E, A>& src)
        : pStart_(nullptr)
        , pEnd_(nullptr)
        , pTop_(nullptr)
        , allocator_(src.allocator_)
    {
        constructContainer(src.getCapacity());

        const SizeType elementCount = src.getElementCount();
        const E* pSrc = src.pTop_;
        for(SizeType i = elementCount; i > 0; ) {
            --i;
            --pSrc;

            new (pStart_ + i) E(*pSrc);
        }
        pTop_ = pStart_ + elementCount;
    }

    template <typename E, typename A>
    Vector<E, A>::Vector(Vector<E, A>&& src)
        : pStart_(std::move(src.pStart_))
        , pEnd_(std::move(src.pEnd_))
        , pTop_(std::move(src.pTop_))
        , allocator_(std::move(src.allocator_))
    {
        src.invalidateSelf();
    }

    template <typename E, typename A>
    Vector<E, A>::Vector(SizeType elementCount, const E& e, A allocator)
        : pStart_(nullptr)
        , pEnd_(nullptr)
        , pTop_(nullptr)
        , allocator_(allocator)
    {
        constructContainer(elementCount);

        for(SizeType i = elementCount; i > 0; ) {
            --i;

            new (pStart_ + i) E(e);
        }
        pTop_ = pStart_ + elementCount;
    }

    template <typename E, typename A>
    Vector<E, A>::Vector(const E* pElements, SizeType elementCount, A allocator)
        : pStart_(nullptr)
        , pEnd_(nullptr)
        , pTop_(nullptr)
        , allocator_(allocator)
    {
        constructContainer(elementCount);

        const E* pSrc = pElements;
        const E* pEnd = pElements + elementCount;
        E* pDest = pStart_;
        for(; pSrc < pEnd; ++pSrc, ++pDest) {
            new (pDest) E(*pSrc);
        }
        pTop_ = pDest;
    }

    template <typename E, typename A>
    Vector<E, A>::Vector(E*&& pAllocatedElements, SizeType elementCount, A allocator)
        : pStart_(std::move(pAllocatedElements))
        , pEnd_(pStart_ + elementCount)
        , pTop_(pStart_ + elementCount)
        , allocator_(allocator)
    {
        pAllocatedElements = nullptr;
    }

    template <typename E, typename A>
    Vector<E, A>::~Vector()
    {
        if(pStart_ != nullptr) {
            clear();

            allocator_.deallocate(pStart_, getCapacity());

            invalidateSelf();
        }
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::operator =(const Vector<E, A>& rhs)
    {
        if(this != &rhs) {
            clear();

            const SizeType rhsCapacity = rhs.getCapacity();
            if(getCapacity() < rhsCapacity) {
                reserve(rhsCapacity);
            }
            
            const SizeType elementCount = rhs.getElementCount();
            pTop_ = pStart_ + elementCount;
            E* pDest = pTop_;
            const E* pSrc = rhs.pStart_ + elementCount;
            for(SizeType i = elementCount; i > 0; ) {
                --i;
                --pDest;
                --pSrc;

                *pDest = *pSrc;
            }
        }

        return *this;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::operator =(Vector<E, A>&& rhs)
    {
        if(this != &rhs) {
            pStart_ = std::move(rhs.pStart_);
            pEnd_ = std::move(rhs.pEnd_);
            pTop_ = std::move(rhs.pTop_);
            allocator_ = std::move(rhs.allocator_);

            rhs.invalidateSelf();
        }

        return *this;
    }

    template <typename E, typename A>
    typename Vector<E, A>::const_iterator Vector<E, A>::cbegin() const
    {
        return const_iterator(pStart_, pTop_);
    }

    template <typename E, typename A>
    typename Vector<E, A>::const_iterator Vector<E, A>::cend() const
    {
        return const_iterator(pTop_, pTop_);
    }

    template <typename E, typename A>
    typename Vector<E, A>::const_iterator Vector<E, A>::begin() const
    {
        return cbegin();
    }

    template <typename E, typename A>
    typename Vector<E, A>::iterator Vector<E, A>::begin()
    {
        return iterator(pStart_, pTop_);
    }

    template <typename E, typename A>
    typename Vector<E, A>::const_iterator Vector<E, A>::end() const
    {
        return cend();
    }

    template <typename E, typename A>
    typename Vector<E, A>::iterator Vector<E, A>::end()
    {
        return iterator(pTop_, pTop_);
    }
    
    template <typename E, typename A>
    bool Vector<E, A>::isEmpty() const
    {
        return pStart_ == pTop_;
    }

    template <typename E, typename A>
    SizeType Vector<E, A>::getElementCount() const
    {
        return pTop_ - pStart_;
    }

    template <typename E, typename A>
    SizeType Vector<E, A>::getCapacity() const
    {
        return pEnd_ - pStart_;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::reserve(SizeType size)
    {
        if(getCapacity() < size) {
            reconstructContainer(size);
        }

        return *this;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::resize(SizeType size)
    {
        if(!resizeByReducing(size) && size > getElementCount()) {
            resize(size, E());
        }

        return *this;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::resize(SizeType size, const E& e)
    {
        if(!resizeByReducing(size) && size > getElementCount()) {
            reserve(size);

            E* const pDestEnd = pStart_ + size;

            while(pTop_ < pDestEnd) {
                new (pTop_) E(e);
                ++pTop_;
            }
        }

        return *this;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::trim()
    {
        reconstructContainer(getElementCount());

        return *this;
    }

    template <typename E, typename A>
    const E& Vector<E, A>::operator [](SizeType index) const
    {
        return pStart_[index];
    }

    template <typename E, typename A>
    E& Vector<E, A>::operator [](SizeType index)
    {
        return const_cast<E&>(const_cast<const Vector<E, A>*>(this)->operator [](index));
    }

    template <typename E, typename A>
    const E& Vector<E, A>::at(SizeType index) const
    {
        assertIndexInRange(index);

        return (*this)[index];
    }

    template <typename E, typename A>
    E& Vector<E, A>::at(SizeType index)
    {
        assertIndexInRange(index);

        return (*this)[index];
    }

    template <typename E, typename A>
    const E* Vector<E, A>::getElementPointer() const
    {
        return pStart_;
    }
    
    template <typename E, typename A>
    E* Vector<E, A>::getElementPointer()
    {
        return const_cast<E*>(const_cast<const Vector<E, A>*>(this)->getElementPointer());
    }

    template <typename E, typename A>
    void Vector<E, A>::swap(Vector<E, A>& rhs)
    {
        //TODO : Deal with allocators...
        if(allocator_ != rhs.allocator_) {
            throw Exception();
            //A allocTemp = allocator_;
            //allocator_ = rhs.allocator_;
            //rhs.allocator_ = allocTemp;
        }

        E* temp;

        temp = pStart_;
        pStart_ = rhs.pStart_;
        rhs.pStart_ = temp;

        temp = pEnd_;
        pEnd_ = rhs.pEnd_;
        rhs.pEnd_ = temp;

        temp = pTop_;
        pTop_ = rhs.pTop_;
        rhs.pTop_ = temp;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::emplace(const_iterator iter, E&& e)
    {
        E* pDest = &const_cast<E&>(*(iter + 1));
        assertPointerInElements(pDest);

        pDest->~E();

        new (pDest) E(std::move(e));

        return *this;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::swapElements(iterator lhs, iterator rhs)
    {
        const E temp(*lhs);
        *lhs = *rhs;
        *rhs = temp;

        return *this;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::insert(const_iterator iter, const E& e)
    {
        expandIfFull(getElementCount() + 1);

        E* pDest = &const_cast<E&>(*(iter + 1));
        assertPointerInElements(pDest);

        shiftElementsToRight(pDest, pTop_);

        new (pDest) E(e);

        return *this;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::insert(const_iterator iter, E&& e)
    {
        expandIfFull(getElementCount() + 1);

        E* pDest = &const_cast<E&>(*(iter + 1));
        assertPointerInElements(pDest);

        shiftElementsToRight(pDest, pTop_);

        new (pDest) E(std::move(e));

        return *this;
    }
    
    //template <typename E, typename A>
    //template <typename Iter>
    //Vector<E, A>& Vector<E, A>::insert(const_iterator iter, Iter beginIter, Iter endIter)
    //{
    //    //TODO : 구현
    //}
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::remove(const_iterator iter)
    {
        assertIsNotEmpty();
        
        E* pElem = &const_cast<E&>(*iter);
        assertPointerInElements(pElem);

        pElem->~E();

        shiftElementsToLeft(pElem + 1, pTop_);

        return *this;
    }
    
    //template <typename E, typename A>
    //Vector<E, A>& Vector<E, A>::remove(const_iterator beginIter, const_iterator endIter)
    //{
    //    assertIsNotEmpty();

    //    //TODO : 구현

    //    return *this;
    //}
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::clear()
    {
        while(pTop_ > pStart_) {
            --pTop_;

            pTop_->~E();
        }

        return *this;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::pushFront(const E& e)
    {
        expandIfFull(getElementCount() + 1);

        shiftElementsToRight(pStart_, pTop_);

        new (pStart_) E(e);

        return *this;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::pushFront(E&& e)
    {
        expandIfFull(getElementCount() + 1);

        shiftElementsToRight(pStart_, pTop_);

        new (pStart_) E(std::move(e));

        return *this;
    }
    
    template <typename E, typename A>
    E Vector<E, A>::popFront()
    {
        assertIsNotEmpty();

        const E e(*pStart_);
        shiftElementsToLeft(pStart_ + 1, pTop_);
        --pTop_;

        return e;
    }
    
    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::pushBack(const E& e)
    {
        expandIfFull(getElementCount() + 1);

        new (pTop_) E(e);
        ++pTop_;

        return *this;
    }

    template <typename E, typename A>
    Vector<E, A>& Vector<E, A>::pushBack(E&& e)
    {
        expandIfFull(getElementCount() + 1);

        new (pTop_) E(std::move(e));
        ++pTop_;

        return *this;
    }
    
    template <typename E, typename A>
    E Vector<E, A>::popBack()
    {
        assertIsNotEmpty();

        const E e(*(--pTop_));
        pTop_->~E();

        return e;
    }

    template <typename E, typename A>
    bool Vector<E, A>::lessThan(const Vector<E, A>& rhs) const
    {
        const E* pLhs = pStart_;
        const E* pLhsEnd = pTop_;
        const E* pRhs = rhs.pStart_;
        const E* pRhsEnd = rhs.pTop_;

        for(
            ;
            pLhs != pLhsEnd && pRhs != pRhsEnd;
            ++pLhs, ++pRhs
        ) {
            if(*pLhs < *pRhs) {
                return true;
            }

            if(*pRhs < *pLhs) {
                return false;
            }
        }

        return (pLhs == pLhsEnd) && (pRhs != pRhsEnd);
    }

    template <typename E, typename A>
    bool operator ==(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        const SizeType elementCount = lhs.getElementCount();
        if(elementCount != rhs.getElementCount()) {
            return false;
        }

        for(SizeType i = elementCount; i > 0; ) {
            --i;

            if(!(lhs[i] == rhs[i])) {
                return false;
            }
        }

        return true;
    }

    template <typename E, typename A>
    bool operator !=(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename E, typename A>
    bool operator <(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        return lhs.lessThan(rhs);
    }
    
    template <typename E, typename A>
    bool operator >=(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        return !(lhs < rhs);
    }
    
    template <typename E, typename A>
    bool operator <=(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        //TODO : 구현 변경
        return (lhs < rhs || lhs == rhs);
    }
    
    template <typename E, typename A>
    bool operator >(const Vector<E, A>& lhs, const Vector<E, A>& rhs)
    {
        return !(lhs <= rhs);
    }

    template <typename E, typename A>
    E* Vector<E, A>::constructContainer(SizeType capacity)
    {
        pStart_ = allocator_.allocate(sizeof(E) * capacity);
        pEnd_ = pStart_ + capacity;

        return pStart_;
    }
    
    template <typename E, typename A>
    void Vector<E, A>::reconstructContainer(SizeType size)
    {
        const SizeType elementCount = getElementCount();
        if(size < elementCount) {
            throw RangeException();
        }

        E* pNewContainer = allocator_.allocate(size) + elementCount;

        while(pTop_ > pStart_) {
            --pTop_;
            --pNewContainer;

            new (pNewContainer) E(*pTop_);
            pTop_->~E();
        }

        pStart_ = pNewContainer;
        pTop_ = pNewContainer + elementCount;
        pEnd_ = pStart_ + size;
    }

    template <typename E, typename A>
    void Vector<E, A>::expandIfFull(SizeType n)
    {
        const SizeType capacity = getCapacity();
        if(capacity < n) {
            reserve(capacity << 1);
        }
    }

    template <typename E, typename A>
    bool Vector<E, A>::resizeByReducing(SizeType size)
    {
        const bool done = size < getElementCount();
        if(done) {
            E* const pBegin = pStart_ + size;

            while(pTop_ > pBegin) {
                --pTop_;
                pTop_->~E();
            }
        }

        return done;
    }

    template <typename E, typename A>
    void Vector<E, A>::shiftElementsToLeft(E* pBegin, E* pEnd)
    {
        assertInElementRange(pBegin, pEnd);

        E* pDest = pBegin - 1;
        for(
            ;
            pDest < pEnd;
            ++pBegin, ++pDest
        ) {
            pDest->~E();
            new (pDest) E(*pBegin);
        }

        pDest->~E();
    }

    template <typename E, typename A>
    void Vector<E, A>::shiftElementsToRight(E* pBegin, E* pEnd)
    {
        assertInElementRange(pBegin, pEnd);

        for(
            E* pDest = pEnd;
            pEnd > pBegin;
            --pDest
        ) {
            --pEnd;

            new (pDest) E(*pEnd);
            pEnd->~E();
        }
    }

    template <typename E, typename A>
    void Vector<E, A>::invalidateSelf()
    {
        pStart_ = nullptr;
        pEnd_ = pStart_;
        pTop_ = pStart_;
    }

    template <typename E, typename A>
    void Vector<E, A>::assertIndexInRange(SizeType index) const
    {
        if(index >= getElementCount()) {
            throw IndexOutOfRangeException();
        }
    }

    template <typename E, typename A>
    void Vector<E, A>::assertInElementRange(E* pBegin, E* pEnd) const
    {
        if(pBegin < pStart_ || pEnd > pTop_) {
            throw RangeException();
        }
    }

    template <typename E, typename A>
    void Vector<E, A>::assertIsNotEmpty() const
    {
        if(isEmpty()) {
            throw ContainerUnderflowException();
        }
    }

    template <typename E, typename A>
    void Vector<E, A>::assertPointerInElements(const E* p) const
    {
        if(p < pStart_ || p >= pTop_) {
            throw RangeException();
        }
    }
}
}

#endif
