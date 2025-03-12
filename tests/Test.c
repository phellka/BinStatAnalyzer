#include "Test.h"
#include <math.h>
#include <sys/time.h>

int compare_by_cost(const void* a, const void* b) {
    float cost_a = ((StatData*)a)->cost;
    float cost_b = ((StatData*)b)->cost;
    if ((cost_a > cost_b) - (cost_a < cost_b) != 0) {
        return (cost_a > cost_b) - (cost_a < cost_b);
    }
    return ((StatData*)a)->id - ((StatData*)b)->id;
}

int CompareResults(const StatCollection *expected, const StatCollection *actual) {
    if (expected->size != actual->size) return 1;
    for (size_t i = 0; i < expected->size; i++) {
        if (expected->items[i].id != actual->items[i].id ||
            expected->items[i].count != actual->items[i].count ||
            fabs(expected->items[i].cost - actual->items[i].cost) > 0.001 ||
            expected->items[i].primary != actual->items[i].primary ||
            expected->items[i].mode != actual->items[i].mode) {
                printf("%f %f %ld\n\n", expected->items[i].cost, actual->items[i].cost, i);
            return 1; 
        }
    }
    return 0;
}

double ExecTest(Test* test) {
    test->prepareTestData(test);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    StatCollection col_a = { .items = test->input_a, .size = test->size_a };
    StatCollection col_b = { .items = test->input_b, .size = test->size_b };
    StatCollection expected = { .items = test->expected, .size = test->size_expected };

    if (StoreDump(&col_a, TEST_FILE_A) || StoreDump(&col_b, TEST_FILE_B)) {
        fprintf(stderr, "Error writing test data to files!\n");
        return -1;
    }
    char command[256];
    snprintf(command, sizeof(command), "./data_processor %s %s %s >> %s", TEST_FILE_A, TEST_FILE_B, TEST_FILE_OUT, DATA_PROCESSOR_NAME);
    if (system(command) != 0) {
        fprintf(stderr, "Error executing data processing utility!\n");
        return -1;
    }

    StatCollection result;
    if (LoadDump(&result, TEST_FILE_OUT)) {
        fprintf(stderr, "Error reading processed data!\n");
        return -1;
    }
    int testPassed = CompareResults(&expected, &result);

    free(result.items);

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    if (testPassed) {
        fprintf(stderr, "Error: processed data does not match expected results!\n");
        return -1;
    } else {
        return elapsed;
    }
}