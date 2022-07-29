/* Lab. Prog II 2022/1 - Prova 4 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct grafo
{
    int vertices;
    int **arestas;
    int **pesos;
    int **matriz;
} Grafo;

Grafo *criaGrafo(int v)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->vertices = v;
    g->matriz = (int **)malloc(v * sizeof(int *));
    g->pesos = (int **)malloc(v * sizeof(int *));

    for (int i = 0; i < v; i++)
    {
        g->matriz[i] = (int *)malloc(v * sizeof(int));
        g->pesos[i] = (int *)malloc(v * sizeof(int));
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            g->matriz[i][j] = 0;
            g->pesos[i][j] = -1;
        }
    }
    return g;
}

void adcAresta(Grafo *g, int x, int y, int p)
{
    g->matriz[x][y] = 1;
    g->pesos[x][y] = p;
}

void rmvAresta(Grafo *g, int x, int y)
{
    g->matriz[x][y] = 0;
    g->pesos[x][y] = -1;
}

void dijkstra(Grafo *g, int vertices, int origem, int destino)
{
    int i, v, ant[g->vertices], visit[g->vertices];
    double min, dist[g->vertices];

    for (i = 0; i < vertices; i++)
    {
        if (g->pesos[origem][i] != -1)
        {
            ant[i] = origem - 1;
            dist[i] = g->pesos[origem][i];
        }
        else
        {
            ant[i] = -1;
            dist[i] = HUGE_VAL;
        }
        visit[i] = 0;
    }
    visit[origem] = 1;
    dist[origem] = 0;

    /* Calcula a menor distancia entre o vertice atual e seus vizinhos */
    do
    {

        min = HUGE_VAL;
        for (i = 0; i < vertices; i++)
        {
            if (!visit[i])
            {
                if (dist[i] >= 0 && dist[i] < min)
                {
                    min = dist[i];
                    v = i;
                }
            }
        }

        if (min != HUGE_VAL && v != destino)
        {
            visit[v] = 1;
            for (i = 0; i < vertices; i++)
            {
                if (!visit[i])
                {
                    if (g->pesos[v][i] != -1 && dist[v] + g->pesos[v][i] < dist[i])
                    {
                        dist[i] = dist[v] + g->pesos[v][i];
                        ant[i] = v;
                    }
                }
            }
        }
    } while (v != destino && min != HUGE_VAL);

    /* Imprime o menor caminho obtido anteriormente e seu peso. */
    if (min == HUGE_VAL)
        printf("\nNao existe caminho do %d ate o %d !!\n", origem, destino);
    else
    {
        printf("\nO menor caminho de %d ate %d  (ordem reversa):\n", origem, destino);
        i = destino;
        printf("%d", i);
        i = ant[i];
        while (i != -1)
        {
            printf("<-%d", i);
            i = ant[i];
        }
        printf("<-%d", origem);
        printf("\nO peso deste caminho : %d\n", (int)dist[destino]);
    }
}

void prntGrafo(Grafo *g, int v)
{
    printf("\t vertices \t\t//\t\t pesos\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            printf("%d\t", g->matriz[i][j]);
        }
        printf("\t");
        for (int k = 0; k < g->vertices; k++)
        {
            printf("%d\t", g->pesos[i][k]);
        }
        printf("\n");
    }
}
