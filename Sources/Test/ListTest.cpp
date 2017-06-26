#include "ListTest.h"

ListTest::ListTest( ) :
    list( allocator )
{
}

ListTest::~ListTest( )
{
}

void ListTest::SetUp( )
{
}

void ListTest::TearDown( )
{
    list.Clear( );
}

TEST_F( ListTest, PushFront )
{
    list.PushFront( 4 );
    list.PushFront( 3 );
    list.PushFront( 2 );
    list.PushFront( 1 );

    EXPECT_EQ( list.GetSize( ), 4 );
    EXPECT_EQ( list.PopFront( ), 1 );
    EXPECT_EQ( list.PopFront( ), 2 );
    EXPECT_EQ( list.PopFront( ), 3 );
    EXPECT_EQ( list.PopFront( ), 4 );
}

TEST_F( ListTest, PushBack )
{
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    list.PushBack( 4 );

    EXPECT_EQ( list.GetSize( ), 4 );
    EXPECT_EQ( list.PopBack( ), 4 );
    EXPECT_EQ( list.PopBack( ), 3 );
    EXPECT_EQ( list.PopBack( ), 2 );
    EXPECT_EQ( list.PopBack( ), 1 );
}

TEST_F( ListTest, MixPushPop )
{
    list.PushBack( 2 );
    list.PushFront( 1 );
    list.PushBack( 3 );

    EXPECT_EQ( list.GetSize( ), 3 );
    EXPECT_EQ( list.PopFront( ), 1 );
    EXPECT_EQ( list.PopFront( ), 2 );
    EXPECT_EQ( list.PopBack( ), 3 );
}

TEST_F( ListTest, Clear )
{
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );
    list.Clear( );
    EXPECT_EQ( list.GetSize( ), 0 );
    EXPECT_TRUE( list.IsEmpty( ) );
}

TEST_F( ListTest, CopyConstructor )
{
    list.PushFront( 2 );
    list.PushFront( 1 );

    Rumia::List<int> copiedList{ list };
    EXPECT_EQ( copiedList.PopBack( ), 2 );
    EXPECT_EQ( copiedList.PopBack( ), 1 );
    EXPECT_EQ( list.PopBack( ), 2 );
    EXPECT_EQ( list.PopBack( ), 1 );
}

TEST_F( ListTest, CopyOperator )
{
    list.PushFront( 2 );
    list.PushFront( 1 );

    Rumia::List<int> copiedList{ allocator };
    copiedList = list;
    EXPECT_EQ( copiedList.PopBack( ), 2 );
    EXPECT_EQ( copiedList.PopBack( ), 1 );
    EXPECT_EQ( list.PopBack( ), 2 );
    EXPECT_EQ( list.PopBack( ), 1 );
}

TEST_F( ListTest, MoveConstructor )
{
    list.PushFront( 2 );
    list.PushFront( 1 );

    Rumia::List<int> movedList{ std::move( list ) };
    EXPECT_EQ( movedList.PopBack( ), 2 );
    EXPECT_EQ( movedList.PopBack( ), 1 );
    EXPECT_TRUE( list.IsEmpty( ) );
}

TEST_F( ListTest, MoveOperator )
{
    list.PushBack( 1 );
    list.PushBack( 2 );

    Rumia::List<int> movedList{ allocator };
    movedList = std::move( list );
    EXPECT_EQ( movedList.PopBack( ), 2 );
    EXPECT_EQ( movedList.PopBack( ), 1 );
    EXPECT_TRUE( list.IsEmpty( ) );
}

TEST_F( ListTest, Find )
{
    list.PushBack( 1 );
    list.PushBack( 2 );

    EXPECT_EQ( 1, ( *( list.Find( 1 ) ) ) );
}

TEST_F( ListTest, FindIf )
{
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );

    int FoundData = ( *list.FindIf( [ ]( int Data )->bool { return ( Data == 2 ); } ) );
    EXPECT_EQ( FoundData, 2 );
}

TEST_F( ListTest, Erase )
{
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );

    list.Erase( 4 );
    EXPECT_EQ( 3, list.GetSize( ) );
    list.Erase( 2 );
    EXPECT_EQ( 2, list.GetSize( ) );
    list.Erase( list.begin( ) );
    EXPECT_EQ( 1, list.GetSize( ) );
    EXPECT_EQ( 3, ( *( list.begin( ) ) ) );
}