#include <stdio.h>
#include <stdlib.h>
/*  Una empresa dedicada a la venta de localidades por teléfono e Internet maneja
 seis tipos de localidades para un circo ubicado en la zona sur de la Ciudad de
 México. Algunas de las zonas del circo tienen el mismo precio, pero se manejan
 diferente para administrar eficientemente la asignación de los asientos. Los pre
cios de cada localidad y los datos referentes a la venta de boletos */

void main(void)
{
 float L1,L2,L3,L4,L5,L6;  // Precios de L1 a L6
 int CLA, CAN;
 float total = 1;

    // Leer precios de cada localidad

        printf("Ingrese el precio de la localidad 1: ");
        scanf("%f", &L1);
        printf("Ingrese el precio de la localidad 2: ");
        scanf("%f", &L2);
        printf("Ingrese el precio de la localidad 3: ");
        scanf("%f", &L3);
        printf("Ingrese el precio de la localidad 4: ");
        scanf("%f", &L4);
        printf("Ingrese el precio de la localidad 5: ");
        scanf("%f", &L5);
        printf("Ingrese el precio de la localidad 6: ");
        scanf("%f", &L6);

   while (CLA) {
        printf("Ingrese la localidad (1-6) y la cantidad de boletos (0 0 para terminar): ");
        scanf("%d %d", &CLA, &CAN);

        if (CLA == 0 && CAN == 0)
            break;

        switch (CLA) {
            case 1:
                total += L1 * CAN;
                break;
            case 2:
                total += L2 * CAN;
                break;
            case 3:
                total += L3 * CAN;
                break;
            case 4:
                total += L4 * CAN;
                break;
            case 5:
                total += L5 * CAN;
                break;
            case 6:
                total += L6 * CAN;
                break;
            default:
                printf("Tipo de localidad inválido.\n");
                break;
        }


    }

    printf("Total de ingresos: $%.2f\n", total);

}






