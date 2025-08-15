#include <stdio.h>
#include <stdlib.h>

/* Temperaturas.
El programa recibe como datos 24 números reales que representan las
temperaturas en el exterior en un período de 24 horas. Calcula el
promedio del día y las temperaturas máxima y mínima con la hora en la
que se registraron.
*/

void Acutem(float);
void Maxima(float, int);
void Minima(float, int);

// Variables globales
float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

void main(void)
{
    float TEM;
    int I;

    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);
    }

    printf("\nPromedio del dia: %.2f", ACT / 24.0);
    printf("\nTemperatura maxima: %.2f a las %d horas", MAX, HMAX);
    printf("\nTemperatura minima: %.2f a las %d horas", MIN, HMIN);




}

void Acutem(float T)
{
    ACT += T;
}

void Maxima(float T, int H)
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;
    }
}

void Minima(float T, int H)
{
    if (MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
