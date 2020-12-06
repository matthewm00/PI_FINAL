#include "readFiles.h"

int readNHood(const char *file, NHoodADT nHood)
{
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char *nHoodName;
	char *habs;

	FILE *dataFlow = fopen(file, "r"); //Abrimos el archivo de barrios
	if (dataFlow == NULL)
	{
		return FILE_ERROR;
	}
	if (!feof(dataFlow))
		fgets(aux, MAX_LONG, dataFlow); //Salteamos la primer linea
	while (!feof(dataFlow))
	{
		fgets(aux, MAX_LONG, dataFlow);
		if (!feof(dataFlow))
		{
			nHoodName = strtok(aux, delim);
			habs = strtok(NULL, delim);
			if (!addNHood(nHood, nHoodName, atol(habs)))
			{
				return MEM_ERROR;
			}
		}
	}
	fclose(dataFlow);
	return OK;
}

// Envia la informacion necesaria recopilada en readTree (explicita en los nombres de las funciones get)
// a la estructura de los barrios
static void treesToNHoods(treeADT t, NHoodADT nh)
{
	size_t treeSize = getSize(t);
	for (int i = 0; i < treeSize; i++)
	{
		char *NHoodName = getNHoodName(t, i);
		char *treeName = getTreeName(t, i);
		size_t ap = getTreeAppearences(t, i);

		//Funcion presente en NHoodADT.c que agrega solamente los arboles pertenecientes a los barrios
		//que figuran en los archivos de barrios CSV
		addTreeToNHood(nh, NHoodName, treeName, ap);
	}
}

int readTree(const char *file, NHoodADT nh, treeADT t, size_t cNHood, size_t cTree)
{
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char *nHoodName;
	char *treeName;

	FILE *dataFlow = fopen(file, "r"); //Abrimos el archivo de arboles
	if (dataFlow == NULL)
	{
		return FILE_ERROR;
	}
	if (!feof(dataFlow))
		fgets(aux, MAX_LONG, dataFlow); //Salteamos la primer linea

	while (!feof(dataFlow))
	{
		fgets(aux, MAX_LONG, dataFlow);

		if (!feof(dataFlow))
		{
			strtok(aux, delim);
			for (int i = 1, j = 0; j < DATA_TREES; i++)
			{
				if (i == cNHood - 1)
				{
					nHoodName = strtok(NULL, delim);
					j++;
				}
				else if (i == cTree - 1)
				{
					treeName = strtok(NULL, delim);
					j++;
				}
				else
					strtok(NULL, delim);
			}
			if (!addTree(t, treeName, nHoodName))
			{
				return MEM_ERROR;
			}
		}
	}
	fclose(dataFlow);

	treesToNHoods(t, nh);

	return OK;
}
