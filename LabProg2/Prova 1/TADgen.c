/* Lab. Prog II 2022/1 - Prova 1 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void lgen_vazia(ListaGen *head, void (*cb)(void*))
{
    cb(head);
}

void lgen_remove(ListaGen *head, int (*cb)(void*, void*, void*), void *dado)
{
    ListaGen *p;
    for (p=head; p!=NULL; p=p->prox)
    {
        int z = cb(p, p->info, dado);
        if (z != 0)
        {
            ListaGen* q = head;
            while (q->prox != p)
            {
                q=q->prox;
            }
            q->prox = p->prox;
            free(p->info);
            free(p);
            p=NULL;
        }
    }
}