#include <stdio.h>
#include <stdlib.h>  // para malloc
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *);  // prototipo de función

int main(void)
{
    struct alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
    struct alumno *a3, *a4, *a5, a6;

    a3 = &a0;

    // Reservar memoria para a4 y a5
    a4 = (struct alumno *) malloc(sizeof(struct alumno));
    a5 = (struct alumno *) malloc(sizeof(struct alumno));

    if (a4 == NULL || a5 == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("\nIngrese la matrícula del alumno 4: ");
    scanf("%d", &a4->matricula);
    getchar();  // limpiar el buffer

    printf("Ingrese el nombre del alumno 4: ");
    fgets(a4->nombre, sizeof(a4->nombre), stdin);
    a4->nombre[strcspn(a4->nombre, "\n")] = '\0';

    printf("Ingrese la carrera del alumno 4: ");
    fgets(a4->carrera, sizeof(a4->carrera), stdin);
    a4->carrera[strcspn(a4->carrera, "\n")] = '\0';

    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    getchar();

    printf("Ingrese la dirección del alumno 4: ");
    fgets(a4->direccion, sizeof(a4->direccion), stdin);
    a4->direccion[strcspn(a4->direccion, "\n")] = '\0';

    // Lectura para a5 y a6 usando función
    Lectura(a5);
    Lectura(&a6);

    // Imprimir datos
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);

    // Liberar memoria dinámica
    free(a4);
    free(a5);

    return 0;
}

void Lectura(struct alumno *a)
{
    printf("\nIngrese la matrícula del alumno: ");
    scanf("%d", &a->matricula);
    getchar();

    printf("Ingrese el nombre del alumno: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';

    printf("Ingrese la carrera del alumno: ");
    fgets(a->carrera, sizeof(a->carrera), stdin);
    a->carrera[strcspn(a->carrera, "\n")] = '\0';

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    getchar();

    printf("Ingrese la dirección del alumno: ");
   gets(a->direccion);
}
