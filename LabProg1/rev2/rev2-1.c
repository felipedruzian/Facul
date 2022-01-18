#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char nome[15];
    char setor;
    int quantidade;
    float real;
} estoque[99];

int c = 0;

int cadastro(int c)
{
    int teste=0;
    while (teste != 1)
    {
        printf("Dados do produto %i: \t (Digite 0 no nome para voltar)\n", c+1);
        printf("Nome: ");
        scanf("%s", &estoque[c].nome);
        if (strcmp(estoque[c].nome, "0") == 0)
        {
            teste = 1;
        }else{
            fflush(stdin);
            printf("Setor (letra) ");
            scanf("%c", &estoque[c].setor);
            fflush(stdin);
            printf("Valor (un): ");
            scanf("%f", &estoque[c].real);
            fflush(stdin);
            printf("Quantidade: ");
            scanf("%i", &estoque[c].quantidade);
            fflush(stdin);
            printf("\n");
            c++;
        }
    }
    return c;
}

void leitura()
{
    if (c == 0)
    {
        printf("Sem estoque no momento!!\n");
    } else {
        for (int i = 0; i < c; i++)
        {
            printf("Produto %i:\n", i + 1);
            printf("Nome: %s\n", estoque[i].nome);
            printf("Setor: %c\n", estoque[i].setor);
            printf("Valor: R$ %.2f\n", estoque[i].real);
            printf("Quantidade: %i\n\n", estoque[i].quantidade);
        }
    }
}

void filtrasetor()
{
    char letra;
    if (c == 0)
    {
        printf("Sem estoque no momento!!\n");
    } else {
        printf("Digite o setor para filtrar: (caractere)\n");
        scanf("%c", &letra);
        for (int i = 0; i < c; i++)
        {
            if (letra == estoque[i].setor)
            {
                printf("Produto %i:\n", i + 1);
                printf("Nome: %s\n", estoque[i].nome);
                printf("Setor: %c\n", estoque[i].setor);
                printf("Valor: R$ %.2f\n", estoque[i].real);
                printf("Quantidade: %i\n\n", estoque[i].quantidade);
            }
        }
    }
}

void capitaltotal()
{
    float captotal=0;
    if (c == 0)
    {
        printf("Sem estoque no momento!!\n");
    } else {
        for (int i = 0; i < c; i++)
        {
            printf("\ntotal investido =\t total investido +\t valor do produto %i x\t quantidade do prod %i\n", i+1, i+1);
            printf("%.2f \t=\t %.2f \t+\t %.2f \tx\t %i\n", captotal, captotal, estoque[i].real, estoque[i].quantidade);
            captotal += (estoque[i].real*estoque[i].quantidade);
            printf("Total investido: %.2f\n", captotal);
        }
    }
}

int main()
{
    int opc = 0;
    int tecla = 0;
    while (opc != 5)
    {
        system("cls");
        printf("MENU:\n");
        printf("1 - Cadastra produto no estoque\n");
        printf("2 - Ler estoque\n");
        printf("3 - Filtrar por setor\n");
        printf("4 - Total gasto\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            while (tecla != 10)
            {
                system("cls");
                c = cadastro(c);
                printf("\nPressione ENTER para voltar ao menu...");
                fflush(stdin);
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 2:
            while (tecla != 10)
            {
                system("cls");
                fflush(stdin);
                leitura();
                printf("\nPressione ENTER para voltar ao menu...");
                fflush(stdin);
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 3:
            while (tecla != 10)
            {
                system("cls");
                fflush(stdin);
                filtrasetor();
                printf("\nPressione ENTER para voltar ao menu...");
                fflush(stdin);
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 4:
            while (tecla != 10)
            {
                system("cls");
                fflush(stdin);
                capitaltotal();
                printf("\nPressione ENTER para voltar ao menu...");
                fflush(stdin);
                tecla = getchar();
            }
            tecla = 0;
            break;
        case 5:
            printf("\nSaindo do programa . . .\n");
            break;

        default:
            printf("Opcao invalida!");
            break;
        }
    }

    system("pause");
    return 0;
}
