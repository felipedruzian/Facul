/* Lab. Prog II 2022/1 - Prova 4 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad.h"

Grafo *grafo;

int main()
{
    int opc = 1, vertices, v1, v2, peso, orig, dest;

    while (opc != 9)
    {
        printf("\n-----// MENU //-----\n");
        printf("1 - Criar Grafo\n");
        printf("2 - Inserir Aresta\n");
        printf("3 - Remover Aresta\n");
        printf("4 - Imprimir menor caminho destino fixo\n");
        printf("5 - Imprimir menor caminho de todos os destinos\n");
        printf("6 - Imprimir Grafo\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);
        
        switch (opc)
        {
        case 1:
            printf("\nDigite um numero de vertices: ");
            scanf("%d", &vertices);

            grafo = criaGrafo(vertices);
            printf("\nGrafo criado.\n");
            break;
        
        case 2:
            printf("Digite vertices para conectar: ");
            scanf("%d %d", &v1, &v2);

            printf("Insira o peso da aresta %d -> %d : ", v1, v2);
            scanf("%d", &peso);

            adcAresta(grafo, v1, v2, peso);
            printf("\nAresta Inserida com sucesso!\n");
            break;
        
        case 3:
            printf("Digite vertices para desconectar: ");
            scanf("%i %i", &v1, &v2);

            rmvAresta(grafo, v1, v2);
            printf("\nAresta removida com sucesso!\n");
            break;

        case 4:
            printf("\nInforme o vertice de origem: ");
            scanf("%d", &orig);

            printf("\nInforme o vertice de destino: ");
            scanf("%d", &dest);

            dijkstra(grafo, vertices, orig, dest);
            break;

        case 5:
            printf("\nInforme o vertice de origem: ");
            scanf("%d", &orig);

            for (int i = 0; i < vertices; i++)
            {
                dijkstra(grafo, vertices, orig, i);
            }
            break;

        case 6:
            prntGrafo(grafo, vertices);
            break;
        
        default:
            printf("Opcao invalida!");
            break;
        }
    }
    printf("\nPrograma Encerrado!!!");

    return 0;
}