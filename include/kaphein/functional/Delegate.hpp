#ifndef KAPHEIN_FUNCTIONAL_DELEGATE_HPP
#define KAPHEIN_FUNCTIONAL_DELEGATE_HPP

#include <utility>
#include "kaphein/Exception.hpp"
#include "kaphein/RangeException.hpp"
#include "kaphein/collection/Vector.hpp"
#include "kaphein/functional/Function.hpp"

namespace kaphein
{
namespace functional
{
#define KAPHEIN_xx_TYPE_PARAMETER(...) \
    R ( \
        KAPHEIN_x_MAKE_LIST(__VA_ARGS__) \
    )

#define KAPHEIN_xx_THIS_TYPE(...) \
    Delegate< \
        KAPHEIN_xx_TYPE_PARAMETER(__VA_ARGS__) \
    >

    template <typename>
    class Delegate;

    template <
        typename R
        KAPHEIN_x_MAKE_OPTIONAL_TYPENAME_LIST(A1, A2, A3, A4)
    >
    class Delegate<KAPHEIN_xx_TYPE_PARAMETER(A1, A2, A3, A4)>
    {
    public:
        typedef Function<
            KAPHEIN_xx_TYPE_PARAMETER(A1, A2, A3, A4)
        > FunctionType;

        typedef typename collection::Vector<FunctionType>::const_iterator const_iterator;

        typedef typename collection::Vector<FunctionType>::iterator iterator;

    public:
        Delegate()
            : functions_()
        {}

        Delegate(
            const KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)& src
        )
            : functions_(src.functions_)
        {}

        Delegate(
            KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)&& src
        )
            : functions_(std::move(src.functions_))
        {}

        ~Delegate()
        {}

        KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)& operator =(
            const KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)& rhs
        )
        {
            functions_ = rhs.functions_;

            return *this;
        }

        KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)& operator =(
            KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)&& rhs
        )
        {
            functions_ = std::move(rhs.functions_);

            return *this;
        }

    public:
        const_iterator bind(
            typename FunctionType::FreeFunctionPtrType pFreeFunc
        )
        {
            functions_.pushBack(FunctionType(pFreeFunc));

            return --functions_.cend();
        }

        template <typename E>
        const_iterator bind(
            E& obj
            , typename FunctionType::MethodPtrTypeSelector<E>::type pMethod
        )
        {
            functions_.pushBack(FunctionType(obj, pMethod));

            return --functions_.cend();
        }

        template <typename Callable>
        const_iterator bind(
            Callable callable
        )
        {
            functions_.pushBack(FunctionType(callable));

            return --functions_.cend();
        }

        const_iterator bind(
            const FunctionType& func
        )
        {
            functions_.pushBack(func);

            return --functions_.cend();
        }

        const_iterator bind(
            FunctionType&& func
        )
        {
            functions_.pushBack(std::move(func));

            return --functions_.cend();
        }

        const_iterator unbind(const_iterator dest)
        {
            const const_iterator cb = functions_.cbegin();
            if(cb < dest || functions_.cend() >= dest) {
                throw RangeException();
            }

            const auto diff = dest - cb;

            functions_.remove(dest);

            return functions_.cbegin() + diff;
        }

        KAPHEIN_xx_THIS_TYPE(A1, A2, A3, A4)& clear()
        {
            functions_.clear();

            return *this;
        }

        bool isNull() const
        {
            return functions_.isEmpty();
        }

        R operator ()(
            KAPHEIN_x_MAKE_ARGUMENT_LIST(A1, A2, A3, A4)
        )
        {
            if(isNull()) {
                throw Exception();
            }

            const typename collection::Vector<FunctionType>::iterator endIter = functions_.end();
            typename collection::Vector<FunctionType>::iterator iter = functions_.begin();
            typename collection::Vector<FunctionType>::iterator nextIter = iter;
            ++nextIter;
            for(; ; ) {
                if(nextIter == endIter) {
                    return (*iter)(
                        KAPHEIN_x_MAKE_ARGVAR_LIST(A1, A2, A3, A4)
                    );
                }
                else {
                    (*iter)(
                        KAPHEIN_x_MAKE_ARGVAR_LIST(A1, A2, A3, A4)
                    );
                }

                ++iter;
                ++nextIter;
            }
        }
        
        collection::Vector<R> callAndGetAllResults(
            KAPHEIN_x_MAKE_ARGUMENT_LIST(A1, A2, A3, A4)
        )
        {
            if(isNull()) {
                throw Exception();
            }

            collection::Vector<R> results;
            const typename collection::Vector<FunctionType>::iterator endIter = functions_.end();
            typename collection::Vector<FunctionType>::iterator iter = functions_.begin();
            results.reserve(endIter - iter);

            for(; iter != endIter; ++iter) {
                results.pushBack(
                    (*iter)(
                        KAPHEIN_x_MAKE_ARGVAR_LIST(A1, A2, A3, A4)
                    )
                );
            }

            return results;
        }

    private:
        collection::Vector<FunctionType> functions_;
    };

//#undef KAPHEIN_xx_THIS_TYPE
//#undef KAPHEIN_xx_TYPE_PARAMETER
}
}

#endif
