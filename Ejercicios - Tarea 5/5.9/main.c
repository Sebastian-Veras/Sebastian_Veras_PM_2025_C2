 #include <stdio.h>
 /* Búsqueda secuencial en arreglos desordenados. */
 const  int  MAX=100;
 void Lectura(int*, int);
 int  Busca(int *, int, int);

 void main(void)
 {
 int RES, ELE, TAM, VEC[MAX];
 do
 {
 printf("Ingrese el tamaño del arreglo: ");
 scanf("%d", &TAM);
 }
 while  (TAM>MAX||TAM<1);   /* Se verifica que el tamaño del arreglo sea
 ➥correcto. */
 Lectura(VEC, TAM);
 printf("\nIngrese el elemento a buscar: ");
 scanf("%d", &ELE);
 RES = Busca(VEC, TAM, ELE);   /* Se llama a la función que busca en el
 ➥arreglo. */
 if (RES)
 /* Si RREESS tiene un valor verdadero —diferente de 0—, se escribe la posición
 ➥en la que se encontró el elemento. */
 printf("\nEl elemento se encuentra en la posición %d", RES);
 else
 printf("\nEl elemento no se encuentra en el arreglo");
 }
  void Lectura(int  A[], int T)
 /* La función LLeeccttuurraa se utiliza para leer un arreglo unidimensional de TT
 ➥elementos de tipo entero. */
 {
 int I;
 for (I=0; I<T; I++)
 {
 printf("Ingrese el elemento %d: ", I+1);
 scanf("%d", &A[I]);
 }
 }
 int Busca(int A[], int T, int K)
 /* Esta función localiza en el arreglo un elemento determinado. Si el elemento
 ➥es encontrado, regresa la posición correspondiente. En caso contrario, regresa
 ➥0. */
 {
 int I = 0, BAN = 0, RES;
 while  (I < T && !BAN)
  if  (A[I] == K)
   BAN++;
  else
   I++;
  if (BAN)
   RES = I + 1;
/* Se asigna II++11 dado que las posiciones en el arreglo comienzan desde
 ➥cero. */
   else
    RES = BAN;
 return (RES);
 }

