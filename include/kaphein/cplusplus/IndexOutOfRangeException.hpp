#ifndef KAPHEIN_INDEXOUTOFRANGEEXCEPTION_HPP
#define KAPHEIN_INDEXOUTOFRANGEEXCEPTION_HPP

#include "kaphein/cplusplus/pp/basic.hpp"
#include "RangeException.hpp"

namespace kaphein
{
    class KAPHEIN_PP_DLL_API IndexOutOfRangeException
        : public RangeException
    {
    public:
        virtual ~IndexOutOfRangeException();
    };
}

#endif
