#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//LOAD
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_nameFile(LinkedList* pArrayList);
//SAVE
int controller_saveAsText(char* path , LinkedList* pArrayList);
//LIST
int controller_List(LinkedList* pArrayList);
//ESTADISTICAS
void* controller_GenerarEstadisticas(void* pRed);
//FILTROS
int controller_filtrarPorMejores(LinkedList* pArray);
int controller_filtrarHaters(LinkedList* pArray);
//INFORME
int controller_MasPopular(LinkedList* pArrayPais);

#endif /* CONTROLLER_H_ */
