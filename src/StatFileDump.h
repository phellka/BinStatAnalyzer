#pragma once

#include "StatCollection.h"

void StoreDump(StatCollection* stats, const char* fileName);
void LoadDump(StatCollection* stats, const char* fileName);