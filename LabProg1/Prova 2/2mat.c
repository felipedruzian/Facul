#include <stdio.h>
#include <stdlib.h>

float potencia(float x, float z)
{
    float y=1;
    for (int i = 0; i < z; i++)
    {
        y=y*x;
    }
    return y;
}