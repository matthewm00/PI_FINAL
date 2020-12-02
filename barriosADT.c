#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "barriosADT.h"

#define BLOQUE 50

typedef struct barrio
{
    char *name;
    size_t habitants;
    size_t treeQty;
    char **treeName;
    size_t *count;
    size_t sizeTreeName;
} tBarrio;

struct node
{
    tBarrio barrio;
    size_t treesQty; //cantidad de arboles en el barrio
    size_t treesPerHab;
    char **treeName;   //nombres de los arboles que hay en el barrio
    size_t *count;     //cant de veces que aparecen dichos arboles
    char *popularTree; //nombre del arbol + popular del barrio
    struct node *tail;
};
typedef struct node *TNodeBarrio;

struct barrioCDT
{
    TNodeBarrio first;   //orden descendente por cantidad de arboles por hab
    TNodeBarrio current; //para iterar
    tBarrio *vec;
    size_t size;
};
static int checkMemory()
{
    if (errno != ENOMEM)
        return 1;
    perror("ERROR");
    errno = 0;
    return 0;
}

barrioADT newBarrio()
{
    barrioADT barr = calloc(1, sizeof(struct barrioCDT));
    if (!checkMemory())
        return NULL;
    return barr;
}

int addNeighbourhood(barrioADT barr, const char *name, size_t habitants)
{

    if (barr->size % BLOQUE == 0)
    {
        barr->vec = realloc(barr->vec, (barr->size + BLOQUE) * sizeof(tBarrio));
        if (!checkMemory())
            return 0;
    }

    barr->vec[barr->size].name = malloc(strlen(name) + 1);
    if (!checkMemory())
        return 0;
    strcpy(barr->vec[barr->size].name, name);
    barr->vec[barr->size].habitants = habitants;
    barr->size++;
    return 1;
}
int addTree(barrioADT barr, const char *neighbourhoodName, const char *treeName)
{
    for (int i = 0; i < barr->size; i++)
    {
        if (strcmp(barr->vec[i].name, neighbourhoodName) == 0)
        {
            barr->vec[i].treeQty++;
            int j;
            for (j = 0; j < barr->vec[i].sizeTreeName; j++) //chequeo si esta ese arbol para incrementar su cantidad
            {
                if (strcmp(barr->vec[i].treeName[j], treeName))
                {
                    barr->vec[i].count[j]++;
                }
            }
            if (barr->vec[i].sizeTreeName % BLOQUE == 0)
            {
                barr->vec[i].treeName = realloc(barr->vec[i].treeName, (barr->vec[i].sizeTreeName + BLOQUE) * sizeof(char *));
                barr->vec[i].count = realloc(barr->vec[i].count, (barr->vec[i].sizeTreeName + BLOQUE) * sizeof(size_t));
            }
            barr->vec[i].treeName[j] = malloc(strlen(treeName) + 1);
            strcpy(barr->vec[i].treeName[j], treeName);
            barr->vec[i].count[j]++;
            barr->vec[i].sizeTreeName++;

            return 1;
        }
    }
    return 0;
}