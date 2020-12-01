#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "treesADT.h"

typedef struct tree
{
    char *neighbourhood;
    char *street;
    char *name; //nombre cientifico
    size_t diameter;
} tTree;
struct node
{
    tTree tree;
    float perHabitant; //cant por habitante
    struct node *tail;
};
typedef struct node *TNodeTree;

struct barrioCDT
{
    TNodeTree first;
    TNodeTree current; //para iterar
};
