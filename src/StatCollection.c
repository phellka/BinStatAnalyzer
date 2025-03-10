#include "StatCollection.h"
#include <stdio.h>
#include <stdlib.h>

int compStaDataById(const void* a, const void* b) {
    return (*(StatData*)a).id - (*(StatData*)b).id;
}

int compStaDataByCost(const void* a, const void* b) {
    return (*(StatData*)a).cost - (*(StatData*)b).cost;
}

int SortCollection(StatCollection* stats) {
    if (stats == NULL) {
        fprintf(stderr, "Error: Invalid stats pointer\n");
        return 1;
    }
    qsort(stats->items, stats->size, sizeof(StatData), compStaDataByCost);
}

void mergeStatData(StatData* target, const StatData* source) {
    target->count += source->count;
    target->cost += source->cost;
    if (target->primary * source->primary == 0) {
        target->primary = 0;
    }
    if (source->mode > target->mode) {
        target->mode = source->mode;
    }
}

void copyStatData(StatData* target, const StatData* source) {
    target->id = source->id;
    target->cost = source->cost;
    target->count = source->count;
    target->mode = source->mode;
    target->primary = source->primary;
}

int JoinCollections(const StatCollection* left, const StatCollection* right, StatCollection* res) {
    if (left == NULL || right == NULL)  {
        fprintf(stderr, "Error: Invalid collection pointer\n");
        return 1;
    }
    qsort(left->items, left->size, sizeof(StatData), compStaDataById);
    qsort(right->items, right->size, sizeof(StatData), compStaDataById);

    res->items = malloc((left->size + right->size) * sizeof(StatData));
    if (res->items  == NULL) {
        perror("Failed to allocate memory for items");
        return 1;
    }
    size_t l = 0;
    size_t r = 0;
    size_t size = 0;
    while (l < left->size || r < right->size) {
        StatData* newData;
        size_t* indNewData;
        if (l >= left->size) {
            newData = &right->items[r];
            indNewData = &r;
        } else
        if (r >= right->size) {
            newData = &left->items[l];
            indNewData = &l;
        } else
        if (left->items[l].id < right->items[r].id) {
            newData = &left->items[l];
            indNewData = &l;
        } else {
            newData = &right->items[r];
            indNewData = &r;
        }

        if (size > 0 && newData->id == res->items[size - 1].id) {
            mergeStatData(&res->items[size - 1], newData);
            (*indNewData)++;
        }
        else {
            copyStatData(&res->items[size++], newData);
            (*indNewData)++;
        }
    }
    res->size = size;
    if (size >= left->size + right->size) {
        fprintf(stderr, "Error: Size exceeds allocated space\n");
        free(res->items);
        return 1;
    }
    StatData* temp = realloc(res->items, res->size * sizeof(StatData));
    if (temp == NULL) {
        perror("Failed to realloc memory for merged collection");
        free(res->items);
        return 1;
    }
    res->items = temp;
    return 0;
}