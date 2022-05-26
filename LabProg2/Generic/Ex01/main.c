#include <stdio.h>
#include <stdlib.h>
#include "TADgen.h"

typedef struct ponto
{
    int x;
    float y
}Ponto;

Ponto *phead = NULL;

static ListaGen* insere_ponto(ListaGen* head, int x, float y)
{
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return lgen_insere(head,p);
}

static void imprime(void* info)
{
    Ponto *p = (Ponto*)info;
    printf("%i\n", p->x);
}

void busca(void* dado, void* dado2)
{
    Ponto *p = (Ponto*)dado;
    Ponto *p2 = (Ponto*)dado2;
    if (p->x == p2->x)
    {
        printf("%i\n", p->x);
        printf("%f\n", p->y);
    }
}




int main()
{
    int opc, key=0, d;
    float d2;

    while (opc != 6)
    {
        printf("-----// MENU //-----\n");
        printf("1- Inserir dado\n");
        printf("2- Buscar dado\n");
        printf("3- Imprimir dados\n");
        printf("4- Remover por dado\n");
        printf("5- Verifica Lista vazia\n");
        printf("6- Sair \n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            while (key != 10)
            {
                system("cls");

                printf("Digite um numero: ");
                scanf("%i", &d);
                printf("Digite outro numero: ");
                scanf("%f", &d2);
                phead = insere_ponto(phead, d, d2);

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

                printf("Digite um numero: ");
                scanf("%i", &d);
                
                lgen_busca(phead, busca, &d);

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

                lgen_percorre(phead, imprime);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 4:
            
            break;

        case 5:
            
            break;

        case 6:
            
            break;
        
        case 7:
            system("cls");
            phead = lgen_free(phead);
            system("cls");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}
