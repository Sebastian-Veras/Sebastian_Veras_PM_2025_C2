#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas de caracteres. */

void main(void) {
    char cad0[50] = "Hola México"; // arreglo para permitir strcat
    char cad1[20], cad2[20], cad3[20] = ", buenos días!!!";

    strcpy(cad1, cad0);
    /* La función strcpy permite copiar una cadena de caracteres completa.
       En este caso se copia la cadena cad0 a cad1. */
    printf("\nPrueba de la función strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de la función strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de la función strcpy. Se copia la cadena XX a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';  // terminar cadena manualmente
    /* La función strncpy permite copiar un número determinado de caracteres */
    printf("\nPrueba de la función strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de la función strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    strcat(cad0, cad3);
    /* La función strcat concatena cadenas */
    printf("\nPrueba de la función strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba de la función strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    /* strncat concatena un número limitado de caracteres */
    printf("\nPrueba de la función strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    char *ptr;
    ptr = strstr(cad0, "México");
    printf("\nPrueba de la función strstr. Se trata de localizar la cadena México dentro de cad0: %s\n", ptr);

    ptr = strstr(cad0, "Guatemala");
    printf("\nPrueba de la función strstr. Se trata de localizar la cadena Guatemala dentro de cad0: %s\n", ptr ? ptr : "No encontrada");


}
