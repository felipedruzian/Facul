/* Lab. Prog II 2022/1 - Prova 3 - Felipe B Druzian & Gabriel Dalmazo */

typedef struct grafo Grafo;
typedef struct dfs Depth;
typedef struct pilha Pilha;
Grafo *criaGrafo(int v);
Grafo *adcAresta(Grafo *g, int x, int y);
Grafo *rmvAresta(Grafo *g, int x, int y);
void prntGrafo(Grafo *g);
Grafo *clnGrafo(Grafo *g);
Pilha *criaPilha();
Pilha *inserePilha(Pilha *p, int n);
void topoPrint(Pilha *p);
void esvaziaPilha(Pilha *p);
Depth *criaDFS(int n);
void DFS(Grafo *G, Depth *r, Pilha *p);
void DFSvisit(Grafo *G, int origem, Depth *r, Pilha *p);
void DFSresult(int vertices, Depth *r, Pilha *p);
