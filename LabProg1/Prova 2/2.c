#include <stdio.h>
#include <stdlib.h>
#include "2mat.h"

int main()
{
    float a, b, c;
    printf("Digite um numero (x) para ser elevado a (z):\n");
    printf("x: ");
    scanf("%f", &a);
    printf("z: ");
    scanf("%f", &b);
    c = potencia(a, b);
    printf("\nResultado de x^z (%.0f ^ %.0f): %.1f", a, b, c);
    return 0;
}
