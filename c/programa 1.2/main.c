#include <stdio.h>
#include <stdlib.h>

int main()
{
int A = 0;
int B = 0;
int C = 0;
int D = 0;


printf("Ingrese el valor de A:\n");
scanf("%d",&A);

printf("Ingrese el valor de B:\n");
scanf("%d",&B);

printf("Ingrese el valor de C:\n");
scanf("%d", &C);

printf("Ingrese el valor de D:\n");
scanf("%d", &D);



printf("Estos son los valores de forma contraria de orden:");
printf("%d %d %d %d\n", D, C, B, A);

return 0;
}
