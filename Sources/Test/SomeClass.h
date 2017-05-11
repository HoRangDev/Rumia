#pragma once
class SomeClass
{
public:
    SomeClass( ) : SomeClass( 0 )
    {
    }

    SomeClass( int data ) : m_data( data )
    {
    }

    SomeClass( const SomeClass& in ) :
        m_data( in.m_data )
    {
    }

    SomeClass( SomeClass&& in ) :
        m_data( in.m_data )
    {
        in.m_data = -1;
    }

    ~SomeClass( ){ }

    SomeClass& operator=( const SomeClass& in )
    {
        m_data = in.m_data;
        return ( *this );
    }

    SomeClass& operator=( SomeClass&& in )
    {
        m_data = in.m_data;
        in.m_data = -1;
        return ( *this );
    }

public:
    int m_data;
};
