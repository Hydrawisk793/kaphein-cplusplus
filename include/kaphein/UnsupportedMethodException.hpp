#ifndef KAPHEIN_UNSUPPORTEDMETHODEXCEPTION_HPP
#define KAPHEIN_UNSUPPORTEDMETHODEXCEPTION_HPP

#include "pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    UnsupportedMethodException
        : public Exception
    {
    public:
        virtual ~UnsupportedMethodException();
    };
}

#endif
