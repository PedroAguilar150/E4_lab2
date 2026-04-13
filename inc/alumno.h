/**
 * @file alumno.h
 * @author Pedro Aguilar
 * @brief Definición de la estructura del alumno y declaración de la función de serialización.
 */
#ifndef ALUMNO_H_
#define ALUMNO_H_
#include <stddef.h>
// para lo de arriba, la funcion es evitar que el compilador lea el mismo archivo .h mas de una vez.
// todo archivo .h debe empezar con estas lineas y terminar con un #endif, si no el makefile lanzara errores de
// compilacion

/** @brief Estructura que representa a un alumno, con campos para el apellido, nombre y número de documento. */
typedef struct alumno_s {
    char apellido[30];
    char nombre[30];
    int documento;
} alumno_t;

/**
 * @brief Función que serializa la información de un alumno en formato JSON.
 * @param alumno El puntero a la estructura del alumno.
 * @param buffer El buffer donde se guardará la cadena serializada.
 * @param tamanio_total El tamaño total del buffer.
 * @return El número de caracteres escritos, o -1 en caso de error.
 */
int serializar(const struct alumno_s * alumno, char * buffer, int tamanio_total);
#endif
