#include <iostream>
#include <tchar.h>
#include <crtdbg.h>

#ifdef __TEST__
#include "gtest\gtest.h"
int _tmain( int argc, TCHAR* argv[ ] )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
#else
#include "DefaultAllocator.h"
#include "Array.h"
#include "List.h"
using namespace Rumia;

#if _DEBUG | DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE)
#endif


int main( )
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    DefaultAllocator allocator;

    /*
    int a = 9;
    Rumia::Array<int> dynamicArr( allocator );
    dynamicArr.Push( a );
    dynamicArr.Push( 8 );
    dynamicArr.Push( 7 );
    dynamicArr.Push( 6 );

    std::cout << "1. Original Arr" << std::endl;
    for ( int index = 0; index < dynamicArr.GetSize( ); ++index )
    {
    std::cout << dynamicArr[ index ] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "2. Resized" << std::endl;
    dynamicArr.Resize( 7, 0 );
    for ( int index = 0; index < dynamicArr.GetSize( ); ++index )
    {
    std::cout << dynamicArr[ index ] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "3. Insert" << std::endl;
    dynamicArr.Insert( 3, 300 );
    dynamicArr.Insert( 8, 100 );
    for ( int index = 0; index < dynamicArr.GetSize( ); ++index )
    {
    std::cout << dynamicArr[ index ] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "4. Pop" << std::endl;
    for ( int index = 0; index < 2; ++index )
    {
    std::cout << "Poped: " << dynamicArr.Pop( ) << std::endl;
    }
    for ( int index = 0; index < dynamicArr.GetSize( ); ++index )
    {
    std::cout << dynamicArr[ index ] << std::endl;
    }
    std::cout << std::endl;

    Rumia::Array<int> MovedArr = std::move( dynamicArr );
    std::cout << dynamicArr.GetSize( ) << std::endl;
    */

    Rumia::List<int> list( allocator );
    list.PushBack( 1 );
    list.PushBack( 2 );
    list.PushBack( 3 );

    Rumia::List<int> copyList( list );

    std::cout << copyList.PopBack( ) << std::endl;
    std::cout << copyList.PopFront( ) << std::endl;
    copyList.PushFront( 9 );
    std::cout << copyList.PopBack( ) << std::endl;
    std::cout << copyList.PopBack( ) << std::endl;
    std::cout << std::boolalpha << copyList.IsEmpty( ) << std::endl;
    return 0;
}
#endif