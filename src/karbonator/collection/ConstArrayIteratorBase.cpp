#include <utility>
#include "karbonator/RangeException.hpp"
#include "karbonator/collection/ConstArrayIteratorBase.hpp"

namespace karbonator
{
namespace collection
{
    ConstArrayIteratorBase::ConstArrayIteratorBase()
        : pStart_(nullptr)
        , pEnd_(nullptr)
        , pCurrent_(nullptr)
    {}

    ConstArrayIteratorBase::ConstArrayIteratorBase(const ConstArrayIteratorBase& src)
        : pStart_(src.pStart_)
        , pEnd_(src.pEnd_)
        , pCurrent_(src.pCurrent_)
    {}

    ConstArrayIteratorBase::ConstArrayIteratorBase(ConstArrayIteratorBase&& src)
        : pStart_(std::move(src.pStart_))
        , pEnd_(std::move(src.pEnd_))
        , pCurrent_(std::move(src.pCurrent_))
    {
        invalidateSelf();
    }

    ConstArrayIteratorBase::ConstArrayIteratorBase(const void* pStart, const void* pEnd)
        : pStart_(static_cast<const char*>(pStart))
        , pEnd_(static_cast<const char*>(pEnd))
        , pCurrent_(static_cast<const char*>(pStart))
    {
        if(pEnd < pStart) {
            throw RangeException();
        }
    }

    ConstArrayIteratorBase::ConstArrayIteratorBase(const void* pStart, const void* pEnd, const void* pCurrent)
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

    ConstArrayIteratorBase::~ConstArrayIteratorBase()
    {}

    ConstArrayIteratorBase& ConstArrayIteratorBase::operator =(const ConstArrayIteratorBase& rhs)
    {
        //if(this != &rhs) {
        //    return *this;
        //}

        pStart_ = rhs.pStart_;
        pEnd_ = rhs.pEnd_;
        pCurrent_ = rhs.pCurrent_;

        return *this;
    }

    ConstArrayIteratorBase& ConstArrayIteratorBase::operator =(ConstArrayIteratorBase&& rhs)
    {
        if(this != &rhs) {
            pStart_ = std::move(rhs.pStart_);
            pEnd_ = std::move(rhs.pEnd_);
            pCurrent_ = std::move(rhs.pCurrent_);
        
            rhs.invalidateSelf();
        }

        return *this;
    }

    const void* ConstArrayIteratorBase::getStart() const
    {
        return pStart_;
    }

    const void* ConstArrayIteratorBase::getEnd() const
    {
        return pEnd_;
    }

    const void* ConstArrayIteratorBase::getCurrent() const
    {
        return pCurrent_;
    }

    void ConstArrayIteratorBase::moveToNext(SizeType elementSize)
    {
        pCurrent_ += elementSize;

        if(pCurrent_ > pEnd_) {
            throw RangeException();
        }
    }

    void ConstArrayIteratorBase::moveToNext(SizeType elementSize, PtrDiff diff)
    {
        pCurrent_ += elementSize * diff;

        if(pCurrent_ > pEnd_) {
            throw RangeException();
        }
    }

    void ConstArrayIteratorBase::moveToPrevious(SizeType elementSize)
    {
        pCurrent_ -= elementSize;

        if(pCurrent_ > pStart_) {
            throw RangeException();
        }
    }

    void ConstArrayIteratorBase::moveToPrevious(SizeType elementSize, PtrDiff diff)
    {
        pCurrent_ -= elementSize * diff;

        if(pCurrent_ > pStart_) {
            throw RangeException();
        }
    }

    PtrDiff ConstArrayIteratorBase::getDifference(const ConstArrayIteratorBase& rhs) const
    {
        return pCurrent_ - rhs.pCurrent_;
    }

    bool ConstArrayIteratorBase::equals(const ConstArrayIteratorBase& rhs) const
    {
        return pCurrent_ == rhs.pCurrent_;
    }

    bool ConstArrayIteratorBase::lessThan(const ConstArrayIteratorBase& rhs) const
    {
        return pCurrent_ < rhs.pCurrent_;
    }

    bool ConstArrayIteratorBase::lessThanOrEqualTo(const ConstArrayIteratorBase& rhs) const
    {
        return pCurrent_ <= rhs.pCurrent_;
    }

    void ConstArrayIteratorBase::invalidateSelf()
    {
        pStart_ = nullptr;
        pEnd_ = nullptr;
        pCurrent_ = nullptr;
    }
}
}
