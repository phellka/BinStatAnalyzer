#include "TestSmallJoin_2.h"

static const StatData case_in_a[] = {
    {.id = 1, .count = 10, .cost = 2.5, .primary = 1, .mode = 1},
    {.id = 2, .count = 5, .cost = 1.5, .primary = 0, .mode = 2}
};
static const StatData case_in_b[] = {
    {.id = 3, .count = 7, .cost = 3.0, .primary = 1, .mode = 0}
};

static const StatData case_out[] = {
    {.id = 2, .count = 5, .cost = 1.5, .primary = 0, .mode = 2},
    {.id = 1, .count = 10, .cost = 2.5, .primary = 1, .mode = 1},
    {.id = 3, .count = 7, .cost = 3.0, .primary = 1, .mode = 0}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestSmallJoin_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeBaseSmallArrays_2"
};