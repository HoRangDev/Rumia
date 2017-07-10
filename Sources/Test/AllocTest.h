#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\Allocator.h"

class AllocTest : public testing::Test
{
public:
    AllocTest( ){ }
    ~AllocTest( ){ }

    virtual void SetUp( ) override{ }
    virtual void TearDown( ) override{ }

public:
    Rumia::Allocator allocator;

};

#endif