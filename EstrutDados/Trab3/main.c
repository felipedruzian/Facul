// Trabalho 03 - Árvores Binárias de Pesquisa
/* Felipe Barreto Druzian - felipedruzian.aluno@unipampa.edu.br */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int opc = 0, tecla = 0;
    int num;
    while (opc != 4)
    {
        system("cls");
        printf("1. Inserir\n");
        printf("2. Printar\n");
        printf("3. Buscar\n");
        printf("4. Sair\n");
        scanf("%d", &opc);
        fflush(stdin);
        switch (opc)
        {
        case 1:
            while (tecla != 10)
            {
                system("cls");
                printf("Digite um numero para adicionar na arvore: ");
                scanf("%d", &num);
                raiz = Insert(raiz, num);

                fflush(stdin);
                printf("\nEnter para voltar... ");
                tecla = getchar();
            }
            tecla = 0;
            break;
        
        case 2:
            while (tecla != 10)
            {
                system("cls");

                printTree(raiz, 0);

                fflush(stdin);
                printf("\nEnter para voltar... ");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 3:
            while (tecla != 10)
            {
                printf("Digite um numero a buscar: ");
                scanf("%d", &num);

                findNode(raiz, num, raiz);

                fflush(stdin);
                printf("\nEnter para voltar... ");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 4:
            freeTree(raiz);
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    
    return 0;
}
