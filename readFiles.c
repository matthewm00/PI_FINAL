#include "readFiles.h"
#include "errors.h"

int readNHood(const char *file, NHoodADT nHood)
{
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char nHoodName[MAX_NHOOD];
	char habs[MAX_NHOOD];

	FILE *dataFlow = fopen(file, "r"); // apertura del archivo de barrios
	if (dataFlow == NULL)
	{
		return FILE_ERROR;
	}
	if (!feof(dataFlow))
		// fgets(aux, MAX_LONG, dataFlow); // Descartamos la primer linea
		// no seria mejor usar fseek para saltear la 1er linea
		fseek(dataFlow, MAX_LONG, SEEK_SET);
	while (!feof(dataFlow))
	{
		fgets(aux, MAX_LONG, dataFlow);
		if (!feof(dataFlow))
		{
			strcpy(nHoodName, strtok(aux, delim));
			strcpy(habs, strtok(NULL, delim));
			if (!addNHood(nHood, nHoodName, atol(habs)))
			{
				return MEM_ERROR;
			}
		}
	}
	fclose(dataFlow);
	return OK;
}

int readTree(const char *file, NHoodADT nh, treeADT t, size_t cNHood, size_t cTree)
{
	char aux[MAX_LONG];
	const char delim[2] = ";";
	char nHoodName[MAX_NHOOD];
	char treeName[MAX_NAME_TREES];

	FILE *dataFlow = fopen(file, "r"); // apertura del archivo de arboles
	if (dataFlow == NULL)
	{
		return FILE_ERROR;
	}
	if (!feof(dataFlow))
		fgets(aux, MAX_LONG, dataFlow); // Descartamos la primer linea

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
					strcpy(nHoodName, aux);
				}
				if (i == cTree - 1)
				{
					strcpy(treeName, aux);
				}
				strtok(NULL, delim);
				if (!addTree(t, treeName, nHoodName))
				{
					return MEM_ERROR;
				}
			}
		}
	}
	fclose(dataFlow);

	treesToNHoods(t, nh);

	return OK;
}

static void treesToNHoods(treeADT t, NHoodADT nh)
{
	size_t treeSize = getSize(t);
	for (int i = 0; i < treeSize; i++)
	{
		//funcion presente en el NHoodADT que agrega solamente los arboles pertenecientes a los barrios
		//que figuran en los archivos de barrios csv
		addTreeToNHood(nh, getNHoodName(t, i), getTreeName(t, i), getTreeAppearences(t, i));
	}
}
