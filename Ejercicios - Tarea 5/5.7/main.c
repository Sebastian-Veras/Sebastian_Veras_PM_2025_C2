#include <stdlib.h>

#include <stdio.h>

/* Arreglo sin elementos repetidos.
   El programa, al recibir como dato un arreglo unidimensional desordenado de N
   elementos, obtiene como salida ese mismo arreglo pero sin los elementos
   repetidos. */

void Lectura(int *, int);             // Prototipos de funciones
void Imprime(int *, int);
void Elimina(int *, int *);           // Se pasa el tamaño por referencia

void main(void)
{
    int TAM, ARRE[100];

    // Validación del tamaño del arreglo
    do {
        printf("Ingrese el tamaño del arreglo (1 a 100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(ARRE, TAM);
    Elimina(ARRE, &TAM);
    Imprime(ARRE, TAM);


}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional */
{
    printf("\n");
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("A[%d]: %d\n", I, A[I]);
}

void Elimina(int A[], int *T)
/* Elimina elementos repetidos del arreglo */
{
    int I = 0, K, L;

    while (I < (*T - 1)) {
        K = I + 1;
        while (K < *T) {
            if (A[I] == A[K]) {
                for (L = K; L < (*T - 1); L++) {
                    A[L] = A[L + 1];
                }
                (*T)--;  // Reduce el tamaño del arreglo
            } else {
                K++;
            }
        }
        I++;
    }
}
