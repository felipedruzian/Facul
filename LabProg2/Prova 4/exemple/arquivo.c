#include "arquivo.h"

//Cria o grafo e aloca os espacos em memoria
Grafo* CriaGrafo(int num_de_vertices, int grau_max){
  Grafo *g = (Grafo*)malloc(sizeof(Grafo));
  g->grau_max = grau_max;
  g->vertices = num_de_vertices;
  g->matriz = (int**)malloc(sizeof(int*)*num_de_vertices);
  g->pesos = (int**)malloc(sizeof(int*)*num_de_vertices);

  for(i = 0; i < num_de_vertices; i++){
    g->matriz[i] = (int*)malloc(sizeof(int)*num_de_vertices);
    g->pesos[i] = (int*)malloc(sizeof(int)*num_de_vertices);
    }
  
  for(i = 0; i < num_de_vertices; i++){
    for(j = 0; j < num_de_vertices; j++){
      g->matriz[i][j] = 0;
      g->pesos[i][j] = -1;

    }
  }
  return g;
}

//Insere arestas individualmente
void InserirAresta(Grafo* grafo, int v1, int v2, int p1){
   grafo->matriz[v1][v2] = 1;
   grafo->pesos[v1][v2] = p1;
}

//Algoritmo de dijkstra
void MenorCaminho(Grafo *g, int vertices, int origem, int destino)
{ 
  int i, v, j, anterior[g->vertices], visitado[g->vertices];
  double min, dist[g->vertices]; 

  for (i=0; i<vertices; i++) {
    if (g->pesos[origem][i] != -1){
      anterior[i] = origem-1; 
      dist[i] = g->pesos[origem][i];
    }
    else {
      anterior[i]=-1;
      dist[i] = HUGE_VAL; 
    }
    visitado[i]=0;
  }
  visitado[origem]=1;
  dist[origem]=0;
  
  //Calcula a menor distancia entre o nÃ³ atual e seus vizinhos
  do {

    min = HUGE_VAL;
    for (i=0; i<vertices; i++){
        if (!visitado[i]){
          if (dist[i] >= 0 && dist[i] < min) 
          {
            min = dist[i];
            v=i;
          }
        }
      }

    if (min != HUGE_VAL && v != destino) {
      visitado[v]=1;
      for (i=0;i<vertices;i++)
      {
        if (!visitado[i]) {
          if (g->pesos[v][i] != -1 && dist[v] + g->pesos[v][i] < dist[i])
            { 
              dist[i] = dist[v] + g->pesos[v][i];
              anterior[i] = v;
            }
        }
      }
    }
  } while (v != destino && min != HUGE_VAL);

  //Imprime o menor caminho obtido anteriormente e seu peso.
  if (min == HUGE_VAL)
    printf("\nNao existe caminho entre os vertices %d e %d !!\n",origem,destino);
  else {
    printf("\nO menor caminho entre os vertices %d e %d  (na ordem reversa):\n", origem,destino);
    i = destino;
    printf("%d",i);
    i = anterior[i];
    while (i != -1) {
      printf("<-%d",i);
      i=anterior[i];
    }
    printf ("<-%d", origem);
    printf("\nO peso deste caminho : %d\n",(int) dist[destino]);
  } 
}

  //Imprime o grafo
  void ImprimeGrafo(Grafo *g, int vertices)
  {
    int i, j;
    for (i=0; i < vertices; i++)
    {
      for (j=0; j < g->vertices; j++)
      {
      	if(g->pesos[i][j]!=-1){
		  
        printf ("Vertice [%d][%d] = %d -> Peso %d\n", i, j, g->matriz[i][j], g->pesos[i][j]);
    	}
    	else{
    		printf ("Vertice [%d][%d] = %d ->(nao tem pesso esse vertice) ou eh Peso -1 \n", i, j, g->matriz[i][j]);
		}
      }
    }
  }
