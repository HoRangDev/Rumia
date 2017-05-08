#include <iostream>
#include <crtdbg.h>
#include "DefaultAllocator.h"
using namespace Rumia;

#if _DEBUG | DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE)
#endif

int main( )
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    DefaultAllocator allocator;
    int* arr = allocator.NewObjectArray<int>( 5 );
    for ( int index = 0; index < 5; ++index )
    {
        arr[ index ] = (index);
    }

    for ( int index = 0; index < 5; ++index )
    {
        std::cout << arr[ index ] << std::endl;
    }

    allocator.DeleteObjectArray<int>( arr );
    return 0;
}