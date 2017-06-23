#ifdef __TEST__
#include "PairTest.h"

PairTest::PairTest( )
{
}

PairTest::~PairTest( )
{
}

TEST_F( PairTest, Pair )
{
    auto pair = Rumia::Pair<std::string, int>( std::string( "String" ), 3 );
    EXPECT_EQ( "String", pair.first );
    EXPECT_EQ( 3, pair.second );
    EXPECT_EQ( "String", Rumia::Get<0>( pair ) );
    EXPECT_EQ( 3, Rumia::Get<1>( pair ) );
}

TEST_F( PairTest, MakePair )
{
    auto pair = Rumia::MakePair( std::string( "String" ), 3 );
    EXPECT_EQ( "String", pair.first );
    EXPECT_EQ( 3, pair.second );
    EXPECT_EQ( "String", ( Rumia::Get<0>( pair ) ) );
    EXPECT_EQ( 3, (Rumia::Get<1>( pair )) );
    auto get = Rumia::Get<0>( pair );

}

TEST_F( PairTest, TupleSize )
{
    EXPECT_EQ( 2, ( Rumia::TupleSize<Rumia::Pair<int, int>>::value ) );
}
#endif