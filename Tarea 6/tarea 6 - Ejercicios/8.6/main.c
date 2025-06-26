#include <stdio.h>    // Necesario para funciones de entrada/salida (printf, scanf, getchar)
#include <string.h>   // Necesario para funciones de cadena (strcspn)

/* Comercializadora farmacéutica.
 * El programa maneja información sobre ventas, inventario, reabastecimiento y
 * nuevos productos de una comercializadora farmacéutica.
 */

// Definición de la estructura 'producto'
typedef struct {
    int clave;          // Clave única del producto
    char nombre[15];    // Nombre del producto (hasta 14 caracteres + '\0')
    float precio;       // Precio del producto
    int existencia;     // Cantidad de productos en inventario
} producto;

// --- Prototipos de funciones ---
// Permite que las funciones sean llamadas antes de su definición completa.
void Lectura(producto *, int);           // Lee los datos de los productos
void Ventas(producto *, int);            // Maneja las ventas de productos
void Reabastecimiento(producto *, int);  // Permite añadir existencias a productos
void Nuevos_Productos(producto *, int *); // Incorpora nuevos productos, modificando el tamaño del arreglo
void Inventario(producto *, int);        // Muestra el inventario actual

// --- Función principal ---
// Corrección: 'int main(void)' es la firma estándar en C.
int main(void) {
    producto INV[100]; // Declaración de un arreglo unidimensional de 100 productos
    int TAM;           // Variable para el tamaño real del inventario
    int OPE;           // Variable para la operación a realizar (Menú)

    // Bucle para leer y validar el número de productos iniciales.
    // Asegura que TAM esté entre 1 y 100.
    do {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
        // Corrección: Limpiar el búfer de entrada después de scanf.
        // Esto consume el '\n' dejado por el Enter del usuario, evitando problemas en lecturas futuras.
        while (getchar() != '\n');
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM); // Llama a la función 'Lectura' para llenar el inventario inicial

    // Menú principal de operaciones
    printf("\nIngrese operacion a realizar. \n");
    printf("\t\t1 - Ventas \n");
    printf("\t\t2 - Reabastecimiento \n");
    printf("\t\t3 - Nuevos Productos \n");
    printf("\t\t4 - Inventario \n");
    printf("\t\t0 - Salir: ");
    scanf("%d", &OPE);
    // Corrección: Limpiar el búfer de entrada después de scanf.
    while (getchar() != '\n');

    // Bucle principal de operaciones. Continúa mientras OPE no sea 0.
    while (OPE != 0) { // Corrección: Usar OPE != 0 es más claro que solo 'OPE' para una condición de salida.
        switch (OPE) {
            case 1:
                Ventas(INV, TAM); // Llama a la función de ventas
                break;
            case 2:
                Reabastecimiento(INV, TAM); // Llama a la función de reabastecimiento
                break;
            case 3:
                // Se pasa &TAM por referencia porque la función puede modificar el número total de productos.
                Nuevos_Productos(INV, &TAM);
                break;
            case 4:
                Inventario(INV, TAM); // Llama a la función de inventario para mostrarlo
                break;
            default: // Mensaje si la opción no es válida
                printf("Opcion invalida. Por favor, intente de nuevo.\n");
                break;
        }

        // Muestra el menú de nuevo y solicita la siguiente operación
        printf("\nIngrese operacion a realizar. \n");
        printf("\t\t1 - Ventas \n");
        printf("\t\t2 - Reabastecimiento \n");
        printf("\t\t3 - Nuevos Productos \n");
        printf("\t\t4 - Inventario \n");
        printf("\t\t0 - Salir: ");
        scanf("%d", &OPE);
        // Corrección: Limpiar el búfer de entrada después de scanf.
        while (getchar() != '\n');
    }

    return 0; // Indica que el programa finalizó correctamente.
}

// --- Implementación de la función Lectura ---
// Lee un arreglo de estructuras 'producto'.
void Lectura(producto A[], int T) {
    int I; // Contador para el bucle

    for (I = 0; I < T; I++) {
        printf("\nIngrese informacion del producto %d\n", I + 1); // Añadido '\n' para mejor formato
        printf("\tClave: ");
        scanf("%d", &A[I].clave);
        // Corrección: Limpiar el búfer de entrada después de scanf.
        while (getchar() != '\n');

        printf("\tNombre: ");
        // Corrección crucial: Usar fgets() en lugar de gets() por seguridad.
        // Limita la lectura al tamaño del búfer para prevenir desbordamientos.
        fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
        // Corrección: Eliminar el salto de línea ('\n') que fgets() puede incluir.
        A[I].nombre[strcspn(A[I].nombre, "\n")] = '\0';

        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);
        // Corrección: Limpiar el búfer de entrada después de scanf.
        while (getchar() != '\n');

        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
        // Corrección: Limpiar el búfer de entrada después de scanf.
        while (getchar() != '\n');
    }
}

// --- Implementación de la función Ventas ---
// Maneja las ventas, actualizando el inventario y calculando el total de la venta.
void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES; // CLA: clave, CAN: cantidad, I: índice, RES: respuesta
    float TOT, PAR;       // TOT: total de la venta, PAR: parcial de un producto

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    // Corrección: Limpiar el búfer de entrada.
    while (getchar() != '\n');

    TOT = 0.0; // Inicializa el total de la venta
    while (CLA != 0) { // Continúa mientras la clave no sea 0
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        // Corrección: Limpiar el búfer de entrada.
        while (getchar() != '\n');

        I = 0;
        // Búsqueda lineal para localizar la clave del producto.
        // Asume que los productos están ordenados por clave para optimizar la búsqueda (aunque no se garantiza en Lectura).
        while ((I < T) && (A[I].clave < CLA)) {
            I++;
        }

        // Verifica si la clave fue encontrada
        if ((I == T) || (A[I].clave > CLA)) { // Si se llegó al final o se pasó la clave
            printf("\nLa clave del producto es incorrecta.\n"); // Añadido '\n' para formato
        } else {
            // Si el stock es suficiente para satisfacer el pedido
            if (A[I].existencia >= CAN) {
                A[I].existencia -= CAN; // Actualiza el stock del producto
                PAR = A[I].precio * CAN;
                TOT += PAR; // Suma al total de la venta
            } else {
                // Si no hay suficiente stock
                printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d unidades.", A[I].existencia);
                printf(" Los lleva (1 - Si / 0 - No)?: "); // Clarificado el prompt
                scanf("%d", &RES);
                // Corrección: Limpiar el búfer de entrada.
                while (getchar() != '\n');

                if (RES == 1) { // Si el cliente decide llevar lo que hay
                    PAR = A[I].precio * A[I].existencia;
                    A[I].existencia = 0; // El stock queda en cero
                    TOT += PAR;
                }
            }
        }
        printf("\nIngrese la siguiente clave del producto -0 para salir-: "); // Corrección: Cierre de comillas y formato
        scanf("%d", &CLA);
        // Corrección: Limpiar el búfer de entrada.
        while (getchar() != '\n');
    }
    printf("\nTotal de la venta: %.2f\n", TOT); // Muestra el total con 2 decimales
}

// --- Implementación de la función Reabastecimiento ---
// Permite aumentar la existencia de productos en el inventario.
void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I; // CLA: clave, CAN: cantidad, I: índice

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    // Corrección: Limpiar el búfer de entrada.
    while (getchar() != '\n');

    while (CLA != 0) {
        I = 0;
        // Búsqueda lineal para localizar la clave del producto.
        while ((I < T) && (A[I].clave < CLA)) {
            I++;
        }

        // Verifica si la clave fue encontrada
        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto ingresada es incorrecta.\n"); // Añadido '\n' para formato
        } else {
            printf("\tCantidad a reabastecer: "); // Clarificado el prompt
            scanf("%d", &CAN);
            // Corrección: Limpiar el búfer de entrada.
            while (getchar() != '\n');
            A[I].existencia += CAN; // Aumenta la existencia
            printf("\nProducto %s actualizado. Nueva existencia: %d\n", A[I].nombre, A[I].existencia);
        }
        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
        // Corrección: Limpiar el búfer de entrada.
        while (getchar() != '\n');
    }
}

// --- Implementación de la función Nuevos_Productos ---
// Incorpora nuevos productos al inventario, manteniendo el orden por clave.
// Recibe un puntero a 'T' porque el tamaño del inventario puede cambiar.
void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J; // CLA: clave, I, J: índices para bucles

    printf("\nIngrese clave del nuevo producto -0 para salir-: "); // Clarificado el prompt
    scanf("%d", &CLA);
    // Corrección: Limpiar el búfer de entrada.
    while (getchar() != '\n');

    // Continúa mientras haya espacio en el arreglo (máximo 100) y la clave no sea 0.
    while ((*T < 100) && (CLA != 0)) { // Corrección: Usar 100 en lugar de 30 para el límite.
        I = 0;
        // Búsqueda de la posición correcta para insertar el nuevo producto, manteniendo el orden.
        while ((I < *T) && (A[I].clave < CLA)) {
            I++;
        }

        if (I == *T) { // Si se llegó al final, se inserta el elemento en la última posición.
            A[I].clave = CLA;
            printf("\tNombre: ");
            fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
            A[I].nombre[strcspn(A[I].nombre, "\n")] = '\0';

            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            while (getchar() != '\n');

            printf("\tCantidad: "); // Corregido: "Cantidad" en lugar de "Existencia" para la entrada
            scanf("%d", &A[I].existencia);
            while (getchar() != '\n');

            (*T)++; // Incrementa el tamaño total del inventario.
            printf("\nProducto agregado correctamente al final.\n");
        } else if (A[I].clave == CLA) { // Si la clave ya existe
            printf("\nEl producto ya se encuentra en el inventario.\n");
        } else { // Si la clave no existe pero hay que insertarla en medio del arreglo
            // Mueve los elementos una posición a la derecha para hacer espacio.
            for (J = *T; J > I; J--) {
                A[J] = A[J - 1];
            }
            A[I].clave = CLA; // Inserta el nuevo producto en la posición encontrada
            printf("\tNombre: ");
            fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
            A[I].nombre[strcspn(A[I].nombre, "\n")] = '\0';

            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            while (getchar() != '\n');

            printf("\tCantidad: "); // Corregido: "Cantidad" en lugar de "Existencia" para la entrada
            scanf("%d", &A[I].existencia);
            while (getchar() != '\n');

            (*T)++; // Incrementa el tamaño total del inventario.
            printf("\nProducto agregado correctamente y reordenado.\n");
        }
        printf("\nIngrese otra clave de producto -0 para salir-: ");
        scanf("%d", &CLA);
        while (getchar() != '\n');
    }
    // Mensaje si ya no hay espacio
    if (*T == 100) { // Corrección: Usar 100 en lugar de 30 para el límite.
        printf("\nYa no hay espacio para incorporar nuevos productos.\n");
    }
}

// --- Implementación de la función Inventario ---
// Muestra la información de todos los productos almacenados en el inventario.
void Inventario(producto A[], int T) {
    int I; // Contador para el bucle

    if (T == 0) { // Manejar el caso de un inventario vacío
        printf("\nEl inventario esta vacio.\n");
        return;
    }

    printf("\n--- Inventario Actual ---\n");
    for (I = 0; I < T; I++) {
        printf("Producto %d:\n", I + 1);
        printf("\tClave: %d\n", A[I].clave);
        printf("\tNombre: %s\n", A[I].nombre);
        // Corrección: Usar %.2f para imprimir el precio (float).
        printf("\tPrecio: %.2f\n", A[I].precio);
        printf("\tExistencia: %d\n", A[I].existencia); // Eliminado espacio extra
    }
    printf("--- Fin del Inventario ---\n");
}
