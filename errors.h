
#include "treesADT.h"
#include "NHoodADT.h"
#include <errno.h>

#define OK 1
#define FILE_ERROR 0
#define MEM_ERROR 2

int checkMemory(void);

void doFrees(NHoodADT nh, treeADT tree);