#include <stdio.h> // Necesario para las funciones de E/S de archivos y la consola

void main(void) {
    FILE *archivo_origen;  // Puntero para el archivo de donde vamos a leer (arch1.txt)
    FILE *archivo_destino; // Puntero para el archivo donde vamos a escribir (arch2.txt)
    int byte_leido;        // Usamos 'int' para almacenar el byte (incluyendo EOF)

    // --- 1. Abrir el archivo de origen (arch1.txt) en modo lectura ("r") ---
    archivo_origen = fopen("arch1.txt", "r");

    // Verificar si el archivo de origen se abrió correctamente
    if (archivo_origen == NULL) {
        printf("Error: No se pudo abrir 'arch1.txt' para lectura.\n");
        printf("Asegúrate de que 'arch1.txt' exista en la misma carpeta que el programa.\n");
        // Importante: Si el archivo de origen no se abre, no podemos continuar.
        // Aquí deberíamos salir del programa.
        return; // Sale de main
    }


    archivo_destino = fopen("arch2.txt", "w");

    if (archivo_destino == NULL) {
        printf("Error: No se pudo abrir 'arch2.txt' para escritura.\n");
        fclose(archivo_origen);

    }
    printf("--- Mostrando y copiando el contenido de 'arch1.txt' ---\n");


while ((byte_leido = fgetc(archivo_origen)) != EOF) {

        fputc(byte_leido, archivo_destino);

        putchar(byte_leido);
    }


    fclose(archivo_origen);
    fclose(archivo_destino);

    printf("\n--- Fin de la operación ---\n");
    printf("Contenido de 'arch1.txt' copiado exitosamente a 'arch2.txt' (byte a byte).\n");
}
