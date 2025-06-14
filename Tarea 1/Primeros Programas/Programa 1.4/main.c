#include <stdio.h>
#include <stdlib.h>
/* Superficie del triangulo
El programa, al recbir como datos la base y la altura
de un triangulo, calcula su superficie;*/

void main(void)
{
    float BAS,ALT,SUP;
    printf ("Ingrese la base y la altura del triangulo:");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT/2;
    printf("\nLa Superficie del triangulo es: %5.2f", SUP);

}
