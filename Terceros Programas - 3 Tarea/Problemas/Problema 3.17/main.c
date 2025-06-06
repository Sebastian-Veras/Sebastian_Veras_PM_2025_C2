#include <stdio.h>
#include <stdlib.h>
/*,al recibir como dato un
 número entero positivo,escriba una figura como la que se muestra a continua
ción
1
121
12321
1234321*/
void main(void)
{
       int N, i, j;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        // Parte creciente
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Parte decreciente
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}
