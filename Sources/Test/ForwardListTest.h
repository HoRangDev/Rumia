#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\ForwardList.h"

class ForwardListTest : public testing::Test
{
public:
    ForwardListTest( );
    ~ForwardListTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::DefaultAllocator allocator;
    Rumia::ForwardList<int> list;

};


#endif