#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\Map.h"

class MapTest : public testing::Test
{
public:
    MapTest( );
    ~MapTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::Allocator allocator;

};

#endif