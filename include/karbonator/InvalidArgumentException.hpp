#ifndef KARBONATOR_INVALIDARGUMENTEXCEPTION_HPP
#define KARBONATOR_INVALIDARGUMENTEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "Exception.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API InvalidArgumentException
        : public Exception
    {
    public:
        virtual ~InvalidArgumentException();
    };
}

#endif
