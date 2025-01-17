
#include "treesADT.h"

#define BLOCK 50

typedef struct tree
{
    char *NHoodName;    //nombre del barrio
    char *name;         //nombre del arbol
    size_t appearences; //cantidad de apariciones de ese arbol en ese barrio
} tTree;

struct treeCDT
{
    tTree *vec;
    size_t size;
};

static int checkMemory(void)
{
    if (errno != ENOMEM)
        return 1;
    perror("Error: ");
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

int addTree(treeADT t, const char *name, const char *NHoodName)
{
    for (int i = 0; i < t->size; i++)
    {
        if (strcmp(t->vec[i].NHoodName, NHoodName) == 0 && strcmp(t->vec[i].name, name) == 0)
        {
            t->vec[i].appearences++;
            return 1;
        }
    }

    if (t->size % BLOCK == 0)
    {
        t->vec = realloc(t->vec, (t->size + BLOCK) * sizeof(tTree));
        if (!checkMemory())
            return 0;
        for (int k = t->size; k < t->size + BLOCK; k++)
        {
            t->vec[k].appearences = 0;
        }
    }

    t->vec[t->size].name = malloc(strlen(name) + 1);
    t->vec[t->size].NHoodName = malloc(strlen(NHoodName) + 1);

    if (!checkMemory())
        return 0;

    strcpy(t->vec[t->size].name, name);
    strcpy(t->vec[t->size].NHoodName, NHoodName);
    t->vec[t->size].appearences = 1;
    t->size++;
    return 1;
}
static int checkIndex(treeADT t, int index)
{
    return index < t->size;
}
char *getNHoodName(treeADT t, int index)
{
    if (!checkIndex(t, index))
        return NULL;

    return t->vec[index].NHoodName;
}
char *getTreeName(treeADT t, int index)
{
    if (!checkIndex(t, index))
        return NULL;

    return t->vec[index].name;
}
int getTreeAppearences(treeADT t, int index)
{
    if (!checkIndex(t, index))
        return 0;

    return t->vec[index].appearences;
}
size_t getSize(treeADT t)
{
    return t->size;
}

void freeTreeVec(treeADT t)
{
    for (size_t i = 0; i < t->size; i++)
    {
        free(t->vec[i].NHoodName);
        free(t->vec[i].name);
    }
    free(t->vec);
    free(t);
}
