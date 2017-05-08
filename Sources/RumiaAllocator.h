#pragma once
#include <cstdlib>
#define ALIGN_OF(...) __alignof(__VA_ARGS__)

namespace Rumia
{
    class Allocator
    {
    public:
        virtual ~Allocator( ) { }

        template <typename T, typename... Args>
        T* NewObject( Args&&... params )
        {
            T* newMemory = Allocate( sizeof( T ) );
            return new ( newMemory ) T( std::forward<Args>( params )... );
        }

        template <typename T>
        void DeleteObject( T* ptr )
        {
            ptr->~T( );
            DeallocateAligned( ptr, sizeof( T ), ALIGN_OF( T ) );
        }

        virtual void* Allocate( size_t size ) = 0;
        virtual void* AllocateAligned( size_t size, size_t align ) = 0;
        virtual void Deallocate( void* ptr ) = 0;
        virtual void DeallocateAligned( void* ptr, size_t size, size_t align ) = 0;

    };
}