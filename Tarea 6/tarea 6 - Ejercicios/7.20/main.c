#include <stdio.h>
#include <string.h>

int longitud(char *cad); /* Prototipo de función. */

void main(void)
{
    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    fflush(stdin);

    for(i = 0; i < n; i++)
    {
        printf("\nIngrese la línea %d de texto. Máximo 50 caracteres: ", i + 1);
        fflush(stdin);
        gets(FRA[i]); /* Se lee la cadena dentro del ciclo. */
    }
    printf("\n");

    for(i = 0; i < n; i++)
    {
        strcpy(cad, FRA[i]);
       int t = longitud(cad);
        if(t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d\n", l);
}

int longitud(char *cadena)
/* Esta función calcula la longitud de la cadena sin usar strlen. */
{
    int cue = 0;
    while(cadena[cue] != '\0')
        cue++;
    return cue;
}
