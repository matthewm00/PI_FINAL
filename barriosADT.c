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
    size_t treesPerHab;
} tBarrio;

struct node
{
    tBarrio barr;
    char *popularTree; //nombre del arobol + popular del barrio
    struct node *tail;
};
typedef struct node *TNodeBarrio;

struct barrioCDT
{
    TNodeBarrio first;
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

int addTree(barrioADT barr, const char *name, size_t habitants)
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