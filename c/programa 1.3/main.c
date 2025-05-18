#include <stdio.h>
#include <stdlib.h>



int main() {
    int CLA;                // Clave del empleado
    float SU1, SU2, SU3, SU4, SU5, SU6;  // Sueldos mensuales
    float ingreso_total, promedio_mensual;

    // Entrada de datos
    printf("Ingrese la clave del empleado: ");
    scanf("%d", &CLA);

    printf("Ingrese los 6 sueldos mensuales:\n");
    scanf("%f %f %f %f %f %f", &SU1, &SU2, &SU3, &SU4, &SU5, &SU6);

    // Cálculos
    ingreso_total = SU1 + SU2 + SU3 + SU4 + SU5 + SU6;
    promedio_mensual = ingreso_total / 6.0;

    // Salida de resultados
    printf("\n--- Resultados ---\n");
    printf("Clave del empleado: %d\n", CLA);
    printf("Ingreso total semestral: %.2f\n", ingreso_total);
    printf("Promedio mensual: %.2f\n", promedio_mensual);

    return 0;
}


