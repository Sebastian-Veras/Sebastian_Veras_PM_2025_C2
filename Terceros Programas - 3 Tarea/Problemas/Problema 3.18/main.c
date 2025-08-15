#include <stdio.h>
#include <stdlib.h>
/*al recibir como dato un
 número entero positivo,escriba una figura como la que se muestra a continua
ción
 1  2  3  4  5  6  7      7  6  5  4  3  2  1
 1  2  3  4  5  6              6  5  4  3  2  1
como ejemplo de la figura*/                                                     1
void main(void)
{
    int N, i, j;
    float espacios;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {

        for (j = 1; j <= N - i; j++) {
            printf("%2d ", j);
        }

        // Espacios al centro
        espacios = i * 6.01 - 1;
        for (j = 0; j < espacios; j++) {
            printf(" ");
        }

        // Parte derecha decreciente (solo si i != 0)

            for (j = N - i; j >= 1; j--) {
                printf("%2d ", j);
            }


        printf("\n");
    }


}
