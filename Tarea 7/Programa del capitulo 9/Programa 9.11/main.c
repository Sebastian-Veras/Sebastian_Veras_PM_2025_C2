#include <stdio.h>
#include <stdlib.h>
// RELLENAR  EL ARCHIVO AD5.DAT ANTES DE CREAR EL PROGRMA//
typedef struct
{
    int clave;
    int departamento;
    float salario;
    float ventas [12];

}empleado;

void incrementa (FILE *);

void main (void)
{

FILE *ar;
if ((ar = fopen ("ad5.dat","r+")) !=NULL)
{
    incrementa(ar);

}
else
    printf("\El archivo no se puede abrir");

    rewind(ar);
    fclose(ar);


}
void incrementa(FILE *ap)
{
    int i,j,t;
    float sum;
    empleado emple;

    t= sizeof(empleado);
    fread(&emple,sizeof(empleado),1,ap);
    while (!feof(ap))
    {
        i = ftell(ap) /t;
        sum = 0;
        for (j=0;j<12;j++)
        {
            sum += emple.ventas[j];
            if (sum> 1000000)
            {
                emple.salario;
                fseek(ap,(i-1)*sizeof(empleado),0);
                fwrite(&emple,sizeof(empleado),1,ap);
                fseek(ap,i*sizeof(empleado),0);
            }
            fread(&emple,sizeof(empleado),1,ap);
        }
    }
}
