
/* Lab. Prog II 2022/1 - Prova 4 - Felipe B Druzian & Gabriel Dalmazo */

typedef struct grafo
{
    int vertices;
    int grau_max;
    int **arestas;
    int **pesos;
    int **matriz;
} Grafo;
Grafo *criaGrafo(int v);
void adcAresta(Grafo *g, int x, int y, int p);
void rmvAresta(Grafo *g, int x, int y);
void dijkstra(Grafo *g, int vertices, int origem, int destino);
void prntGrafo(Grafo *g, int v);
