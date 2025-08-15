#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
    struct Alumno *siguiente;
} Alumno;


Alumno *listaAlumnos = NULL;


void agregarAlumno() {
    Alumno *nuevoAlumno = (Alumno *)malloc(sizeof(Alumno));
    if (nuevoAlumno == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo alumno.\n");
        return;
    }

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nuevoAlumno->nombre);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &nuevoAlumno->edad);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &nuevoAlumno->promedio);

    nuevoAlumno->siguiente = NULL;

    if (listaAlumnos == NULL) {
        listaAlumnos = nuevoAlumno;
    } else {
        Alumno *temp = listaAlumnos;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoAlumno;
    }
    printf("Alumno agregado exitosamente.\n");
}

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
        temp = temp->siguiente;
    }
}


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


    while (actual != NULL) {
        if (strcmp(actual->nombre, nombreAEliminar) == 0) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("Alumno '%s' no encontrado.\n", nombreAEliminar);
        return;
    }


    if (anterior == NULL) {
        listaAlumnos = actual->siguiente;
    } else {

        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Alumno '%s' eliminado exitosamente.\n", nombreAEliminar);
}



void guardarAlumnos() {
    FILE *archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }

    Alumno *temp = listaAlumnos;
    while (temp != NULL) {

        fwrite(temp, sizeof(Alumno) - sizeof(Alumno *), 1, archivo);
        temp = temp->siguiente;
    }

    fclose(archivo);
    printf("Alumnos guardados exitosamente en 'alumnos.dat'.\n");
}


void cargarAlumnos() {

    while (listaAlumnos != NULL) {
        Alumno *temp = listaAlumnos;
        listaAlumnos = listaAlumnos->siguiente;
        free(temp);
    }

    FILE *archivo = fopen("alumnos.dat", "rb");
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

        if (fread(nuevoAlumno, sizeof(Alumno) - sizeof(Alumno *), 1, archivo) != 1) {
            free(nuevoAlumno);
            break;
        }
        nuevoAlumno->siguiente = NULL;
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


void liberarMemoria() {
    Alumno *temp;
    while (listaAlumnos != NULL) {
        temp = listaAlumnos;
        listaAlumnos = listaAlumnos->siguiente;
        free(temp);
    }
    printf("Memoria liberada exitosamente.\n");
}

int main() {
    int opcion;

    do {
        printf("\n--- Menú de Alumnos ---\n");
        printf("1. Agregar Alumno\n");
        printf("2. Mostrar Alumnos\n");
        printf("3. Guardar Alumnos en Disco\n");
        printf("4. Cargar Alumnos desde Disco\n");
        printf("5. Eliminar Alumno\n");
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
            case 5:
                eliminarAlumno();
                break;
            case 6:
                liberarMemoria();
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
    return 0;
}
