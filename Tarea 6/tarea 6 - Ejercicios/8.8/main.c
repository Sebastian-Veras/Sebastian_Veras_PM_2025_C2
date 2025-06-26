#include <stdio.h>    // Necesario para funciones de entrada/salida (printf, scanf, getchar)
#include <string.h>   // Necesario para funciones de cadena (strcspn)

/* Hospital.
 * El programa genera información acerca de los pacientes de un hospital.
 */

// Declaración de la estructura 'domicilio'
typedef struct {
    char cal[20];   // Calle
    int num;        // Número
    char col[20];   // Colonia
    char cp[6];     // Código Postal (ajustado a 6 para permitir 5 dígitos + '\0')
    char ciu[20];   // Ciudad
} domicilio;

// Declaración de la estructura 'paciente' (anidada con 'domicilio')
typedef struct {
    char nom[20];       // Nombre y apellido
    int edad;
    char sexo;          // Sexo (F-M)
    int con;            // Condición (gravedad: 1..5)
    domicilio dom;      // Campo 'dom' es de tipo estructura 'domicilio'
    char tel[10];       // Teléfono
} paciente;

// --- Prototipos de funciones ---
// Declaran las funciones que se usarán en el programa antes de su definición.
void Lectura(paciente *, int);  // Lee los datos de un arreglo de pacientes
void F1(paciente *, int);       // Calcula y muestra porcentaje de hombres y mujeres
void F2(paciente *, int);       // Cuenta pacientes por categoría de condición
void F3(paciente *, int);       // Muestra nombre y teléfono de pacientes en condición 5

// --- Función principal ---
// Corrección: 'int main(void)' es la firma estándar en C.
int main(void) {
    paciente HOSPITAL[100]; // Arreglo unidimensional de tipo estructura 'paciente'
    int TAM;                 // Variable para el número real de pacientes a ingresar

    // Bucle do-while para leer y validar el número de pacientes.
    // Corrección: El tamaño máximo ahora es 100, para coincidir con la declaración del arreglo.
    do {
        printf("Ingrese el numero de pacientes : ");
        scanf("%d", &TAM);
        // Corrección: Limpia el búfer de entrada después de 'scanf'.
        // Esto consume el '\n' dejado por el Enter del usuario, evitando problemas en futuras lecturas.
        while (getchar() != '\n');
    } while (TAM > 100 || TAM < 1); // Validación del tamaño del arreglo

    Lectura(HOSPITAL, TAM); // Llama a la función 'Lectura' para llenar los datos de los pacientes
    F1(HOSPITAL, TAM);      // Llama a 'F1' para los porcentajes por sexo
    F2(HOSPITAL, TAM);      // Llama a 'F2' para el conteo por condición
    F3(HOSPITAL, TAM);      // Llama a 'F3' para pacientes en condición de gravedad 5

    return 0; // Indica que el programa finalizó correctamente.
}

// --- Implementación de la función Lectura ---
// Esta función lee los campos de un arreglo de estructuras 'paciente'.
void Lectura(paciente A[], int T) {
    int I; // Contador para el bucle de pacientes

    for (I = 0; I < T; I++) {
        printf("\n\t\t--- Paciente %d ---\n", I + 1); // Añadido '\n' para mejor formato

        printf("Nombre: ");
        // Corrección crucial: Usa fgets() en lugar de gets() por seguridad.
        // Limita la lectura al tamaño del búfer para prevenir desbordamientos.
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        // Corrección esencial: Elimina el caracter de nueva línea ('\n') que fgets() puede incluir.
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';

        printf("Edad: ");
        scanf("%d", &A[I].edad);
        // Corrección: Limpia el búfer de entrada después de leer la edad.
        while (getchar() != '\n');

        printf("Sexo (F-M): ");
        // Corrección: Limpia el búfer ANTES de leer el caracter para evitar que lea un '\n' anterior.
        // Luego, limpia el búfer DESPUES para futuras lecturas.
        scanf("%c", &A[I].sexo);
        while (getchar() != '\n');

        printf("Condicion (1..5): ");
        scanf("%d", &A[I].con);
        // Corrección: Limpia el búfer de entrada después de leer la condición.
        while (getchar() != '\n');

        // --- Lectura del Domicilio ---
        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = '\0';

        printf("\tNumero: ");
        scanf("%d", &A[I].dom.num);
        // Corrección: Limpia el búfer de entrada.
        while (getchar() != '\n');

        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = '\0';

        printf("\tCodigo Postal: ");
        // Corrección: cp[5] puede ser demasiado pequeño para 5 dígitos + '\0'.
        // Asegúrate de que tu CP no tenga más de 4 dígitos si usas char cp[5].
        // Se recomienda char cp[6] para 5 dígitos + '\0'.
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = '\0';

        printf("Telefono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = '\0';
    }
}

// --- Implementación de la función F1 ---
// Calcula el porcentaje de hombres y mujeres registrados.
void F1(paciente A[], int T) {
    int I;
    // Corrección crucial: Inicializar contadores a 0 para evitar valores basura.
    int FEM = 0, MAS = 0;
    int TOT; // Total de pacientes procesados (hombres + mujeres)

    for (I = 0; I < T; I++) {
        // Usa toupper() para manejar 'f', 'm', 'F', 'M' indistintamente
        // (requiere #include <ctype.h> si se usara, pero aquí asumimos entrada limpia)
        switch (A[I].sexo) {
            case 'F':
            case 'f': // Considera ambos casos para mayor robustez
                FEM++;
                break;
            case 'M':
            case 'm': // Considera ambos casos
                MAS++;
                break;
            // Opcional: default para manejar entradas de sexo inválidas


        }
    }
    TOT = FEM + MAS; // Total de pacientes con sexo válido

    // Manejo para evitar división por cero si no hay pacientes o sexos válidos
    if (TOT == 0) {
        printf("\nNo hay datos de pacientes validos para calcular porcentajes de sexo.\n");
        return;
    }

    // Corrección: Usar '%%' para imprimir el símbolo de porcentaje literal.
    printf("\nPorcentaje de Hombres: %.2f%%\n", (float)MAS / TOT * 100);
    printf("Porcentaje de Mujeres: %.2f%%\n", (float)FEM / TOT * 100);
}

// --- Implementación de la función F2 ---
// Cuenta el número de pacientes en cada categoría de condición (1 a 5).
void F2(paciente A[], int T) {
    int I;
    // Corrección crucial: Inicializar contadores a 0.
    int C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
            default:
                printf("Advertencia: Condicion invalida %d para el paciente %s (se ignorara para el calculo F2).\n", A[I].con, A[I].nom);
                break;
        }
    }
    printf("\n--- Conteo de Pacientes por Condicion ---\n");
    printf("Numero pacientes en condicion 1: %d\n", C1);
    printf("Numero pacientes en condicion 2: %d\n", C2);
    printf("Numero pacientes en condicion 3: %d\n", C3);
    printf("Numero pacientes en condicion 4: %d\n", C4);
    printf("Numero pacientes en condicion 5: %d\n", C5);
}

// --- Implementación de la función F3 ---
// Muestra el nombre y teléfono de pacientes con condición de máxima gravedad (5).
void F3(paciente A[], int T) {
    int I;

    int found = 0; // Flag para saber si se encontró al menos un paciente

    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("Nombre: %s\tTelefono: %s\n", A[I].nom, A[I].tel);
            found = 1;
        }
    }

}
