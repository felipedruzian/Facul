/* Lab. Prog II 2022/1 - Prova 3 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

int main()
{
    int opc, key=0, v;

    Grafo *g = NULL;
    Pilha *phead = criaPilha();
    Depth *r = NULL;

    while (opc != 6)
    {
        printf("-----// MENU //-----\n");
        printf("1- Criar Grafo\n");
        printf("2- Inserir Aresta\n");
        printf("3- Remover Aresta\n");
        printf("4- Printar Grafo\n");
        printf("5- DFS \n");
        printf("6- Topologia \n");
        printf("8- Sair \n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            while (key != 10)
            {
                system("cls");

                printf("Digite um numero de vertices: ");
                scanf("%i", &v);
                
                g = criaGrafo(v);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;
        
        case 2:
            while (key != 10)
            {
                system("cls");

                int x, y;
                printf("Digite vertices para conectar: ");
                scanf("%i %i", &x, &y);
                
                g = adcAresta(g, x-1, y-1);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 3:
            while (key != 10)
            {
                system("cls");

                int x, y;
                printf("Digite vertices para remover: ");
                scanf("%i %i", &x, &y);

                g=rmvAresta(g, x-1, y-1);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 4:
            while (key != 10)
            {
                system("cls");

                prntGrafo(g);                
                
                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 5:
            while (key != 10)
            {
                system("cls");

                r = criaDFS(v);             
                DFS(g,r,phead);
                DFSresult(v,r,phead);


                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 6:
            while (key != 10)
            {
                system("cls");

                topoPrint(phead);
                

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 7:
            break;

        case 8:
            while (key != 10)
            {
                system("cls");

                g = clnGrafo(g);
                esvaziaPilha(phead);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}