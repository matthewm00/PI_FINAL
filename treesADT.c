#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "treesADT.h"

#define BLOQUE 50

typedef struct tree
{
    char *neighbourhood;
    char *name; //nombre cientifico
    size_t appearences;
} tTree;
struct node
{
    tTree tree;
    struct node *tail;
};
typedef struct node *TNodeTree;

struct treeCDT
{
    TNodeTree first;
    TNodeTree current; //para iterar
    tTree *vec;
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

treeADT newTree()
{
    treeADT t = calloc(1, sizeof(struct treeCDT));
    if (!checkMemory())
        return NULL;
    return t;
}

int addTree(treeADT t, const char *name, const char *neighbourhood)
{
    for (int i = 0; i < t->size; i++)
    {
        if (strcmp(t->vec[i].name, name) == 0)
        {
            t->vec[i].appearences++;

            /*if (strcmp(t->vec[i].neighbourhood, neighbourhood) == 0)
            {
                t->vec[i].appearencesInNeighbourhood++;
            }
            */
            return 1;
        }
    }

    if (t->size % BLOQUE == 0)
    {
        t->vec = realloc(t->vec, (t->size + BLOQUE) * sizeof(tTree));
        if (!checkMemory())
            return 0;
    }

    t->vec[t->size].name = malloc(strlen(name) + 1);
    t->vec[t->size].neighbourhood = malloc(strlen(neighbourhood) + 1);
    if (!checkMemory())
        return 0;
    strcpy(t->vec[t->size].name, name);
    strcpy(t->vec[t->size].neighbourhood, neighbourhood);
    t->vec[t->size].appearences = 1;
    t->size++;
    return 1;
}