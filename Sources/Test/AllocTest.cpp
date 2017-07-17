#include "AllocTest.h"

TEST_F( AllocTest, SharedPtr )
{
    auto Ptr = Rumia::MakeShared<int>( allocator, 0 );
}