#include <stdio.h>


void main (void)
{
    int X = 5, Y =8, V[5] ={1,2,5,7,9};
    int *AY , *AX;
    AY = &Y;
    X = *AY;
    *AY = V[3]+V[2];
    printf("\nX = %d  \t Y=%d \t V[0] =%d \t V[1]=%d \tV[2]=%d \tV[3]=%d \t V[4]=%d",X,Y,V[0],V[1],V[2],V[3],V[4]);

    AX = &V[V[0]*V[1]];
    X = *AX;
    Y= *AX *V[1];
    *AX = *AY - 3;
    printf("\nX=%d  \t  Y=%d \t V[0] =%d \t V[1] = %d \t V[2] =%d \t V[3]=%d \tV[4] =%d",X,Y,V[0],V[1],V[2],V[3],V[4]);




}
