#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*al recibir como dato una X cualquiera,calcule el sen(x)utilizando la siguiente serie:
 La diferencia entre la serie y un nuevo término debe ser menor o igual a 0.001.
 Imprima el número de términos requerido para obtener esta precisión.*/
void main(void)
{
     int X, n = 0;
    double x, termino, seno = 0.0;

    printf("Ingrese el valor de X (en grados): ");
    scanf("%d", &X);


    x = X * M_PI / 180.0;


    termino = x;

    while (fabs(termino) > 0.001) {
        seno += termino;

        n++;


        int exp = 2 * n + 1;
        double num = pow(x, exp);


        int f = 1;
        for (int i = 1; i <= exp; i++) {
            f *= i;
        }


        termino = pow(-1, n) * num / f;
    }

    printf("\nsen(%d) = %.6f\n", X, seno);


}
