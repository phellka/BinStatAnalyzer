#include "AllTests.h"

static const StatData case_in_a[] = {
    {.id = 3, .count = 7, .cost = 3.3, .primary = 0, .mode = 2}
};

static const StatData case_in_b[] = {
    {.id = 2, .count = 6, .cost = 2.2, .primary = 0, .mode = 2},
    {.id = 1, .count = 5, .cost = 1.1, .primary = 1, .mode = 1}
};

static const StatData case_out[] = {
    {.id = 1, .count = 5, .cost = 1.1, .primary = 1, .mode = 1},
    {.id = 2, .count = 6, .cost = 2.2, .primary = 0, .mode = 2},
    {.id = 3, .count = 7, .cost = 3.3, .primary = 0, .mode = 2}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestSorting_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeBaseSmallArrays_1"
};