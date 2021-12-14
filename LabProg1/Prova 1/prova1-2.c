#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco
{
    char Rua[32];
    int Numero;
    char Cidade[32];
    char Estado[16];
};

struct cadastro
{
    char Nome[32];
    int Identidade;
    char Sexo;
    struct endereco Endereco;
    
} Cadastro[5];

int masc() {
    int qntM=0;
    for (int i = 0; i < 5; i++)
    {
        if (Cadastro[i].Sexo == 77) //  77 = M  ASCII 
        {
            qntM+=1;
        }
    }
    return qntM;
}


int main() {
    for (int i = 0; i < 5; i++)
    {
        printf("Informe os dados para o cadastro: \n");
        printf("Digite o nome: ");
        gets(Cadastro[i].Nome);
        fflush(stdin);
        printf("Digite o numero da Identidade: ");
        scanf("%i", &Cadastro[i].Identidade);
        fflush(stdin);
        printf("Digite o Sexo: (M ou F) ");
        scanf("%c", &Cadastro[i].Sexo);
        fflush(stdin);
        printf("Digite as informacoes do endereco: \n");
        printf("Rua: ");
        gets(Cadastro[i].Endereco.Rua);
        fflush(stdin);
        printf("Numero: ");
        scanf("%i", &Cadastro[i].Endereco.Numero);
        fflush(stdin);
        printf("Cidade: ");
        gets(Cadastro[i].Endereco.Cidade);
        fflush(stdin);
        printf("Estado: ");
        gets(Cadastro[i].Endereco.Estado);
        
    }
    
    printf("\nQuantidade de pessoa com sexo masculino: %i\n", masc());

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(Cadastro[i].Endereco.Rua, "Rua dos Bobos") == 0)
        {
            printf("\nO %s mora na %s\n", Cadastro[i].Nome, Cadastro[i].Endereco.Rua);
        }
    }
    

    printf("\nFinalizando o programa . . .\n");
    system("pause");
    return 0;
}
