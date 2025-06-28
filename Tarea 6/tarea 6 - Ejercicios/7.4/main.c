#include <stdio.h>  // Para puts, printf, gets
#include <string.h> // Para strcpy y strcspn (si quieres copiar cadenas o limpiar newlines)
void main(void) {
    char *cad0;
    cad0 = "Argentina";
    puts(cad0); // Esto imprimirá "Argentina" correctamente

    cad0 = "Brasil";
    puts(cad0); // Esto imprimirá "Brasil" correctamente

    // --- Forma correcta de manejar la entrada de usuario para una cadena ---
    char cad1_buffer[50]; // Declara un arreglo de caracteres para guardar la entrada
    printf("Ingrese una cadena para cad1: ");
    // gets(cad1_buffer); // ¡NO ES SEGURO!: Considera reemplazar con fgets para seguridad
    // Ejemplo de entrada más segura con fgets:
    if (fgets(cad1_buffer, sizeof(cad1_buffer), stdin) != NULL) {
        // Elimina el salto de línea final si fgets lo lee (es común)
        cad1_buffer[strcspn(cad1_buffer, "\n")] = 0;
    }
    puts(cad1_buffer);

    // --- Declaración y modificación correcta de un arreglo de cadena ---
    char cad2[20] = "México";
    puts(cad2);

    printf("Ingrese una nueva cadena para cad2: ");
    // gets(cad2); // ¡NO ES SEGURO!: Considera reemplazar con fgets
    if (fgets(cad2, sizeof(cad2), stdin) != NULL) {
        cad2[strcspn(cad2, "\n")] = 0; // Eliminar el salto de línea
    }
    puts(cad2);

    // --- Forma correcta de asignar una nueva cadena a un arreglo de caracteres existente ---
    // En lugar de: cad2[10] = "Guatemala"; (error de compilación)
    // Usa strcpy si la cadena cabe:
    if (strlen("Guatemala") < sizeof(cad2)) { // Verifica si la nueva cadena cabe para evitar desbordamiento
        strcpy(cad2, "Guatemala");
        puts(cad2);
    } else {
        printf("Error: 'Guatemala' es demasiado larga para cad2.\n");
    }


}
