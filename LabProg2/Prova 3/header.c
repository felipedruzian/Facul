#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

// global
int tempo = 0;

typedef struct grafo *Grafo;
typedef struct resultado Resultado;
typedef struct Elemento Elemento;
typedef struct pilha Pilha;

struct grafo
{
    int **Matriz;
    int vertices; // n
};
struct resultado
{
    int *cor;
    int *predecessor;
    int *descobre; // tempo de descoberta
    int *tempoF;      // tempo de t�rmino de adjacentes de v
};
struct Elemento
{
    int valor;
    struct Elemento *prox;
};
///*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct pilha
{
    struct Elemento *topo ///*aponta para o elemento qu esta Elemento topo da pilha*/
};

// inicia o grafo em 0
Grafo iniciarGrafo(int n)
{
    int i, j;
    Grafo Gr = malloc(sizeof(Gr));

    Gr->vertices = n;
    Gr->Matriz = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        Gr->Matriz[i] = malloc(n * sizeof(int *));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Gr->Matriz[i][j] = 0;
        }
    }
    return Gr;
}

// insere o arco v-w no grafo. se j� existe n�o faz nada
void inserirArco(Grafo G, int v, int w)
{
    if (G->Matriz[v][w] == 0)
    {
        printf("\nAresta inserida!");
        G->Matriz[v][w] = 1;
    }
    else
    {
        printf("\nEssa aresta j� existe\n");
    }
}

// se existe remove
void removeArco(Grafo G, int v, int w)
{
    if (G->Matriz[v][w] == 1)
    {
        G->Matriz[v][w] = 0;
        printf("\nAresta removida!\n");
    }
    else
    {
        printf("\nA aresta n�o existe\n");
    }
}

void imprimeMatriz(Grafo G)
{
    int i, j;
    for (i = 0; i < G->vertices; i++) // imprime cada vertice
    {
        for (j = 0; j < G->vertices; j++)
        {
            printf("%i\t", G->Matriz[i][j]);
        }
        printf("\n");
    }
}

Grafo freeGrafo(Grafo G)
{
    int i;
    for (i = 0; i < G->vertices; i++)
    {
        free(G->Matriz[i]);
        G->Matriz[i] == NULL;
    }
    free(G->Matriz);
    G->Matriz = NULL;
    free(G);

    return NULL;
}

// aqui come�a a parte de bfs

Pilha *criaPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->topo = NULL;
    }
    return p;
}

void inserePilha(Pilha *p, int n)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    novo->valor = n;
    novo->prox = p->topo;

    /*como o n�mero inserido ser� o novo topo, ele apontar� para o topo atual que ser� o segundo elemento da pilha*/
    novo->prox = p->topo;
    /*topo aponta para o endere�o de novo*/
    p->topo = novo;
}

void invertePilha(Pilha *p)
{
    Pilha *p2 = criaPilha(); // cria uma segunda pilha
    Elemento *aux;
    while (p->topo != NULL) // enquanto o topo da primeira tiver valores
    {
        aux = p->topo;               // guarda o topo da primeira pilha
        p->topo = p->topo->prox;     // o topo da primeira pilha aponta para o proximo elemento
        inserePilha(p2, aux->valor); // insere na pilha nova o valor do topo da primeira pilha
        free(aux);
    }
    p->topo = p2->topo; // o topo da primeira pilha aponta para o topo da segunda pilha
    p2->topo = NULL;    // o topo da segunda pilha aponta para NULL
    free(p2);
}

void topologia(Pilha *p)
{
    Elemento *aux = p->topo;
    while (aux != NULL)
    {
        printf("%i -> ", aux->valor);
        aux = aux->prox;
    }
}

void esvaziaPilha(Pilha *p)
{
    //reinicia o tempo quando se inicia uma nova ordem
    tempo = 0;

    Elemento *aux;
    while (p->topo != NULL)
    {
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

Resultado *criaResultado(int n)
{
    Resultado *r = (Resultado *)malloc(sizeof(Resultado));
    if (r != NULL)
    {
        r->cor = malloc(n * sizeof(int));
        r->predecessor = malloc(n * sizeof(int));
        r->descobre = malloc(n * sizeof(int));
        r->tempoF = malloc(n * sizeof(int));
    }

    // inicia todos em branco, predecessor nulo, tempo de descoberta e fim nulo
    for (int i = 0; i < n; i++)
    {
        r->cor[i] = BRANCO;
        r->predecessor[i] = -1;
        r->descobre[i] = 0;
        r->tempoF[i] = 0;
    }

    return r;
}

void DFS(Grafo G, Resultado *r, Pilha *p)
{
    // se o vertice nao foi descoberto ainda, chama fun��o pra fazer a busca
    for (int i = 0; i < G->vertices; i++)
    {
        if (r->cor[i] == BRANCO)
        {
            DFS_visit(G, i, r, p); // grafo, vertice a ser visitado, resultado
        }
    }
}

void DFS_visit(Grafo G, int origem, Resultado *r, Pilha *p)
{
    tempo += 1;
    r->descobre[origem] = tempo; // origem � o vertice que foi informado, e o tempo � o tempo de descoberta
    r->cor[origem] = CINZA;

    for (int v = 0; v < G->vertices; v++) // v = linhas
    {
        if (G->Matriz[origem][v] == 1 && r->cor[v] == BRANCO)
        {
            r->predecessor[v] = origem;
            DFS_visit(G, v, r, p); // muda a origem para o vertice adjacente, e chama a fun��o novamente
        }
    }

    r->cor[origem] = PRETO;
    tempo += 1;
    r->tempoF[origem] = tempo;

    // insere no inicio da fila topologica o que foi terminado
    inserePilha(p, origem);
}

void resultado(int vertices, Resultado *r, Pilha *p)
{
    char corNome[10][vertices];

    printf("\n\nV�rtice   Cor     Predecessor      Descoberta      Tempo Final\n");
    for (int i = 0; i < vertices; i++)
    {
        if (r->cor[i] == 0)
        {
            strcpy(corNome[i], "BRANCO");
        }
        else if (r->cor[i] == 1)
        {
            strcpy(corNome[i], "CINZA");
        }
        else if (r->cor[i] == 2)
        {
            strcpy(corNome[i], "PRETO");
        }

        printf("%i %13s %8d %15d %16d\n", i, corNome[i], r->predecessor[i], r->descobre[i], r->tempoF[i]);
    }
}