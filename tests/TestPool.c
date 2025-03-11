#include "TestPool.h"
#include "Tests/TestSmallJoin_1.h"
#include "Tests/TestSmallJoin_2.h"
#include "Tests/TestSmallDuplicates_1.h"
#include "Tests/TestSmallDuplicates_2.h"
#include "Tests/TestEmptyInput_1.h"
#include "Tests/TestEmptyInput_2.h"
#include "Tests/TestEmptyInput_3.h"
#include "Tests/TestEdgeCase_1.h"
#include "Tests/TestEdgeCase_2.h"
#include "Tests/TestSorting_1.h"
#include "Tests/TestSorting_2.h"
#include "Tests/TestAverageSize_1.h"
#include "Tests/TestAverageSize_2.h"
#include "Tests/TestAverageSize_3.h"
#include "Tests/TestAverageSize_4.h"
#include "Tests/TestAverageSize_5.h"
#include "Tests/TestAverageSize_6.h"
#include "Tests/TestMaxSize_1.h"
#include "Tests/TestMaxSize_2.h"
#include "Tests/TestMaxSize_3.h"
#include "Tests/TestMaxSize_4.h"
#include "Tests/TestMaxSize_5.h"
#include "Tests/TestMaxSize_6.h"



void InitTestPool(TestPool* testPool) {
    int testCount = 23;
    testPool->tests = malloc(sizeof(Test*) * testCount);
    testPool->testCount = testCount;

    int i = 0;
    testPool->tests[i++] = &TestEdgeCase_2;
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