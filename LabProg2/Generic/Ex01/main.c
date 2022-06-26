/* Lab. Prog II 2022/1 - Prova 1 - Felipe B Druzian & Gabriel Dalmazo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADgen.h"

typedef struct aluno
{
    int matricula;
    char nome[50];
}Aluno;

Aluno *phead = NULL;

ListaGen* insere_aluno(ListaGen* head, int x, char y[50])
{
    Aluno *p = malloc(sizeof(Aluno));
    p->matricula = x;
    strcpy(p->nome, y);
    return lgen_insere(head,p);
}

void imprime(void* info)
{
    Aluno *p = info;
    printf("Matricula: %i\n", p->matricula);
    printf("Nome: ");
    puts(p->nome);
    printf("\n");
}

void busca(void* dado, void* dado2)
{
    Aluno *p = (Aluno*)dado;
    Aluno *p2 = (Aluno*)dado2;
    if (p->matricula == p2->matricula)
    {
        printf("Matricula: %i\n", p->matricula);
        printf("Aluno: %s\n", p->nome);
    }
}

void vazia(void *info)
{
    if (info == NULL)
    {
        printf("A lista esta VAZIA!!\n");
    }
    if (info != NULL)
    {
        printf("A lista NAO esta VAZIA!!\n");
    }
}
int remover(void* q, void* dado, void* dado2)
{
    Aluno *p = (Aluno*)dado;
    Aluno *p2 = (Aluno*)dado2;
    if (p->matricula == p2->matricula)
    {
        printf("Matricula: %i\n", p->matricula);
        printf("Aluno: %s\n", p->nome);
        return 1;
    }else
    {
        printf("Aluno nao encontrado!\n");
        return 0;
    }
}

int main()
{
    int opc, key=0, d;
    char d2[50];

    while (opc != 6)
    {
        printf("-----// MENU //-----\n");
        printf("1- Inserir aluno\n");
        printf("2- Buscar aluno por matricula\n");
        printf("3- Imprimir alunos\n");
        printf("4- Remover por matricula\n");
        printf("5- Verifica lista vazia\n");
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

                printf("Digite um numero de matricula: ");
                scanf("%i", &d);
                fflush(stdin);
                printf("Digite um nome: ");
                gets(d2);
                phead = insere_aluno(phead, d, d2);

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

                printf("Digite um numero de matricula: ");
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
            while (key != 10)
            {
                system("cls");

                printf("Digite um numero: ");
                scanf("%i", &d);
                
                lgen_remove(phead, remover, &d);

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

                lgen_vazia(phead, vazia);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 6:
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
