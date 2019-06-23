#ifndef KAPHEIN_INDEXOUTOFRANGEEXCEPTION_HPP
#define KAPHEIN_INDEXOUTOFRANGEEXCEPTION_HPP

#include "pp/basic.hpp"
#include "RangeException.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    IndexOutOfRangeException
        : public RangeException
    {
    public:
        virtual ~IndexOutOfRangeException();
    };
}

#endif
