#include "StatData.h"
#include <stdio.h>

void printBinary(int num, int length) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void printStatData(const StatData* statData) {
    printf("%lX %d %.3e %c ", statData->id, statData->count, statData->cost, 
        statData->primary == 0 ? 'n' : 'y');
    printBinary(statData->mode, 3);
    printf("\n");
}