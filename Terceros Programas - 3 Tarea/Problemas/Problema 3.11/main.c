#include <stdio.h>
#include <stdlib.h>
/* En una bodega en Tarija, Bolivia, manejan información sobre las cantidades pro
ducidas de cada tipo de vino en los últimos años. Escribe un diagrama de flujo y
 el correspondiente programa en C que permita calcular lo siguiente:
 a. El total producido de cada tipo de vino en los últimos años.
 b. El total de la producción anual de los últimos años.*/

void main(void)
{
     int N,i;
    float VIN1, VIN2, VIN3, VIN4;
    float tT1 = 0, tT2 = 0, tT3 = 0, tT4 = 0;
    float totalAnuales;

    printf("Ingrese el número de años: ");
    scanf("%d", &N);

    for ( i = 1; i <= N; i++) {


        printf("Litros de vino año 1: ");
        scanf("%f", &VIN1);

        printf("Litros de vino año 2: ");
        scanf("%f", &VIN2);

        printf("Litros de vino año 3: ");
        scanf("%f", &VIN3);

        printf("Litros de vino año 4: ");
        scanf("%f", &VIN4);

        tT1 += VIN1;
        tT2 += VIN2;
        tT3 += VIN3;
        tT4 += VIN4;

        totalAnual = VIN1 + VIN2 + VIN3 + VIN4;
        printf("Producción total en el año %d: %.2f litros\n", i, totalAnuales);
    }

    printf("\nProducción total por tipo de vino:\n");
    printf("Tipo 1: %.2f litros\n", tT1);
    printf("Tipo 2: %.2f litros\n", tT2);
    printf("Tipo 3: %.2f litros\n", tT3);
    printf("Tipo 4: %.2f litros\n", tT4);


}
