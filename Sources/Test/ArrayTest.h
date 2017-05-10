#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "RumiaArray.h"

class ArrayTest : public testing::Test
{
public:
    ArrayTest( );
    ~ArrayTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::DefaultAllocator allocator;
    Rumia::Array<int> arr;

};

#endif
