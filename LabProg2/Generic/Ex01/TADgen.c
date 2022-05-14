#include <stdio.h>
#include <stdlib.h>

typedef struct listaGen
{
    void* info;
    struct listaGen* prox;
}ListaGen;

ListaGen* lgen_insere (ListaGen* l, void* p)
{
    ListaGen* n = (ListaGen*) malloc(sizeof(ListaGen));
    n->info = p;
    n->prox = l;
    return n;
}

void lgen_percorre(ListaGen *l, void (*cb)(void*))
{
    ListaGen *p;
    for (p=l; p!=NULL; p=p->prox)
    {
        cb(p->info);
    }
}