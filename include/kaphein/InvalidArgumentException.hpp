#ifndef KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP
#define KAPHEIN_INVALIDARGUMENTEXCEPTION_HPP

#include "pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    InvalidArgumentException
        : public Exception
    {
    public:
        virtual ~InvalidArgumentException();
    };
}

#endif
