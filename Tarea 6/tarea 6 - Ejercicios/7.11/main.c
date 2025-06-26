#include <stdio.h>
#include <ctype.h>

/* Verifica.
   El programa, al recibir como datos una cadena de caracteres y una posición específica en la cadena,
   determina si el caracter correspondiente es una letra minúscula.
*/

void main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (máximo 50): ");
    gets(cad);  // Usando gets() como pediste (aunque está obsoleto)

    printf("\nIngrese la posición en la cadena que desea verificar: ");
    scanf("%d", &n);

    if ((n >= 1) && (n <= 50))  // Posición válida (1 a 50)
    {
        p = cad[n - 1];  // Se resta 1 para convertir a índice (0-based)
        if (islower(p))
            printf("\n%c es una letra minúscula", p);
        else
            printf("\n%c no es una letra minúscula", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto");
    }
}
