#include "AlgorithmTest.h"

AlgorithmTest::AlgorithmTest( ) :
    allocator( Rumia::Allocator( ) ),
    array( allocator ),
    list( allocator ),
    fList( allocator )
{
}

AlgorithmTest::~AlgorithmTest( )
{
}

void AlgorithmTest::SetUp( )
{
    array.Clear( );
    list.Clear( );
    fList.Clear( );

    array.PushBack( 1 );
    array.PushBack( 2 );
    array.PushBack( 3 );

    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );

    fList.PushFront( 3 );
    fList.PushFront( 2 );
    fList.PushFront( 1 );
}

void AlgorithmTest::TearDown( )
{
}

TEST_F( AlgorithmTest, ArrayFindIf )
{
    int FoundData = *( Rumia::FindIf( array.begin( ), array.end( ),
                       [ ]( int data )->bool { return ( data == 2 ); } ) );

    EXPECT_EQ( 2, FoundData );

}

TEST_F( AlgorithmTest, ListFindIf )
{
    int FoundData = *( Rumia::FindIf( list .begin( ), list.end( ),
                       [ ]( int data )->bool { return ( data == 2 ); } ) );

    EXPECT_EQ( 2, FoundData );
}

TEST_F( AlgorithmTest, ForwardListFindIf )
{
    int FoundData = *( Rumia::FindIf( fList.begin( ), fList.end( ),
                       [ ]( int data )->bool { return ( data == 2 ); } ) );

    EXPECT_EQ( 2, FoundData );
}