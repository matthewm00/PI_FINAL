#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "barriosADT.h"

#define BLOCK 50

typedef struct NHood
{
    char *name; // nombre del barrio
    size_t habitants;
    size_t treeQty; // total de arboles del barrio
    char **treeName; // nombres de todos los arboles del barrio
    size_t *count; // cantidad de apariciones de cada arbol
    size_t sizeTreeName; // dimension de los dos vecs de arriba
} tNHood;

struct node
{
    tNHood NHood;
    size_t treesQty; //cantidad de arboles en el barrio
    size_t treesPerHab;
    char **treeName;   //nombres de los arboles que hay en el barrio
    size_t *count;     //cant de veces que aparecen dichos arboles
    char *popularTree; //nombre del arbol + popular del barrio
    struct node *tail;
};
typedef struct node *TNodeNHood;

struct NHoodCDT
{
    TNodeNHood first;   //orden descendente por cantidad de arboles por hab
    TNodeNHood current; //para iterar
    tNHood *vec;
    size_t size;
};
static int checkMemory()
{
    if (errno != ENOMEM)
        return 1;
    perror("MEMORY ERROR");
    errno = 0;
    return 0;
}

NHoodADT newNHood()
{
    NHoodADT nh = calloc(1, sizeof(struct NHoodCDT));
    if (!checkMemory())
        return NULL;
    return nh;
}

int addNHood(NHoodADT nh, const char *name, size_t habitants)
{

    if (nh->size % BLOCK == 0)
    {
        nh->vec = realloc(nh->vec, (nh->size + BLOCK) * sizeof(tNHood));
        if (!checkMemory())
            return 0;
    }

    nh->vec[nh->size].name = malloc(strlen(name) + 1);
    if (!checkMemory())
        return 0;
    strcpy(nh->vec[nh->size].name, name);
    nh->vec[nh->size].habitants = habitants;
    nh->vec[nh->size].treeName = malloc(sizeof(char*));
    nh->vec[nh->size].count = NULL;
    nh->vec[nh->size].sizeTreeName = 0;
    nh->vec[nh->size].treeQty = 0;
    nh->size++;
    return 1;
}
int addTree(NHoodADT nh, const char *NHoodName, const char *treeName)
{
    for (int i = 0; i < nh->size; i++)
    {
        if (strcmp(nh->vec[i].name, NHoodName) == 0)
        {
            nh->vec[i].treeQty++;
            int j;
            for (j = 0; j < nh->vec[i].sizeTreeName; j++) //chequeo si esta ese arbol para incrementar su cantidad
            {
                if (strcmp(nh->vec[i].treeName[j], treeName) == 0)
                {
                    nh->vec[i].count[j]++;
                    return 1;
                }
            }
            if (nh->vec[i].sizeTreeName % BLOCK == 0)
            {
                nh->vec[i].treeName = realloc(nh->vec[i].treeName, (nh->vec[i].sizeTreeName + BLOCK) * sizeof(char *));
                nh->vec[i].count = realloc(nh->vec[i].count, (nh->vec[i].sizeTreeName + BLOCK) * sizeof(size_t));
                for (int k = j; k < j + BLOCK; k++) {
                     nh->vec[i].count[k] = 0;
                }
            }
            nh->vec[i].treeName[j] = malloc(strlen(treeName) + 1);
            strcpy(nh->vec[i].treeName[j], treeName);
            nh->vec[i].count[j]++;
            nh->vec[i].sizeTreeName++;

            return 1;
        }
    }
    return 0;
}
