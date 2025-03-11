#include "TestAverageSize_5.h"
#include <limits.h>
#include <float.h>

static StatData case_in_a[1000];

static StatData case_in_b[1000];

static StatData case_out[1] = {
    {.id = 1, .count = 2000, .cost = 2000, .primary = 1, .mode = 1}
};


static int compare_by_cost(const void* a, const void* b) {
    float cost_a = ((StatData*)a)->cost;
    float cost_b = ((StatData*)b)->cost;
    return cost_a - cost_b;
}

static void prepareTestData(Test* test) {
    for (int i = 0; i < 1000; i++) {
        case_in_a[i].id = 1;
        case_in_a[i].count = 1;
        case_in_a[i].cost = 1;
        case_in_a[i].primary = 1;
        case_in_a[i].mode = 1;

        case_in_b[i].id = 1;
        case_in_b[i].count = 1;
        case_in_b[i].cost = 1;
        case_in_b[i].primary = 1;
        case_in_b[i].mode = 1;

    }

    qsort(case_out, sizeof(case_out) / sizeof(StatData), sizeof(StatData), compare_by_cost);


    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestAverageSize_5 = {
    .prepareTestData = prepareTestData,
    .name = "MergeAverageSizeOnlyOneId"
};