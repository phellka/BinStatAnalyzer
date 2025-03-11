#include "TestAverageSize_6.h"
#include <limits.h>
#include <float.h>

static StatData case_in_a[1000];

static StatData case_in_b[] = {};

static StatData case_out[1000] = {
};


static int compare_by_cost(const void* a, const void* b) {
    float cost_a = ((StatData*)a)->cost;
    float cost_b = ((StatData*)b)->cost;
    return cost_a - cost_b;
}

static void prepareTestData(Test* test) {
    for (int i = 0; i < 1000; i++) {
        case_in_a[i].id = i;
        case_in_a[i].count = rand() % 100;
        case_in_a[i].cost = (rand() % 10000) / 100.0f;
        case_in_a[i].primary = rand() % 2;
        case_in_a[i].mode = rand() % 8;

        case_out[i].id = i;
        case_out[i].count = case_in_a[i].count;
        case_out[i].cost = case_in_a[i].cost;
        case_out[i].primary = case_in_a[i].primary;
        case_out[i].mode = case_in_a[i].mode;
    }

    qsort(case_out, sizeof(case_out) / sizeof(StatData), sizeof(StatData), compare_by_cost);


    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestAverageSize_6 = {
    .prepareTestData = prepareTestData,
    .name = "MergeAverageSizeOneEmptyArray"
};