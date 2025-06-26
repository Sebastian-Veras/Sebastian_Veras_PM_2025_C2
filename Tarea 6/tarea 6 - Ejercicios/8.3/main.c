#include <stdio.h>    // Para printf, scanf, getchar
#include <string.h>   // Para strcpy, strcspn
#include <stdlib.h>   // Para malloc, free, exit
#include <ctype.h>    // Aunque no se usa directamente para la entrada de cadenas, es útil para entradas de char

/* Estructuras-3.
 * El programa muestra la manera en que se declara una estructura anidada, así
 * como la forma de acceso a los campos de las variables o apuntadores de tipo
 * estructura, tanto para lectura como para escritura. Se utiliza además una
 * función que recibe como parámetro un apuntador de tipo estructura.
 */

// Declaración de la estructura domicilio utilizando typedef.
typedef struct {
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

// Declaración de la estructura anidada empleado.
struct empleado {
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; // 'direccion' es un campo de tipo estructura domicilio
                         // de la estructura empleado.
};

// Prototipo de la función Lectura.
// Función que permite leer los campos de un apuntador de tipo estructura empleado.
void Lectura(struct empleado *a);

// Corrección: 'int main(void)' es la firma estándar en C.
int main(void) {
    // Inicialización estática de un empleado con sintaxis correcta para anidación.
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jerónimo", 120, 3490, "Toluca"}};

    // Declaración de variables y apuntadores de la estructura empleado.
    struct empleado *e1, *e2, e3, e4;

    // --- Asignación de memoria dinámica para e1 y e2 ---
    // Corrección: Usar malloc para asignación de memoria en C.
    e1 = (struct empleado *) malloc(sizeof(struct empleado));
    if (e1 == NULL) { // Verificación de errores de malloc.
        perror("Error al asignar memoria para e1");
        return EXIT_FAILURE; // Salir con código de error.
    }
    e2 = (struct empleado *) malloc(sizeof(struct empleado));
    if (e2 == NULL) { // Verificación de errores de malloc.
        perror("Error al asignar memoria para e2");
        free(e1); // Liberar la memoria de e1 antes de salir.
        return EXIT_FAILURE; // Salir con código de error.
    }

    // --- Ingreso de datos para empleado 1 (*e1) ---
    printf("\nIngrese el nombre del empleado 1: ");
    // Corrección: Usar fgets por seguridad en lugar de scanf("%s") o gets().
    fgets(e1->nombre, sizeof(e1->nombre), stdin);
    e1->nombre[strcspn(e1->nombre, "\n")] = '\0'; // Eliminar el '\n' de fgets.

    printf("Ingrese el departamento de la empresa: ");
    fgets(e1->departamento, sizeof(e1->departamento), stdin);
    e1->departamento[strcspn(e1->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    // Corrección: Limpiar el buffer de entrada después de scanf.
    while (getchar() != '\n');

    printf("---Ingrese la direccion del empleado---\n"); // Corregido formato de guiones
    printf("\tCalle: ");
    // Corrección: Acceso correcto a miembro de estructura anidada y uso de fgets.
    fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin);
    e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';

    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    while (getchar() != '\n');

    printf("\tCodigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    while (getchar() != '\n');

    printf("\tLocalidad: ");
    fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin);
    e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';

    // --- Ingreso de datos para empleado 3 (e3) ---
    printf("\nIngrese el nombre del empleado 3: ");
    // Corrección: Uso de fgets para la variable estática.
    fgets(e3.nombre, sizeof(e3.nombre), stdin);
    e3.nombre[strcspn(e3.nombre, "\n")] = '\0';

    printf("Ingrese el departamento de la empresa: ");
    fgets(e3.departamento, sizeof(e3.departamento), stdin);
    e3.departamento[strcspn(e3.departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    while (getchar() != '\n');

    printf("---Ingrese la direccion del empleado---\n"); // Corregido formato de guiones
    printf("\tCalle: ");
    fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin);
    e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';

    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    while (getchar() != '\n');

    printf("\tCodigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    while (getchar() != '\n');

    printf("\tLocalidad: ");
    fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin);
    e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';

    // --- Lectura de empleados 2 (*e2) y 4 (e4) usando la función Lectura ---
    // Se mantiene la estructura de llamadas tal como la tenías
    Lectura(e2);
    Lectura(&e4);

    // --- Mostrar los datos de los empleados ---
    // Corregido el formato de los printf para mostrar todos los datos de forma legible
    printf("\nDatos del empleado 0:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e0.nombre, e0.departamento, e0.sueldo,
           e0.direccion.calle, e0.direccion.numero, e0.direccion.cp, e0.direccion.localidad);

    printf("\nDatos del empleado 1:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 2:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e2->nombre, e2->departamento, e2->sueldo,
           e2->direccion.calle, e2->direccion.numero, e2->direccion.cp, e2->direccion.localidad);

    printf("\nDatos del empleado 3:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e3.nombre, e3.departamento, e3.sueldo,
           e3.direccion.calle, e3.direccion.numero, e3.direccion.cp, e3.direccion.localidad);

    printf("\nDatos del empleado 4:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    // --- Liberar memoria dinámicamente asignada ---
    free(e1);
    free(e2);

    return EXIT_SUCCESS; // Retorno estándar para éxito.
}

// Implementación de la función Lectura.
void Lectura(struct empleado *a) {
    printf("\nIngrese el nombre del empleado: "); // Añadido \n para mejor formato
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';

    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, sizeof(a->departamento), stdin);
    a->departamento[strcspn(a->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    while (getchar() != '\n'); // Limpiar el buffer.

    printf("---Ingrese la direccion del empleado---\n"); // Corregido formato de guiones
    printf("\tCalle: ");
    fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin);
    a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';

    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    while (getchar() != '\n');

    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    while (getchar() != '\n');

    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin);
    a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';
}

