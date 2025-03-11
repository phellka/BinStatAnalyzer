#include "TestEdgeCase_1.h"

static const StatData case_in_a[] = {
    {.id = 0, .count = 0, .cost = 0.0, .primary = 0, .mode = 0}
};

static const StatData case_in_b[] = {
    {.id = 0, .count = 0, .cost = 0.0, .primary = 1, .mode = 7}
};

static const StatData case_out[] = {
    {.id = 0, .count = 0, .cost = 0.0, .primary = 0, .mode = 7}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestEdgeCase_1 = {
    .prepareTestData = prepareTestData,
    .name = "MergeMinimalValues"
};