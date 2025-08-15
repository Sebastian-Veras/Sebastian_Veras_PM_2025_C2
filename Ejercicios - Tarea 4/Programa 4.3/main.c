#include <stdio.h>
#include <stdlib.h>

 /* Conflicto de variables con el mismo nombre. */


void f1(void);

int K = 5;  // Variable global

void main(void) {
    int I;
    for (I = 1; I <= 3; I++)
        f1();
}

void f1(void) {
    int k_local = 2;  // Usamos otro nombre para evitar conflicto
    k_local += k_local;
    printf("\n\nEl valor de la variable local es: %d", k_local);

    K = K + k_local;  // Usamos directamente K, que es la global
    printf("\nEl valor de la variable global es: %d", K);
}
