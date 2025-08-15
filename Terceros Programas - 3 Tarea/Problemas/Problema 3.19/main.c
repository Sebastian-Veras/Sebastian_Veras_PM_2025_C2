#include <stdio.h>
#include <stdlib.h>
/* figura que crea es la siguiente
              1
            2 3 2
          3 4 5 4 3
        4 5 6 7 6 5 4
      5 6 7 8 9 8 7 6 5
    6 7 8 9 0 1 0 8 7 6
 7 8 9 0 1 2 3 2 1 0 9 8 7
 como ejemplo*/
void main( void)
{
    int filas = 10,i,j,num;
    int numero_inicio;

    printf("Ingresa el número con el que deseas que inicie la pirámide: ");
    scanf("%d", &numero_inicio);

    for ( i = 1; i <= filas; i++) {

        for ( j = 1; j <= filas - i; j++) {
            printf("  ");
        }

                // Parte creciente (izquierda)
        num = i % 10;
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num = (num + 1) % 10;
        }

        // Parte decreciente (derecha)
        num = (num - 2 + 10) % 10;
        for (j = 1; j < i; j++) {
            printf("%d ", num);
            num = (num - 1 + 10) % 10;
        }


        printf("\n");
    }


}

