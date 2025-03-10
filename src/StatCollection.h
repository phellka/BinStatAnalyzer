#pragma once

#include <stdio.h>
#include "StatData.h"


typedef struct 
{
    StatData* items;
    size_t size;
} StatCollection;


void JoinDump(const StatCollection* left, const StatCollection* right, StatCollection* res);
void SortDump(StatCollection* stats);