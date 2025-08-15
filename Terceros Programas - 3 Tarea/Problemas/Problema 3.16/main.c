#include <stdio.h>
#include <stdlib.h>
/* El correspondiente programa en Cque,al recibir
 como dato un número entero positivo,escriba una figura como la que se muestra
 a continuación (ejemplo para N = 6)*/
void main(void)
{
int N,I,J;

printf("Ingrese un numero entero positivo: ");
scanf("%i",&N);

for (I =1;I<=N;I++)
{
    for (J=1;J<=I;J++){
        printf("%d",J);
    }
    printf("\n");
}

for (I =N-1;I>=1;I--)
{
    for (J=1;J<=I;J++)
        {
        printf("%d",J);
    }
    printf("\n");
}
}
