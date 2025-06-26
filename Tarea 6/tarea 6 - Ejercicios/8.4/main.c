#include <stdio.h>
#include <string.h>

/* Escuela.
   El programa genera información estadística de los alumnos de una escuela.
*/

typedef struct {
    int matricula;
    char nombre[30];
    float cal[5]; // Arreglo de 5 calificaciones por alumno
} alumno;

// Prototipos de funciones
void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

void main(void)
{
    alumno ARRE[50];  // Arreglo de alumnos
    int TAM;

    // Lectura del tamaño del arreglo con validación
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ARRE, TAM);  // Llenar datos
    F1(ARRE, TAM);       // Mostrar matrícula y promedio de cada alumno
    F2(ARRE, TAM);       // Mostrar matrículas con nota alta en materia 3
    F3(ARRE, TAM);       // Promedio general de la materia 4
}

void Lectura(alumno A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d\n", I + 1);
        printf("Ingrese la matrícula del alumno: ");
        scanf("%d", &A[I].matricula);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nombre);  // Se mantiene gets

        for (J = 0; J < 5; J++) {
            printf("\tIngrese la calificación %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
        }
    }
}

void F1(alumno A[], int T)
{
    int I, J;
    float SUM, PRO;

    printf("\n--- Matrículas y Promedios ---\n");
    for (I = 0; I < T; I++) {
        printf("Matrícula del alumno: %d", A[I].matricula);
        SUM = 0.0;
        for (J = 0; J < 5; J++) {
            SUM += A[I].cal[J];
        }
        PRO = SUM / 5.0;
        printf("\t\tPromedio: %.2f\n", PRO);
    }
}

void F2(alumno A[], int T)
{
    int I;
    printf("\n--- Alumnos con calificación en la tercera materia > 9 ---\n");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2] > 9) {
            printf("Matrícula del alumno: %d\n", A[I].matricula);
        }
    }
}

void F3(alumno A[], int T)
{
    int I;
    float PRO, SUM = 0.0;

    for (I = 0; I < T; I++) {
        SUM += A[I].cal[3];  // Materia 4 es índice 3
    }
    PRO = SUM / T;

    printf("\nPromedio de la materia 4: %.2f\n", PRO);
}
