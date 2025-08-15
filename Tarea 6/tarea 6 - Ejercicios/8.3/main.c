#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <string.h> // Para funciones de cadena como strlen, aunque no estrictamente necesaria para gets()

/* Estructuras-3.
El programa muestra la manera en que se declara una estructura anidada, así
como la forma de acceso a los campos de las variables o apuntadores de tipo
estructura, tanto para lectura como para escritura. Se utiliza además una
función que recibe como parámetro un apuntador de tipo estructura. */

typedef struct { // Declaración de la estructura domicilio utilizando typedef.
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado { // Declaración de la estructura anidada empleado.
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; // direccion es un campo de tipo estructura domicilio de la estructura empleado.
};

void Lectura(struct empleado *a) {
    /* Función que permite leer los campos de un apuntador de tipo estructura
     empleado. */
    printf("\nIngrese el nombre del empleado: ");
    gets(a->nombre); // Usando gets como en el original
    fflush(stdin);   // Usando fflush(stdin) como en el original

    printf("Ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("----Ingrese la direccion del empleado----");
    printf("\n\tCalle: ");
    gets(a->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

void main() { // Usando void main() como se solicitó
    // Inicialización de struct empleado e0
    // Asegúrate de que los datos corresponden a la estructura anidada {nombre, departamento, sueldo, {calle, numero, cp, localidad}}
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};

    struct empleado *e1, *e2, e3, e4;
    /* Se declaran diferentes variables y apuntadores de la estructura empleado
     para que el lector pueda apreciar también las diferentes formas en que los
     campos reciben valores. */

    /* En el programa principal se leen los campos de una variable, e3, y un
     apuntador de tipo estructura, *e1. */

    // Asignación de memoria para e1 (sustituye 'new' por 'malloc')
    e1 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e1 == NULL) { // Comprobación de asignación de memoria
        printf("Error: No se pudo asignar memoria para e1.\n");
        return; // Salir de void main
    }

    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", e1->nombre); // scanf para cadenas, sin '&' al usar el nombre del array
    fflush(stdin);

    printf("Ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("----Ingrese la direccion del empleado----");
    printf("\n\tCalle: ");
    gets(e1->direccion.calle); // Corregido: e1->direccion.calle
    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    gets(e1->direccion.localidad);

    printf("\nIngrese el nombre del empleado 3: ");
    scanf("%s", e3.nombre); // scanf para cadenas, sin '&' al usar el nombre del array
    fflush(stdin);

    printf("Ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("----Ingrese la direccion del empleado----");
    printf("\n\tCalle: ");
    gets(e3.direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    fflush(stdin); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    gets(e3.direccion.localidad);

    /* En la función Lectura se leen los campos de una variable, e4, y un apuntador
     de tipo estructura, *e2. */
    e2 = (struct empleado *)malloc(sizeof(struct empleado)); // Asignación de memoria para e2
    if (e2 == NULL) { // Comprobación de asignación de memoria
        printf("Error: No se pudo asignar memoria para e2.\n");
        free(e1); // Liberar e1 antes de salir
        return;
    }

    Lectura(e2);
    Lectura(&e4);

    // Impresión de datos (corregido e1->sueldo y el formato)
    printf("\nDatos del empleado 0:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e0.nombre, e0.departamento, e0.sueldo,
           e0.direccion.calle, e0.direccion.numero, e0.direccion.cp, e0.direccion.localidad);

    printf("\nDatos del empleado 1:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 3:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e3.nombre, e3.departamento, e3.sueldo,
           e3.direccion.calle, e3.direccion.numero, e3.direccion.cp, e3.direccion.localidad);

    printf("\nDatos del empleado 4:\n");
    printf("Nombre: %s\nDepartamento: %s\nSueldo: %.2f\nDireccion: %s #%d, CP %d, %s\n",
           e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    // Liberar la memoria asignada dinámicamente
}
