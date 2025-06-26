#include <stdio.h>
#include <string.h>

/* Cuenta caracteres.
   El programa, al recibir como datos una cadena de caracteres y un caracter,
   cuenta cuántas veces se encuentra el caracter en la cadena. */

int cuenta(char *, char); // Prototipo de función

void main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0'; // Eliminar salto de línea

    printf("\nIngrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s\n", car, res, cad);


}

int cuenta(char *cad, char car)
{
    int i = 0, r = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return r;
}
