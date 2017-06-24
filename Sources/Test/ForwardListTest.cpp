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
    list.PushFront( 3 );
    list.PushFront( 2 );
    list.PushFront( 1 );

    EXPECT_EQ( list.GetSize( ), 3 );
}

TEST_F( ForwardListTest, Pop )
{
    list.PushFront( 3 );
    list.PushFront( 2 );
    list.PushFront( 1 );

    EXPECT_EQ( list.PopFront( ), 1 );
    EXPECT_EQ( list.PopFront( ), 2 );
    EXPECT_EQ( list.PopFront( ), 3 );
    EXPECT_EQ( list.GetSize( ), 0 );
}

TEST_F( ForwardListTest, Find )
{
    list.PushFront( 1 );
    list.PushFront( 2 );
    list.PushFront( 3 );

    EXPECT_EQ( ( *list.Find( 2 ) ), 2 );
}

TEST_F( ForwardListTest, Erase )
{
    list.PushFront( 3 );
    list.PushFront( 2 );
    list.PushFront( 1 );

    list.Erase( 4 );
    EXPECT_EQ( list.GetSize( ), 3 );
    list.Erase( 2 );
    EXPECT_EQ( list.GetSize( ), 2 );
    EXPECT_EQ( ( *list.cbegin( ) ), 1 );
    list.Erase( list.begin( ) );
    EXPECT_EQ( list.GetSize( ), 1 );
    EXPECT_EQ( ( *list.cbegin( ) ), 3 );
}

TEST_F( ForwardListTest, Clear )
{
    list.PushFront( 3 );
    list.PushFront( 2 );
    list.PushFront( 1 );
    list.Clear( );

    EXPECT_EQ( list.GetSize( ), 0 );
}