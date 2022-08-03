#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Red.h"
#include "parser.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;

	eRed* auxRed= NULL;

		char id[50];
		char user[50];
		char likes[50];
		char dislikes[20];
		char followers[20];
		int cant;


		if(pFile != NULL && pArrayList != NULL)
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, user, likes, dislikes, followers);

			do
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, user, likes, dislikes, followers);


				if(cant < 5)
				{
					break;
				}

				auxRed = newParametros(id, user, likes,dislikes, followers);

				if(auxRed!= NULL)
				{
					ll_add(pArrayList,auxRed);
					retorno = 0;
				}
			}while(!feof(pFile));
		}
	    return retorno;
}
