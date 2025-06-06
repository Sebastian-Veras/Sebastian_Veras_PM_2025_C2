#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Suma cuadrados
el programa, al recibir como datos un grupo de enteros positivos, obtiene el
cuadrado de lso mismos y la suam correspondiente a dichos cuadrados.*/

void main (void)
{
    int NUM;
    long CUA, SUC = 0;
    printf("\n Ingrese un numero enetero, -0 para terminar -:\t");;
    scanf("%d",&NUM);
    while (NUM)
    {
        CUA = pow(NUM, 2);
        printf("%d al cubo es %ld", NUM,CUA);
        SUC = SUC + CUA;
        printf("\nIngrese un numero entero -0 para terminar -:\t");
        scanf("%d", NUM);
    }
    printf("\nLa suma de los cuadrados es %ld", SUC);
}
