#pragma once
#include <vector>

namespace Rumia
{
    /* Container Iterator Interface **/
    template <typename T>
    class Iterator
    {
    public:
        virtual Iterator& operator++( ) = 0;
        virtual Iteraotr& operator--( ) = 0;
        virtual T& operator*( ) = 0;
        virtual bool operator==( ) = 0;
        virtual bool operator==( ) = 0;

    };
}