#include <stdio.h>
#include <stdlib.h>

int main()
{
    float BAS,ALT,SUP;
    printf ("Ingrese la base y la altura del triangulo:");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT/2;
    printf("\nLa Superficie del triangulo es: %5.2f", SUP);
    return 0;
}
