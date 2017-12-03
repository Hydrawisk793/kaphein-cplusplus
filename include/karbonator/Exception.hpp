#ifndef KARBONATOR_EXCEPTION_HPP
#define KARBONATOR_EXCEPTION_HPP

#include "karbonator/pp/basic.hpp"

namespace karbonator
{
    class KARBONATOR_PP_DLL_API Exception
    {
    public:
        Exception();

        Exception(const Exception& o);

        Exception(Exception&& o);

        virtual ~Exception();

    public:
        Exception& operator =(const Exception& rhs);

        Exception& operator =(Exception&& rhs);
    };
}

#endif
