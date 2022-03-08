#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ficha
{
    char nome[21];
    int idade;
    struct ficha *prox;
};

typedef struct ficha _ficha;

_ficha *topo = NULL;

void preenche(_ficha **top)
{
    _ficha *ptr = malloc(sizeof(_ficha));
    if (ptr != NULL)
    {
        fflush(stdin);
        printf("Nome: ");
        gets(ptr->nome);
        fflush(stdin);
        printf("Idade: ");
        scanf("%d", &ptr->idade);
        ptr->prox = NULL;
        *top = ptr;
    }
    else
    {
        printf("\nMalloc Error!\n");
        return;
    }
}

void incluir(_ficha **top)
{
    _ficha *outro;
    preenche(&outro);
    outro->prox = *top;
    *top = outro;
}

void mostrar(_ficha *topo)
{
    if (topo == NULL)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        printf("Ultimo adicionado:\n");
        printf("Nome: %s\n", topo->nome);
        printf("Idade: %d\n", topo->idade);
    }
}

void mostrarFull(_ficha *topo)
{
    if (topo == NULL)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        printf("Pilha completa:\n");
        _ficha *outro = topo;
        while (outro != NULL)
        {
            printf("\nNome: %s\n", outro->nome);
            printf("Idade: %d\n", outro->idade);
            outro = outro->prox;
        }
        free(outro);
    }
}

void excluir(_ficha **top)
{
    _ficha *topo = *top;
    if (topo == NULL)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        _ficha *outro = topo;
        topo = topo->prox;
        *top = topo;
        free(outro);
    }
}

void sair(_ficha **top)
{
    _ficha *topo = *top;
    if (topo != NULL)
    {
        _ficha *outro = topo;
        while (topo != NULL)
        {
            topo = topo->prox;
            *top = topo;
            free(outro);
            outro = topo;
        }
    }
}