#pragma once
#include <type_traits>
#include "DefaultAllocator.h"

namespace Rumia
{
    template <typename T, typename TAllocator = Rumia::DefaultAllocator, 
        typename IsBaseOfAllocator = std::enable_if<std::is_base_of<Rumia::Allocator, TAllocator>::value>::type>
    class Array
    {
    public:


    private:
        /** Size of Element buffer */
        unsigned int Capacity;

        /* Number of Elements **/
        unsigned int Size;

        T* Elements;

    private:
        constexpr unsigned int CapacityExtendScale = 2;
    };
}