//#ifndef KAPHEIN_COLLECTION_LIST_HPP
//#define KAPHEIN_COLLECTION_LIST_HPP
//
//#include "kaphein/pp/basic.hpp"
//#include "kaphein/memory/DefaultAllocator.hpp"
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
