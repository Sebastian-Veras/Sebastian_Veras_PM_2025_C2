#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define NOMBRE_ARCHIVO "alumnos.dat"

// Estructura para representar a un alumno
typedef struct {
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

// Función para agregar un alumno al archivo binario
void agregarAlumno() {
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "ab"); // Abrir en modo "append binary"
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return;
    }

    Alumno nuevoAlumno;
    printf("Ingrese el nombre del alumno: ");
    getchar(); // Consumir el salto de línea pendiente
    fgets(nuevoAlumno.nombre, MAX_NOMBRE, stdin);
    nuevoAlumno.nombre[strcspn(nuevoAlumno.nombre, "\n")] = 0; // Eliminar el salto de línea

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &nuevoAlumno.promedio);

    fwrite(&nuevoAlumno, sizeof(Alumno), 1, archivo);
    fclose(archivo);
    printf("Alumno agregado con éxito.\n");
}

// Función para leer todos los alumnos del archivo binario
// y devolverlos en un array dinámico
Alumno *leerAlumnos(int *numAlumnos) {
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "rb"); // Abrir en modo "read binary"
    if (archivo == NULL) {
        *numAlumnos = 0;
        return NULL; // No hay alumnos o el archivo no existe
    }

    fseek(archivo, 0, SEEK_END);
    long tamanoArchivo = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    *numAlumnos = tamanoArchivo / sizeof(Alumno);
    if (*numAlumnos == 0) {
        fclose(archivo);
        return NULL;
    }

    Alumno *alumnos = (Alumno *)malloc(*numAlumnos * sizeof(Alumno));
    if (alumnos == NULL) {
        perror("Error al asignar memoria");
        fclose(archivo);
        return NULL;
    }

    fread(alumnos, sizeof(Alumno), *numAlumnos, archivo);
    fclose(archivo);
    return alumnos;
}

// Función para escribir un array de alumnos de nuevo en el archivo
void escribirAlumnosEnArchivo(const Alumno *alumnos, int numAlumnos) {
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "wb"); // Abrir en modo "write binary" (sobrescribe)
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return;
    }
    fwrite(alumnos, sizeof(Alumno), numAlumnos, archivo);
    fclose(archivo);
}


// Función para eliminar un alumno del archivo binario
void eliminarAlumno() {
    int numAlumnos;
    Alumno *alumnos = leerAlumnos(&numAlumnos);

    if (alumnos == NULL || numAlumnos == 0) {
        printf("No hay alumnos para eliminar.\n");
        return;
    }

    printf("\n--- Alumnos Registrados ---\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("%d. Nombre: %s, Promedio: %.2f\n", i + 1, alumnos[i].nombre, alumnos[i].promedio);
    }

    int indiceAEliminar;
    printf("Ingrese el número del alumno a eliminar: ");
    scanf("%d", &indiceAEliminar);

    if (indiceAEliminar < 1 || indiceAEliminar > numAlumnos) {
        printf("Número de alumno no válido.\n");
        free(alumnos);
        return;
    }

    // Mover los elementos después del índice a eliminar para sobrescribir
    for (int i = indiceAEliminar - 1; i < numAlumnos - 1; i++) {
        alumnos[i] = alumnos[i + 1];
    }

    numAlumnos--; // Decrementar el contador de alumnos


    escribirAlumnosEnArchivo(alumnos, numAlumnos);

    printf("Alumno eliminado con éxito.\n");
    free(alumnos);
}


// Función para imprimir un solo alumno
void imprimirAlumno(const Alumno *alumno) {
    printf("Nombre: %s, Promedio: %.2f\n", alumno->nombre, alumno->promedio);
}


void intercambiar(Alumno *a, Alumno *b) {
    Alumno temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritmo Bubble Sort para ordenar por nombre
void bubbleSortPorNombre(Alumno *alumnos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(alumnos[j].nombre, alumnos[j+1].nombre) > 0) {
                intercambiar(&alumnos[j], &alumnos[j+1]);
            }
        }
    }
}

// Algoritmo Bubble Sort para ordenar por promedio
void bubbleSortPorPromedio(Alumno *alumnos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alumnos[j].promedio < alumnos[j+1].promedio) { // Mayor a menor promedio
                intercambiar(&alumnos[j], &alumnos[j+1]);
            }
        }
    }
}

// Función para imprimir la lista de alumnos
void imprimirAlumnos(int opcion) {
    int numAlumnos;
    Alumno *alumnos = leerAlumnos(&numAlumnos);

    if (alumnos == NULL || numAlumnos == 0) {
        printf("No hay alumnos registrados.\n");
        return;
    }

    if (opcion == 1) {
        bubbleSortPorNombre(alumnos, numAlumnos);
        printf("\n--- Lista de Alumnos (Ordenada Alfabéticamente por Nombre) ---\n");
    } else if (opcion == 2) {
        bubbleSortPorPromedio(alumnos, numAlumnos);
        printf("\n--- Lista de Alumnos (Ordenada por Promedio de Mayor a Menor) ---\n");
    }

    for (int i = 0; i < numAlumnos; i++) {
        imprimirAlumno(&alumnos[i]);
    }

    free(alumnos); // Liberar la memoria asignada dinámicamente
}

int main(void) {
    int opcion;

    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Agregar alumno\n");
        printf("2. Imprimir alumnos (Orden Alfabético por Nombre)\n");
        printf("3. Imprimir alumnos (Orden por Promedio de Mayor a Menor)\n");
        printf("4. Imprimir alumnos (Orden de Registro)\n");
        printf("5. Eliminar alumno\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarAlumno();
                break;
            case 2:
                imprimirAlumnos(1); // Opción para ordenar por nombre
                break;
            case 3:
                imprimirAlumnos(2); // Opción para ordenar por promedio
                break;
            case 4:
                imprimirAlumnos(3); // Opción para orden de registro (natural)
                break;
            case 5:
                eliminarAlumno();
                break;
            case 6:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0; // Se recomienda que main devuelva un int
}
