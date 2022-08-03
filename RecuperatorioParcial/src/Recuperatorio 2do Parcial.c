#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Red.h"
int menu();

int main()
{
	setbuf(stdout,NULL);

	int flag = 0;
	int flagAsignacion = 0;
    int opcion = 0;

    LinkedList* listaRed = ll_newLinkedList();

    if(listaRed == NULL)
    {
    	exit(1);
    }

    do{

    	opcion = menu();

        switch(opcion)
        {
            case 1:
            	if(!flag)
            	{
            		controller_nameFile(listaRed);
            		printf("El archivo de texto se cargo con exito \n");
            		flag = 1;
            	}
            	break;

            case 2:
            	if(flag)
            	{
            		controller_List(listaRed);
            	}
            	else
            	{
            		printf("\nDebe cargar un archivo previamente\n");
            	}
            	break;
            case 3:
            	if(flag)
            	{
            		listaRed = ll_map(listaRed, controller_GenerarEstadisticas);
            		if(listaRed !=NULL)
            		{
            			controller_List(listaRed);
            			printf("\nEstadisticas asignadas con exito\n");
            			flagAsignacion = 1;
            		}
            			else
            			{
            					printf("\nOcurrio un error al asignar la lista\n");
            			}
            	}
            			else
            			{
            				 printf("\nDebe cargar el archivo de texto de la red previamente \n\n");
            			}
            		system("pause");
            break;
            case 4:
            	if(flagAsignacion == 1 && flag == 1 )
            	{
            		if(listaRed!=NULL)
            		{
            			controller_filtrarPorMejores(listaRed);
            			printf("\nArchivo guardado con exito\n");
            			flagAsignacion = 2;
            		}
            			else
            			{
            				printf("\nOcurrio un error al asignar la lista\n");
            			}
            	}
            		else if(flag==0)
            		{
            			printf("\nDebe cargar el archivo de texto de los posteos previamente \n\n");
            		}
            		 	 else
            		 	 {
            				printf("\nPrimero tiene que asignar las estadisticas a la lista\n");
            			 }
            				system("pause");
            	break;
			case 5:
				if(flagAsignacion==1 || flagAsignacion== 2)
				{
					controller_filtrarHaters(listaRed);
					printf("\n\n");
				}
				else
				{
					printf("\nPrimero tiene que asignar las estadisticas\n");
				}
				system("pause");
            	break;
			case 6:
				if(flagAsignacion == 1)
				{
					if(listaRed!=NULL)
					{
						ll_sort(listaRed, Red_sortFollowers, 0);
						if(listaRed!=NULL)
						{
							controller_List(listaRed);
							flagAsignacion =3;
							printf("\nLa lista se ordeno con exito\n");
		            		controller_saveAsText("ListaOrdenada.csv", listaRed);
		            		printf("Archivo de texto guardado correctamente\n");
						}
					}
				}
					else
					{
						printf("\nPrimero tiene que asignar estadisticas a la lista\n");
					}
				system("pause");
			break;
            case 7:
            	if(flagAsignacion == 1||flagAsignacion == 2 || flagAsignacion == 3)
            	{
            		controller_MasPopular(listaRed);
            		printf("\n\n");
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo de texto de los posteos previamente \n\n");
            	}
            	break;
            case 8:
            	printf("\nSaliste del programa exitosamente.\n");
            	break;

        }
    }while(opcion != 8);
    return 0;
}

int menu()
{
	 	int opcion;
	 	printf("|=============================================|\n");
	    printf("|   \t***Bienvenido ***                     |\n");
	    printf("|=============================================|\n");
	    printf("|1. Cargar Archivo                            |\n");
	    printf("|2. Imprimir lista                            |\n");
	    printf("|3. Asignar estadisticas                      |\n");
	    printf("|4. Filtrar por mejores posteos               |\n");
	    printf("|5. Filtrar por haters                        |\n");
	    printf("|6. Ordenar por nivel de cantidad de followers|\n");
	    printf("|7. Mostrar mas popular                       |\n");
	    printf("|8. Salir                                     |\n");
	    printf("|=============================================|\n");
	    printf("Elija una opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);
	    while(opcion < 1 || opcion > 8)
	    {
	        printf("Error. Elija una opcion valida: ");
	        fflush(stdin);
	        scanf("%d", &opcion);
	    }
	    return opcion;
}
