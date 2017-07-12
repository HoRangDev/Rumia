#ifdef __TEST__
#include "ArrayTest.h"

ArrayTest::ArrayTest( ) :
    allocator( Rumia::Allocator( ) ),
    arr( Rumia::Array<int>( allocator ) ),
    objArr( Rumia::Array<SomeClass>( allocator ) )
{
}

ArrayTest::~ArrayTest( )
{
}

void ArrayTest::SetUp( )
{
    arr.PushBack( 1 );
    arr.PushBack( 2 );
    arr.PushBack( 3 );
    arr.PushBack( 4 );
} 

void ArrayTest::TearDown( )
{
    arr.Clear( );
    objArr.Clear( );
}

TEST_F( ArrayTest, Reserve )
{
    EXPECT_EQ( arr.GetCapacity( ), 4 );
    arr.Reserve( 8 );
    EXPECT_EQ( arr.GetCapacity( ), 8 );
    // arr.Reserve( 4 ); // it going to make assertion
}

TEST_F( ArrayTest, Resize )
{
    EXPECT_EQ( arr.GetSize( ), 4 );
    arr.Resize( 5 );
    EXPECT_EQ( arr.GetSize( ), 5 );
    arr.Resize( 4 );
    EXPECT_EQ( arr.GetSize( ), 4 );
    arr.Resize( 5, 999 );
    EXPECT_EQ( arr.GetSize( ), 5 );
    EXPECT_EQ( arr.At( 4 ), 999 );
}

TEST_F( ArrayTest, PushBack )
{
    EXPECT_EQ( arr.At( 0 ), 1 );
    EXPECT_EQ( arr.At( 1 ), 2 );
    EXPECT_EQ( arr.At( 2 ), 3 );
    EXPECT_EQ( arr.At( 3 ), 4 );
    EXPECT_EQ( arr.GetCapacity( ), 4 );
    EXPECT_EQ( arr.GetSize( ), 4 );
    arr.PushBack( 5 );
    EXPECT_EQ( arr.At( arr.GetSize( ) - 1 ), 5 );
    EXPECT_EQ( arr.GetCapacity( ), 8 );
    EXPECT_FALSE( arr.GetCapacity( ) == arr.GetSize( ) );
}

TEST_F( ArrayTest, PopBack )
{
    EXPECT_EQ( arr.PopBack( ), 4 );
    EXPECT_EQ( arr.GetSize( ), 3 );
    EXPECT_EQ( arr.PopBack( ), 3);
    EXPECT_EQ( arr.GetSize( ), 2 );
    EXPECT_EQ( arr.PopBack( ), 2 );
    EXPECT_EQ( arr.GetSize( ), 1 );
    EXPECT_EQ( arr.PopBack( ), 1 );
    EXPECT_EQ( arr.GetSize( ), 0 );
}

TEST_F( ArrayTest, Emplace )
{
    arr.Emplace( 5 );
    EXPECT_EQ( arr.GetSize( ), 5 );
    EXPECT_EQ( arr.GetCapacity( ), 8 );
    arr.Emplace( 6 );
    EXPECT_EQ( arr.GetSize( ), 6 );
    EXPECT_EQ( arr.At( arr.GetSize( ) - 1 ), 6 );
}

TEST_F( ArrayTest, Insert )
{
    arr.Insert( 0, -1 );
    EXPECT_EQ( arr.At( 0 ), -1 );
    EXPECT_EQ( arr.GetSize( ), 5 );
    EXPECT_EQ( arr.GetCapacity( ), 8 );
    arr.Insert( arr.GetSize( ) - 1, 1001 );
    EXPECT_EQ( arr.At( ( arr.GetSize( ) - 2 ) ), 1001 );
}

TEST_F( ArrayTest, IsEmpty )
{
    EXPECT_TRUE( !arr.IsEmpty( ) );
    arr.PopBack( );
    arr.PopBack( );
    arr.PopBack( );
    arr.PopBack( );
    EXPECT_TRUE( arr.IsEmpty( ) );
}

TEST_F( ArrayTest, IsFull )
{
    EXPECT_TRUE( arr.IsFull( ) );
    arr.PopBack( );
    EXPECT_FALSE( arr.IsFull( ) );
    arr.PushBack( 4 );
    arr.PushBack( -1 );
    EXPECT_FALSE( arr.IsFull( ) );
}

TEST_F( ArrayTest, Clear )
{
    arr.Clear( false );
    EXPECT_TRUE( arr.IsEmpty( ) );
    arr.Clear( true );
    EXPECT_EQ( arr.GetCapacity( ), 0 );
}

TEST_F( ArrayTest, Copy )
{
    Rumia::Array<int> copyConstructorObj{ arr };
    EXPECT_EQ( copyConstructorObj.PopBack( ), 4 );
    EXPECT_EQ( copyConstructorObj.PopBack( ), 3 );
    EXPECT_EQ( copyConstructorObj.PopBack( ), 2 );
    EXPECT_EQ( copyConstructorObj.PopBack( ), 1 );
    copyConstructorObj.PushBack( 999 );
    // arr and copyConstructorObj is not a same object!
    EXPECT_EQ( arr.PopBack( ), 4);

    Rumia::Array<int> anotherCopy{ allocator };
    anotherCopy = arr;
    EXPECT_EQ( anotherCopy.PopBack( ), 3 );
    EXPECT_EQ( anotherCopy.PopBack( ), 2 );
    EXPECT_EQ( anotherCopy.PopBack( ), 1 );
    EXPECT_TRUE( anotherCopy.IsEmpty( ) );
}

TEST_F( ArrayTest, Move )
{
    Rumia::Array<int> movedObj( std::move( arr ) );
    EXPECT_TRUE( arr.IsEmpty( ) );
    EXPECT_EQ( movedObj.PopBack( ), 4 );
    EXPECT_EQ( movedObj.PopBack( ), 3 );

    Rumia::Array<int> anotherMovedObj{ allocator };
    EXPECT_TRUE( anotherMovedObj.IsEmpty( ) );
    anotherMovedObj = std::move( movedObj );
    EXPECT_FALSE( anotherMovedObj.IsEmpty( ) );
    EXPECT_TRUE( movedObj.IsEmpty( ) );
    EXPECT_EQ( anotherMovedObj.PopBack( ), 2 );
    EXPECT_EQ( anotherMovedObj.PopBack( ), 1 );
}

TEST_F( ArrayTest, ObjectMove )
{
    SomeClass obj{ 30 };
    objArr.PushBack( obj );
    EXPECT_EQ( objArr.PopBack( ).m_data, 30 );
    EXPECT_EQ( obj.m_data, 30 );
    objArr.PushBack( std::move( obj ) );
    EXPECT_EQ( objArr.PopBack( ).m_data, 30 );
    EXPECT_EQ( obj.m_data, -1 );
}

TEST_F( ArrayTest, IndexOf )
{
    EXPECT_EQ( arr.IndexOf( 1 ), 0 );
    EXPECT_EQ( arr.IndexOf( 2 ), 1 );
    EXPECT_EQ( arr.IndexOf( 3 ), 2 );
    EXPECT_EQ( arr.IndexOf( 4 ), 3 );
    EXPECT_EQ( arr.IndexOf( 9999 ), arr.GetSize( ) );
}

TEST_F( ArrayTest, EraseAt )
{
    arr.EraseAt( 1 );
    EXPECT_EQ( arr.GetSize( ), 3 );
    EXPECT_EQ( arr.At( 1 ), 3 );
    EXPECT_EQ( arr.At( 2 ), 4 );
}

TEST_F( ArrayTest, Erase )
{
    arr.Erase( 2 );
    EXPECT_EQ( arr.GetSize( ), 3 );
    EXPECT_EQ( arr.At( 1 ), 3 );
    EXPECT_EQ( arr.At( 2 ), 4 );
    EXPECT_EQ( arr.IndexOf( 2 ), arr.GetSize( ) );
    arr.Erase( 999 );
    EXPECT_EQ( arr.GetSize( ), 3 );

    arr.Clear( );
    arr.PushBack( 1 );
    arr.PushBack( 2 );
    arr.Erase( arr.begin( ) );
    EXPECT_EQ( 2, arr.At( 0 ) );

    arr.Clear( );
    arr.PushBack( 3 );
    arr.PushBack( 2 );
    arr.PushBack( 1 );

    for ( auto itr = arr.begin( ); itr != arr.end( ); ++itr )
    {
        if ( ( *itr ) == 2 )
        {
            arr.Erase( itr );
        }
    }

    EXPECT_EQ( 1, arr[ 1 ] );
    EXPECT_EQ( 3, ( *arr.begin( ) ) );
}

TEST_F( ArrayTest, FindIf )
{
    arr.Clear( );
    arr.PushBack( 1 );
    arr.PushBack( 2 );
    arr.PushBack( 3 );

    int FoundData = ( *arr.FindIf( [ ]( int Data )->bool { return ( Data == 2 ); } ) );
    EXPECT_EQ( FoundData, 2 );
}

TEST_F( ArrayTest, ConstItr )
{
    arr.Clear( );
    arr.PushBack( 1 );
    arr.PushBack( 2 );
    arr.PushBack( 3 );

    int Counter = 1;
    for ( auto itr = arr.cbegin( ); itr != arr.cend( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), Counter );
        ++Counter;
    }
}

TEST_F( ArrayTest, Shrink )
{
    arr.Clear( );
    arr.PushBack( 1 ); // Capacity 2
    arr.PushBack( 2 ); 
    arr.PushBack( 3 ); // Capacity 4
    arr.PushBack( 4 );
    arr.PushBack( 5 ); // Capacity 8

    EXPECT_EQ( arr.GetCapacity( ), 8 );
    arr.Shrink( );
    EXPECT_EQ( arr.GetCapacity( ), 5 );
    EXPECT_EQ( arr[ 4 ], 5 );
}

#endif