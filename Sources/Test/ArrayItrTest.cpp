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
    for ( auto itr = arr.Begin( ); itr != arr.End( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), ++count );
    }

    for ( auto itr = arr.RBegin( ); itr != arr.REnd( ); ++itr )
    {
        EXPECT_EQ( ( *itr ), count-- );
    }
}