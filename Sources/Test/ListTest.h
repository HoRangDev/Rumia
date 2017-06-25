#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\List.h"

class ListTest : public testing::Test
{
public:
    ListTest( );
    ~ListTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::Allocator allocator;
    Rumia::List<int> list;

};

#endif