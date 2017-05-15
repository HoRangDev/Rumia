#include "ArrayItrTest.h"

void ArrayItrTest::SetUp( )
{
    arr.Push( 1 );
    arr.Push( 2 );
    arr.Push( 3 );
}

void ArrayItrTest::TearDown( )
{
    arr.Clear( );
}

TEST_F( ArrayItrTest, RoundTest )
{
    int count = 0;
    for ( auto itr = arr.begin( ); itr != arr.end( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), ++count );
    }

    for ( auto itr = arr.rbegin( ); itr != arr.rend( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), count-- );
    }

    count = 0;
    for ( auto value : arr )
    {
        EXPECT_EQ( value, ++count );
    }
}