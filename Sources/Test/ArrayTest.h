#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\Array.h"
#include "SomeClass.h"

class ArrayTest : public testing::Test
{
public:
    ArrayTest( );
    ~ArrayTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::Allocator allocator;
    Rumia::Array<int> arr;
    Rumia::Array<SomeClass> objArr;

};

#endif
