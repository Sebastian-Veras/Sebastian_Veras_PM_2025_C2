#include <stdio.h>
#include <string.h>

/* Uniones.
   El programa muestra cómo se usa una unión dentro de una estructura.
*/

union datos { // Declaración de una unión
    char celular[15];
    char correo[20];
};

typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales; // Campo de tipo unión
} alumno;

void Lectura(alumno *a); // Prototipo de función

void main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, .personales.celular = "5-158-40-50"};
    alumno a2, a3;

    printf("\nAlumno 2\n");
    printf("Ingrese la matrícula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf("Ingrese el correo electrónico: ");
    gets(a2.personales.correo);

    printf("\nAlumno 3\n");
    Lectura(&a3);  // Se leen los datos del alumno 3

    // Impresión de resultados
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); // válido
    // puts(a1.personales.correo); // ¡No válido! Se sobrescribiría la unión

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    // Esta impresión está mal porque el último valor escrito fue en `correo`
    puts(a2.personales.celular);  // Basura
    puts(a2.personales.correo);   // Correcto

    printf("\nIngrese el teléfono celular del alumno 2: ");
    fflush(stdin);
    gets(a2.personales.celular); // Se sobreescribe la unión
    puts(a2.personales.celular); // Ahora válido
    puts(a2.personales.correo);  // Ahora basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular); // Correcto
    puts(a3.personales.correo);  // Basura
}

// Función que lee datos del alumno, incluyendo campo de unión
void Lectura(alumno *a)
{
    printf("Ingrese la matrícula: ");
    scanf("%d", &a->matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("Ingrese el teléfono celular: ");
    gets(a->personales.celular);
}
