#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro
{
    char Nome[15];
    int Matricula;
    int Codigo;
}vet[10];

void verificaCodigo (int code)
{
    printf("Alunos do curso %i:\n", code);
    for (int i = 0; i < 10; i++)
    {
        if (code == vet[i].Codigo)
        {
            printf("%i. %s\n", i+1, vet[i].Nome);
        }
    }
}

int verificaMatricula (int mat)
{
    int test=1;
    for (int i = 0; i < 10; i++)
    {
        if (mat == vet[i].Matricula)
        {
            test = 0;
        }
    }
    return test;
}

int main()
{
    int opc, indice=0, ver, cod;
    while (opc != 4)
    {
        printf("\n---Menu---\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Verificar alunos do Curso\n");
        printf("3. Verificar aluno por Matricula\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            if (indice < 10)
            {
                printf("\n---Cadastro---\n");
                printf("Informe os dados do aluno:\n");
                printf("Nome: ");
                fflush(stdin);
                gets(vet[indice].Nome);
                fflush(stdin);
                printf("Numero da Matricula: ");
                scanf("%i", &vet[indice].Matricula);
                printf("Codigo do Curso: ");
                scanf("%i", &vet[indice].Codigo);
                indice++;
            }
            else
                printf("\nNumero maximo de alunos cadastrados!\n");

            break;

        case 2:
            printf("\n---Verificacao por Curso---\n");
            printf("Digite o Codigo do curso para mostrar os alunos.\n");
            printf("Codigo: ");
            scanf("%i", &cod);
            verificaCodigo(cod);
            printf("\n");

            break;

        case 3:
            printf("\n---Verificacao por Matricula---\n");
            printf("Digite a Matricula do aluno para verificar se ele foi cadastrado.\n");
            printf("Matricula: ");
            scanf("%i", &ver);
            ver = verificaMatricula(ver);
            if (ver == 0)
                printf("\nO aluno esta cadastrado.\n");
            else
                printf("\nO aluno nao esta cadastrado.\n");

            break;

        case 4:
            printf("\nSaindo do sistema...\n");
            break;
        
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }
    
    return 0;
}
