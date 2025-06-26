#include <stdio.h>
#include <stdlib.h>

/* Funciones para el manejo de caracteres de la biblioteca stdlib.h. */

void main(void) {
    int i;
    double d;
    long l;
    char cad0[100], *cad1;  // Cadena de entrada y puntero para strtod/strtol

    printf("\nIngrese una cadena de caracteres (entero): ");
    gets(cad0);
    i = atoi(cad0);
    // La función atoi convierte cadena a entero.
    printf("\n%s \t %d\n", cad0, i + 3);

    printf("Ingrese una cadena de caracteres (double): ");
    gets(cad0)
    d = atof(cad0);
    // atof convierte cadena a double.
    printf("\n%s \t %.2lf\n", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    // strtod convierte cadena a double y cad1 apunta al resto de la cadena
    printf("\n%s \t %.2lf\n", cad0, d + 1.50);
    printf("Resto de cadena: %s\n", cad1);

    l = atol(cad0);
    // atol convierte cadena a long.
    printf("\n%s \t %ld\n", cad0, l + 10);

    l = strtol(cad0, &cad1, 0);
    // strtol convierte cadena a long con base automática (octal, decimal, hex)
    printf("\n%s \t %ld\n", cad0, l + 10);
  puts(cad1);
    // Nota importante:
    // No se debe hacer asignación de cadena directamente a un índice de un arreglo, por ejemplo:
    // cad2[10] = "Guatemala";   <- Esto es incorrecto y dará error.
    // Para copiar cadenas se usa strcpy o memcpy.
}
