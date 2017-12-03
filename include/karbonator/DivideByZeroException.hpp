#ifndef KARBONATOR_DIVIDEBYZEROEXCEPTION_HPP
#define KARBONATOR_DIVIDEBYZEROEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "Exception.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API DivideByZeroException
        : public Exception
    {
    public:
        virtual ~DivideByZeroException();
    };
}

#endif
