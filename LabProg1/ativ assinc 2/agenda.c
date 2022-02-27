#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _telefone
{
    int DDD;
    long int numero;
};

struct _aniversario
{
    int dia;
    int mes;
    int ano;
};

struct _agenda
{
    char nome[32];
    char email[32];
    struct _telefone telefone;
    struct _aniversario aniversario;
    char obs[64];
};
typedef struct _agenda cadastro;

cadastro agenda[10];
int i = 0;

void cadastrar() {
    printf("Informe os dados:\n");
    printf("Nome: ");
    fflush(stdin);
    gets(agenda[i].nome);
    printf("Email: ");
    fflush(stdin);
    gets(agenda[i].email);
    printf("Telefone: (DDD e Numero separados por espaco)\n");
    //printf("DDD: ");
    fflush(stdin);
    scanf("%i %i", &agenda[i].telefone.DDD, &agenda[i].telefone.numero);
    //printf("Numero: ");
    //scanf("%i", &agenda[i].telefone.numero);
    printf("Aniversario: (separados por / )\n");
    //printf("Dia: ");
    fflush(stdin);
    scanf("%i/%i/%i", &agenda[i].aniversario.dia, &agenda[i].aniversario.mes, &agenda[i].aniversario.ano);
    //printf("Mes: ");
    //scanf("%i", &agenda[i].aniversario.mes);
    //printf("Ano: ");
    //scanf("%i", &agenda[i].aniversario.ano);
    printf("Observacao: ");
    fflush(stdin);
    gets(agenda[i].obs);
    fflush(stdin);
    i++;
}

void buscaNome() {
    char busca[32], copy[32];
    char *ret;
    printf("Digite o nome para buscar: ");
    fflush(stdin);
    gets(busca);
    
    for (int j = 0; j < i; j++)
    {
        strcpy(copy, agenda[j].nome);
        ret = strtok(copy, " ");
        if (strcmp(busca, agenda[j].nome) == 0 || strcmp(busca, ret) == 0)
        {
            printf("\n -------//------ \n");
            printf("Nome: %s\n", agenda[j].nome);
            printf("Email: %s\n", agenda[j].email);
            printf("Telefone: %i %i\n", agenda[j].telefone.DDD, agenda[j].telefone.numero);
            printf("Data de Nascimento: %i/%i/%i\n", agenda[j].aniversario.dia, agenda[j].aniversario.mes, agenda[j].aniversario.ano);
            printf("Observacoes: %s\n", agenda[j].obs);
        }
    }
}

void buscaMes() {
    int busca;
    printf("Digite o mes para buscar: ");
    fflush(stdin);
    scanf("%i", &busca);
    for (int j = 0; j < i; j++)
    {
        if (busca == agenda[i].aniversario.mes)
        {
            printf("\n -------//------ \n");
            printf("Nome: %s\n", agenda[j].nome);
            printf("Email: %s\n", agenda[j].email);
            printf("Telefone: %i %i\n", agenda[j].telefone.DDD, agenda[j].telefone.numero);
            printf("Data de Nascimento: %i/%i/%i\n", agenda[j].aniversario.dia, agenda[j].aniversario.mes, agenda[j].aniversario.ano);
            printf("Observacoes: %s\n", agenda[j].obs);
        }
    }
}

void imprimeAgenda() {
    int opt;
    printf("Escolha uma opcao: \n");
    printf("1. Mostrar apenas Nome, Telefone e Email\n");
    printf("2. Mostrar todos os dados\n");
    scanf("%i", &opt);
    if (opt == 1)
    {
        for (int j = 0; j < i; j++)
        {
            printf("\n -------//------ \n");
            printf("Nome: %s\n", agenda[j].nome);
            printf("Email: %s\n", agenda[j].email);
            printf("Telefone: %i %i\n", agenda[j].telefone.DDD, agenda[j].telefone.numero);
        }
    }else if(opt == 2) 
    {
        for (int j = 0; j < i; j++)
        {
            printf("\n -------//------ \n");
            printf("Nome: %s\n", agenda[j].nome);
            printf("Email: %s\n", agenda[j].email);
            printf("Telefone: %i %i\n", agenda[j].telefone.DDD, agenda[j].telefone.numero);
            printf("Data de Nascimento: %i/%i/%i\n", agenda[j].aniversario.dia, agenda[j].aniversario.mes, agenda[j].aniversario.ano);
            printf("Observacoes: %s\n", agenda[j].obs);
        }
    }
}