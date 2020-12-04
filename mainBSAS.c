#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "NHoodADT.h"
#include "treesADT.h"

#define MAX_BUFFER 1024
#define TREE_NAME_BUFFER 80
#define NHOOD_NAME_BUFFER 5

int main(int argc, char const *argv[]) {
     if(argc!=3){
          printf("Cantidad incorrecta de argumentos introducidos\n");
          return 1;
     }
     // ciudadADT newciudad = nuevaCiudad();
     NHoodADT NHood = newNHood();
     if (!checkMemory()) {
          return 1; // revisar que retornar
     }
     // leeBarrios(argv[2], newciudad);
     FILE *trees, *nHoods, *query1BUE, *query2BUE;
     // ordenarBarrios(newciudad);
     //
     // leeArboles(argv[1], newciudad, BUE, CAMPO_COMUNA, CAMPO_ESPECIE, CAMPO_DIAM);
     //
     // generarQuery(newciudad,QUERY1);
     // generarQuery(newciudad,QUERY2);
     // generarQuery(newciudad,QUERY3);
     //
     // freeCiudad(newciudad);
     // printf("Se han generado los archivos correctamente\n");
     return 0;
}
