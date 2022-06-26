/* Lab. Prog II 2022/1 - Prova 2 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2


struct grafo
{
    int vertices;   // número de vértices
    int **matriz; // matriz de adjacência
};
typedef struct grafo Grafo;

struct resultado
{
    int *cor;
    int *predecessor;
    int *distancia;
};
typedef struct resultado Resultado;

struct fila
{
    int xesq;
    struct fila *next;
};
typedef struct fila Fila;

struct visitado
{
    int dele;
    struct visitado *next;
};
typedef struct visitado Visitado;

void BFS(Grafo *g, int a, Fila *Fhead, Visitado *Vhead)
{
    Vhead = criaVisit(Vhead, a);
    for (int i = 0; i < g->vertices; i++)
    {
        if (g->matriz[a][i] == 1)
        {
            Fhead = Fpercorre(Fhead, i);
        }
    }
    BFS(g, Fhead->xesq, Fhead, Vhead);
}

Fila *Fpercorre(Fila *head, int a)
{   
    Fila *aux = head;
    while (aux != NULL && a == aux->xesq)
    {
        aux = aux->next;
    }
    if (aux->xesq == a)
    {
        return head;
    }
    
    Fila *node = malloc(sizeof(Fila));
    node->xesq = a;
    node->next = NULL;
    if (head == NULL)
    {
        return node;
    }

    while (aux->next != NULL)
    {
        aux->next = node;
    }
    
    return head;
}

Visitado* criaVisit(Visitado *head, int x)
{
    if (head == NULL)
    {
        head = malloc(sizeof(Visitado));
        head->dele = x;
        head->next = NULL;
        return head;
    }
    else
    {
        Visitado *node = malloc(sizeof(Visitado));
        node->dele = x;
        node->next = head;
        return node;
    }
}

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
    g->matriz[y][x] = 1;
    return g;
}

Grafo *rmvAresta(Grafo *g, int x, int y)
{
    g->matriz[x][y] = 0;
    g->matriz[y][x] = 0;
    return g;
}

Grafo *clnGrafo(Grafo *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        free(g->matriz[i]);
    }
    free(g);
    g = NULL;
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


