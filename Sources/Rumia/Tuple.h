#pragma once

namespace Rumia
{
    template <typename Ty, typename... Rest>
    class Tuple : public Tuple<Rest...>
    {
    public:
        Tuple( Ty data, Rest... rest ) : Tuple<Rest...>( rest... ), m_data( data )
        {
        }

    public:
        Ty m_data;

    };

    template <typename Ty>
    class Tuple<Ty>
    {
    public:
        Tuple( Ty data ) : m_data( data )
        {
        }

    public:
        Ty m_data;

    };

    template <int index, typename Ty, typename... Rest>
    class GetImpl
    {
    public:
        static decltype( auto ) value( const Tuple<Ty, Rest...>& tuple )
        {
            return GetImpl< index - 1, Rest...>::value( tuple );
        }
    };

    template <typename Ty, typename... Rest>
    class GetImpl<0, Ty, Rest...>
    {
    public:
        static Ty value( const Tuple<Ty, Rest...>& tuple )
        {
            return tuple.m_data;
        }
    };

    template <int index, typename Ty, typename... Rest>
    decltype( auto ) Get( const Tuple<Ty, Rest...>& tuple )
    {
        return GetImpl<index, Ty, Rest...>::value( tuple );
    }
}
