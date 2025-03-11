#include "TestSmallDuplicates_1.h"

static const StatData case_in_a[] = {
    {.id = 100, .count = 10, .cost = 5.0, .primary = 1, .mode = 1}
};

static const StatData case_in_b[] = {
    {.id = 100, .count = 15, .cost = 2.5, .primary = 0, .mode = 3}
};

static const StatData case_out[] = {
    {.id = 100, .count = 25, .cost = 7.5, .primary = 0, .mode = 3}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestSmallDuplicates_1 = {
    .prepareTestData = prepareTestData,
    .name = "MergeWithDuplicateIDsAcrossArrays"
};