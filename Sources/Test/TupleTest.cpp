#include "TupleTest.h"
#include <tuple>

TupleTest::TupleTest( )
{
}

TupleTest::~TupleTest( )
{
}

TEST_F( TupleTest, Tuple )
{
    Rumia::Tuple<int, double, std::string> tuple( 3, 2.0, "WOW" );
    EXPECT_EQ( Rumia::Get<0>( tuple ), 3 );
    EXPECT_EQ( Rumia::Get<1>( tuple ), 2.0 );
    EXPECT_EQ( Rumia::Get<2>( tuple ), "WOW" );
}

TEST_F( TupleTest, MakeTuple )
{
    auto tuple = Rumia::MakeTuple( 3, 2.0, "WOW" );
    EXPECT_EQ( Rumia::Get<0>( tuple ), 3 );
    EXPECT_EQ( Rumia::Get<1>( tuple ), 2.0 );
    EXPECT_EQ( Rumia::Get<2>( tuple ), "WOW" );
}

TEST_F( TupleTest, TupleSize )
{
    EXPECT_EQ( 3, ( Rumia::TupleSize<Rumia::Tuple<int, int, int>>::value ) );
}