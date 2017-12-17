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

#ifndef KAPHEIN_COLLECTION_ARRAYITERATORBASE_HPP
#define KAPHEIN_COLLECTION_ARRAYITERATORBASE_HPP

#include "kaphein/pp/basic.hpp"

namespace kaphein
{
namespace collection
{
    /**
     *  @brief A base class of array iterators.
     *  @since 2014-03-23
     */
    class KAPHEIN_PP_DLL_API ArrayIteratorBase
    {
    public:
        typedef PtrDiff difference_type;

    protected:
        ArrayIteratorBase();

        ArrayIteratorBase(const ArrayIteratorBase& src);

        ArrayIteratorBase(ArrayIteratorBase&& src);

        ArrayIteratorBase(const void* pStart, const void* pEnd);

        ArrayIteratorBase(const void* pStart, const void* pEnd, const void* pCurrent);

    public:
        virtual ~ArrayIteratorBase();

    protected:
        ArrayIteratorBase& operator =(const ArrayIteratorBase& rhs);

        ArrayIteratorBase& operator =(ArrayIteratorBase&& rhs);

    public:
        const void* getStart() const;

        const void* getEnd() const;

        const void* getCurrent() const;

    public:
        void moveToNext(SizeType elementSize);

        void moveToNext(SizeType elementSize, difference_type diff);

        void moveToPrevious(SizeType elementSize);

        void moveToPrevious(SizeType elementSize, difference_type diff);

        difference_type getDifference(const ArrayIteratorBase& rhs) const;

    public:
        bool equals(const ArrayIteratorBase& rhs) const;

        bool lessThan(const ArrayIteratorBase& rhs) const;

        bool lessThanOrEqualTo(const ArrayIteratorBase& rhs) const;

    private:
        void invalidateSelf();

    private:
        const char* pStart_;

        const char* pEnd_;

        const char* pCurrent_;
    };
}
}

#endif
