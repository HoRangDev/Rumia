#pragma once
#include <vector>

namespace Rumia
{
    /* Container Iterator Interface **/
    template <typename T>
    class Iterator
    {
    public:
        virtual ~Iterator( ) { }

        virtual Iterator& operator++( ) = 0;
        virtual Iterator& operator--( ) = 0;
        virtual T& operator*( ) = 0;
        virtual T& operator*( ) const = 0;

    };
}