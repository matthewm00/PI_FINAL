
#include "queries.h"

#define COL_NHOOD 3
#define COL_TREE_NAME 8

int main(int argc, char const *argv[])
{
     if (argc != 3)
     {
          fprintf(stderr, "Incorrect amount of arguments introduced\n");
          return EXIT_FAILURE;
     }
     treeADT tree = newTree();
     NHoodADT nh = newNHood();

     if (tree == NULL || nh == NULL)
     {
          fprintf(stderr, "Memory Error\n");
          freeNHoodList(nh);
          freeTreeVec(tree);
          return EXIT_FAILURE;
     }
     int r;
     r = readNHood(argv[2], nh);
     if (r == FILE_ERROR)
     {
          fprintf(stderr, "Error in input files\n");
          doFrees(nh, tree);
          return EXIT_FAILURE;
     }
     else if (r == MEM_ERROR)
     {
          fprintf(stderr, "Memory Error\n");
          doFrees(nh, tree);
          return EXIT_FAILURE;
     }

     r = readTree(argv[1], nh, tree, COL_NHOOD, COL_TREE_NAME);
     if (r == FILE_ERROR)
     {
          fprintf(stderr, "Error in input files\n");
          doFrees(nh, tree);
          return EXIT_FAILURE;
     }
     else if (r == MEM_ERROR)
     {
          fprintf(stderr, "Memory Error\n");
          doFrees(nh, tree);
          return EXIT_FAILURE;
     }

     if (!NHoodList(nh))
     {
          fprintf(stderr, "Memory error\n");
          doFrees(nh, tree);
          return EXIT_FAILURE;
     }

     FILE *query1, *query2;
     query1 = fopen("query1BUE.csv", "w");
     query2 = fopen("query2BUE.csv", "w");
     createQuery(nh, query1, 1);
     createQuery(nh, query2, 2);

     doFrees(nh, tree);

     return EXIT_SUCCESS;
}
