/**
 * @file alumno.c
 * @author Pedro Aguilar
 * @brief Implementación de la función de serialización para la estructura del alumno.
 */
#include "alumno.h"
#include <stdio.h>

// como necesito funciones internas uso static para que no sean visibles fuera de este archivo
/**
 * @brief Función que serializa un campo de texto en formato JSON.
 * @param etiqueta La etiqueta del campo.
 * @param dato El dato del campo.
 * @param buffer El buffer donde se guardará la cadena serializada.
 * @param tamanio El tamaño del buffer.
 * @return El número de caracteres escritos, o -1 en caso de error.
 */
static int serializar_texto(const char * etiqueta, const char * dato, char * buffer, int tamanio) {
    return snprintf(buffer, tamanio, "\"%s\":\"%s\"", etiqueta, dato);
}

/**
 * @brief Función que serializa un campo numérico en formato JSON.
 * @param etiqueta La etiqueta del campo.
 * @param dato El dato del campo.
 * @param buffer El buffer donde se guardará la cadena serializada.
 * @param tamanio El tamaño del buffer.
 * @return El número de caracteres escritos, o -1 en caso de error.
 */
static int serializar_numerico(const char * etiqueta, int dato, char * buffer, int tamanio) {
    return snprintf(buffer, tamanio, "\"%s\":%d", etiqueta, dato);
}

/**
 * @brief Función principal de serialización.
 * @param alumno El puntero a la estructura del alumno.
 * @param buffer El buffer donde se guardará la cadena serializada.
 * @param tamanio_total El tamaño total del buffer.
 * @return El número de caracteres escritos, o -1 en caso de error.
 */
int serializar(const struct alumno_s * alumno, char * buffer, int tamanio_total) {

    // verifico que los punteros no esten en nulo
    if (alumno == NULL || buffer == NULL) {
        // si son nulos retorno -1 para indicar un error
        return -1;
    }

    // JSON es una forma de guardar y enviar datos en formato texto, de manera ordenada.
    //  es veria asi: {"Nombre":"x","Apellido":"x","Documento":123}
    int espacio_libre = tamanio_total; // el espacio libre es el tamaño total del buffer al inicio
    int escrito = 0;   // escrito es la cantidad de caracteres escritos en cada llamada a snprintf o a las funciones de
                       // serialización
    int acumulado = 0; // acumulado es la cantidad total de caracteres escritos hasta el momento, se va actualizando con
                       // cada llamada a snprintf o a las funciones de serialización

    // comienzo a escribir en formato JSON/
    escrito = snprintf(buffer + acumulado, espacio_libre, "{");
    acumulado = acumulado + escrito;

    // uso serializar_texto para escribir el nombre
    escrito = serializar_texto("Nombre", alumno->nombre, buffer + acumulado, espacio_libre - acumulado);
    acumulado = acumulado + escrito;

    // agrego una coma para separar los campos
    escrito = snprintf(buffer + acumulado, espacio_libre - acumulado, ",");
    acumulado = acumulado + escrito;

    // uso serializar_texto para escribir el apellido
    escrito = serializar_texto("Apellido", alumno->apellido, buffer + acumulado, espacio_libre - acumulado);
    acumulado = acumulado + escrito;

    // agrego otra coma para separar los campos
    escrito = snprintf(buffer + acumulado, espacio_libre - acumulado, ",");
    acumulado = acumulado + escrito;

    // uso serializar_numerico para escribir el documento
    escrito = serializar_numerico("Documento", alumno->documento, buffer + acumulado, espacio_libre - acumulado);
    acumulado = acumulado + escrito;

    // cierro el formato JSON
    escrito = snprintf(buffer + acumulado, espacio_libre - acumulado, "}");
    acumulado = acumulado + escrito;

    // verifico que no haya un error por espacio insuficiente
    if (acumulado >= tamanio_total) {
        return -1;
    }
    // retorno el total de caracteres escritos
    return acumulado;
}
