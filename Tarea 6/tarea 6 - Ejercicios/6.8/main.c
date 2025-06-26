#include <stdio.h>

const int MAX = 50;

// Prototipos
void Lectura(int A[][MAX], int F, int C);
void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C);
void Imprime(int A[][MAX], int F, int C);

void main(void) {
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;

    // Leer número de filas
    do {
        printf("Ingrese el número de filas de la matriz: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1);

    // Leer número de columnas
    do {
        printf("Ingrese el número de columnas de la matriz: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1);

    // Procesamiento
    Lectura(MAT, FIL, COL);
    Traspuesta(MAT, TRA, FIL, COL);
    Imprime(TRA, COL, FIL);  // Ojo: traspuesta tiene filas y columnas invertidas


}

// Función para leer la matriz
void Lectura(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

// Función para calcular la traspuesta
void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            M2[J][I] = M1[I][J];
        }
    }
}

// Función para imprimir la matriz
void Imprime(int A[][MAX], int F, int C) {
    int I, J;
    printf("\nMatriz traspuesta:\n");
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("Elemento [%d][%d]: %d\n", I + 1, J + 1, A[I][J]);
        }
    }
}
