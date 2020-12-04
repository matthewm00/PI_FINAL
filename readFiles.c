#include "readFiles.h"

void readNHood(const char * file, NHoodADT nHood) {
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char nHoodName[MAX_NHOOD];
	char habs[MAX_NHOOD];

	FILE * dataFlow = fopen(file, "r"); // apertura del archivo de barrios
	if( dataFlow == NULL ) {
		printf("Error in input file\n");
		exit(1);
	}
  if ( !feof ( dataFlow) )
		// fgets(aux, MAX_LONG, dataFlow); // Descartamos la primer linea
		// no seria mejor usar fseek para saltear la 1er linea
		fseek(dataFlow, MAX_LONG, SEEK_SET);
	while(!feof(dataFlow)) {
		fgets(aux, MAX_LONG, dataFlow);
		if(!feof(dataFlow)){
			strcpy(nHoodName, strtok(aux,delim));
			strcpy(habs, strtok(NULL, delim));
			if(!addNHood(nHood,nHoodName,atol(habs))){
				freeCiudad(nHood);
				exit(2);
			}
		}
	}
	fclose(dataFlow);
}

void readTree(const char * file, NHoodADT nh, treeADT t, size_t flag, size_t cNHood, size_t cTree) {
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char nHoodName[MAX_NHOOD];
	char treeName[MAX_NAME_TREES];

	FILE * dataFlow = fopen(file, "r"); // apertura del archivo de arboles
	if( dataFlow == NULL ) {
		printf("Error en la apertura del archivo\n");
		exit(1);
	}
	if ( !feof ( dataFlow) )
		fgets(aux, MAX_LONG, dataFlow); // Descartamos la primer linea

	while(!feof(dataFlow)) {
		fgets(aux, MAX_LONG, dataFlow);
		if(!feof(dataFlow)) {
			strtok(aux,delim);
			for(int i = 1, j = 0; j < DATA_TREES; i++) {
		          if(i == cNHood - 1)
		          {
		             strcpy(nHoodName,aux);
		          }
		          if(i == cTree - 1)
		          {
		            strcpy(treeName,aux);
		          }
		            aux=strtok(NULL,";");
				  if(!addTree(t, treeName, nHoodName)){
					  freeTree(t);
					  freeNHoodList(nh);
					  exit(2);
				  }
		     }
		}
	}
	fclose(dataFlow);
	if (!treesToNHoods(t, nh)) {
		freeTree(t);
		freeNHoodList(nh);
		exit(2);
	}
}

static int treesToNHoods(treeADT t, NHoodADT nh){
	for (size_t i = 0; i < t->size; i++) {
		if (!addTreeToNHood(nh, t->vec[i].NHoodName, t->vec[i].name, t->vec[i].appearences)) {
			return 0;
		}
	}
	return 1;
}
