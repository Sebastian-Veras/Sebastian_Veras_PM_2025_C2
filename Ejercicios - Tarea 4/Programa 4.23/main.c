#include <stdio.h>
#include <stdlib.h>
void main (void)
{
 void trueque(int *x, int *y)
 {
 int tem;
 tem = *x;
 *x = *y;
 *y = tem;
 }
 int suma(int x)
 {
 return (x + x);
 }
}
