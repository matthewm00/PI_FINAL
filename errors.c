
#include "errors.h"

int checkMemory(void)
{
    if (errno != ENOMEM)
        return 1;
    perror("Error ");
    errno = 0;
    return 0;
}

void doFrees(NHoodADT nh, treeADT tree)
{
    freeNHoodList(nh);
    freeNHoodVec(nh);
    freeTreeVec(tree);
}
