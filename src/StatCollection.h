#pragma once

#include <stdio.h>
#include "StatData.h"


typedef struct 
{
    StatData* items;
    size_t size;
} StatCollection;


int JoinDump(const StatCollection* left, const StatCollection* right, StatCollection* res);
int SortDump(StatCollection* stats);