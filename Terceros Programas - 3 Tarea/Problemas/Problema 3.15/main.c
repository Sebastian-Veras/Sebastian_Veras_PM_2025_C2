#include <stdio.h>
#include <stdlib.h>
/*
el correspondiente programa en Cque calcule
 el máximo común divisor(MCD) de dos números naturales N1y N2. El MCD
 entre dos números es el natural más grande que divide a ambos.*/
void main(void)
{
    int N1,N2,RESUL;

    do {
        printf("Ingrese el primer número (mayor que 0): ");
        scanf("%d", &N1);
    } while (N1 <= 0);

    do {
        printf("Ingrese el segundo número (mayor que 0): ");
        scanf("%d", &N2);
    } while (N2 <= 0);



    while (N2!=0)
    {
     RESUL = N1 % N2;
     N1 = N2;
     N2 = RESUL;

    }
    printf("EL MCD es:%d\n",N1);
}
