
#include "queries.h"

#define COL_NHOOD 3
#define COL_TREE_NAME 8

int main(int argc, char const *argv[])
{
     if (argc != 3)
     {
          printf("Cantidad incorrecta de argumentos introducidos\n");
          return 1;
     }
     treeADT tree = newTree();
     NHoodADT nh = newNHood();

     readNHood(argv[2], nh);
     readTree(argv[1], nh, tree, COL_NHOOD, COL_TREE_NAME);

     if (!NHoodList(nh))
     {
          fprintf(stderr, "Memory Error\n");
     }
     else
     {
          FILE *query1, *query2;
          query1 = fopen("query1BUE.csv", "w");
          query2 = fopen("query2BUE.csv", "w");
          addToQuery(nh, query1, 1);
          addToQuery(nh, query2, 2);
     }

     freeNHoodList(nh);
     freeNHoodVec(nh);
     freeTreeVec(tree);

     return 0;
}
