
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "treesADT.h"
#include "NHoodADT.h"

#define MAX_LONG 1024
#define DATA_NHOOD 2
#define DATA_TREES 2
#define MAX_NHOOD 8
#define MAX_NAME_TREES 64

#define OK 1
#define FILE_ERROR 0
#define MEM_ERROR 2

//Copia la info del dataset en un vector presente en la estructura a la que apunta nHood
int readNHood(const char *file, NHoodADT nHood);

/*Copia solamente la info del dataset que nos interesa (nombre del arbol y el nombre del barrio en donde se encuentra)
**en un vector presente en la estructura a la que apunta t
**los dos ultimos parametros sirven para identificar en que columnas estan esos datos
*/
int readTree(const char *file, NHoodADT nh, treeADT t, size_t cNHood, size_t cTree);
