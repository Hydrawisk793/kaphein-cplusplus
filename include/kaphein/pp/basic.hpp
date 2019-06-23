#ifndef KAPHEIN_PP_BASIC_HPP
#define KAPHEIN_PP_BASIC_HPP

#include <cstddef>
#include <cstdint>
#include <kaphein/def.h>

#if defined(_MSC_VER) && _MSC_VER >= 1600
    #define nullptr nullptr
#elif defined(__GNUG__)
    #define nullptr nullptr
#else
    #define nullptr (0)
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1600
    #define KAPHEIN_PP_RIGHT_REF_SUPPORTED 1
#elif defined(__GNUG__)
    #define KAPHEIN_PP_RIGHT_REF_SUPPORTED 1
#else
    #define KAPHEIN_PP_RIGHT_REF_SUPPORTED 0
#endif

#if defined(_MSC_VER)
    #if _MSC_VER >= 1700
        #define final final
    #elif _MSC_VER >= 1500
        #define final sealed
    #else
        #define final
    #endif
#elif defined(__GNUG__)
    #define final final
#else
    #define final
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1700
    #define EXPLICIT_CAST explicit
#elif defined(__GNUG__)
    #define EXPLICIT_CAST explicit
#else
    #define EXPLICIT_CAST
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1700
    #define KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED 1
#elif defined(__GNUG__)
    #define KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED 1
#else
    #define KAPHEIN_PP_IS_CONSTEXPR_SUPPORTED 0
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1700
    #define KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED 1
#elif defined(__GNUG__)
    #define KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED 1
#else
    #define KAPHEIN_PP_IS_INITIALIZER_LIST_SUPPORTED 0
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1900
    #define KAPHEIN_PP_DEFAULTED_AND_DELETED_FUNCTIONS_SUPPORTED 1
#elif defined(__GNUG__)
    #define KAPHEIN_PP_DEFAULTED_AND_DELETED_FUNCTIONS_SUPPORTED 1
#else
    #define KAPHEIN_PP_DEFAULTED_AND_DELETED_FUNCTIONS_SUPPORTED 0
#endif

#define KAPHEIN_x_EXPAND(x) x
#define KAPHEIN_PP_x_EXPAND(x) x
#define KAPHEIN_PP_x_VARIADIC_SELECT_LAST_ARGUMENT( \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
    _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, \
    _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, \
    _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, \
    _91, _92, _93, _94, _95, _96, _97, _98, _99, _100, \
    _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, \
    _111, _112, _113, _114, _115, _116, _117, _118, _119, N, ... \
) N
#define KAPHEIN_PP_x_VARIADIC_REVERSED_ARGUMENT_COUNTS() \
    119, 118, 117, 116, 115, 114, 113, 112, 111, 110, \
    109, 108, 107, 106, 105, 104, 103, 102, 101, 100, \
    99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
    89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
    79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
    69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_EXPAND(...) \
    KAPHEIN_PP_x_EXPAND( \
        KAPHEIN_PP_x_VARIADIC_SELECT_LAST_ARGUMENT(__VA_ARGS__) \
    )
#define KAPHEIN_PP_x_COMMA_REVERSED_SEQUENCE() \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0
#define KAPHEIN_PP_x_COMMA(...) ,
#define KAPHEIN_PP_x_HAS_COMMA(...) \
    KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_EXPAND( \
        __VA_ARGS__, \
        KAPHEIN_PP_x_COMMA_REVERSED_SEQUENCE() \
    )
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH01(N) 0
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH00(N) 1
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH11(N) N
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH(a, b, N) \
    KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH##a##b(N)
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_EXPAND_MACRO_ARGUMENTS(a, b, N) \
    KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_BRANCH(a, b, N)
#define KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT(...) \
    KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_EXPAND_MACRO_ARGUMENTS( \
        KAPHEIN_PP_x_HAS_COMMA(__VA_ARGS__), \
        KAPHEIN_PP_x_HAS_COMMA(KAPHEIN_PP_x_COMMA __VA_ARGS__ ()), \
        KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT_EXPAND( \
            __VA_ARGS__, \
            KAPHEIN_PP_x_VARIADIC_REVERSED_ARGUMENT_COUNTS() \
        ) \
    )
#define KAPHEIN_PP_GET_ARGUMENT_COUNT(...) \
    KAPHEIN_PP_x_VARIADIC_ARGUMENT_COUNT(__VA_ARGS__)

namespace kaphein
{
    typedef std::size_t SizeType;

    typedef std::int8_t Int8;

    typedef std::uint8_t UInt8;

    typedef std::int16_t Int16;

    typedef std::uint16_t UInt16;

    typedef std::int32_t Int32;

    typedef std::uint32_t UInt32;

    typedef std::int64_t Int64;

    typedef std::uint64_t UInt64;

    typedef std::ptrdiff_t PtrDiff;
}

#endif
