#include "StatFileDump.h"
#include <stdio.h>
#include <stdlib.h>

void storeStatData(FILE* file,  StatData* statData) {
    fwrite(statData, sizeof(StatData), 1, file);
}

void loadStatData(FILE* file, StatData* statData) {
    fread(statData, sizeof(StatData), 1, file);
}

void storeStatCollection(FILE* file, const StatCollection* stats) {
    fwrite(&stats->size, sizeof(stats->size), 1, file);

    for (size_t i = 0; i < stats->size; ++i) {
        storeStatData(file, &stats->items[i]);
    }
}

void loadStatCollection(FILE* file, StatCollection* collection) {
    fread(&collection->size, sizeof(size_t), 1, file);
    
    collection->items = malloc(collection->size * sizeof(StatData));

    for (size_t i = 0; i < collection->size; i++) {
        loadStatData(file, &collection->items[i]);
    }
}

void StoreDump(StatCollection* stats, const char* fileName) {
    if (stats == NULL) {
        fprintf(stderr, "StoreDump: Collection is null\n");
    }
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        perror("StoreDump: File not open");
        return;
    }
    storeStatCollection(file, stats);

    fclose(file);
}

void LoadDump(StatCollection* stats, const char* fileName) {
    if (stats == NULL) {
        fprintf(stderr, "LoadDump: Collection is null\n");
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("LoadDump: File not open");
        return;
    }
    loadStatCollection(file, stats);

    fclose(file);
}