#pragma once

#include <stdio.h>
#include "StatData.h"


typedef struct 
{
    StatData* items;
    size_t size;
} StatCollection;


int JoinCollections(const StatCollection* left, const StatCollection* right, StatCollection* res);
int SortCollection(StatCollection* stats);