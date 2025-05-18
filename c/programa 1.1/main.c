#include <stdio.h>
#include<stdlib.h>
int main() {
    // Ingredientes principales
    int chiles_morita = 150;       // gramos
    int cucharadas_aceite = 2;
    int dientes_ajo = 12;
    int cebollas = 1;
    int tazas_vinagre = 2;
    int granos_pimienta = 10;
    float cucharadas_oregano = 1.5;
    int piloncillo = 185;          // gramos

    // Ingredientes para el relleno
    int cucharada_aceite_relleno = 1;
    float cebolla_picada = 0.5;
    int ajos_picados = 2;
    float taza_tomate = 0.5;
    float taza_almendras = 0.25;
    float taza_pasas = 0.25;
    int pechugas_pollo = 1;
    float sal = 1.0;               // cucharadita
    float pimienta = 0.5;          // cucharada

    // Ingredientes para la salsa
    int huevos = 2;
    float taza_harina = 0.75;
    float taza_nueces = 0.75;
    float taza_crema = 1.0;

    // Mostrar los ingredientes
    printf("Ingredientes:\n");
    printf("- %d g de chiles morita\n", chiles_morita);
    printf("- %d cucharadas de aceite\n", cucharadas_aceite);
    printf("- %d dientes de ajo\n", dientes_ajo);
    printf("- %d cebolla\n", cebollas);
    printf("- %d tazas de vinagre de vino tinto\n", tazas_vinagre);
    printf("- %d granos de pimienta negra\n", granos_pimienta);
    printf("- %.1f cucharadas de orégano seco\n", cucharadas_oregano);
    printf("- %d g de piloncillo rallado\n", piloncillo);

    printf("\nRelleno:\n");
    printf("- %d cucharada de aceite\n", cucharada_aceite_relleno);
    printf("- %.1f cebolla picada\n", cebolla_picada);
    printf("- %d dientes de ajo picados\n", ajos_picados);
    printf("- %.1f taza de tomate picado\n", taza_tomate);
    printf("- %.2f taza de almendras picadas\n", taza_almendras);
    printf("- %.2f taza de uvas pasas\n", taza_pasas);
    printf("- %d pechuga de pollo desmenuzada\n", pechugas_pollo);
    printf("- %.1f cucharadita de sal\n", sal);
    printf("- %.1f cucharada de pimienta\n", pimienta);

    printf("\nSalsa:\n");
    printf("- %d huevos (separadas las claras y yemas)\n", huevos);
    printf("- %.2f taza de harina\n", taza_harina);
    printf("- %.2f taza de nueces\n", taza_nueces);
    printf("- %.1f taza de crema espesa\n", taza_crema);

    // Mostrar los pasos
    printf("\nPasos de preparación:\n");
    printf("1. Lava y seca los chiles. Saltéalos con ajo y cebolla.\n");
    printf("2. Añade vinagre, sal, pimienta, orégano y piloncillo. Cocina por 10 minutos.\n");
    printf("3. Refrigera la mezcla por 24 horas.\n");
    printf("4. Prepara el relleno cocinando los ingredientes del relleno por 8 minutos.\n");
    printf("5. Abre los chiles con cuidado y rellénalos.\n");
    printf("6. Bate claras de huevo y añade las yemas.\n");
    printf("7. Pasa los chiles por harina y huevo, y fríelos hasta dorar.\n");
    printf("8. Procesa las nueces con la crema. Sirve la salsa sobre los chiles.\n");

    return 0;
}
