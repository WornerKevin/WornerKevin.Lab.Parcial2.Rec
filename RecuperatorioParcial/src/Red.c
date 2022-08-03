#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Red.h"
#include "funciones.h"

eRed* Red_new()
{
	eRed* newRed= (eRed*) malloc(sizeof(eRed));

	return newRed;
}
/*-----------------------------------------------------------------------------------------------*/
eRed* newParametros(char* idStr,char* userStr,char* likesStr,char* dislikesStr, char* followersStr)
{
	eRed* newRed = Red_new();
	int auxId;
	int auxLikes;
	int auxDislikes;
	int auxFollowers;

	if(newRed != NULL)
	{
		auxId = atoi(idStr);
		auxLikes = atoi(likesStr);
		auxDislikes = atoi(dislikesStr);
		auxFollowers = atoi(followersStr);
		Red_setId(newRed, auxId);
		Red_setUser(newRed, userStr);
		Red_setLikes(newRed, auxLikes);
		Red_setDislikes(newRed, auxDislikes);
		Red_setFollowers(newRed, auxFollowers);

	}
	return newRed;
}
/*-----------------------------------------------------------------------------------------------*/
void Red_delete(eRed* this)
{
	free(this);
}
/*-----------------------------------------------------------------------------------------------*/
//SETTERS
int Red_setId(eRed* this,int id)
{
	int ret = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
/*------------------------------------------------------------------------------------------------*/
int Red_setUser(eRed* this,char* user)
{
	int ret = -1;
	if(this != NULL && user != NULL)
	{
		strcpy(this->user, user);
		ret = 0;
	}

	return ret;
}
/*-------------------------------------------------------------------------------------------------*/
int Red_setLikes(eRed* this,int likes)
{
	int ret = -1;
	if(this != NULL)
	{
		this->likes = likes;
		ret = 0;
	}
	return ret;
}
int Red_setDislikes(eRed* this,int dislikes)
{
	int ret = -1;
	if(this != NULL)
	{
		this->dislikes = dislikes;
		ret = 0;
	}
	return ret;
}
int Red_setFollowers(eRed* this,int followers)
{
	int ret = -1;
	if(this != NULL)
	{
		this->followers = followers;
		ret = 0;
	}
	return ret;
}

//GETTERS
int Red_getId(eRed* this,int* id)
{
	int ret = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Red_getUser(eRed* this,char* user)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(user, this->user);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Red_getLikes(eRed* this,int* likes)
{
	int ret = -1;
	if(this != NULL)
	{
		*likes = this->likes;
		ret = 0;
	}
	return ret;
}
int Red_getDislikes(eRed* this,int* dislikes)
{
	int ret = -1;
	if(this != NULL)
	{
		*dislikes = this->dislikes;
		ret = 0;
	}
	return ret;
}
int Red_getFollowers(eRed* this,int* followers)
{
	int ret = -1;
	if(this != NULL)
	{
		*followers = this->followers;
		ret = 0;
	}
	return ret;
}
int red_mostrarUno(eRed* red)
{
	int ret = -1;
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;

	if(red != NULL)
	{
			Red_getId(red, &id);
			Red_getUser(red, user);
			Red_getLikes(red, &likes);
			Red_getDislikes(red, &dislikes);
			Red_getFollowers(red, &followers);

			printf("  %4d  %30s   %7d  %7d   %7d\n", id, user, likes, dislikes, followers);

		ret = 0;
	}
    return ret;
}
int filtrarMejores(void* pElement)
{
	int ret = 0;

	if(((eRed*) pElement)->likes > 3000)
	{
		ret = 1;
	}

	return ret;
}
int filtrarHaters(void* pElement)
{
	int ret = 0;
	int likes;
	int dislikes;
	if(pElement != NULL)
	{
		likes = ((eRed*)pElement)->likes;
		dislikes = ((eRed*)pElement)->dislikes;
		if(dislikes > likes)
		{
			ret = 1;
		}
	}

	return ret;
}

int Red_sortFollowers(void* followers1,void* followers2)
{
	int ret = 0;

	eRed* auxRed1;
	eRed* auxRed2;

	if(followers1!=NULL && followers2!=NULL)
	{
		auxRed1 = (eRed*) followers1;
		auxRed2 = (eRed*) followers2;

		if(auxRed1->followers>auxRed2->followers)
		{
			ret=1;
		}
		else if(auxRed1->followers<auxRed2->followers)
		{
			ret=-1;
		}
	}

	return ret;
}
