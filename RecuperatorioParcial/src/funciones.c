#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int getInteger(int* integer, char* message, char* messageMistake, int min, int max)
{
	int ret= -1;
	int enteredNumber;

	if(integer != NULL && message != NULL &&  messageMistake != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enteredNumber);

		while(enteredNumber < min || enteredNumber > max)
		{
			printf("%s", messageMistake);
			fflush(stdin);
			scanf("%d", &enteredNumber);
		}

		*integer = enteredNumber;
		ret = 0;
	}

	return ret;
}

int getFloat(float* number, char* message, char* messageMistake, float min, float max)
{
	int ret = -1;
	float enteredNumber;

	if(number != NULL && message != NULL && messageMistake != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%f", &enteredNumber);

		while(enteredNumber < min ||enteredNumber > max)
		{
			printf("%s", messageMistake);
			fflush(stdin);
			scanf("%f", &enteredNumber);
		}

		*number = enteredNumber;
		ret = 0;
	}

	return ret;
}

int getString(char* chain, char* message, char* messageMistake, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	if(chain != NULL && message != NULL && messageMistake != NULL && max > 0)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		while(len > max)
		{
			printf("%s", messageMistake);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}

		strcpy(chain, buffer);
		ret = 0;
	}

	return ret;
}

int getCharacter(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		*character = getchar();
		ret = 0;
	}

	return ret;
}

