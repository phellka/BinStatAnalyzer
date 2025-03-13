#include "TestPool.h"
#include "Tests/AllTests.h"




void InitTestPool(TestPool* testPool) {
    int testCount = 23;
    testPool->tests = malloc(sizeof(Test*) * testCount);
    testPool->testCount = testCount;

    int i = 0;
    testPool->tests[i++] = &TestSmallJoin_1;
    testPool->tests[i++] = &TestSmallJoin_2;
    testPool->tests[i++] = &TestSmallDuplicates_1;
    testPool->tests[i++] = &TestSmallDuplicates_2;
    testPool->tests[i++] = &TestEmptyInput_1;
    testPool->tests[i++] = &TestEmptyInput_2;
    testPool->tests[i++] = &TestEmptyInput_3;
    testPool->tests[i++] = &TestEdgeCase_1;
    testPool->tests[i++] = &TestEdgeCase_2;
    testPool->tests[i++] = &TestSorting_1;
    testPool->tests[i++] = &TestSorting_2;
    testPool->tests[i++] = &TestAverageSize_1;
    testPool->tests[i++] = &TestAverageSize_2;
    testPool->tests[i++] = &TestAverageSize_3;
    testPool->tests[i++] = &TestAverageSize_4;
    testPool->tests[i++] = &TestAverageSize_5;
    testPool->tests[i++] = &TestAverageSize_6;
    testPool->tests[i++] = &TestMaxSize_1;
    testPool->tests[i++] = &TestMaxSize_2;
    testPool->tests[i++] = &TestMaxSize_3;
    testPool->tests[i++] = &TestMaxSize_4;
    testPool->tests[i++] = &TestMaxSize_5;
    testPool->tests[i++] = &TestMaxSize_6;
}

void CloseTestPool(TestPool* testPool) {
    free(testPool->tests);
}