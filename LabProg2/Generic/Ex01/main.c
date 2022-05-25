#include <stdio.h>
#include <stdlib.h>
#include "TADgen.h"

typedef struct ponto
{
    float x;
}Ponto;

float CGx;
int NP;

static ListaGen* insere_ponto(ListaGen* l, float x, float y)
{
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    return lgen_insere(l,p);
}

static void imprime(void* info)
{
    Ponto *p = (Ponto*)info;
    printf("%f\n", p->x);
}

static void centro_geom(void* info)
{
    Ponto *p = (Ponto*)info;
    CGx = CGx + p->x;
    NP++;
}

int main()
{
    lgen_percorre(l, centro_geom);
    CGx /= NP;
    return 0;
}
