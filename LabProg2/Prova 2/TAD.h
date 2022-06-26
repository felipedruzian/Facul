/* Lab. Prog II 2022/1 - Prova 2 - Felipe B Druzian & Gabriel Dalmazo */

typedef struct grafo Grafo;
typedef struct resultado Resultado;
typedef struct fila Fila;
typedef struct visitado Visitado;
void BFS(Grafo *g, int a, Fila *Fhead, Visitado *Vhead);
Fila *Fpercorre(Fila *head, int a);
Visitado* criaVisit(Visitado *head, int x);
Grafo *criaGrafo(int v);
Grafo *adcAresta(Grafo *g, int x, int y);
Grafo *rmvAresta(Grafo *g, int x, int y);
Grafo *clnGrafo(Grafo *g);
void prntGrafo(Grafo *g);
