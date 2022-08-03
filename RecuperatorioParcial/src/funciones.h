/*
 * funciones.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Kevin Worner
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



/**
 * @brief Toma un entero con la posibilidad de pedirlo con un mensaje y con su minimo y maximo
 *
 * @param integer puntero a la variable que guardara el entero
 * @param message puntero al mensaje que se mostrara
 * @param messageMistake puntero al mensaje de error que mostrara si se necesita
 * @param min entero minimo a ingresar
 * @param max entero maximo a ingresar
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int getInteger(int* integer, char* message, char* messageMistake, int min, int max);



/**
 * @brief Toma una cadena de texto con la posibilidad de pedirlo con un mensaje y con su minimo y maximo de espacio reservado
 *
 * @param chain puntero a la variable que guarda la cadena
 * @param message puntero al mensaje que se mostrara
 * @param messageMistake puntero al mensaje de error que mostrara si se necesita
 * @param max caracteres maximos a ingresar
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int getString(char* chain, char* message, char* messageMistake, int max);

/**
 * @brief Toma un caracter con la posibilidad de pedirlo con un mensaje
 *
 * @param character puntero a la variable que guardara el caracter
 * @param message puntero al mensaje que se mostrara
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int getCharacter(char* character, char* message);

/**
 * @brief Toma un numero flotante con la posibilidad de pedirlo con un mensaje y con su minimo y maximo
 *
 * @param number puntero a la variable que guardara el entero
 * @param message puntero al mensaje que se mostrara
 * @param messageMistake puntero al mensaje de error que mostrara si se necesita
 * @param min flotante minimo a ingresar
 * @param max flotante maximo a ingresar
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int getFloat(float* number, char* message, char* messageMistake, float min, float max);



#endif /* FUNCIONES_H_ */
