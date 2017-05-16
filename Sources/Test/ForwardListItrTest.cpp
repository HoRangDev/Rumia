#include "ForwardListItrTest.h"

void ForwardListItrTest::SetUp( )
{
    list.Push( 3 );
    list.Push( 2 );
    list.Push( 1 );
}

void ForwardListItrTest::TearDown( )
{
    list.Clear( );
}

TEST_F( ForwardListItrTest, RoundTest )
{
    int count = 0;
    for ( auto itr = list.begin( ); itr != list.end( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), ++count );
    }

    count = 0;
    for ( auto value : list )
    {
        EXPECT_EQ( value, ++count );
    }
}