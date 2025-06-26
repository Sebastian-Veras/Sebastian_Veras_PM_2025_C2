#include <stdio.h>
#include <string.h>

/* Cuenta cadenas.
   El programa, al recibir dos cadenas de caracteres, calcula e imprime cuántas
   veces se encuentra la segunda cadena en la primera. */

void main(void)
{
    char cad1[50], cad2[50], *cad0;
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    gets(cad1);

    printf("\nIngrese la cadena a buscar: ");
    gets(cad2);

    cad0 = strstr(cad1, cad2);
    /* En cad0 se asigna el apuntador a la primera ocurrencia de la cadena cad2.
       Si no existe se almacena NULL. */

    while (cad0 != NULL)
    {
        i++;
        cad0 = strstr(cad0 + 1, cad2); // Buscar la siguiente ocurrencia
    }

    printf("\nEl número de veces que aparece la segunda cadena es: %d", i);
}
