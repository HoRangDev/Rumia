#pragma once
#if __TEST__
#include "gtest\gtest.h"
#include "Rumia\Array.h"

class ArrayItrTest : public testing::Test
{
public:
    ArrayItrTest( ) : arr( allocator )
    {
    }

    ~ArrayItrTest( ) { }

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::DefaultAllocator allocator;
    Rumia::Array<int> arr;

};

#endif
