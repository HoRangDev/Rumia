#pragma once
#include <type_traits>
#include "DefaultAllocator.h"
#include <vector>

namespace Rumia
{
    /* Rumia::Array is Dynamic Array class **/
    template <typename T, typename TAllocator = Rumia::DefaultAllocator,
        typename IsBaseOfAllocator = std::enable_if<std::is_base_of<Rumia::Allocator, TAllocator>::value>::type>
        class Array
    {
    public:
        Array( TAllocator& allocator, size_t initCapacity = 2 ) :
            m_allocator( allocator ), m_elements( nullptr ), m_capacity( 0 ),
            m_size( 0 )
        {
            Reserve( initCapacity );
        }

        virtual ~Array( )
        {
            RUMIA_DELETE_ARRAY( m_allocator, m_elements );
        }

        T& operator[]( size_t index )
        {
            /* Out of range **/
            assert( index >= 0 && index < m_size );
            return ( m_elements[ index ] );
        }

        // const index operator
        T& operator[]( size_t index ) const
        {
            /* Out of range **/
            assert( index >= 0 && index < m_size );
            return ( m_elements[ index ] );
        }

        // copy operator
        Array& operator=( const Array& target )
        {
            RUMIA_DELETE_ARRAY( m_allocator, m_elements );

            // Change allocator
            m_allocator = target.m_allocator;

            // Reserve Memory space
            Reserve( target.m_capacity );

            // Copy elements
            for ( size_t index = 0; index < target.m_size; ++index )
            {
                m_elements[ index ] = target.m_elements[ index ];
            }
            m_size = target.m_size;

            return ( *this );
        }

        // move operator
        Array& operator=( Array&& target )
        {
            RUMIA_DELETE_ARRAY( m_allocator, m_elements );

            // Change allocator
            m_allocator = std::move( target.m_allocator );

            // Move element array
            m_elements = target.m_elements;
            m_capacity = target.m_capacity;
            m_size = target.m_size;

            return ( *this );
        }

        template <typename Ty>
        void Push( Ty&& element )
        {
            Growth( );
            m_elements[ m_size++ ] = std::forward<Ty>( element );
        }

        template <typename... Args>
        void Emplace( Args&&... params )
        {
            Growth( );
            m_elements[ m_size++ ] = T( std::forward<Args>( params )... );
        }

        T Pop( )
        {
            assert( m_size != 0 );
            return m_elements[ --m_size ];
        }

        void Reserve( size_t targetCapacity )
        {
            assert( targetCapacity != 0 && targetCapacity > m_capacity );
            if ( targetCapacity != m_capacity )
            {
                T* cachedElements = m_elements;
                m_elements = m_allocator.NewObjectArray<T>( targetCapacity );
                for ( size_t index = 0; index < m_size; ++index )
                {
                    m_elements[ index ] = std::move( cachedElements[ index ] );
                }

                RUMIA_DELETE_ARRAY( m_allocator, cachedElements );

                m_capacity = targetCapacity;
            }
        }

        void Clear( bool resetReserve = true )
        {
            if ( resetReserve )
            {
                m_capacity = 0;
                m_size = 0;
                RUMIA_DELETE_ARRAY( m_allocator, m_elements );
            }
            else
            {
                m_size = 0;
            }
        }

        inline size_t GetCapacity( ) const { return m_capacity; }
        inline size_t GetSize( ) const { return m_size; }

    protected:
        inline void Growth( )
        {
            if ( m_size == m_capacity )
            {
                Reserve( m_capacity * CapacityExtendScale );
            }
        }

    protected:
        TAllocator& m_allocator;

        /** Size of Element buffer */
        size_t m_capacity;

        /* Number of Elements **/
        size_t m_size;

        T* m_elements;

    protected:
        static const unsigned int CapacityExtendScale = 2;

    };
}