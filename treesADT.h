#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

typedef struct treeCDT *treeADT;

//Devuelve un nuevo y vacio treeADT
treeADT newTree();

//Agrega un arbol al vector de arboles
int addTree(treeADT t, const char *name, const char *NHoodName);

//Libera el espacio en memoria utilizado
void freeTreeVec(treeADT t);

//Devuelve el nombre del arbol de la posicion index del vector
char *getTreeName(treeADT t, int index);

//Devuelve el nombre del barrio donde se encuentra el arbol de la posicion index del vec
char *getNHoodName(treeADT t, int index);

//Devuelve la cantidad de veces que esta el tipo de arbol de la posicion index en ese barrio
int getTreeAppearences(treeADT t, int index);

//Devuelve la dimension del vector de arboles
size_t getSize(treeADT t);
