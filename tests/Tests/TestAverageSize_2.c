#include "AllTests.h"

static StatData case_in_a[1000];

static StatData case_in_b[1000];

static StatData case_out[1000];




static void prepareTestData(Test* test) {

    for (int i = 0; i < 1000; i++) {
        case_in_a[i].id = 1000 + i;
        case_in_a[i].count = i % 20;
        case_in_a[i].cost = i * 1.05f;
        case_in_a[i].primary = i % 2;
        case_in_a[i].mode = i % 8;

        case_in_b[i].id = 1000 + i;
        case_in_b[i].count = (i + 3) % 20;
        case_in_b[i].cost = i * 1.08f;
        case_in_b[i].primary = (i + 1) % 2;
        case_in_b[i].mode = (i + 4) % 8;

        case_out[i].id = 1000 + i;
        case_out[i].count = case_in_a[i].count + case_in_b[i].count;
        case_out[i].cost = case_in_a[i].cost + case_in_b[i].cost;
        case_out[i].primary = case_in_a[i].primary * case_in_b[i].primary;
        case_out[i].mode = case_in_a[i].mode > case_in_b[i].mode ? case_in_a[i].mode : case_in_b[i].mode;
    }

    qsort(case_out, sizeof(case_out) / sizeof(StatData), sizeof(StatData), compare_by_cost);


    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestAverageSize_2 = {
    .prepareTestData = prepareTestData,
    .name = "MergeAverageSizeWithDuplicateIDsAcrossArrays"
};