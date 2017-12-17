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

//#ifndef KAPHEIN_COLLECTION_LIST_HPP
//#define KAPHEIN_COLLECTION_LIST_HPP
//
//#include "kaphein/cplusplus/pp/basic.hpp"
//#include "kaphein/cplusplus/memory/DefaultAllocator.hpp"
//
//namespace kaphein
//{
//namespace collection
//{
//    template <
//        typename E
//        , typename A = memory::DefaultAllocator<E>
//    >
//    class List
//    {
//    public:
//        typedef E ElementType;
//
//        typedef A AllocatorType;
//
//    private:
//        struct Node
//        {
//            Node* pPrev_;
//
//            Node* pNext_;
//        };
//
//    public:
//        List(A allocator = A());
//
//        List(const List<E, A>& src);
//
//        List(List<E, A>&& src);
//
//        List(SizeType elementCount, const E& e = E(), A allocator = A());
//
//        List(const E* pElements, SizeType elementCount, A allocator = A());
//
//        virtual ~List();
//
//        List<E, A>& operator =(const List<E, A>& rhs);
//
//        List<E, A>& operator =(List<E, A>&& rhs);
//
//    public:
//        const_iterator cbegin() const;
//
//        const_iterator cend() const;
//
//        const_iterator begin() const;
//
//        iterator begin();
//
//        const_iterator end() const;
//
//        iterator end();
//
//    public:
//        bool isEmpty() const;
//
//        SizeType getElementCount() const;
//
//        List<E, A>& resize(SizeType size);
//        
//        List<E, A>& resize(SizeType size, const E& e);
//
//    public:
//        const E& operator [](SizeType index) const;
//
//        E& operator [](SizeType index);
//
//        const E& at(SizeType index) const;
//
//        E& at(SizeType index);
//        
//    public:
//        List<E, A>& set(const_iterator iter, const E& e);
//
//        List<E, A>& set(const_iterator iter, E&& e);
//
//        List<E, A>& swapElements(iterator lhs, iterator rhs);
//
//        List<E, A>& insert(const_iterator iter, const E& e);
//
//        List<E, A>& insert(const_iterator iter, E&& e);
//
//        template <typename Iter>
//        List<E, A>& insert(const_iterator iter, Iter beginIter, Iter endIter);
//
//        List<E, A>& remove(const_iterator iter);
//
//        List<E, A>& remove(const_iterator beginIter, const_iterator endIter);
//
//        List<E, A>& clear();
//
//        List<E, A>& pushFront(const E& e);
//
//        List<E, A>& pushFront(E&& e);
//
//        E popFront();
//
//        List<E, A>& pushBack(const E& e);
//
//        List<E, A>& pushBack(E&& e);
//
//        E popBack();
//
//    private:
//        Node* pHead_;
//
//        Node* pTail_;
//
//        A allocator_;
//    };
//}
//}
//
//#endif
