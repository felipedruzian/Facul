/*
Gabriel dos Santos Fredes - 2110102628
gabrielfredes.aluno@unipampa.edu.br

Dados usados no teste do programa:

Vértices: 6
Grau máximo de arestas: 6

Aresta / Peso
0 - 1 / 6
0 - 2 / 1
0 - 3 / 5
1 - 2 / 2
1 - 4 / 5
2 - 3 / 2
2 - 4 / 6
2 - 5 / 4
3 - 5 / 4
4 - 5 / 3
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int vertices, origem, destino, peso, op, grauMax, se;
    int digrafo = 0; // não direcionado

    printf("Quantos vértices? ");
    scanf("%d", &vertices);
    printf("Grau máximo de arestas? ");
    scanf("%d", &grauMax);

    Grafo *G = criaGrafo(vertices, grauMax, 1); // ponderado
    if (G == NULL)
    {
        printf("\nErro ao criar o grafo!\n");
        return 0;
    }

    do
    {
        printf("\n1 - Inserir aresta");
        printf("\n2 - Remover aresta");
        printf("\n3 - Imprimir grafo");
        printf("\n4 - Algoritimo de PRIM");
        printf("\n5 - Sair");

        printf("\n\nOpção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nOrigem: ");
            scanf("%d", &origem);
            printf("Destino: ");
            scanf("%d", &destino);
            printf("Peso: ");
            scanf("%d", &peso);

            se = insereAresta(G, origem, destino, digrafo, peso);
            if (se == 1)
                printf("\nAresta inserida com sucesso!\n");
            else
                printf("\nErro ao inserir aresta!\n");
            break;
        case 2:
            printf("\nOrigem: ");
            scanf("%d", &origem);
            printf("Destino: ");
            scanf("%d", &destino);

            se = removeAresta(G, origem, destino, digrafo);
            if (se == 1)
                printf("\nAresta removida com sucesso!\n");
            else
                printf("\nErro ao remover aresta!\n");
            break;
        case 4:
            printf("\nOrigem: ");
            scanf("%d", &origem);
            printf("\nResultado: \n");

            int *pai = (int *)malloc(vertices * sizeof(int));
            PRIM(G, origem, pai);

            for (int i = 0; i < vertices; i++)
            {
                printf("Vértice %d - Pai: %d\n", i, pai[i]);
            }
            break;
        case 5:
            printf("\nSaindo...\n");
            liberaGrafo(G);
            free(pai);

            system("pause");
            return 0;
            break;
        default:
            break;
        }
    } while (op != 5);
    system("pause");
    return 0;
}