#ifndef KAPHEIN_UTILITY_UNROLLEDLOOP_HPP
#define KAPHEIN_UTILITY_UNROLLEDLOOP_HPP

#include "kaphein/pp/basic.hpp"

namespace kaphein
{
    namespace utility
    {
        /**
         *  @since 2016-06-18
         */
        template <
            SizeType End
            , SizeType Start = 0
            , SizeType Current = End - Start
        >
        struct UnrolledLoop
        {
            template <typename Callable>
            static void step(Callable callable);
        };

        /**
         *  @since 2016-06-18
         */
        template <
            SizeType End
            , SizeType Start
        >
        struct UnrolledLoop<End, Start, 0>
        {
            template <typename Callable>
            static void step(Callable callable);
        };
    }
}

#include "UnrolledLoop.inl"

#endif
