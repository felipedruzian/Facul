/* Lab. Prog II 2022/1 - Prova 3 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>

int tempo = 0;

struct grafo
{
    int vertices;
    int **matriz;
};
typedef struct grafo Grafo;

struct dfs
{
    int *cor;
    int *predecessor;
    int *tempoD; // tempo de descoberta
    int *tempoF; // tempo final
};
typedef struct dfs Depth;

struct pilha
{
    int valor;
    struct pilha *prox
};
typedef struct pilha Pilha;

Grafo *criaGrafo(int v)
{
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = v;
    g->matriz = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++)
    {
        g->matriz[i] = (int*)malloc(sizeof(int) * v);
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            g->matriz[i][j] = 0;
        }
    }
    return g;
}

Grafo *adcAresta(Grafo *g, int x, int y)
{
    g->matriz[x][y] = 1;
    return g;
}

Grafo *rmvAresta(Grafo *g, int x, int y)
{
    g->matriz[x][y] = 0;
    return g;
}

void prntGrafo(Grafo *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            printf("%d\t", g->matriz[i][j]);
        }
        printf("\n");
    }
}

Grafo *clnGrafo(Grafo *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        free(g->matriz[i]);
        g->matriz[i] = NULL;
    }
    free(g->matriz);
    g->matriz = NULL;    
    free(g);
    g = NULL;
    return g;
}

Pilha *criaPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->valor = 0;
    p->prox = NULL;
    return p;
}

Pilha* inserePilha(Pilha *p, int n)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->valor = n;
    novo->prox = p;
    return novo;
}

void topoPrint(Pilha *p)
{
    Pilha *aux = p;
    while (aux != NULL)
    {
        printf("%i -> ", aux->valor);
        aux = aux->prox;
    }
}

void esvaziaPilha(Pilha *p)
{
    tempo = 0;

    Pilha *aux;
    while (p->prox != NULL)
    {
        aux = p->prox;
        p->prox = p->prox->prox;
        free(aux);
    }
}

Depth *criaDFS(int v)
{
    Depth *r = (Depth *)malloc(sizeof(Depth));
    r->cor = malloc(v * sizeof(int));
    r->predecessor = malloc(v * sizeof(int));
    r->tempoD = malloc(v * sizeof(int));
    r->tempoF = malloc(v * sizeof(int));

    for (int i = 0; i < v; i++)
    {
        r->cor[i] = 0;
        r->predecessor[i] = -1;
        r->tempoD[i] = 0;
        r->tempoF[i] = 0;
    }

    return r;
}

void DFS(Grafo *G, Depth *r, Pilha *p)
{
    for (int i = 0; i < G->vertices; i++)
    {
        if (r->cor[i] == 0)
        {
            DFSvisit(G, i, r, p);
        }
    }
}

void DFSvisit(Grafo *G, int origem, Depth *r, Pilha *p)
{
    tempo += 1;
    r->tempoD[origem] = tempo;
    r->cor[origem] = 1;

    for (int v = 0; v < G->vertices; v++)
    {
        if (G->matriz[origem][v] == 1 && r->cor[v] == 0)
        {
            r->predecessor[v] = origem;
            DFSvisit(G, v, r, p);
        }
    }

    r->cor[origem] = 2;
    tempo += 1;
    r->tempoF[origem] = tempo;

    p = inserePilha(p, origem);
}

void DFSresult(int vertices, Depth *r, Pilha *p)
{
    printf("\nVertice\t\tCor\tPredecessor\t\tTempo Descoberta\tTempo Final\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%i\t\t%i\t\t%i\t\t\t%i\t/\t%i\n", i, r->cor[i], r->predecessor[i], r->tempoD[i], r->tempoF[i]);
    }
}