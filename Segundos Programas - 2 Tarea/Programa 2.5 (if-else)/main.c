#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
int OP,T;
float RES;


printf("Ingrese la opcion del calculo y el valor entero:");
scanf("%d %d",&OP, &T);

if(OP == 1)
{
    RES = T/5.0;

}
else if (OP == 2){
    RES = pow(T,T);
}
else if (OP == 3|| OP == 4){
    RES = 6 * T / 2.0;
}
else {
    RES =1;
}
printf("\nResultado: %7.2fn", RES);
}
