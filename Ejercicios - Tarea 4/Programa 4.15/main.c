#include <stdio.h>
#include <stdlib.h>

/* Productoria.
 El programa calcula la productoria de los N primeros números naturales. */


int Productor(int);



void main(void)
{
    int NUM;

    do
    {
 printf("Ingresa el numero del cual quieres calcular la productora: ");
 scanf("%d",&NUM);

    }
    while (NUM > 100 || NUM < 1);
    printf("\nLa productora de %d es: %d", NUM, Productor(NUM));


}
int Productor(int N)
{
    int I,PRO = 1;
    for (I = 1; I<= N; I++)
        PRO *= I;
    return (PRO);
}
