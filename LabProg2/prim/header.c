#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;

// grafo usando lista de adjacencia

struct grafo
{
    int ponderado; // 0 nao - 1 sim
    int vertices;
    int grauMax; // max de arestas por vertices
    int **arestas;
    int **pesos;
    int *grau; // quantas arestas um vertice tem
};

Grafo *criaGrafo(int vertices, int grauMax, int ponderado)
{
    Grafo *G = (Grafo *)malloc(sizeof(Grafo));
    if (G != NULL)
    {
        G->vertices = vertices;
        G->grauMax = grauMax;
        G->ponderado = ponderado;

        G->grau = (int *)calloc(vertices, sizeof(int)); // Aloca zerado
        G->arestas = (int **)malloc(vertices * sizeof(int *));

        // pra cada vertice aloca o max de arestas
        for (int i = 0; i < vertices; i++)
            G->arestas[i] = (int *)malloc(grauMax * sizeof(int));

        // se for ponderado aloca o peso
        if (G->ponderado == 1)
        {
            G->pesos = (int **)malloc(vertices * sizeof(int *));
            for (int i = 0; i < vertices; i++)
                G->pesos[i] = (int *)malloc(grauMax * sizeof(int));
        }
        return G;
    }
}

void liberaGrafo (Grafo *G)
{
    for(int t = 0; t < G->vertices; t++)
    {
        free(G->arestas[t]);
        if (G->ponderado == 1)
            free(G->pesos[t]);
    }
    free(G->arestas);
    free(G->pesos);
    free(G);
}

int insereAresta (Grafo *G, int origem, int destino, int digrafo, int peso)
{
    if (G == NULL)
    {
        return 0;
    }
    //verifica se a origem e o destino são validos e tambem se eles não sao maiores que o numero de vertices
    if (origem < 0 || origem >= G->vertices || destino >= G->vertices || destino < 0)
    {
        return 0;
    }

    //acrescenta o destino no grau maximo do vertice origem
    G->arestas[origem][G->grau[origem]] = destino;
    if(G->ponderado == 1)
    {
        G->pesos[origem][G->grau[origem]] = peso;
    }
    //soma mais um no grau
    G->grau[origem]++;

    if(digrafo == 0)
    {
        insereAresta(G, destino, origem, 1, peso);
    }
    return 1;
}

int removeAresta (Grafo *G, int origem, int destino, int digrafo)
{
    if (G == NULL)
    {
        return 0;
    }
    //verifica se a origem e o destino são validos e tambem se eles não sao maiores que o numero de vertices
    if (origem < 0 || origem >= G->vertices || destino >= G->vertices || destino < 0)
    {
        return 0;
    }
    //procura a aresta no grafo
    int i;
    //procura dentro da quantidade de arestas do vertice
    //e se existe na posição i ele remove
    while(i < G->grau[origem] && G->arestas[origem][i] != destino)
    {
        i++;
    }

    //se não existe a aresta
    if (i == G->grau[origem])
    {
        return 0;
    }

    //se exite a aresta, diminui um grau = aresta
    G->grau[origem]--;
    //passa a ultima aresta pra posição i
    G->arestas[origem][i] = G->arestas[origem][G->grau[origem]];

    if(G->ponderado == 1)
    {
        G->pesos[origem][i] = G->pesos[origem][G->grau[origem]];
    }

    if(digrafo == 0)
    {
        removeAresta(G, destino, origem, 1);
    }
}

void PRIM (Grafo *G, int origem, int *pai)
{
    int i, j, destino, primeiro, menorPeso;
    //começa todos sem pai
    for(i = 0; i < G->vertices; i++)
    {
        pai[i] = -1;
    }

    //inicia o pai do vertice origem como ele mesmo
    pai[origem] = origem;

    while(1)
    {
        primeiro = 1;
        //percorre todos vertices
        for(i=0 ; i<G->vertices ; i++)
        {
            //procura vertice que já foi visitado
            if(pai[i] != -1)
            {
                //percorre os vizinhos do vertice visitado
                for(j = 0; j < G->grau[i]; j++)
                {
                    //procura menor peso
                    if(pai[G->arestas[i][j]] == -1)
                    {
                        if(primeiro)
                        {
                            menorPeso = G->pesos[i][j];
                            origem = i;
                            destino = G->arestas[i][j];
                            primeiro = 0;
                        }
                        else
                        {
                            if(G->pesos[i][j] < menorPeso)
                            {
                                menorPeso = G->pesos[i][j];
                                origem = i;
                                destino = G->arestas[i][j];
                            }
                        }
                    }
                }   
            }
        }

        //se não encontrou ninguém termina
        if (primeiro == 1)
        {
            break;
        }

        //se não o destino passa a ser origem
        pai[destino] = origem;

    }
}