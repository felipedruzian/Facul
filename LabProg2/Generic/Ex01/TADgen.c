#include <stdio.h>
#include <stdlib.h>

typedef struct listaGen
{
    void* info;
    struct listaGen* prox;
}ListaGen;

ListaGen* lgen_insere (ListaGen* head, void* data)
{
    ListaGen* n = (ListaGen*) malloc(sizeof(ListaGen));
    n->info = data;
    n->prox = head;
    return n;
}

void lgen_percorre(ListaGen *head, void (*cb)(void*))
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)
    {
        cb(p->info);
    }
}

void lgen_busca(ListaGen *head, void (*cb)(void*, void*), void *dado)
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)
    {
        cb(p->info, dado);
    }
}

ListaGen* lgen_free(ListaGen *head)
{
    ListaGen *aux;
    while (head != NULL)
    {
        aux = head;
        head = head->prox;
        free(aux->info);
        free(aux);
    }
    return head;
}