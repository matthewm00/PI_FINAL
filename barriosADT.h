typedef struct NHoodCDT *NHoodADT;

//devuelve un nuevo y vacio NHoodADT
NHoodADT newNHood();

//agrega un barrio al vector que guarda todos los barrios
int addNHood(NHoodADT nh, const char *name, size_t habitants);

//agrega un arbol a un barrio contenido en el vector
int addTree(NHoodADT nh, const char *NHoodName, const char *treeName, size_t appearences);

/*crea una lista de barrios, ordenada de dos formas distintas:
**la 1era es por orden descendente segun el total de arboles/habitantes
**en caso de igual valor en dos barrios distintos, se desempata por orden alfabetico
**la 2da forma, corresponde exclusivamente a orden alfabetico
*/
int NHoodList(NHoodADT nh);

//libera el espacio en memoria utilizado
void freeNHoodList(NHoodADT nhList);

//para iniciar la iteracion por la lista de la 1era forma
void toBeginByHab(NHoodADT nhList);

//verifica que el iterador no haya llegado al final de la lista
int hasNextByHab(NHoodADT nhList);

//setea valores en los parametros de salida y avanza en la iteracion
void nextByHab(NHoodADT nhList, char *NHoodName, double treesPerHab);

//idem para la 2da forma del tipo de recorrido de la lista
void toBeginByPop(NHoodADT nhList);

int hasNextByPop(NHoodADT nhList);

void nextByPop(NHoodADT nhList, char *NHoodName, char *popularTree);
