

typedef struct treeCDT *treeADT;

//devuelve un nuevo y vacio treeADT
treeADT newTree();

//agrega un arbol al vector de arboles
int addTree(treeADT t, const char *name, const char *NHoodName);

//libera el espacio en memoria utilizado
void freeTree(treeADT t);

char *getNHoodName(treeADT t, int index);
char *getTreeName(treeADT t, int index);
int getTreeAppearences(treeADT t, int index);
size_t getSize(treeADT t);