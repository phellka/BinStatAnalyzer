#include "StatFileDump.h"
#include <stdio.h>
#include <stdlib.h>

int storeStatData(FILE* file,  StatData* statData) {
    if (fwrite(statData, sizeof(StatData), 1, file) != 1) {
        perror("Error writing StatData to file");
        return 1;
    }
    return 0;
}

int loadStatData(FILE* file, StatData* statData) {
    if (fread(statData, sizeof(StatData), 1, file) != 1) {
        perror("Error reading StatData from file");
        return 1;
    }
    return 0;
}

int storeStatCollection(FILE* file, const StatCollection* stats) {
    if (fwrite(&stats->size, sizeof(stats->size), 1, file) != 1) {
        perror("Error writing collection size to file");
        return 1;
    }

    for (size_t i = 0; i < stats->size; ++i) {
        if (storeStatData(file, &stats->items[i]) != 0) {
            return 1;
        }
    }
    return 0;
}

int loadStatCollection(FILE* file, StatCollection* collection) {
    if (fread(&collection->size, sizeof(size_t), 1, file) != 1) {
        perror("Error reading collection size from file");
        return 1;
    }
    
    collection->items = malloc(collection->size * sizeof(StatData));
    if (collection->items == NULL) {
        perror("Failed to allocate memory for items");
        return 1;
    }

    for (size_t i = 0; i < collection->size; i++) {
        if (loadStatData(file, &collection->items[i]) != 0) {
            fprintf(stderr, "Error reading StatData[%zu]\n", i);
            free(collection->items);
            return 1;
        }
    }
    return 0;
}

int StoreDump(StatCollection* stats, const char* fileName) {
    if (stats == NULL) {
        fprintf(stderr, "StoreDump: Collection is null\n");
        return 1;
    }
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        perror("StoreDump: File not open");
        return 1;
    }
    if (storeStatCollection(file, stats) != 0) {
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

int LoadDump(StatCollection* stats, const char* fileName) {
    if (stats == NULL) {
        fprintf(stderr, "LoadDump: Collection is null\n");
        return 1;
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("LoadDump: File not open");
        return 1;
    }
    if (loadStatCollection(file, stats) != 0) {
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}