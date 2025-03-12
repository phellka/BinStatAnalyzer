#include "TestAverageSize_1.h"

static StatData case_in_a[1000];

static StatData case_in_b[1000];

static StatData case_out[2000];




static void prepareTestData(Test* test) {
    int index = 0;

    for (int i = 0; i < 1000; i++) {
        case_in_a[i].id = 1000 + i;
        case_in_a[i].count = i % 10;
        case_in_a[i].cost = i * 1.1f;
        case_in_a[i].primary = i % 2;
        case_in_a[i].mode = i % 8;

        case_out[index++] = case_in_a[i];
    }
    
    for (int i = 0; i < 1000; i++) {
        case_in_b[i].id = 2000 + i;
        case_in_b[i].count = (i + 5) % 10;
        case_in_b[i].cost = i * 1.5f;
        case_in_b[i].primary = (i + 1) % 2;
        case_in_b[i].mode = (i + 3) % 8;

        case_out[index++] = case_in_b[i];
    }

    qsort(case_out, index, sizeof(StatData), compare_by_cost);


    test->input_a = case_in_a;
    test->input_b = case_in_b;
    test->expected = case_out;
    test->size_a = sizeof(case_in_a) / sizeof(StatData);
    test->size_b = sizeof(case_in_b) / sizeof(StatData);
    test->size_expected = sizeof(case_out) / sizeof(StatData);
}

Test TestAverageSize_1 = {
    .prepareTestData = prepareTestData,
    .name = "MergeAverageSizeWithoutDuplicates"
};