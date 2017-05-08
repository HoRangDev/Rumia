#include <iostream>
#include <crtdbg.h>
#include "DefaultAllocator.h"
#include "RumiaArray.h"
using namespace Rumia;

#if _DEBUG | DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE)
#endif

int main( )
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    DefaultAllocator allocator;
    int* arr = RUMIA_NEW_ARRAY( allocator, int, 5 );
    for ( int index = 0; index < 5; ++index )
    {
        arr[ index ] = ( index );
    }

    for ( int index = 0; index < 5; ++index )
    {
        std::cout << arr[ index ] << std::endl;
    }

    RUMIA_DELETE_ARRAY( allocator, arr );

    int a = 9;
    Rumia::Array<int> dynamicArr( allocator );
    dynamicArr.Push( a );
    dynamicArr.Push( 8 );
    dynamicArr.Push( 7 );
    dynamicArr.Push( 6 );

    for ( int index = 0; index < dynamicArr.GetSize( ); ++index )
    {
        std::cout << dynamicArr[ index ] << std::endl;
    }

    return 0;
}