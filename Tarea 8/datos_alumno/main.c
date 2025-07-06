#include <stdio.h>
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcpy, strcmp

// Estructura para almacenar los datos de un alumno
typedef struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
    struct Alumno *siguiente; // Puntero al siguiente alumno en la lista
} Alumno;

// Puntero global al inicio de la lista de alumnos
Alumno *listaAlumnos = NULL;

// Función para agregar un nuevo alumno a la lista
void agregarAlumno() {
    Alumno *nuevoAlumno = (Alumno *)malloc(sizeof(Alumno));
    if (nuevoAlumno == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo alumno.\n");
        return;
    }

    printf("Ingrese el nombre del alumno: ");
    // Usar fgets para leer nombres con espacios si es necesario, y luego limpiar el newline
    // Para simplificar, seguimos con scanf para un solo token (sin espacios)
    scanf("%s", nuevoAlumno->nombre);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &nuevoAlumno->edad);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &nuevoAlumno->promedio);

    nuevoAlumno->siguiente = NULL; // El nuevo alumno es el último por ahora

    if (listaAlumnos == NULL) {
        listaAlumnos = nuevoAlumno; // Si la lista está vacía, el nuevo alumno es el primero
    } else {
        Alumno *temp = listaAlumnos;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente; // Recorre la lista hasta el último elemento
        }
        temp->siguiente = nuevoAlumno; // Enlaza el nuevo alumno al final
    }
    printf("Alumno agregado exitosamente.\n");
}

// Función para mostrar todos los alumnos en la lista
void mostrarAlumnos() {
    if (listaAlumnos == NULL) {
        printf("No hay alumnos para mostrar.\n");
        return;
    }

    Alumno *temp = listaAlumnos;
    int i = 1;
    while (temp != NULL) {
        printf("\n--- Alumno %d ---\n", i++);
        printf("Nombre: %s\n", temp->nombre);
        printf("Edad: %d\n", temp->edad);
        printf("Promedio: %.2f\n", temp->promedio);
        temp = temp->siguiente; // Mueve al siguiente alumno usando el puntero
    }
}

// Función para eliminar un alumno por nombre
void eliminarAlumno() {
    if (listaAlumnos == NULL) {
        printf("No hay alumnos para eliminar.\n");
        return;
    }

    char nombreAEliminar[50];
    printf("Ingrese el nombre del alumno a eliminar: ");
    scanf("%s", nombreAEliminar);

    Alumno *actual = listaAlumnos;
    Alumno *anterior = NULL;
    int encontrado = 0;

    // Buscar el alumno en la lista
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombreAEliminar) == 0) {
            encontrado = 1;
            break; // Se encontró el alumno
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("Alumno '%s' no encontrado.\n", nombreAEliminar);
        return;
    }

    // Si el alumno a eliminar es el primero de la lista
    if (anterior == NULL) {
        listaAlumnos = actual->siguiente; // El nuevo primer alumno es el siguiente
    } else {
        // Si el alumno a eliminar está en medio o al final
        anterior->siguiente = actual->siguiente; // El anterior ahora apunta al siguiente del actual
    }

    free(actual); // Libera la memoria del alumno eliminado
    printf("Alumno '%s' eliminado exitosamente.\n", nombreAEliminar);
}


// Función para guardar los alumnos en un archivo binario
void guardarAlumnos() {
    FILE *archivo = fopen("alumnos.dat", "wb"); // Abre el archivo en modo escritura binaria
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }

    Alumno *temp = listaAlumnos;
    while (temp != NULL) {
        // Escribe solo los datos del alumno (no el puntero 'siguiente')
        fwrite(temp, sizeof(Alumno) - sizeof(Alumno *), 1, archivo);
        temp = temp->siguiente;
    }

    fclose(archivo);
    printf("Alumnos guardados exitosamente en 'alumnos.dat'.\n");
}

// Función para cargar los alumnos desde un archivo binario
void cargarAlumnos() {
    // Primero, liberar cualquier memoria existente para evitar fugas
    while (listaAlumnos != NULL) {
        Alumno *temp = listaAlumnos;
        listaAlumnos = listaAlumnos->siguiente;
        free(temp);
    }

    FILE *archivo = fopen("alumnos.dat", "rb"); // Abre el archivo en modo lectura binaria
    if (archivo == NULL) {
        printf("No se encontró el archivo 'alumnos.dat' o error al abrirlo.\n");
        return;
    }

    Alumno *nuevoAlumno;
    while (1) {
        nuevoAlumno = (Alumno *)malloc(sizeof(Alumno));
        if (nuevoAlumno == NULL) {
            printf("Error: No se pudo asignar memoria al cargar alumnos.\n");
            break;
        }
        // Lee los datos del alumno (excluyendo el puntero 'siguiente')
        if (fread(nuevoAlumno, sizeof(Alumno) - sizeof(Alumno *), 1, archivo) != 1) {
            free(nuevoAlumno); // Si no se leyó un registro completo, libera la memoria
            break;
        }
        nuevoAlumno->siguiente = NULL; // Inicializa el puntero siguiente

        if (listaAlumnos == NULL) {
            listaAlumnos = nuevoAlumno;
        } else {
            Alumno *temp = listaAlumnos;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoAlumno;
        }
    }

    fclose(archivo);
    printf("Alumnos cargados exitosamente desde 'alumnos.dat'.\n");
}

// Función para liberar toda la memoria asignada dinámicamente
void liberarMemoria() {
    Alumno *temp;
    while (listaAlumnos != NULL) {
        temp = listaAlumnos;
        listaAlumnos = listaAlumnos->siguiente;
        free(temp); // Libera la memoria de cada nodo
    }
    printf("Memoria liberada exitosamente.\n");
}

int main() {
    int opcion;

    do {
        printf("\n--- Menú de Gestión de Alumnos ---\n");
        printf("1. Agregar Alumno\n");
        printf("2. Mostrar Alumnos\n");
        printf("3. Guardar Alumnos en Disco\n");
        printf("4. Cargar Alumnos desde Disco\n");
        printf("5. Eliminar Alumno\n"); // Nueva opción
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarAlumno();
                break;
            case 2:
                mostrarAlumnos();
                break;
            case 3:
                guardarAlumnos();
                break;
            case 4:
                cargarAlumnos();
                break;
            case 5: // Nuevo caso para eliminar
                eliminarAlumno();
                break;
            case 6: // Salir ahora es la opción 6
                liberarMemoria(); // Liberar memoria antes de salir
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 6); // La condición de salida es ahora 6

    return 0;
}
