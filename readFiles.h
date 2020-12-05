
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

#define OK 1
#define FILE_ERROR 0
#define MEM_ERROR 2

int readNHood(const char *file, NHoodADT nHood);

int readTree(const char *file, NHoodADT nh, treeADT t, size_t cNHood, size_t cTree);
