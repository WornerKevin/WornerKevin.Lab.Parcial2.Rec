/*
 * Red.h
 *
 *  Created on: 3 ago. 2022
 *      Author: Kevin Worner
 */

#ifndef RED_H_
#define RED_H_

struct{
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;

}typedef eRed;

eRed* Red_new();
eRed* newParametros(char* idStr,char* userStr,char* likesStr,char* dislikesStr, char* followersStr);
void Red_delete(eRed* this);
//SETTERS
int Red_setId(eRed* this,int id);
int Red_setUser(eRed* this,char* user);
int Red_setLikes(eRed* this,int likes);
int Red_setDislikes(eRed* this,int dislikes);
int Red_setFollowers(eRed* this,int followers);
//GETTERS
int Red_getId(eRed* this,int* id);
int Red_getUser(eRed* this,char* user);
int Red_getLikes(eRed* this,int* likes);
int Red_getDislikes(eRed* this,int* dislikes);
int Red_getFollowers(eRed* this,int* followers);
//FILTROS
int filtrarMejores(void* pElement);
int filtrarHaters(void* pElement);
//ORDENAMIENTO
int Red_sortFollowers(void* followers1,void* followers2);

int red_mostrarUno(eRed* red);

#endif /* RED_H_ */
