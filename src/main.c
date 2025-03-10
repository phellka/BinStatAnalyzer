#include <stdio.h>
#include "StatData.h"
#include "StatFileDump.h"
#include "StatCollection.h"
#include "StatFileDump.h"
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Утилита принимает 3 аргумента. Два пути до двух файлов, сформированных StoreDump. Путь до файла результата\n");
        return 0;
    }

    StatCollection collection1;
    if (LoadDump(&collection1, argv[1]) != 0) {
        printf("Error load file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    StatCollection collection2;
    if (LoadDump(&collection2, argv[2])!= 0) {
        free(collection1.items);
        printf("Error load file %s\n", argv[2]);
        return EXIT_FAILURE;
    }
    StatCollection collectionRes;
    if (JoinCollections(&collection1, &collection2, &collectionRes) != 0) {
        printf("Error joinDump %s\n", argv[3]);
        free(collection1.items); 
        free(collection2.items); 
        return EXIT_FAILURE;
    }
    free(collection1.items);
    free(collection2.items);

    SortCollection(&collectionRes);
    if (StoreDump(&collectionRes, argv[3]) != 0) {
        free(collectionRes.items);
        printf("Error save file %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    
    int n = 10;
    if (collectionRes.size < n) {
        n = collectionRes.size;
    }
    printf("| %-15s | %-7s | %-12s | %-1s | %-3s |\n", "ID", "Count", "Cost", "Primary", "Mode");
    printf("|-----------------|---------|--------------|---------|------|\n");
    for (int i = 0; i < n; ++i) {
        PrintStatData(&collectionRes.items[i]);
    }
    printf("\nWork complete\n");
    free(collectionRes.items);

    return 0;
}