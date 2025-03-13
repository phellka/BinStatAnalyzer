#include "AllTests.h"

static const StatData case_in_a[] = {
    {.id = 90889, .count = 13, .cost = 3.567, .primary = 0, .mode = 3},
    {.id = 90089, .count = 1, .cost = 88.90, .primary = 1, .mode = 0}
};

static const StatData case_in_b[] = {
    {.id = 90089, .count = 13, .cost = 0.011, .primary = 0, .mode = 2},
    {.id = 90189, .count = 1000, .cost = 1.00003, .primary = 1, .mode = 2}
};

static const StatData case_out[] = {
    {.id = 90189, .count = 1000, .cost = 1.00003, .primary = 1, .mode = 2},
    {.id = 90889, .count = 13, .cost = 3.567, .primary = 0, .mode = 3},
    {.id = 90089, .count = 14, .cost = 88.911, .primary = 0, .mode = 2}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestSmallJoin_1 = {
    .prepareTestData = prepareTestData,
    .name = "MergeBaseSmallArrays_1"
};