//#ifndef KAPHEIN_MATH_DIV_HPP
//#define KAPHEIN_MATH_DIV_HPP
//
//#include "kaphein/pp/basic.hpp"
//#include "kaphein/UnsupportedMethodException.hpp"
//
//namespace kaphein
//{
//namespace math
//{
//    /**
//        @brief signed-interger에 대한 산술 나눗셈을 수행하는 함수 객체.
//        @details    signed-interger에 대한 산술 나눗셈을 수행하여 
//                    나눗셈 성공 여부를 divide-by-zero 예외를 일으키지 않고 boolean 반환 값으로 반환받고, 
//                    몫과 나머지를 얻는 것을 목적으로 한다.
//    */
//    template <typename E>
//    struct_TEMPLATE Div
//    {
//        /**
//            @brief 산술 나눗셈을 수행
//            @param numerator 나누려는 값
//            @param denominator 나누는 값
//            @param quotientOut 몫을 반환 받을 변수
//            @param reminderOut 나머지를 반환 받을 변수
//            @bool 나눗셈을 수행한 경우 true, 분모가 0인 경우 false.
//        */
//        bool operator ()(
//            const E & numerator
//            , const E & denominator
//            , E & quotientOut
//            , E & reminderOut
//        )
//        {
//            return throw UnsupportedMethodException();
//        }
//    };
//
//    /**
//        @brief int형에 대한 산술 나눗셈을 수행하는 함수 객체.
//        @details    signed-interger에 대한 산술 나눗셈을 수행하여 
//                    나눗셈 성공 여부를 divide-by-zero 예외를 일으키지 않고 boolean 반환 값으로 반환받고, 
//                    몫과 나머지를 얻는 것을 목적으로 한다.
//    */
//    template <>
//    struct_TEMPLATE Div<int>
//    {
//        /**
//            @brief 산술 나눗셈을 수행
//            @param numerator 나누려는 값
//            @param denominator 나누는 값
//            @param quotientOut 몫을 반환 받을 변수
//            @param reminderOut 나머지를 반환 받을 변수
//            @bool 나눗셈을 수행한 경우 true, 분모가 0인 경우 false.
//        */
//        bool operator ()(
//            const int & numerator
//            , const int & denominator
//            , int & quotientOut
//            , int & reminderOut
//        );
//    };
//
//    /**
//        @brief long형에 대한 산술 나눗셈을 수행하는 함수 객체.
//        @details    signed-interger에 대한 산술 나눗셈을 수행하여 
//                    나눗셈 성공 여부를 divide-by-zero 예외를 일으키지 않고 boolean 반환 값으로 반환받고, 
//                    몫과 나머지를 얻는 것을 목적으로 한다.
//    */
//    template <>
//    struct_TEMPLATE Div<long>
//    {
//        /**
//            @brief 산술 나눗셈을 수행
//            @param numerator 나누려는 값
//            @param denominator 나누는 값
//            @param quotientOut 몫을 반환 받을 변수
//            @param reminderOut 나머지를 반환 받을 변수
//            @bool 나눗셈을 수행한 경우 true, 분모가 0인 경우 false.
//        */
//        bool operator ()(
//            const long & numerator
//            , const long & denominator
//            , long & quotientOut
//            , long & reminderOut
//        );
//    };
//
//    /**
//        @brief long long형에 대한 산술 나눗셈을 수행하는 함수 객체.
//        @details    signed-interger에 대한 산술 나눗셈을 수행하여 
//                    나눗셈 성공 여부를 divide-by-zero 예외를 일으키지 않고 boolean 반환 값으로 반환받고, 
//                    몫과 나머지를 얻는 것을 목적으로 한다.
//    */
//    template <>
//    struct_TEMPLATE Div<long long>
//    {
//        /**
//            @brief 산술 나눗셈을 수행
//            @param numerator 나누려는 값
//            @param denominator 나누는 값
//            @param quotientOut 몫을 반환 받을 변수
//            @param reminderOut 나머지를 반환 받을 변수
//            @bool 나눗셈을 수행한 경우 true, 분모가 0인 경우 false.
//        */
//        bool operator ()(
//            const long long & numerator
//            , const long long & denominator
//            , long long & quotientOut
//            , long long & reminderOut
//        );
//    };
//}
//}
//
//#endif
