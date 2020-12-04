
#include "queries.h"

#define NHOOD_NAME 6
#define TREE_NAME 64

void addToQuery(NHoodADT nh, FILE *query, int num)
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
