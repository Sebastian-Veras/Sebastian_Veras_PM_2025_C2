#include <stdio.h>
#include <stdlib.h>
/* Nomina
el programa, al recibir lso salarios de 15 profesores, obitene el total de la
nomina de la universidad*/

void main (void)
{
int I;
float SAl, NOM;
NOM = 0;
for (I=1;I<=15; I++)
{
    printf("\nIngrese el salario del profesor%d:\t",I);
    scanf("%f",&SAl);
    NOM = NOM + SAl;
}
printf("\nEl total de la nomina es: %2.f", NOM);
}
