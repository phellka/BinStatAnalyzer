#pragma once

#include <stdlib.h>
#include "../src/StatData.h"
#include "../src/StatCollection.h"

#define TEST_FILE_A "test_a.bin"
#define TEST_FILE_B "test_b.bin"
#define TEST_FILE_OUT "test_out.bin"
#define DATA_PROCESSOR_NAME "test_output.txt"

typedef struct Test Test; 

typedef struct Test {
    const char *name;
    const StatData *input_a;
    size_t size_a;
    const StatData *input_b;
    size_t size_b;
    const StatData *expected;
    size_t size_expected;
    void (*prepareTestData)(Test* test);
} Test;

int compare_by_cost(const void* a, const void* b);
int CompareResults(const StatCollection *expected, const StatCollection *actual);
double ExecTest(Test* test);