#include <stdio.h>

 const int TAM =100;
 void Imprime (int Primos[], int T);
 void Primo (int , int *);

 void main (void)
 {

 int P[TAM];
 int FLA, J , PRI ;

if (TAM >=1)
{
    P[0] =2;
    J=1;
    PRI = 3;

}
else {
    printf("\nEl tamaño del arreglo dede ser de 1 al menos");
}
if (TAM >=2)
{
    P[1]=3;
    J=2;
    PRI =5;
}


 while (J<TAM)
 {
     FLA =1;
     Primo(PRI,&FLA);
     if (FLA)
     {
     P[J]=PRI;
     J++;

     }
     PRI += 2;
 }
 Imprime(P,TAM);

 }
 void Primo(int A, int *B)
 {
     int DI = 3;
     while (*B &&(DI*DI <= A))
     {
         if ((A%DI)==0)
         {
             *B =0;

         }
         DI+=2;
     }
 }
 void Imprime (int Primos[], int T)
 {
     int I;
     for (I=0;I<T;I++)
     printf("\nPrimos[%d]: %d",I, Primos[I]);

 }

