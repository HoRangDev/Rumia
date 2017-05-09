#pragma once
#include <type_traits>
#include "DefaultAllocator.h"
#include <list>

namespace Rumia
{
    template <typename T>
    struct Node
    {
    public:
        Node( ) :
            m_prev( nullptr ), m_next( nullptr )
        {
        }

        Node( const T& data, Node<T>* prev, Node<T>* next ) :
            m_data( ( data ) ),
            m_prev( prev ), m_next( next )
        {
        }

    public:
        T m_data;
        Node<T>* m_prev;
        Node<T>* m_next;

    };

    template <typename T, typename TAllocator = Rumia::DefaultAllocator,
        typename IsChlidOfAllocator = std::enable_if<std::is_base_of<Rumia::Allocator, TAllocator>::value>>
        class List
    {
    public:
        List( TAllocator& allocator ) :
            m_allocator(allocator), 
            m_root( nullptr )
        {
        }

        List( const List& target ) :
            m_allocator( target.m_allocator ),
            m_root( nullptr )
        {
            Clear( );
            CopyFrom( target.m_root );
        }

        List( List&& target ) :
            m_allocator( std::move( target.m_allocator ) ),
            m_root( nullptr )
        {
            Clear( );
            m_root = target.m_root;
            target.m_root = nullptr;
        }

        virtual ~List( )
        {
            Clear( );
        }

        template <typename Ty>
        void PushFront( Ty&& element )
        {
            Node<T>* newNode = RUMIA_NEW( m_allocator, Node<T>, std::forward<Ty>(element), nullptr, nullptr );
            if ( m_root == nullptr )
            {
                m_root = newNode;
            }
            else
            {
                newNode->m_next = m_root;
                m_root->m_prev = newNode;
                m_root = newNode;
            }
        }

        template <typename Ty>
        void PushBack( Ty&& element )
        {
            Node<T>* newNode = RUMIA_NEW( m_allocator, Node<T>, std::forward<T>( element ), nullptr, nullptr );
            if ( m_root == nullptr )
            {
                m_root = newNode;
            }
            else
            {
                Node<T>* node = GetMostBackNode( );
                node->m_next = newNode;
                newNode->m_prev = node;
            }
        }

        T PopFront( )
        {
            assert( !IsEmpty( ) );
            T data = std::move( m_root->m_data );
            Node<T>* newRoot = m_root->m_next;
            RUMIA_DELETE( m_allocator, m_root );
            m_root = newRoot;

            if ( m_root != nullptr )
            {
                m_root->m_prev = nullptr;
            }

            return std::move( data );
        }

        T PopBack( )
        {
            assert( !IsEmpty( ) );
            Node<T>* popNode = GetMostBackNode( );
            if ( popNode == m_root )
            {
                m_root = nullptr;
            }

            T data = std::move( popNode->m_data );
            if ( popNode->m_prev != nullptr )
            {
                popNode->m_prev->m_next = nullptr;
            }

            RUMIA_DELETE( m_allocator, popNode );
            return std::move( data );
        }

        void Clear( )
        {
            for ( Node<T>* node = m_root; node != nullptr; )
            {
                Node<T>* nextNode = node->m_next;
                RUMIA_DELETE( m_allocator, node );
                node = nextNode;
            }

            m_root = nullptr;
        }

        inline bool IsEmpty( ) const { return ( m_root == nullptr ); }

    protected:
        void CopyFrom( Node<T>* root )
        {
            assert( ( m_root == nullptr ) );
            Node<T>** targetNode = ( &m_root );
            Node<T>* prevNode = nullptr;
            for ( Node<T>* node = root; node != nullptr; )
            {
                Node<T>* nextNode = node->m_next;
                Node<T>* newNode = RUMIA_NEW( m_allocator, Node<T>, node->m_data, nullptr, nullptr );
                ( *targetNode ) = newNode;
                if ( prevNode != nullptr )
                {
                    prevNode->m_next = newNode;
                    newNode->m_prev = prevNode;
                }
                ( prevNode ) = newNode;
                node = nextNode;
                (targetNode) = &(newNode->m_next);
            }
        }

        void DeleteNodes( Node<T>* root )
        {
            assert( root != nullptr && m_root != root );
            for ( Node<T>* node = root; node != nullptr; )
            {
                Node<T>* nextNode = node->m_next;
                RUMIA_DELETE( m_allocator, node );
                node = nextNode;
            }
        }

        inline Node<T>* GetMostBackNode( ) const
        {
            if ( m_root != nullptr )
            {
                Node<T>* node = m_root;
                while ( node->m_next != nullptr )
                {
                    node = node->m_next;
                }

                return node;
            }

            return nullptr;
        }

    protected:
        TAllocator& m_allocator;
        Node<T>* m_root;

    };
}