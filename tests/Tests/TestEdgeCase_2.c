#include "AllTests.h"
#include <limits.h>
#include <float.h>


static const StatData case_in_a[] = {
    {.id = LONG_MAX, .count = INT_MAX, .cost = FLT_MAX, .primary = 1, .mode = 7}
};

static const StatData case_in_b[] = {
    {.id = LONG_MAX, .count = INT_MAX, .cost = FLT_MAX, .primary = 0, .mode = 3}
};

static const StatData case_out[] = {
    {.id = LONG_MAX, .count = INT_MAX + INT_MAX, .cost = FLT_MAX + FLT_MAX, .primary = 0, .mode = 7}
};

static void prepareTestData(Test* test) {
    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestEdgeCase_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeMaximumValues"
};