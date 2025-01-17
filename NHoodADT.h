#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>

typedef struct NHoodCDT *NHoodADT;

//Devuelve un nuevo y vacio NHoodADT
NHoodADT newNHood();

//Agrega un barrio al vector que guarda todos los barrios
int addNHood(NHoodADT nh, const char *name, size_t habitants);

//Agrega un arbol a un barrio contenido en el vector
void addTreeToNHood(NHoodADT nh, const char *NHoodName, const char *treeName, size_t appearences);

/*Crea una lista de barrios, ordenada de dos formas distintas:
**la 1era es por orden descendente segun el total de arboles/habitantes
**en caso de igual valor en dos barrios distintos, se desempata por orden alfabetico
**la 2da forma, corresponde exclusivamente al orden alfabetico
*/
int NHoodList(NHoodADT nh);

//Libera el espacio en memoria reservado para la estructura principal CDT
void freeNHoodList(NHoodADT nhList);

//Libera el espacio en memoria reservado para el vector
void freeNHoodVec(NHoodADT nh);

//Para iniciar la iteracion por la lista de la 1era forma
void toBeginByHab(NHoodADT nhList);

//Verifica que el iterador no haya llegado al final de la lista
int hasNextByHab(NHoodADT nhList);

//Setea valores en los parametros de salida y avanza en la iteracion
void nextByHab(NHoodADT nhList, char *NHoodName, float *treesPerHab);

//Idem para la 2da forma del tipo de recorrido de la lista
void toBeginByPop(NHoodADT nhList);

int hasNextByPop(NHoodADT nhList);

void nextByPop(NHoodADT nhList, char *NHoodName, char *popularTree);
