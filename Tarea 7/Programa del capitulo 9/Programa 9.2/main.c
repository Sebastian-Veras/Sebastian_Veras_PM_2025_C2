#include <stdio.h>
#include <stdlib.h>


// RELLENAR  Y CREAR EL ARCHIVO ARC.TXT ANTES DE UTILIZAR EL PROGRAMA//
void main (void)
{
    char p1;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)
        {
        while (!feof(ar))
    {
        p1 = fgetc(ar);
        putchar(p1);
    }
    fclose(ar);
    }
else
    printf("No se puede abrir el archivo ");
}
