
#include "queries.h"

#define NHOOD_NAME 64
#define TREE_NAME 64

void createQuery(NHoodADT nh, FILE *query, int num)
{
    if (num == 1)
    {
        fprintf(query, "BARRIO;ARBOLES_POR_HABITANTE\n");
        char NHoodName[NHOOD_NAME];
        double treesPerHab;
        toBeginByHab(nh);
        while (hasNextByHab(nh))
        {
            nextByHab(nh, NHoodName, &treesPerHab);
            fprintf(query, "%s;%g\n", NHoodName, treesPerHab);
        }
    }
    else
    {
        fprintf(query, "BARRIO;NOMBRE_CIENTIFICO\n");
        char NHoodName[NHOOD_NAME];
        char treeName[TREE_NAME];
        toBeginByPop(nh);
        while (hasNextByPop(nh))
        {
            nextByPop(nh, NHoodName, treeName);
            fprintf(query, "%s;%s\n", NHoodName, treeName);
        }
    }
    fclose(query);
}

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