#include <stdio.h>
#include <stdlib.h>

// Ordenacion por insercion directa
const int MAX = 100;

void Lectura(int *, int);
void Ordena(int *, int);   // Prototipos de funciones
void Imprime(int *, int);

int main(void)
{
    int TAM, VEC[MAX];

    // Validación del tamaño del arreglo
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[], int T)
/* Lee T elementos y los guarda en el arreglo A */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
/* Imprime el arreglo ordenado */
{
    int I;
    printf("\nArreglo ordenado:\n");
    for (I = 0; I < T; I++) {
        printf("A[%d]: %d\n", I, A[I]);
    }
}

void Ordena(int A[], int T)
/* Ordenamiento por inserción directa */
{
    int AUX, L, I;
    for (I = 1; I < T; I++) {
        AUX = A[I];
        L = I - 1;
        while ((L >= 0) && (AUX < A[L])) {
            A[L + 1] = A[L];
            L--;
        }
        A[L + 1] = AUX;
    }
}

