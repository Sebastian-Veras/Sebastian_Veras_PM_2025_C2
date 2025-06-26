#include <stdio.h>

/* Funciones para el manejo de cadenas de caracteres de la biblioteca stdio.h */

void main(void)
{
    char *cad0 = "Buenos dias";   /* Apuntador a cadena constante */
    char cad1[20] = "Hola";       /* Arreglo con espacio para 20 caracteres */
    char cad2[] = "Mexico";       /* Arreglo con tamaño automático */
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
    char cad4[20], cad5[20], cad6[20];
    char p;
    int i = 0;

    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una linea de texto (se lee con gets): \n");
    /* Advertencia: gets() es peligroso, mejor usar fgets() */
    fgets(cad4, sizeof(cad4), stdin);

    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    /* Limpieza del buffer de entrada */
    while(getchar() != '\n');

    printf("\nIngrese una linea de texto (se lee con scanf): \n");
    scanf("%19s", cad5);   /* Limitamos la lectura para evitar desbordamiento */

    printf("\nLa cadena cad5 es: ");
    printf("%s", cad5);

    /* Limpieza del buffer de entrada */
    while(getchar() != '\n');

    printf("\nIngrese una linea de texto (se lee cada caracter con getchar): \n");
    while((p = getchar()) != '\n' && i < 19) {
        cad6[i++] = p;
    }
    cad6[i] = '\0';

    printf("\nLa cadena cad6 es: ");
    puts(cad6);
}
