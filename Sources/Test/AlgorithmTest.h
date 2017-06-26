#pragma once
#ifdef __TEST__
#include "gtest\gtest.h"
#include "Rumia\Array.h"
#include "Rumia\List.h"
#include "Rumia\ForwardList.h"
#include "Rumia\Algorithm.h"

class AlgorithmTest : public testing::Test
{
public:
    AlgorithmTest( );
    ~AlgorithmTest( );

    virtual void SetUp( ) override;
    virtual void TearDown( ) override;

public:
    Rumia::Allocator allocator;
    Rumia::Array<int> array;
    Rumia::List<int> list;
    Rumia::ForwardList<int> fList;

};

#endif