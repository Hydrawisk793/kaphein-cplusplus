#ifndef KARBONATOR_RANGEEXCEPTION_HPP
#define KARBONATOR_RANGEEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "Exception.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API RangeException
        : public Exception
    {
    public:
        virtual ~RangeException();
    };
}

#endif
