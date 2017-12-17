#ifndef KAPHEIN_RANGEEXCEPTION_HPP
#define KAPHEIN_RANGEEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    class KAPHEIN_PP_DLL_API RangeException
        : public Exception
    {
    public:
        virtual ~RangeException();
    };
}

#endif
