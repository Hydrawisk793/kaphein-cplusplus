#include <utility>
#include "kaphein/RangeException.hpp"
#include "kaphein/collection/ArrayIteratorBase.hpp"

namespace kaphein
{
    namespace collection
    {
        ArrayIteratorBase::ArrayIteratorBase()
            : pStart_(nullptr)
            , pEnd_(nullptr)
            , pCurrent_(nullptr)
        {}

        ArrayIteratorBase::ArrayIteratorBase(const ArrayIteratorBase& src)
            : pStart_(src.pStart_)
            , pEnd_(src.pEnd_)
            , pCurrent_(src.pCurrent_)
        {}

        ArrayIteratorBase::ArrayIteratorBase(ArrayIteratorBase&& src)
            : pStart_(std::move(src.pStart_))
            , pEnd_(std::move(src.pEnd_))
            , pCurrent_(std::move(src.pCurrent_))
        {
            invalidateSelf();
        }

        ArrayIteratorBase::ArrayIteratorBase(const void* pStart, const void* pEnd)
            : pStart_(static_cast<const char*>(pStart))
            , pEnd_(static_cast<const char*>(pEnd))
            , pCurrent_(static_cast<const char*>(pStart))
        {
            if(pEnd < pStart) {
                throw RangeException();
            }
        }

        ArrayIteratorBase::ArrayIteratorBase(const void* pStart, const void* pEnd, const void* pCurrent)
            : pStart_(static_cast<const char*>(pStart))
            , pEnd_(static_cast<const char*>(pEnd))
            , pCurrent_(static_cast<const char*>(pCurrent))
        {
            if(pEnd < pStart) {
                throw RangeException();
            }

            if(pCurrent_ < pStart || pCurrent_ > pEnd_) {
                throw RangeException();            
            }
        }

        ArrayIteratorBase::~ArrayIteratorBase()
        {}

        ArrayIteratorBase& ArrayIteratorBase::operator =(const ArrayIteratorBase& rhs)
        {
            //if(this != &rhs) {
            //    return *this;
            //}

            pStart_ = rhs.pStart_;
            pEnd_ = rhs.pEnd_;
            pCurrent_ = rhs.pCurrent_;

            return *this;
        }

        ArrayIteratorBase& ArrayIteratorBase::operator =(ArrayIteratorBase&& rhs)
        {
            if(this != &rhs) {
                pStart_ = std::move(rhs.pStart_);
                pEnd_ = std::move(rhs.pEnd_);
                pCurrent_ = std::move(rhs.pCurrent_);
        
                rhs.invalidateSelf();
            }

            return *this;
        }

        const void* ArrayIteratorBase::getStart() const
        {
            return pStart_;
        }

        const void* ArrayIteratorBase::getEnd() const
        {
            return pEnd_;
        }

        const void* ArrayIteratorBase::getCurrent() const
        {
            return pCurrent_;
        }

        void ArrayIteratorBase::moveToNext(SizeType elementSize)
        {
            pCurrent_ += elementSize;

            if(pCurrent_ > pEnd_) {
                throw RangeException();
            }
        }

        void ArrayIteratorBase::moveToNext(SizeType elementSize, difference_type diff)
        {
            pCurrent_ += elementSize * diff;

            if(pCurrent_ > pEnd_) {
                throw RangeException();
            }
        }

        void ArrayIteratorBase::moveToPrevious(SizeType elementSize)
        {
            pCurrent_ -= elementSize;

            if(pCurrent_ > pStart_) {
                throw RangeException();
            }
        }

        void ArrayIteratorBase::moveToPrevious(SizeType elementSize, difference_type diff)
        {
            pCurrent_ -= elementSize * diff;

            if(pCurrent_ > pStart_) {
                throw RangeException();
            }
        }

        ArrayIteratorBase::difference_type ArrayIteratorBase::getDifference(const ArrayIteratorBase& rhs) const
        {
            return pCurrent_ - rhs.pCurrent_;
        }

        bool ArrayIteratorBase::equals(const ArrayIteratorBase& rhs) const
        {
            return pCurrent_ == rhs.pCurrent_;
        }

        bool ArrayIteratorBase::lessThan(const ArrayIteratorBase& rhs) const
        {
            return pCurrent_ < rhs.pCurrent_;
        }

        bool ArrayIteratorBase::lessThanOrEqualTo(const ArrayIteratorBase& rhs) const
        {
            return pCurrent_ <= rhs.pCurrent_;
        }

        void ArrayIteratorBase::invalidateSelf()
        {
            pStart_ = nullptr;
            pEnd_ = nullptr;
            pCurrent_ = nullptr;
        }
    }
}
