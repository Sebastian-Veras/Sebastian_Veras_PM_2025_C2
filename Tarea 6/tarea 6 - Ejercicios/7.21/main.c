#include <stdio.h>    // Required for printf, scanf, getchar, puts
#include <string.h>   // Required for strcpy, strcspn

// Prototipo de función.
// char FRA[][30] es una forma correcta de declarar un 2D array de caracteres.
void intercambia(char FRA[][30], int n);

// Corrección: int main(void) es la firma estándar para la función principal.
void main(void) {
    int i, n;
    // FRA[20][30]: Un arreglo para 20 cadenas, cada una de hasta 29 caracteres + '\0'.
    char FRA[20][30];

    printf("\nIngrese el numero de filas del arreglo  ");
    scanf("%d", &n);

    // Validación básica para 'n' para evitar desbordamientos del arreglo.
    if (n < 1 || n > 20) {
        printf("Numero de filas invalido. Se ajustara a un valor entre 1 y 20.\n");
        if (n < 1) n = 1;
        if (n > 20) n = 20;
    }

    // Corrección: Limpiar el buffer de entrada después de scanf.
    // Esto consume el caracter '\n' que scanf deja después de leer el número.
    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("Ingrese la linea de texto numero %d (maximo 29 caracteres): ", i + 1);

        // Corrección CRÍTICA: Usar fgets() en lugar de gets() por seguridad.
        // fgets(destino, tamaño_max_lectura, fuente)
        // sizeof(FRA[i]) asegura que no se lea más allá del límite del buffer (30).
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Corrección: Eliminar el salto de linea '\n' que fgets() puede incluir.
        // strcspn() encuentra la posición del primer '\n' y lo reemplazamos por '\0'.
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n--- Cadenas Originales ---\n");
    for (i = 0; i < n; i++) {
        printf("Linea %d: \"%s\"\n", i + 1, FRA[i]); // Formato de impresión mejorado
    }

    intercambia(FRA, n); // Llama a la función para intercambiar las filas.


    for (i = 0; i < n; i++) {
        printf("Impresion de la linea de texto %d: \"%s\"\n", i + 1, FRA[i]); // Formato de impresión mejorado
    }

 // Se retorna 0 para indicar una ejecución exitosa.
}

// Esta función intercambia las filas del arreglo (la primera con la última, la segunda con la penúltima, etc.).
void intercambia(char FRA[][30], int n) {
    int i, j;
    char cad[30]; // Buffer temporal para el intercambio de cadenas.

    j = n - 1; // 'j' apunta al índice de la última fila.
    for (i = 0; i < (n / 2); i++) { // El bucle solo necesita ir hasta la mitad del arreglo.
        // Proceso de intercambio de dos cadenas:
        strcpy(cad, FRA[i]);    // 1. Copia la cadena de la posición 'i' a 'cad' (temporal).
        strcpy(FRA[i], FRA[j]); // 2. Copia la cadena de la posición 'j' a 'i'.
        strcpy(FRA[j], cad);    // 3. Copia la cadena de 'cad' (que era la original de 'i') a 'j'.

        j--; // Corrección: Decrementa 'j' para moverse hacia el centro del arreglo.
    }
}
