#include <stdio.h>
/* Búsqueda binaria. */
const int MAX = 100;

void Lectura(int *, int);                          /* Prototipos de funciones */
int Binaria(int *, int, int);

int main(void) {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);                /* Validación corregida */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);                  /* Llamada a búsqueda binaria */

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Búsqueda binaria del elemento E en el arreglo A. Si lo encuentra, devuelve su posición. */
{
    int IZQ = 0, CEN, DER = T - 1, BAN = 0;

    while ((IZQ <= DER) && (!BAN)) {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN])
            BAN = CEN + 1; // Se suma 1 para devolver posición comenzando desde 1
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return (BAN);
}
