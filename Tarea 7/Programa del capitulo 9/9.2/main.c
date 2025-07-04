#include <stdio.h> // Incluye la librería estándar de entrada/salida

/* Archivos y caracteres.
El programa lee caracteres de un archivo. */
void main()
{
    char p1;
    FILE *ar; // Declara un puntero a archivo

    // Abre el archivo "arc.txt" en modo de lectura ("r")
    // Verifica si el archivo se abrió correctamente
    if ((ar = fopen("C:\\Users\\1\\Downloads\\Sebastian_Veras_PM_2025_C2\\Tarea 7\\9.1\\arc.txt", "r")) != NULL)
    {
        // Lee caracteres del archivo hasta que se detecte el fin del archivo (EOF)
        while (!feof(ar))
        {
            p1 = fgetc(ar); // Lee un carácter del archivo
            putchar(p1);    // Muestra el carácter en la pantalla
        }
        fclose(ar); // Cierra el archivo
    }
    else
    {
        printf("No se puede abrir el archivo"); // Imprime un error si el archivo no se puede abrir
    }
}
