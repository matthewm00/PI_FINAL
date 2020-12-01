#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "barriosADT.h"

typedef struct barrio
{
    char *name;
    size_t habitants;
} tBarrio;

struct node
{
    tBarrio barr;
    struct node *tail;
};
typedef struct node *TNodeBarrio;

struct barrioCDT
{
    TNodeBarrio first;
    TNodeBarrio current; //para iterar
};
