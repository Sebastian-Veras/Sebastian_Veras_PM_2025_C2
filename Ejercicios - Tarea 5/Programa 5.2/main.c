#include <stdio.h>

/*Eleccion.
El programa alamcenados los votos emitidos en una eleccion en la que hubo cinco
candidatos en imprime el total de votos que obtuvo cada uno de ellos*/

void main (void)
{
    int ELE[5]={0};
    int I,VOT;
    printf("Ingresa el primer voto (0 - Para  terminar): ");
    scanf("%d",&VOT);
    while (VOT)
    {
        if ((VOT>0)&&(VOT<6))
            ELE[VOT - 1]++;

    else
        printf("\nEl voto ingresado es incorrecto.\n");
    printf("Ingresa el siguiente voto (0- Para terminar):");
    scanf("%d",&VOT);
}
printf("\n\nResultados de la Eleccion\n");
for (I=0;I<=4; I++)
    printf("\nCandidato %d: %d", I+1, ELE[I]);
}
