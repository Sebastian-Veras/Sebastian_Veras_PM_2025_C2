#include <stdio.h>
#include <ctype.h>
#include <string.h>


void cambia (FILE *, FILE*);
void main (void)
{
    FILE *ar;
    FILE * ap;
    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");
    if ((ap != NULL )&&(ap !=NULL))
    {
        cambia(ar,ap);
        fclose(ar);
        fclose(ap);

    }
    else printf("No se pueden abrir los archivos");


}
void cambia (FILE *ap1, FILE *ap2)
{
    int i,j,k;
    char cad[30],*cad1 = NULL, *cad2 =NULL ,aux[30];

 while (!feof(ap1))
 {
     if(fgets(cad,30,ap1)==NULL &&feof(ap1))
     {
         break;
     }
     cad1 =cad;
     cad2 = strstr(cad1,"mexico");
     while (cad2 !=NULL)
     {
         cad2[0]='M';
         char *ptr =cad;
         while ((ptr = strstr(ptr,"méxico"))!=NULL)
         {
             ptr[0]= 'M';
             ptr += strlen("México");
         }

     }
      fputs(cad,ap2);
     }
 }




