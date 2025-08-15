#include <stdio.h>   // Para printf, scanf, gets, puts
#include <string.h>  // Para strcspn (necesario si quitaras el \n de fgets, pero con gets no aplica)
#include <ctype.h>   // Para islower, isupper

/* Minúsculas y mayúsculas.
 * El programa, al recibir como dato un arreglo bidimensional de tipo
 * cadena de caracteres, determina el número de minúsculas y mayúsculas
 * que hay en cada cadena.
 */

// Prototipo de función: 'minymay' recibe un puntero a char (char*)
void minymay(char *cadena);

int main(void) // Usamos int main(void) por ser el estándar
{
    int i, n;
    // Arreglo bidimensional de cadenas de caracteres.
    char FRA[20][50];

    printf("\nIngrese el numero de cadenas (filas) del arreglo (max 20): ");
    scanf("%d", &n);

    // Validar que 'n' no exceda el tamaño del arreglo
    if (n > 20 || n < 1) {
        printf("Numero de cadenas invalido. Se ajustara a 20.\n");
        n = 20;
    }

    // Limpiar el buffer de entrada después de scanf.
    // Esto consume el caracter de nueva línea que scanf deja.
    while (getchar() != '\n' && !feof(stdin));

    for (i = 0; i < n; i++) {
        printf("Ingrese la linea %d de texto (¡ADVERTENCIA: NO ingrese mas de 49 caracteres!): ", i + 1);
        // ¡USO DE GETS() - EXTREMADAMENTE INSEGURO!
        // No hay comprobacion de limites, lo que puede causar desbordamientos de buffer.
        gets(FRA[i]);
    }

    printf("\n--- Analisis de Cadenas ---\n");
    for (i = 0; i < n; i++) {
        printf("\nCadena '%s':", FRA[i]); // Muestra la cadena que se esta analizando
        minymay(FRA[i]); // Llama a la funcion para analizar cada cadena
    }

    return 0; // Indica que el programa finalizó correctamente
}

void minymay(char *cadena)
/* Esta función se utiliza para calcular el número de minúsculas
 * y mayúsculas que hay en cada cadena.
 */
{
    int i = 0, mi = 0, ma = 0;
    while (cadena[i] != '\0') {
        if (islower(cadena[i])) {
            mi++;
        } else if (isupper(cadena[i])) {
            ma++;
        }
        i++;
    }
    printf("\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
