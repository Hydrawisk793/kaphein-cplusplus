#ifndef KARBONATOR_INDEXOUTOFRANGEEXCEPTION_HPP
#define KARBONATOR_INDEXOUTOFRANGEEXCEPTION_HPP

#include "karbonator/pp/basic.hpp"
#include "RangeException.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API IndexOutOfRangeException
        : public RangeException
    {
    public:
        virtual ~IndexOutOfRangeException();
    };
}

#endif
