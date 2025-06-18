#include <stdio.h>
/* Búsqueda secuencial en arreglos ordenados en forma creciente. */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
int Busca(int *, int, int);

int main(void) {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);   // Validación del tamaño

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);  // Llamada a la función de búsqueda

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

    return 0;
}

/* Función para leer los elementos del arreglo */
void Lectura(int A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Búsqueda secuencial optimizada para arreglos ordenados */
int Busca(int A[], int T, int E) {
    int RES, I = 0, BAN = 0;

    while ((I < T) && (E >= A[I]) && !BAN) {
        if (A[I] == E)
            BAN++;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;  // Posición (humana, empieza en 1)
    else
        RES = BAN;

    return (RES);
}
