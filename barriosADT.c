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
    float treesPerHab; // tree/habitants
    char *popularTree;   //nombre del arbol que aparece + veces
    size_t popularCount; //cantidad de veces que aparece
} tNHood;

struct node
{
    char *name;
    double treesPerHab;
    char *popularTree; //nombre del arbol que aparece + veces
    struct node *tailByHab;
    struct node *tailByPop;
};
typedef struct node *TNodeNHood;

struct NHoodCDT
{
    TNodeNHood firstByHab;    //orden descendente segun total arboles/habitantes, luego alfabetico por nombre de barrio
    TNodeNHood firstByPop;    //alfabetico por nombre de barrio
    TNodeNHood currentPerHab; //para iterar
    TNodeNHood currentByPop;
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
    nh->vec[nh->size].treeQty = 0;
    nh->vec[nh->size].popularTree = NULL;
    nh->vec[nh->size].popularCount = 0;
    nh->size++;
    return 1;
}
int addTree(NHoodADT nh, const char *NHoodName, const char *treeName, size_t appearences)
{
    for (int i = 0; i < nh->size; i++)
    {
        if (strcmp(nh->vec[i].name, NHoodName) == 0)
        {
            nh->vec[i].treeQty++;

            if (nh->vec[i].popularCount < appearences)
            {
                nh->vec[i].popularTree = realloc(nh->vec[i].popularTree, strlen(treeName) + 1);
                strcpy(nh->vec[i].popularTree, treeName);
                nh->vec[i].popularCount = appearences;
            }

            return 1;
        }
    }
    return 0;
}
static void treesPerHab(NHoodADT nh)
{
    for (int i = 0; i < nh->size; i++)
    {
        double ans;
        if (nh->vec[i].habitants == 0)
            ans = 0;
        else
        {
            ans = ((int)(((double)nh->vec[i].treeQty / (double)nh->vec[i].habitants) * 100)) / 100.0;
            //trunca el valor treesPerHab a dos decimales
        }
        nh->vec[i].treesPerHab = ans;
    }
}
static TNodeNHood sortAlph(TNodeNHood first, TNodeNHood new) //ordena alfabeticamente los nodos para la query de los popular trees
{
    if (first == NULL || strcmp(first->name, new->name) > 0)
    {
        new->tailByPop = first;
        return new;
    }
    first->tailByPop = sortAlph(first->tailByPop, new);
    return first;
}

static TNodeNHood createNode(tNHood nh){
     TNodeNHood new = malloc(sizeof(struct node));
     new->treesPerHab = nh.treesPerHab;
     new->name = malloc(strlen(nh.name) + 1);
     new->popularTree = malloc(strlen(nh.popularTree) + 1);
     strcpy(new->name, nh.name);
     strcpy(new->popularTree, nh.popularTree);
     if (!checkMemory())
     {
         free(new);
         return NULL;
     }
     return new;
}

static TNodeNHood addNode(TNodeNHood firstByHab, NHoodADT nhList, tNHood nh, int *ok) //la idea seria que addNode resuelva los dos queries
{
    if (firstByHab == NULL || firstByHab->treesPerHab < nh.treesPerHab)
    {
        TNodeNHood new = createNode(nh);
        if (new == NULL) {
             return firstByHab;
        }
        new->tailByHab = firstByHab;
        nhList->firstByPop = sortAlph(nhList->firstByPop, new);
        *ok = 1;
        return new;
    }
    if (firstByHab->treesPerHab == nh.treesPerHab) {
         TNodeNHood new = createNode(nh);
         if (new == NULL) {
              return firstByHab;
         }
         *ok = 1;
         nhList->firstByPop = sortAlph(nhList->firstByPop, new);
         if (strcmp(firstByHab->name, nh.name) > 0) {
             new->tailByHab = firstByHab;
             return new;
        }else{
             TNodeNHood aux = firstByHab->tailByHab;
             firstByHab->tailByHab = new;
             new->tailByHab = aux;
             return firstByHab;
        }
    }
    firstByHab->tailByHab = addNode(firstByHab->tailByHab, nhList, nh, ok);
    return firstByHab;
}
int NHoodList(NHoodADT nh)
{
    treesPerHab(nh);
    for (int i = 0; i < nh->size; i++)
    {
        int ok = 0;
        nh->firstByHab = addNode(nh->firstByHab, nh, nh->vec[i], &ok);
        if (!ok)
            return 0;
    }
}
