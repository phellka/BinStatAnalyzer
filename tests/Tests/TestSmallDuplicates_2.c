#include "TestSmallDuplicates_2.h"

static const StatData case_in_a[] = {
    {.id = 200, .count = 3, .cost = 1.0, .primary = 1, .mode = 0},
    {.id = 200, .count = 5, .cost = 2.5, .primary = 0, .mode = 1}
};

static const StatData case_in_b[] = {
};

static const StatData case_out[] = {
    {.id = 200, .count = 8, .cost = 3.5, .primary = 0, .mode = 1}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestSmallDuplicates_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeWithDuplicateIDsInSingleArray"
};