#include <utility>
#include "kaphein/string/Utf8String.hpp"

namespace kaphein
{
namespace string
{
    //Utf8String Utf8String::fromUtf16Chars(UInt16* utf16Chars, SizeType elementCount);

    //Utf8String Utf8String::fromUcs4Chars(UInt32* ucs4Chars, SizeType charCount);

    Utf8String::Utf8String()
        : bytes_()
    {}

    Utf8String::Utf8String(const Utf8String& src)
        : bytes_(src.bytes_)
    {}

    Utf8String::Utf8String(Utf8String&& src)
        : bytes_(std::move(src.bytes_))
    {}

    Utf8String::Utf8String(const UInt8* utf8Bytes, SizeType byteCount)
        : bytes_(utf8Bytes, byteCount)
    {}

    Utf8String::Utf8String(const UInt16* utf16Elements, SizeType elementCount)
        : bytes_()
    {
        utf16Elements;
        elementCount;
        //TODO : 코드 작성
    }

    Utf8String::~Utf8String()
    {}
        
    Utf8String& Utf8String::operator =(const Utf8String& rhs)
    {
        bytes_ = rhs.bytes_;

        return *this;
    }

    Utf8String& Utf8String::operator =(Utf8String&& rhs)
    {
        bytes_ = std::move(rhs.bytes_);

        return *this;
    }

    //Utf8String::CharType Utf8String::operator [](SizeType index) const
    //{
    //    //Iterate all bytes....
    //    //What a shitload of fuck...
    //    //This requires O(n)...
    //}

    //Utf8String::CharType Utf8String::at(SizeType index) const
    //{
    //    //assertIndexInRange();
    //}

    //SizeType Utf8String::getByteCount() const
    //{
    //    return bytes_.getElementCount();
    //}

    //SizeType Utf8String::getElementCount() const
    //{
    //    //asdfasdf
    //}

    //int Utf8String::compareTo(const Utf8String& rhs) const
    //{
    //    const SizeType lhsCharCount = getCharCount();
    //    const SizeType rhsCharCount = rhs.getCharCount();


    //}

    //bool Utf8String::equals(const Utf8String& rhs) const
    //{
    //    
    //}

    //bool Utf8String::startsWith(const Utf8String& rhs) const
    //{
    //    
    //}

    //bool Utf8String::endsWith(const Utf8String& rhs) const
    //{
    //    
    //}
    //    
    //const Utf8String Utf8String::slice(SizeType begin, SizeType end) const
    //{
    //    
    //}

    //Utf8String& Utf8String::concatenate(const Utf8String& rhs);

    //Utf8String& Utf8String::padStart(SizeType count, CharType ch = 0x20);

    //Utf8String& Utf8String::padEnd(SizeType count, CharType ch = 0x20);
}
}
