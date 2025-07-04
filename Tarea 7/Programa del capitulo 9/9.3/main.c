#include <stdio.h>
#include <stdlib.h>
/* Archivos y cadenas de caracteres.
 El programa escribe cadenas de caracteres en un archivo. */

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void main(void) // Changed to standard main function signature
{
    char cad[50];
    int res;
    FILE *ar;


        printf("\n¿Desea ingresar una cadena de caracteres? Si- 1 No -0: ");
        fclose(ar);
        limpiar_buffer();

        while (res)
        {
            printf("Ingrese la cadena: ");
            // WARNING: Using gets() is unsafe and deprecated. Consider fgets() instead.
            gets(cad);
            fputs(cad, ar);

            printf("\n¿Desea ingresar otra cadena de caracteres? Si-1 No -0: ");
            fclose(ar);
            limpiar_buffer();

            if (res)
                fputs("\n", ar);
        }
        fclose(ar);
        printf("Datos escritos exitosamente en arc.txt\n");
    }
