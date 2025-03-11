#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TestPool.h"

#define COLOR_RESET   "\033[0m"
#define COLOR_SUCCESS "\033[32m"
#define COLOR_FAILURE "\033[31m"
#define COLOR_INFO    "\033[34m"
#define COLOR_BOLD    "\033[1m"

int main() {
    TestPool testPool;
    InitTestPool(&testPool);
    
    int countSuccess = 0;
    printf(COLOR_INFO "==================== Running Tests ====================\n" COLOR_RESET);
    
    for (int i = 0; i < testPool.testCount; ++i) {
        printf("Test: %-20s ", testPool.tests[i]->name);
        fflush(stdout);
        
        double testTime = ExecTest(testPool.tests[i]);
        if (testTime < 0) {
            printf(COLOR_FAILURE "[FAILED]\n" COLOR_RESET);
        } else {
            printf(COLOR_SUCCESS "[PASSED]  " COLOR_RESET);
            printf("Execution time: %.6f sec\n", testTime);
            countSuccess++;
        }
    }

    printf(COLOR_INFO "=======================================================\n" COLOR_RESET);
    printf(COLOR_BOLD "Tests passed: %d / %ld  (%.2f%% success rate)\n" COLOR_RESET, 
           countSuccess, testPool.testCount, 
           (testPool.testCount > 0) ? (100.0 * countSuccess / testPool.testCount) : 0.0);

    CloseTestPool(&testPool);
    return 0;
}