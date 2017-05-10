#pragma once
#ifdef __TEST__
#include <gtest/gtest.h>
#include "RumiaArray.h"

class ArrayTest : public testing::Test
{
public:

public:
    Rumia::Array<int> arr;
    Rumia::Array<int> copiedArr;

};

#endif
