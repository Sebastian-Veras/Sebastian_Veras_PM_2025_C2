#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* este programa sastiface esta expresion
 7*T4 - 6*P3 + 12*R5 < 5850*/
void main(void)
{

   long long t_val, p_val, r_val;
    long long resultado_expresion;
    int contador_soluciones = 0;
    int limite_T, limite_P, limite_R;




    printf("Ingresa el límite máximo para T (ej. 10): ");
    scanf("%d", &limite_T);

    printf("Ingresa el límite máximo para P (ej. 15): ");
    scanf("%d", &limite_P);

    printf("Ingresa el límite máximo para R (ej. 5): ");
    scanf("%d", &limite_R);


    for (t_val = 1; t_val <= limite_T; t_val++) {
                for (p_val = 1; p_val <= limite_P; p_val++) {
            for (r_val = 1; r_val <= limite_R; r_val++) {
                resultado_expresion = (long long)(7 * pow(t_val, 4) - 6 * pow(p_val, 3) + 12 * pow(r_val, 5));
                if (resultado_expresion < 5850) {
                    printf("Solución: T = %lld, P = %lld, R = %lld (Resultado: %lld)\n",
                           t_val, p_val, r_val, resultado_expresion);
                    contador_soluciones++;
                }
            }
        }
    }


    printf("Total de soluciones encontradas: %d\n", contador_soluciones);


}
