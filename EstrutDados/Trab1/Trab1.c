// Trabalho 01 - Ponteiros e alocação dinâmica de memória
// Felipe Barreto Druzian - felipedruzian.aluno@unipampa.edu.br
#include <stdio.h>
#include <stdlib.h>

struct produto
{
    long int codigo;
    char descricao[80];
    float valor;
};

int main()
{
    int quant=0;
    struct produto produtos[quant], *p;
    float total=0;

    printf("Digite a quantidade de produtos da lista: ");
    scanf("%i", &quant);

    p = malloc(quant*sizeof(struct produto));

    printf("\n------\\Registro de produtos//------\n");
    for (int i = 0; i < quant; i++)
    {
        printf("Digite o codigo do produto %i: ", i+1);
        scanf("%ld", &produtos[i].codigo);
        fflush(stdin);
        printf("Digite a descricao do produto %i: ", i+1);
        scanf("%s", &produtos[i].descricao);
        fflush(stdin);
        printf("Digite o valor do produto %i: ", i+1);
        scanf("%f", &produtos[i].valor);
        fflush(stdin);
        printf("\n");
    }

    printf("\n---------\\Listagem de todos os produtos//---------\n");
    for (int i = 0; i < quant; i++)
    {
        printf("%i. %ld: \t %s \t $%.2f \n", i+1, produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
    }


    for (int i = 0; i < quant; i++) total+=produtos[i].valor;
    printf("\nValor total de todos os produtos: %.2f\n", total);


    free(p);
    system("pause");
    return 0;
}
