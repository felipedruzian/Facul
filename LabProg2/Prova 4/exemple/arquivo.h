#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i,j;

typedef struct grafo{
  int vertices;
  int grau_max;
  int **arestas;
  int **pesos;
  int **matriz;
}Grafo;

Grafo* CriaGrafo(int num_de_vertices, int grau_max);
int MenorDistancia(float *distancia, int* visitado, int num_vertices);
void InserirAresta(Grafo *grafo, int v1, int v2, int p1);
void MenorCaminho(Grafo *g, int vertices, int origem, int destino);
void ImprimeGrafo(Grafo *g, int vertices);