#include <stdio.h>

/* Cuenta caracteres.
 El programa, al recibir como datos una cadena de caracteres y un caracter,
 cuenta cuántas veces se encuentra el caracter en la cadena. */
int cuenta(char *, char); /* Prototipo de función. */

void main(void) // Cambiado a int main(void) por estándar
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad); // ¡ADVERTENCIA: gets() es inseguro y puede causar desbordamiento de buffer!

    // Limpia el buffer de entrada para consumir el '\n' dejado por gets()
    // y cualquier otro carácter hasta la nueva línea o EOF.
    while (getchar() != '\n' && !feof(stdin));

    printf("\nIngrese el caracter: ");
    car = getchar();

    // Limpia el buffer de entrada para consumir el '\n' dejado por el último getchar()
    while (getchar() != '\n' && !feof(stdin));

    res = cuenta(cad, car);
    printf("\n\n'%c' se encuentra %d veces en la cadena '%s'", car, res, cad); // Agregado retorno para int main
}

int cuenta(char *cad, char car)
/* Esta función se utiliza para obtener el número de veces que se encuentra
el caracter en la cadena. */
{
    int i = 0, r = 0;
    while (cad[i] != '\0') // Usar '\0' para el carácter nulo
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return (r);
}
