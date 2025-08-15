#include <stdio.h>
#include <stdlib.h>
/*Construye un diagrama de flujo y el correspondiente programa en C que, al recibir
 como datos dos números enteros positivos, obtenga e imprima todos los números
 primos gemelos comprendidos entre dichos números. Los primos gemelos son
 una pareja de números primos con una diferencia entre sí de exactamente dos. El
 3 y el 5 son primos gemelos.*/
void main(void)
{



    int A, B, temp;
    int i, j;
    int primo1, primo2;


    printf("Ingrese el primer número entero positivo: ");
    scanf("%d", &A);
    printf("Ingrese el segundo número entero positivo: ");
    scanf("%d", &B);


    if (A > B) {
        temp = A;
        A = B;
        B = temp;
    }

    printf("\nPares de primos gemelos entre %d y %d:\n", A, B);


    for (i = A; i <= B - 2; i++) {

        primo1 = 1;
        if (i < 2) {
            primo1 = 0;
        } else {
            for (j = 2; j < i; j++) {
                if (i % j == 0) {
                    primo1 = 0;

                }
            }
        }


        primo2 = 1;
        if (i + 2 < 2) {
            primo2 = 0;
        } else {
            for (j = 2; j < i + 2; j++) {
                if ((i + 2) % j == 0) {
                    primo2 = 0;

                }
            }
        }

        // Si ambos son primos → imprimir par
        if (primo1 && primo2) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }


}


