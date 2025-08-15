#include <stdio.h>
#include <string.h>

/* Estructuras-1.
El programa muestra cómo se declara una estructura y cómo se accede a sus campos. */

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void main(void)
{
    struct alumno a1 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
    struct alumno a2, a3;
    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    /* Lectura de datos para alumno 2 */
    printf("\nIngrese la matrícula del alumno 2: ");
    scanf("%d", &a2.matricula);
    limpiarBuffer();

    printf("Ingrese el nombre del alumno 2: ");
    fgets(a2.nombre, sizeof(a2.nombre), stdin);
    a2.nombre[strcspn(a2.nombre, "\n")] = '\0';  // Eliminar salto de línea

    printf("Ingrese la carrera del alumno 2: ");
    fgets(a2.carrera, sizeof(a2.carrera), stdin);
    a2.carrera[strcspn(a2.carrera, "\n")] = '\0';

    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    limpiarBuffer();

    printf("Ingrese la dirección del alumno 2: ");
    fgets(a2.direccion, sizeof(a2.direccion), stdin);
    a2.direccion[strcspn(a2.direccion, "\n")] = '\0';

    /* Lectura de datos para alumno 3 */
    printf("\nIngrese la matrícula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;
    limpiarBuffer();

    printf("Ingrese el nombre del alumno 3: ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';
    strcpy(a3.nombre, nom);

    printf("Ingrese la carrera del alumno 3: ");
    fgets(car, sizeof(car), stdin);
    car[strcspn(car, "\n")] = '\0';
    strcpy(a3.carrera, car);

    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;
    limpiarBuffer();

    printf("Ingrese la dirección del alumno 3: ");
    fgets(dir, sizeof(dir), stdin);
    dir[strcspn(dir, "\n")] = '\0';
    strcpy(a3.direccion, dir);

    /* Imprimir datos alumno 1 */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.direccion);

    /* Imprimir datos alumno 2 */
    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.direccion);

    /* Imprimir datos alumno 3 */
    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2f \t %s\n",
           a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);


}
