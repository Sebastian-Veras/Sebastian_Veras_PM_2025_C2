#include <stdio.h>
#include <stdlib.h>

const int MAX =50;

void lectura (int[][MAX],int,int);
void suma (int [][MAX],int[][MAX],int [][MAX], int, int);
void imprime (int [][MAX],int ,int);

void main(void)
{

    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
    int FIL, COL;

    do {
        printf("Ingrese el número de filas de los arreglos: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1); /* Se verifica que el número de filas sea correcto. */

    do {
        printf("Ingrese el número de columnas de los arreglos: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1); /* Se verifica que el número de columnas sea correcto. */

    printf("\nLectura del Arreglo MA\n");
    lectura(MA, FIL, COL);

    printf("\nLectura del Arreglo MB\n");
    lectura(MB, FIL, COL);

    suma(MA, MB, MC, FIL, COL);

    printf("\nImpresión del Arreglo MC\n");
    imprime(MC, FIL, COL);

}


void lectura(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

void suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            M3[I][J] = M1[I][J] + M2[I][J];
}

void imprime(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            printf("\nElemento %d %d: %d", I, J, A[I][J]);
}



