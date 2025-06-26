#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
 * El programa, al recibir como dato un arreglo unidimensional de tipo
 * cadena de caracteres, determina el número de minúsculas y mayúsculas
 * que hay en cada cadena.
 */

// Corrección: El prototipo debe coincidir con la implementación de la función
// Se pasa un puntero al primer carácter de la cadena.
void minymay(char *cad);

int main(void) // Corrección: Cambiado a 'int main(void)' por estándar C
{
    int i, n;
    char FRA[20][50]; // Arreglo de cadenas de caracteres, 20 cadenas de hasta 49 caracteres + \0

    printf("\nIngrese el numero de lineas de texto (maximo 20): ");
    scanf("%d", &n);
    // Validación básica para evitar desbordamiento del arreglo FRA
    if (n < 1 || n > 20) {
        printf("Numero de lineas invalido. Se ajustara a 20.\n");
        n = 20;
    }

    // Limpia el buffer después de scanf. Es buena práctica antes de usar fgets en un bucle.
    while (getchar() != '\n');

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto: ", i + 1);
        // fgets es más seguro que gets, ya que previene desbordamientos de buffer.
        // sizeof(FRA[i]) asegura que no se lea más allá del tamaño de la cadena actual.
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Elimina el salto de línea ('\n') que fgets puede incluir al final de la cadena.
        // strcspn encuentra la posición del primer '\n' y lo reemplaza con '\0'.
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n--- Resultados ---\n");
    for (i = 0; i < n; i++)
    {
        printf("\nAnalizando cadena %d: \"%s\"\n", i + 1, FRA[i]);
        minymay(FRA[i]); // Se pasa cada cadena individual a la función
    }

    return 0; // Se añade un retorno para 'int main'
}

void minymay(char *cad) // La función recibe un puntero a la cadena
{
    int i = 0, mi = 0, ma = 0; // mi para minúsculas, ma para mayúsculas

    // Recorre la cadena hasta encontrar el carácter nulo de terminación ('\0')
    while (cad[i] != '\0')
    {
        // islower() verifica si el carácter es una letra minúscula
        if (islower(cad[i]))
            mi++;
        // isupper() verifica si el carácter es una letra mayúscula
        else if (isupper(cad[i]))
            ma++;
        i++; // Avanza al siguiente carácter
    }

    printf("Numero de letras minusculas: %d\n", mi);
    printf("Numero de letras mayusculas: %d\n", ma);
}
