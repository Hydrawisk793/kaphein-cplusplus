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
