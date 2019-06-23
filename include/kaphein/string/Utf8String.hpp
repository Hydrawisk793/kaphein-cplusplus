#ifndef KAPHEIN_STRING_UTF8STRING_HPP
#define KAPHEIN_STRING_UTF8STRING_HPP

#include <iterator>
#include "kaphein/pp/basic.hpp"
#include "kaphein/collection/Vector.hpp"

namespace kaphein
{
namespace string
{
    template class collection::Vector<UInt8>;

    /**
     *  @since 2017-05-13
     */
    class Utf8String
    {
    private:

    public:
        typedef UInt32 CharType;

    //private:

    //public:
    //    Utf8String fromUtf16Chars(UInt16* utf16Chars, SizeType elementCount);

    //    Utf8String fromUcs4Chars(UInt32* ucs4Chars, SizeType charCount);

    public:
        Utf8String();

        Utf8String(const Utf8String& src);

        Utf8String(Utf8String&& src);

        Utf8String(const UInt8* utf8Bytes, SizeType byteCount);

        Utf8String(const UInt16* utf16Elements, SizeType elementCount);

        virtual ~Utf8String();
        
        Utf8String& operator =(const Utf8String& rhs);

        Utf8String& operator =(Utf8String&& rhs);

    //public:
    //    CharType operator [](SizeType index) const;

    //    CharType at(SizeType index) const;

    //    SizeType getByteCount() const;

    //    SizeType getCharCount() const;

    //public:
    //    int compareTo(const Utf8String& rhs) const;

    //    bool equals(const Utf8String& rhs) const;

    //    bool startsWith(const Utf8String& rhs) const;

    //    bool endsWith(const Utf8String& rhs) const;

    //public:
    //    const Utf8String slice(SizeType begin, SizeType end) const;

    //    Utf8String& concatenate(const Utf8String& rhs);

    //    Utf8String& padStart(SizeType count, CharType ch = 0x20);

    //    Utf8String& padEnd(SizeType count, CharType ch = 0x20);

    private:
        collection::Vector<UInt8> bytes_;
    };
}
}

#endif
