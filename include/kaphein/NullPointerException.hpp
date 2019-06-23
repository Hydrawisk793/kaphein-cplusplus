#ifndef KAPHEIN_NULLPOINTEREXCEPTION_HPP
#define KAPHEIN_NULLPOINTEREXCEPTION_HPP

#include "pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    NullPointerException
        : public Exception
    {
    public:
        virtual ~NullPointerException();
    };
}

#endif
