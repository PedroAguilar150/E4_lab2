/** @file main.c
 * @author Pedro Aguilar
 */

#include "alumno.h"
#include <stdio.h>

/** @brief Función principal para probar la serialización de un alumno.
 * @return El código de salida del programa.
 */
int main(void) {
    // creo un alumno de ejemplo
    alumno_t alumno_ejemplo = {"Pedro", "Aguilar", 50518728};

    // creo un buffer para almacenar la cadena serializada
    char buffer[100];

    // llamo a la función de serialización y guardo el resultado
    int resultado = serializar(&alumno_ejemplo, buffer, sizeof(buffer));
    // esto devuelve la cantidad de caracteres que se habrian escrito si el buffer fuera lo suficientemente grande
    //  verifico el resultado de la serialización
    if (resultado == -1) {
        // si hay error entonces muestro este mensaje
        printf("error: espacio insuficiente\n");
        return 1;
    } else {
        // si no hay error entonces muestro el resultado
        printf("alumno serializado:%s\n", buffer);
        // el %s se usa para indicar que se va a imprimir una cadena de caracteres
        return 0;
    }
}
