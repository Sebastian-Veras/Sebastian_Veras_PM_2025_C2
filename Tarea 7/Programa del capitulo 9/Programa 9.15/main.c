#include <stdio.h>
#include <ctype.h>
// RELLENAR EL ARCHIVO ARC.TXT ANTES DE USAR EL PROGRAMA//
void minmay(FILE *);

void main (void)
{
    FILE *ap;
    if((ap=fopen("arc.txt","r")) !=NULL)
    {
              minmay(ap);
    fclose(ap);
    }
  else
    printf("No se puede abrir el archivo");
}
void minmay(FILE *ap1)
{
    char cad [30];
    int i,mi= 0,ma =0;
    while (!feof(ap1))
    {

    fgets(cad,30,ap1);
    i =0;
    while (cad [i] !='\0')
    {
        if (islower(cad[i]))
            mi++;
        else
            if (isupper(cad[i]))
            ma++;
        i++;
    }
    }
    printf("\n\nNumero  de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}

