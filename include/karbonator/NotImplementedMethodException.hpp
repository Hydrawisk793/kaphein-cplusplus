#ifndef KARBONATOR_NOTIMPLEMENTEDMETHODEXCEPTION_HPP
#define KARBONATOR_NOTIMPLEMENTEDMETHODEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "karbonator/Exception.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API NotImplementedMethodException
        : public Exception
    {
    public:
        virtual ~NotImplementedMethodException();
    };
}

#endif
