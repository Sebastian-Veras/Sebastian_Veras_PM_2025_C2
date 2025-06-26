#include <stdio.h>

/* Declaración de cadenas de caracteres y asignación de valores */

void main(void)
{

    char *cad0;
    cad0 = "Argentina";  // Correcto: asignación de puntero
    puts(cad0);
    cad0 = "Brasil";     // Correcto: cambio de puntero
    puts(cad0);

    // Ejemplo 2: Puntero no inicializado (INCORRECTO)
    char *cad1;



    char *cad2 = "";  // Reserva espacio para el terminador nulo
    // gets(cad2);  // Aunque compila, sigue siendo inseguro


    char cad3[20] = "Mexico";
    puts(cad3);


    printf("Ingrese una cadena (máx 19 caracteres): ");
    fgets(cad3, sizeof(cad3), stdin);  // Versión segura de gets()
    puts(cad3);


}
