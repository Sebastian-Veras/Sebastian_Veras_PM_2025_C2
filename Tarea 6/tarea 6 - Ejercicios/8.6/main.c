#include <stdio.h>
#include <string.h>

// Estructura para un producto
typedef struct {
    int clave;
    char nombre[30];
    float precio;
    int existencia;
} producto;

// Prototipos de funciones
void Lectura(producto A[], int T);
void Ventas(producto A[], int T);
void Reabastecimiento(producto A[], int T);
void Nuevos_Productos(producto A[], int *T);
void Inventario(producto A[], int T);

void main(void) {
    producto INV[100];
    int TAM, OPE;

    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    do {
        printf("\nIngrese operación a realizar. \n\t\t1 – Ventas\n\t\t2 – Reabastecimiento\n\t\t3 – Nuevos Productos\n\t\t4 – Inventario\n\t\t0 – Salir: ");
        scanf("%d", &OPE);

        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
        }
    } while (OPE != 0);
}

void Lectura(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese información del producto %d", I + 1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);
        printf("\tNombre: ");
        gets(A[I].nombre);
        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (CLA) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);

        I = 0;
        while (I < T && A[I].clave != CLA)
            I++;

        if (I == T) {
            printf("\nLa clave del producto es incorrecta");
        } else if (A[I].existencia >= CAN) {
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            printf("\nNo hay suficiente existencia. Solo hay %d", A[I].existencia);
            printf("\n¿Desea llevar lo disponible? 1-Sí  0-No: ");
            scanf("%d", &RES);
            if (RES) {
                PAR = A[I].precio * A[I].existencia;
                TOT += PAR;
                A[I].existencia = 0;
            }
        }

        printf("\nIngrese la siguiente clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }

    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (CLA) {
        I = 0;
        while (I < T && A[I].clave != CLA)
            I++;

        if (I == T) {
            printf("\nLa clave del producto es incorrecta");
        } else {
            printf("\tCantidad a agregar: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }

        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J;

    printf("\nIngrese clave del nuevo producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (*T < 100 && CLA) {
        I = 0;
        while (I < *T && A[I].clave < CLA)
            I++;

        if (I < *T && A[I].clave == CLA) {
            printf("\nEl producto ya se encuentra en el inventario.");
        } else {
            for (J = *T; J > I; J--)
                A[J] = A[J - 1];

            A[I].clave = CLA;
            fflush(stdin);
            printf("\tNombre: ");
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            (*T)++;
        }

        printf("\nIngrese otra clave del nuevo producto -0 para salir-: ");
        scanf("%d", &CLA);
    }

    if (*T == 100)
        printf("\nNo hay más espacio para productos nuevos.");
}

void Inventario(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d", A[I].existencia);
    }
}
