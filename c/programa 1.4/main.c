#include <stdio.h>
#include <stdlib.h>

int main()
{

 float BAS = 0;
 float ALT = 0;
 float SUP = 0;

 printf("Introducir el valor de  la Base:");
 scanf("%f",&BAS);

 printf("Introducir el valor de la Altura:");
 scanf("%f",&ALT);

 SUP = BAS * ALT/2;

 printf("La superficie del triángulo es: %.2f\n",SUP);

 return 0;




}


