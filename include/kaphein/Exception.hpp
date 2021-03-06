#ifndef KAPHEIN_EXCEPTION_HPP
#define KAPHEIN_EXCEPTION_HPP

#include "pp/basic.hpp"

namespace kaphein
{
    /**
     *  @since 2014-03-23
     */
    class
    KAPHEIN_ATTRIBUTE_DLL_API
    Exception
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
