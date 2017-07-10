#include "AllocTest.h"

TEST_F( AllocTest, SharedPtr )
{
    auto Ptr = RUMIA_MAKE_SHARED( Rumia::Allocator, allocator, int, 0 );
}