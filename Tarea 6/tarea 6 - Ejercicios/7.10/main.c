#include <stdio.h>   // Necesario para printf, getchar, puts, etc.
#include <stdlib.h>  // Necesario para atof
void main(void) {
    char respuesta_char;
    // ¡ADVERTENCIA!: Usar gets() con este arreglo es INSEGURO.
    // Si la entrada del usuario excede 49 caracteres, habrá un desbordamiento de búfer.
    char cadena[50];
    int i = 0;
    float suma = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    respuesta_char = getchar();
    // Limpia el buffer de entrada para consumir el '\n' después de getchar()
    while (getchar() != '\n' && !feof(stdin));

    while (respuesta_char == 'S' || respuesta_char == 's') {
        printf("\nIngrese la cadena de caracteres (¡NO ingrese mas de 49 caracteres!): ");
        // ¡USO DE GETS() - EXTREMADAMENTE INSEGURO!
        // No hay comprobacion de limites, lo que puede causar desbordamientos.
        gets(cadena);

        i++;
        suma += atof(cadena);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        respuesta_char = getchar();
        // Limpia el buffer de entrada de nuevo
        while (getchar() != '\n' && !feof(stdin));
    }


        printf("\nSuma: %.2f", suma);
        printf("\nPromedio: %.2f", suma / i);


    ;
}
