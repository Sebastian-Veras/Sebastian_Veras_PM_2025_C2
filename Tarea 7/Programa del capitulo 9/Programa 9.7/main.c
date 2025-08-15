#include <stdio.h>
#include <stdlib.h>
//RELLENAR  EL ARCHIVO ARC9.TXT ANTES DE UTILIZAR EL PROGRAMA//
void promedio (FILE*);

void main (void)
{
 FILE *ar;
 if((ar =fopen("arc9.txt", "r")) !=NULL)
 {
     promedio(ar);
     fclose(ar);

 }
 else
    printf("No se puede abirir el archivo");

}
void promedio (FILE *ar1)
{
    int i,j,n,mat;
    float pro, cal;
    fscanf(ar1, "%d", &n);
    for (i=0;i<n;i++)
    {
        fscanf(ar1,"%f",&cal);
        pro += cal;
    }
    printf("\t %.2f " , pro / 5);
    printf("\n");
}
