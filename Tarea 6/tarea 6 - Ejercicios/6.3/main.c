#include <stdio.h>
#include <stdlib.h>

const int F = 8, C = 2, P = 5;

// Prototipos
void lectura(int A[][C][P], int FI, int CO, int PR);
void Funcion1(int A[][C][P], int FI, int CO, int PR);
void Funcion2(int A[][C][P], int FI, int CO, int PR);
void Funcion3(int A[][C][P], int FI, int CO, int PR);

int main(void) {
    int UNI[F][C][P];

    lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, 6, C, P);  // Carrera en fila 6

    return 0;
}

// Definición de funciones

void lectura(int A[][C][P], int FI, int CO, int PR) {
    for (int i = 0; i < FI; i++) {
        for (int j = 0; j < CO; j++) {
            for (int k = 0; k < PR; k++) {
                printf("Ingrese alumnos para carrera %d, semestre %d, año %d: ", i + 1, j + 1, k + 1);
                scanf("%d", &A[i][j][k]);
            }
        }
    }
}

void Funcion1(int A[][C][P], int FI, int CO, int PR) {
    int K, I, J;
    int MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++) {
        SUM = 0;
        for (I = 0; I < FI; I++) {
            for (J = 0; J < CO; J++) {
                SUM += A[I][J][K];
            }
        }
        if (SUM > MAY) {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\n\nAño con mayor ingreso de alumnos: %d    Alumnos: %d\n", AO + 1, MAY);
}

void Funcion2(int A[][C][P], int FI, int CO, int PR) {
    int I, J, MAY = 0, CAR = -1, SUM;

    for (I = 0; I < FI; I++) {
        SUM = 0;
        for (J = 0; J < CO; J++) {
            SUM += A[I][J][PR - 1];
        }
        if (SUM > MAY) {
            MAY = SUM;
            CAR = I;
        }
    }

    printf("\n\nCarrera con mayor número de alumnos en el último año: %d    Alumnos: %d\n", CAR + 1, MAY);
}

void Funcion3(int A[][C][P], int FI, int CO, int PR) {
    int K, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++) {
        SUM = 0;
        for (J = 0; J < CO; J++) {
            SUM += A[FI][J][K];  // Carrera en fila FI (ej. 6)
        }
        if (SUM > MAY) {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\n\nAño con mayor ingreso en carrera (fila %d): %d   Alumnos: %d\n", FI + 1, AO + 1, MAY);
}
