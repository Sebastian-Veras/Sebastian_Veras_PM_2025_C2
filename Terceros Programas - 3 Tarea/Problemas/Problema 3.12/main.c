#include <stdio.h>
#include <stdlib.h>
/* Se dice que un número N es primo si los únicos enteros positivos que lo dividen
 son exactamente 1 y N. Construye un diagrama de flujo y el correspondiente pro
grama en C que lea un número entero positivo NUM y escriba todos los números
 primos menores a dicho número.*/
void main(void)
{
int NUM=0, i=0, j=0, contador;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &NUM);

    printf("Números primos menores que %d:\n", NUM);

    for (i = 2; i < NUM; i++) {
        contador = 0;

        for (j = 1; j <= i; j++) {
            if (i % j == 0) {
                contador++;
            }
        }

        if (contador == 2) {
            printf("%d ", i);
        }
    }

    printf("\n");
}
