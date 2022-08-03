#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Red.h"
#include "parser.h"
#include "funciones.h"

/*------------------------------------------------------------------------------------------------*/
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int ret = -1;
	FILE* f;
	f = fopen(path, "r");
	if(f != NULL && path != NULL && pArrayList != NULL)
	{
		parser_FromText(f, pArrayList);
		ret = 0;
	}
	fclose(f);
    return ret;
}
int controller_nameFile(LinkedList* pArrayList)
{
	int ret = -1;
	char path[31];

	if(pArrayList != NULL)
	{
			getString(path,"\nIngrese el nombre del archivo que desea cargar: ",
					"\nNombre muy largo\nIngrese el nombre del archivo que desea cargar: ", 30);
		while(controller_loadFromText(path, pArrayList) == -1)
		{
			getString(path,"\nNombre de archivo inexistente\nIngrese el nombre del archivo que desea cargar: ",
							"\nNombre demasiado largo\nIngrese el nombre del archivo que desea cargar: ", 30);
		}
	}
	return ret;
}

int controller_List(LinkedList* pArrayList)
{
	int ret = -1;
	eRed* auxRed;
	if(pArrayList != NULL)
	{
		printf("\t***RED SOCIAL***\n");
		printf("   ID                        User        Likes   Dislikes  Followers\n");
		for(int i = 0; i < ll_len(pArrayList); i++)
		{
			auxRed = (eRed*) ll_get(pArrayList, i);
			red_mostrarUno(auxRed);
			ret = 1;
		}
		if(ret == -1)
		{
			ret = 0;
		}

	}
    return ret;
}
/*------------------------------------------------------------------------------------------------*/
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int ret = 0;
	FILE* pFile = fopen(path,"w");
	eRed* auxRed;
	int auxId;
	char auxUser[50];
	int auxLikes;
	int auxDislikes;
	int followers;

	if (pFile !=NULL && pArrayList != NULL)
	{
        fprintf(pFile,"ID,USER,LIKES,DISLIKES,FOLLOWERS\n");
        for(int i = 1; i < ll_len(pArrayList); i++)
        {
        		auxRed = ll_get(pArrayList, i);
            	Red_getId(auxRed, &auxId);
            	Red_getUser(auxRed, auxUser);
            	Red_getLikes(auxRed, &auxLikes);
            	Red_getDislikes(auxRed, &auxDislikes);
            	Red_getFollowers(auxRed, &followers);

                fprintf(pFile,"%d,%s,%d,%d,%d\n", auxId, auxUser, auxLikes,auxDislikes, followers);
        }
        ret = 1;
        fclose(pFile);
	}
	return ret;
}
/*------------------------------------------------------------------------------------------------*/
void* controller_GenerarEstadisticas(void* pRed)
{
	int likes = -1;
	int dislikes = -1;
	int followers = -1;
	eRed* auxRed = NULL;
	int minLikes = 500;
	int minDislikes = 300;
	int minFollowers = 10000;
	if(pRed!=NULL)
	{
		auxRed = (eRed*) pRed;
		//*****************//
		likes = minLikes + rand() % (5001 - minLikes);
		//***************//
		dislikes = minDislikes + rand() % (3501 - minDislikes);
		//***************//
		followers = minFollowers + rand() % (20001 - minFollowers);
		//************//
		Red_setLikes(auxRed, likes);
		Red_setDislikes(auxRed, dislikes);
		Red_setFollowers(auxRed, followers);
	}

	return auxRed;
}
int controller_filtrarPorMejores(LinkedList* pArray)
{
		int ret = 0;
		LinkedList* listaFiltrada = ll_newLinkedList();

		if(pArray!=NULL)
		{
			for(int i = 0 ; i < ll_len(pArray); i++)
			{
				listaFiltrada = ll_filter(pArray, filtrarMejores);
			}
			if(controller_List(listaFiltrada) == 1)
			{
				if(controller_saveAsText("Mejores.csv", listaFiltrada))
				{
					printf("\nLos mejores posteos se guardaron exitosamente\n");
					ret=1;
				}
			}
			else if(controller_List(listaFiltrada) == 0)
			{
				printf("\nNo hay ningun posteo superior a 5k de likes en la lista\n");
			}
			ll_deleteLinkedList(listaFiltrada);
			ret = 1;
		}

		return ret;
}
int controller_filtrarHaters(LinkedList* pArray)
{
		int ret = 0;
		LinkedList* listaFiltrada = ll_newLinkedList();

		if(pArray!=NULL)
		{
			for(int i = 0 ; i < ll_len(pArray); i++)
			{
				listaFiltrada = ll_filter(pArray, filtrarHaters);
			}
			if(controller_List(listaFiltrada) == 1)
			{
				if(controller_saveAsText("Haters.csv", listaFiltrada))
				{
					printf("\nLos posteos con mas haters se guardaron exitosamente\n");
					ret=1;
				}
			}
			else if(controller_List(listaFiltrada) == 0)
			{
				printf("\nNo hay ningun posteo con mas dislikes que likes en la lista\n");
			}
			ll_deleteLinkedList(listaFiltrada);
			ret = 1;
		}

		return ret;
}
int controller_MasPopular(LinkedList* pArrayPais)
{
	int ret = -1;
	eRed* auxRed;
	int likes = -1;
	int likesTotal = -1;
	int tam;
	char user[50];
	if(pArrayPais != NULL)
	{
		tam = ll_len(pArrayPais);
		for(int i = 0; i < tam; i++)
		{
			auxRed = ll_get(pArrayPais, i);
			likes = auxRed->likes;
			if(likes > likesTotal)
			{
				likesTotal = likes;
			}
		}
		for(int i = 0; i < tam; i++)
		{
			auxRed = ll_get(pArrayPais, i);
			likes = auxRed->likes;
			if(likes == likesTotal)
			{
				auxRed = ll_get(pArrayPais, i);
				strcpy(user, auxRed->user);
				printf("\n****POSTEOS MAS POPULARES: ****\n");
				printf("%22s  con %7d\n", user, likesTotal);
			}
		}
		ret = 0;
	}

	return ret;
}
