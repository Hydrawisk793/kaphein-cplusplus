#include <utility>
#include <cstdlib>
#include "karbonator/collection/DynamicSizeArrayBase.hpp"

namespace karbonator
{
namespace collection
{
    DynamicSizeArrayBase::DynamicSizeArrayBase(SizeType byteCount)
        : pStart_(nullptr)
        , pEnd_(nullptr)
    {
        constructContainer(byteCount);
    }

    DynamicSizeArrayBase::DynamicSizeArrayBase(const DynamicSizeArrayBase& source)
        : pStart_(nullptr)
        , pEnd_(nullptr)
    {
        constructContainer(source.pEnd_ - source.pStart_);
    }

    DynamicSizeArrayBase::DynamicSizeArrayBase(DynamicSizeArrayBase&& source)
        : pStart_(std::move(source.pStart_))
        , pEnd_(std::move(source.pEnd_))
    {
        source.invalidateSelf();
    }

    DynamicSizeArrayBase::DynamicSizeArrayBase(void*&& pAllocatedElements, SizeType byteCount)
        : pStart_(std::move(static_cast<char*>(pAllocatedElements)))
        , pEnd_(pStart_ + byteCount)
    {
        pAllocatedElements = nullptr;
    }

    DynamicSizeArrayBase::~DynamicSizeArrayBase()
    {
        destructSelf();
    }

    DynamicSizeArrayBase& DynamicSizeArrayBase::operator =(const DynamicSizeArrayBase& rhs)
    {
        if(this != &rhs) {
            const SizeType rhsByteCount = rhs.getByteCount();
            if(getByteCount() != rhsByteCount) {
                destructSelf();

                constructContainer(rhsByteCount);
            }
        }

        return *this;
    }

    DynamicSizeArrayBase& DynamicSizeArrayBase::operator =(DynamicSizeArrayBase&& rhs)
    {
        pStart_ = std::move(rhs.pStart_);
        pEnd_ = std::move(rhs.pEnd_);

        rhs.invalidateSelf();

        return *this;
    }

    SizeType DynamicSizeArrayBase::getByteCount() const
    {
        return pEnd_ - pStart_;
    }

    const void* DynamicSizeArrayBase::getBytes() const
    {
        return pStart_;
    }

    void* DynamicSizeArrayBase::getBytes()
    {
        return const_cast<void*>(const_cast<const DynamicSizeArrayBase*>(this)->getBytes());
    }

    const void* DynamicSizeArrayBase::getElementBytes(SizeType elementIndex, SizeType elementSize) const
    {
        return pStart_ + elementIndex * elementSize;
    }

    void* DynamicSizeArrayBase::getElementBytes(SizeType elementIndex, SizeType elementSize)
    {
        return const_cast<void*>(const_cast<const DynamicSizeArrayBase*>(this)->getElementBytes(elementIndex, elementSize));
    }

    void DynamicSizeArrayBase::constructContainer(SizeType byteCount)
    {
        pStart_ = (char*)DynamicSizeArrayBase::allocate(byteCount);
        pEnd_ = pStart_ + byteCount;
    }

    void DynamicSizeArrayBase::destructSelf()
    {
        if(pStart_ != nullptr) {
            DynamicSizeArrayBase::free(pStart_);

            invalidateSelf();
        }
    }

    void DynamicSizeArrayBase::invalidateSelf()
    {
        pStart_ = nullptr;
        pEnd_ = nullptr;
    }

    void* DynamicSizeArrayBase::allocate(SizeType byteCount)
    {
        return std::malloc(byteCount);
    }

    void DynamicSizeArrayBase::free(void* target)
    {
        std::free(target);
    }
}
}
