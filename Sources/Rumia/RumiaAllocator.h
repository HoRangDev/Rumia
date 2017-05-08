#pragma once
#include <cstdlib>
#include <cassert>
#define ALIGN_OF(...) __alignof(__VA_ARGS__)

namespace Rumia
{
    class Allocator
    {
    public:
        virtual ~Allocator( ) { }

        template <typename T, typename... Args>
        T* NewObject( Args&&... params, size_t Align = ALIGN_OF( T ) )
        {
            T* newMemory = ( T* ) ( AllocateAligned( sizeof( T ), Align ) );
            return new ( newMemory ) T( std::forward<Args>( params )... );
        }

        template <typename T>
        void DeleteObject( T* ptr )
        {
            ptr->~T( );
            DeallocateAligned( ptr, sizeof( T ), ALIGN_OF( T ) );
        }

        template <typename T>
        T* NewObjectArray( size_t length, size_t Align = ALIGN_OF( T ) )
        {
            assert( length >= 1 );
            size_t headerSize = sizeof( size_t ) / sizeof( T );

            if ( sizeof( size_t ) % sizeof( T ) > 0 )
            {
                headerSize += 1;
            }
            
            T* origin = ( ( T* ) AllocateAligned( ( (sizeof( T ) * (length + headerSize )) ), Align ) );
            T* newMemory = origin + headerSize;
            *( ( ( size_t* ) ( newMemory - headerSize ) ) ) = length;

            for ( size_t index = 0; index < length; ++index )
            {
                new ( newMemory + index ) T;
            }

            return newMemory;
        }

        template <typename T>
        void DeleteObjectArray( T* array, size_t Align = ALIGN_OF( T ) )
        {
            assert( array != nullptr );
            size_t headerSize = sizeof( size_t ) / sizeof( T );
            if ( sizeof( size_t ) % sizeof( T ) > 0 )
            {
                headerSize += 1;
            }

            size_t length = *( ( ( size_t* ) ( array - headerSize ) ) );
            for ( size_t index = 0; index < length; ++index )
            {
                array[ index ].~T( );
            }
            DeallocateAligned( array - headerSize, ( sizeof( T ) * ( length + headerSize ) ), Align );
        }

        virtual void* Allocate( size_t size ) = 0;
        virtual void* AllocateAligned( size_t size, size_t align ) = 0;
        virtual void Deallocate( void* ptr ) = 0;
        virtual void DeallocateAligned( void* ptr, size_t size, size_t align ) = 0;

    };
}