
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "treesADT.h"
#include "NHoodADT.h"

#define MAX_LONG 1024
#define DATA_NHOOD 2
#define DATA_TREES 2
#define MAX_NHOOD 8
#define MAX_NAME_TREES 64

void readNHood(const char *file, NHoodADT nHood);

void readTree(const char *file, NHoodADT nh, treeADT t, size_t flag, size_t cNHood, size_t cTree);
