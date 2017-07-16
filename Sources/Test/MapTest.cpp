#include "MapTest.h"

MapTest::MapTest( )
{
}

MapTest::~MapTest( )
{
}

void MapTest::SetUp( )
{
}

void MapTest::TearDown( )
{
}

TEST_F( MapTest, NodeTest )
{
    Rumia::Map<int, int> testMap{ allocator };
    testMap.Insert( Rumia::MakePair<int, int>( 1, 1 ) );
    EXPECT_EQ( testMap.m_root->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_pair.first, 1 );

    testMap.Insert( Rumia::MakePair<int, int>( 2, 1 ) );
    EXPECT_EQ( testMap.m_root->m_right->m_bIsRed, true );
    EXPECT_EQ( testMap.m_root->m_right->m_pair.first, 2 );

    testMap.Insert( Rumia::MakePair<int, int>( 3, 1 ) );
    EXPECT_EQ( testMap.m_root->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_pair.first, 2 );

    testMap.Insert( Rumia::MakePair<int, int>( 5, 1 ) );
    testMap.Insert( Rumia::MakePair<int, int>( 0, 1 ) );
    EXPECT_EQ( testMap.m_root->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_pair.first, 2 );
    EXPECT_EQ( testMap.m_root->m_left->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_left->m_pair.first, 1 );
    EXPECT_EQ( testMap.m_root->m_right->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_right->m_pair.first, 3 );
    EXPECT_EQ( testMap.m_root->m_left->m_left->m_bIsRed, true );
    EXPECT_EQ( testMap.m_root->m_left->m_left->m_pair.first, 0 );
    EXPECT_EQ( testMap.m_root->m_right->m_right->m_bIsRed, true );
    EXPECT_EQ( testMap.m_root->m_right->m_right->m_pair.first, 5 );

    testMap.Erase( 3 );
    EXPECT_EQ( testMap.m_root->m_right->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_right->m_pair.first, 5 );

    testMap.Erase( 2 );
    EXPECT_EQ( testMap.m_root->m_left->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_left->m_pair.first, 0 );

    testMap.Erase( 0 );
    EXPECT_EQ( testMap.m_root->m_right->m_bIsRed, true );
    EXPECT_EQ( testMap.m_root->m_right->m_pair.first, 5 );

    testMap.Erase( 1 );
    EXPECT_EQ( testMap.m_root->m_bIsRed, false );
    EXPECT_EQ( testMap.m_root->m_pair.first, 5 );

    testMap.Erase( 5 );
    EXPECT_EQ( testMap.m_root, nullptr );
    
}