#include <stdio.h>

// Prototipo de función
void f1(int*);

void main(void)
{
    int I, K = 4;

    for (I = 1; I <= 3; I++)
    {
        printf("\nValor de K antes de llamar a la funcion: %d", ++K); // preincremento
        f1(&K); // llamada a la función que modifica K por referencia
        printf("\nValor de K despues de llamar a la funcion: %d", K);
    }

}

void f1(int *R)
{
    *R += *R; // Duplicamos el valor apuntado
}
