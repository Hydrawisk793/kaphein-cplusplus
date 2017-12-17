#ifndef KAPHEIN_RANGEEXCEPTION_HPP
#define KAPHEIN_RANGEEXCEPTION_HPP

#include "kaphein/pp/basic.hpp"
#include "Exception.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class KAPHEIN_PP_DLL_API RangeException
        : public Exception
    {
    public:
        virtual ~RangeException();
    };
}

#endif
