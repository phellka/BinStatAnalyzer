#pragma once

#include "StatCollection.h"

int StoreDump(StatCollection* stats, const char* fileName);
int LoadDump(StatCollection* stats, const char* fileName);