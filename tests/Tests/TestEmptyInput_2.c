#include "AllTests.h"

static const StatData case_in_a[] = {
    {.id = 500, .count = 20, .cost = 5.5, .primary = 1, .mode = 2}
};

static const StatData case_in_b[] = {
};

static const StatData case_out[] = {
    {.id = 500, .count = 20, .cost = 5.5, .primary = 1, .mode = 2}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestEmptyInput_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeLeftArrayEmpty"
};