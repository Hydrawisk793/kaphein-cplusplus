#ifndef KAPHEIN_NOTIMPLEMENTEDMETHODEXCEPTION_HPP
#define KAPHEIN_NOTIMPLEMENTEDMETHODEXCEPTION_HPP

#include "pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    NotImplementedMethodException
        : public Exception
    {
    public:
        virtual ~NotImplementedMethodException();
    };
}

#endif
