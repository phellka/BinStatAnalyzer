#pragma once

#include "Test.h"


typedef struct {
    Test** tests;
    size_t testCount;
} TestPool;

void InitTestPool(TestPool* testPool);
void CloseTestPool(TestPool* testPool);