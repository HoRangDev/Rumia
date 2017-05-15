#include "ListItrTest.h"

void ListItrTest::SetUp( )
{
    list.PushBack( 2 );
    list.PushFront( 1 );
    list.PushBack( 3 );
}

void ListItrTest::TearDown( )
{
    list.Clear( );
}

TEST_F( ListItrTest, RoundTest )
{
    int count = 0;
    for ( auto itr = list.begin( ); itr != list.end( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), ++count );
    }

    for ( auto itr = list.rbegin( ); itr != list.rend( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), count-- );
    }

    count = 0;
    for ( auto value : list )
    {
        EXPECT_EQ( value, ++count );
    }
}
