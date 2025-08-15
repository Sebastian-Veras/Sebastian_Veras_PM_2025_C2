#include <stdio.h>

void Lectura1(int A[15][12]);
void Lectura2(float A[], int N);
void Funcion1(int A[][12], int F, int C, float V1[], float V2[]);
void Funcion2(float A[], int C);
void Funcion3(float A[], int C);

void main(void) {
    int FAB[15][12] = {0}; // Ventas por producto y mes
    float COS[15];         // Costos unitarios
    float VEN[15];         // Ventas totales por producto

    Lectura1(FAB);
    Lectura2(COS, 15);
    Funcion1(FAB, 15, 12, COS, VEN);
    Funcion2(VEN, 15);
    Funcion3(VEN, 15);
}

// Función para capturar ventas por producto y mes
void Lectura1(int A[][12]) {
    int MES, PRO, CAN;
    printf("\nIngrese mes, tipo de producto y cantidad vendida (-1 para terminar): ");
    scanf("%d %d %d", &MES, &PRO, &CAN);
    while (MES != -1 && PRO != -1 && CAN != -1) {

        A[MES-1][PRO-1] += CAN;
        printf("Ingrese mes, tipo de producto y cantidad vendida (-1 para terminar): ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

// Función para capturar costo unitario de cada producto
void Lectura2(float A[], int N) {
    int I;
    for (I = 0; I < N; I++) {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

// Función para calcular ventas totales por producto
void Funcion1(int A[][12], int F, int C, float V1[], float V2[]) {
    int I, J, SUM;
    for (I = 0; I < F; I++) {
        SUM = 0;
        for (J = 0; J < C; J++) {
            SUM += A[I][J];
        }
        V2[I] = V1[I] * SUM;
        printf("Total de ventas del producto %d: %8.2f\n", I + 1, V2[I]);
    }
}

// Función para calcular el total de ventas de la fábrica
void Funcion2(float A[], int C) {
    int I;
    float SUM = 0.0;
    for (I = 0; I < C; I++) {
        SUM += A[I];
    }
    printf("\n\nTotal de ventas de la fábrica: %.2f\n", SUM);
}

// Función para identificar el producto más vendido
void Funcion3(float A[], int C) {
    int I, TPR = 0;
    float VEN = A[0];
    for (I = 1; I < C; I++) {
        if (VEN < A[I]) {
            TPR = I;
            VEN = A[I];
        }
    }
    printf("\n\nTipo de Producto más vendido: %d \t Ventas: %.2f\n", TPR + 1, VEN);
}
