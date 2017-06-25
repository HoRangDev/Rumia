#pragma once
#if __TEST__
#include "gtest\gtest.h"
#include "Rumia\List.h"

class ListItrTest : public testing::Test
{
public:
    ListItrTest( ) : list( allocator )
    {
    }

    ~ListItrTest( ) { }

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::Allocator allocator;
    Rumia::List<int> list;

};

#endif
