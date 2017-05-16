#pragma once
#if __TEST__
#include "gtest\gtest.h"
#include "Rumia\ForwardList.h"

class ForwardListItrTest : public testing::Test
{
public:
    ForwardListItrTest( ) : list( allocator )
    {
    }

    ~ForwardListItrTest( ) { }

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::DefaultAllocator allocator;
    Rumia::ForwardList<int> list;

};
#endif