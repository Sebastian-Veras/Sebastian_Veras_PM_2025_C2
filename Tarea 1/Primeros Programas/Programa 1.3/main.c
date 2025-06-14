#include <stdio.h>
#include <stdlib.h>
/* Promedio de sueldos
El programa al recibir como datos seis suledos de un empleado,
calcule tanto el ingreso total como el promedio mensual*/
void main(void)
{
    int CLA;
    float SU1,SU2,SU3,SU4,SU5,SU6,ING, PRO;
    printf("Ingrese la clave de empleado y sus 6 sueldos:");
    scanf("%d %f %f %f %f %f %f %f", &CLA ,&SU1,&SU2,&SU3,&SU4,&SU5,&SU6);
   ING = (SU1+SU2+SU3+SU4+SU5+SU6);
   PRO = ING / 6 ;
   printf("\n %d %5.2f %5.2f", CLA,ING,PRO);

}
