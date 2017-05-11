#include "ForwardListTest.h"

ForwardListTest::ForwardListTest( ) :
    allocator( Rumia::DefaultAllocator( ) ),
    list( Rumia::ForwardList<int>( allocator ) )
{
}

ForwardListTest::~ForwardListTest( )
{
}

void ForwardListTest::SetUp( )
{
}

void ForwardListTest::TearDown( )
{
    list.Clear( );
}

TEST_F( ForwardListTest, Push )
{
    list.Push( 3 );
    list.Push( 2 );
    list.Push( 1 );

    EXPECT_EQ( list.GetSize( ), 3 );
}

TEST_F( ForwardListTest, Pop )
{
    list.Push( 3 );
    list.Push( 2 );
    list.Push( 1 );

    EXPECT_EQ( list.Pop( ), 1 );
    EXPECT_EQ( list.Pop( ), 2 );
    EXPECT_EQ( list.Pop( ), 3 );
    EXPECT_EQ( list.GetSize( ), 0 );
}

TEST_F( ForwardListTest, Clear )
{
    list.Push( 3 );
    list.Push( 2 );
    list.Push( 1 );
    list.Clear( );

    EXPECT_EQ( list.GetSize( ), 0 );
}