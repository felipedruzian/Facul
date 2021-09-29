/*
1. Construa um programa que receba os dados de compras de um individuo. O sistema deve
receber Código da compra, descrição produto, quantidade e valor unitário (calcular o valor total).
Regras do sistema:
a. O programa deve solicitar para o usuário a informação do valor de limite das compras;
b. Só poderão ser lançadas compras dentro do limite informado;
c. O sistema deverá, ao final, apresentar os dados da compra de menor valor;
d. O sistema deverá apresentar a descrição e valor unitário do produto de maior valor(considerar valor unitário);
e. O sistema deverá apresentar o valor médio por compra;
f. Caso o usuário ultrapasse o limite de compras, o sistema deverá apresentar o valor negativo deste cliente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // variaveis
    float ValorLimiteCompras;
    int x = 32;  //quantidade de produtos
    int y = 0;  //"numero" do produto
    int QuantidadeDoProduto[x];
    float ValorDoProduto[x], SomaValores, MediaCompras;
    char codigo[x][16], descricao[x][32]; 
    
    // inicialização
    printf("----------- // Programa de Compras \\ ----------\n");
    printf("Informe o valor maximo de compras: ");
    scanf("%f", &ValorLimiteCompras);
    printf("\n");
    
    // entrada
    printf("Compras: \n\n");
    while (ValorLimiteCompras > 0)
    {
        printf("Valor Disponivel: %.2f \n", ValorLimiteCompras);
        printf("Digite o nome ou descricao do produto: ");
        scanf("%s", &descricao[y]);
        printf("Insira o codigo do produto: ");
        scanf("%s", &codigo[y]);
        printf("Digite a quantidade do produto: ");
        scanf("%i", &QuantidadeDoProduto[y]);
        printf("Insira o valor do produto: ");
        scanf("%f", &ValorDoProduto[y]);
        printf("\n");

        SomaValores += ValorDoProduto[y];
        ValorLimiteCompras = ValorLimiteCompras - QuantidadeDoProduto[y] * ValorDoProduto[y];
        if(y > 30){x++;} //fingi q da certo, so loco
        y++;
    }
    
    // saida
    if (ValorLimiteCompras <= 0) 
    {
        //printf("%i , %i \n", x, y);

        //valor que ficou devendo
        if (ValorLimiteCompras < 0) {
            printf("Valor que voce ficou devendo: %.2f \n", ValorLimiteCompras);
        }
        /*
        for (int z = 0; z < y; z++){
            printf("%.2f \n", ValorDoProduto[z]);
        } */

        //media
        MediaCompras = SomaValores/(y);
        printf("Valor medio por compra: %.2f\n", MediaCompras);

        //maior produto
        

        //menor produto


    }
    



    printf("\nFim do programa! \n");
    system("pause");
    return 0;
}
