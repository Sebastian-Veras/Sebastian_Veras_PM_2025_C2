#include <stdio.h>    // Necesario para funciones de entrada/salida como printf, scanf, getchar
#include <string.h>   // Necesario para funciones de cadena como strcspn

/*
 * Escuela.
 * Este programa gestiona información básica de alumnos para generar estadísticas.
 * Permite ingresar datos de alumnos (matrícula, nombre, 5 calificaciones)
 * y luego muestra:
 * 1. Matrícula y promedio de cada alumno.
 * 2. Matrículas de alumnos con una calificación superior a 9 en la tercera materia.
 * 3. El promedio general de la cuarta materia de todos los alumnos.
 */

// Definición de la estructura 'alumno' usando typedef para simplificar su uso
typedef struct {
    int matricula;      // Campo para almacenar la matrícula del alumno
    char nombre[30];    // Campo para almacenar el nombre del alumno (hasta 29 caracteres + '\0')
    float cal[5];       // Arreglo para almacenar 5 calificaciones del alumno
} alumno;

// --- Prototipos de funciones ---
// Declaran las funciones que se usarán en el programa antes de su definición.
void Lectura(alumno *, int T);  // Función para leer los datos de los alumnos
void F1(alumno *, int TAM);     // Función para calcular y mostrar promedios individuales
void F2(alumno *, int TAM);     // Función para encontrar alumnos con alta calificación en materia 3
void F3(alumno *, int TAM);     // Función para calcular el promedio de la materia 4

// --- Función principal ---
// Corrección: 'int main(void)' es la firma estándar en C.
// Retorna un entero (0 para éxito, diferente de 0 para error).
void main(void) {
    alumno ARRE[50];  // Declaración de un arreglo estático de 50 estructuras tipo 'alumno'
    int TAM;          // Variable para almacenar el tamaño real del arreglo a usar

    // Bucle do-while para leer y validar el tamaño del arreglo.
    // Asegura que TAM esté entre 1 y 50.
    do {
        printf("Ingrese el tamano del arreglo : ");
        scanf("%d", &TAM);
        // Corrección esencial: Limpia el búfer de entrada.
        // Después de 'scanf', el carácter de nueva línea ('\n') presionado por el usuario
        // queda en el búfer. Este bucle lo consume para evitar que afecte futuras lecturas.
        while (getchar() != '\n');
    } while (TAM > 50 || TAM < 1);

    Lectura(ARRE, TAM);  // Llama a la función 'Lectura' para llenar el arreglo 'ARRE'
    F1(ARRE, TAM);       // Llama a 'F1' para mostrar matrículas y promedios
    F2(ARRE, TAM);       // Llama a 'F2' para encontrar alumnos con calificación alta en materia 3
    F3(ARRE, TAM);       // Llama a 'F3' para calcular el promedio de la materia 4


}

// --- Implementación de la función Lectura ---
// Recibe el arreglo de alumnos y su tamaño.
void Lectura(alumno A[], int T) {
    int I, J; // I para iterar sobre alumnos, J para iterar sobre calificaciones

    for (I = 0; I < T; I++) {


        printf("Ingrese la matricula del alumno: ");
        scanf("%d", &A[I].matricula);
        // Corrección esencial: Limpia el búfer de entrada después de leer la matrícula.


        printf("Ingrese el nombre del alumno: ");
        // Corrección crucial: Usa fgets() en lugar de gets() por seguridad.
        // fgets(destino, tamano_maximo, fuente_entrada)
        // Limita la lectura a 'sizeof(A[I].nombre)' para prevenir desbordamientos de búfer.
        fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
        // Corrección esencial: Elimina el carácter de nueva línea ('\n') que fgets() puede incluir.
        // 'strcspn' busca la primera ocurrencia de '\n' y la reemplaza con el terminador nulo '\0'.
        A[I].nombre[strcspn(A[I].nombre, "\n")] = '\0';

        for (J = 0; J < 5; J++) { // Bucle para leer las 5 calificaciones
            printf("\tIngrese la calificacion %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
            // Corrección esencial: Limpia el búfer después de cada lectura de calificación.
            while (getchar() != '\n');
        }
    }
}

// --- Implementación de la función F1 ---
// Calcula y muestra la matrícula y el promedio de cada alumno.
void F1(alumno A[], int T) {
    int I, J;
    float SUM, PRO; // SUM para la suma de calificaciones, PRO para el promedio


    for (I = 0; I < T; I++) {
        // Muestra la matrícula y el nombre para una mejor identificación del alumno.
        printf("Matricula: %d, Nombre: %s", A[I].matricula, A[I].nombre);
        SUM = 0.0; // Reinicia la suma para cada alumno
        for (J = 0; J < 5; J++) { // Suma las 5 calificaciones del alumno actual
            SUM += A[I].cal[J];
        }
        PRO = SUM / 5.0; // Calcula el promedio
        printf("\t\tPromedio: %.2f\n", PRO); // Muestra el promedio con 2 decimales
    }
}

// --- Implementación de la función F2 ---
// Identifica y muestra las matrículas de los alumnos con una calificación superior a 9 en la tercera materia.
void F2(alumno A[], int T) {
    int I;

    for (I = 0; I < T; I++) {
        // Accede a la tercera calificación (índice 2, ya que los arreglos son base 0).
        if (A[I].cal[2] > 9) {
            // Muestra la matrícula y el nombre del alumno que cumple la condición.
            printf("Matricula: %d, Nombre: %s\n", A[I].matricula, A[I].nombre);
        }
    }
}

// --- Implementación de la función F3 ---
// Calcula y muestra el promedio general de la cuarta materia de todos los alumnos.
void F3(alumno A[], int T) {
    int I;
    float PRO, SUM = 0.0; // SUM para la suma de calificaciones de la materia 4

    // Importante: Verifica si hay alumnos para evitar división por cero.
    if (T == 0) {
        printf("\nNo hay alumnos para calcular el promedio de la materia 4.\n");
        return; // Sale de la función si el tamaño es 0.
    }

    // cal[3] es la cuarta calificación (índice 3).
    for (I = 0; I < T; I++) {
        SUM += A[I].cal[3]; // Acumula la calificación de la cuarta materia de cada alumno.
    }
    PRO = SUM / T; // Calcula el promedio general de la cuarta materia.

    printf("\nPromedio de la materia 4: %.2f\n", PRO); // Muestra el promedio con 2 decimales.
}
