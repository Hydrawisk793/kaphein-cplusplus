#ifndef KARBONATOR_UNSUPPORTEDMETHODEXCEPTION_HPP
#define KARBONATOR_UNSUPPORTEDMETHODEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/Exception.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API UnsupportedMethodException
        : public Exception
    {
    public:
        virtual ~UnsupportedMethodException();
    };
}

#endif
