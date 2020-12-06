#include "readFiles.h"

//Realiza los dos frees para la estructura de barrios, y el free para la estructura de arboles
void doFrees(NHoodADT nh, treeADT tree);

//Crea el query1 si num==1, y el query2 para num==2
void createQuery(NHoodADT nh, FILE *query, int num);