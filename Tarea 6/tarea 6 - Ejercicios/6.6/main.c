#include <stdio.h>

const int MAX = 50;

// Prototipos de funciones
void Lectura(float A[][MAX], int F, int C);
void Intercambia(float A[][MAX], int F, int C);
void Imprime(float A[][MAX], int F, int C);

void main(void) {
    int F, C;
    float MAT[MAX][MAX];

    // Lectura de filas
    do {
        printf("Ingrese el número de filas: ");
        scanf("%d", &F);
    } while (F > MAX || F < 1);  // Validación

    // Lectura de columnas
    do {
        printf("Ingrese el número de columnas: ");
        scanf("%d", &C);
    } while (C > MAX || C < 1);  // Validación

    Lectura(MAT, F, C);
    Intercambia(MAT, F, C);
    Imprime(MAT, F, C);


}

// Función para leer la matriz
void Lectura(float A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
    }
}

// Función para intercambiar las columnas
void Intercambia(float A[][MAX], int F, int C) {
    int I, J;
    float AUX;
    for (J = 0; J < C / 2; J++) {
        for (I = 0; I < F; I++) {
            AUX = A[I][J];
            A[I][J] = A[I][C - 1 - J];
            A[I][C - 1 - J] = AUX;
        }
    }
}

// Función para imprimir la matriz
void Imprime(float A[][MAX], int F, int C) {
    int I, J;
    printf("\nMatriz resultante:\n");
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]);
        }
        printf("\n");
    }
}
