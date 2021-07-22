/*Implemente um programa em linguagem C que resolva a seguinte demanda:

Sistema para conversão entre moedas: O software deverá solicitar ao usuário a cotação do dia para a conversão do real em: Dólar, 
Peso Uruguaio, Euro e Libra. Com estas informações, disponibilizar o seguinte menu (usar Switch()) ao usuário:

########## CONVERSÕES #########
1. Conversão de Dólar para Peso
2. Conversão de Euro para Libra
3. Lista das cotações do dia
4. Moeda de menor valor

Regras:
1. Solicitar um valor em Dólar, realizar a conversão para Peso Uruguaio e apresentar o resultado na tela;

2. Solicitar um valor em Euro, realizar a conversão para Libra e apresentar o resultado na tela;

3. Apresentar na tela, em ordem decrescente, os valores de cotação informados pelo usuário;

4. Apresentar na tela a cotação e o nome da moeda com menor valor no dia.

P.S. Todos os cálculos devem ser realizados com base nos valores informados pelo usuário. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float cotReal, valReal, cotDolar, valDolar, cotPeso, valPeso, cotEuro, valEuro, cotLibra, valLibra;
    int opcao;

    printf("Digite a cotacao das Moedas a seguir em relacao a 1 Real:\n");
    printf("Qual a cotacao do Dolar: ");
    scanf("%f", &cotDolar);
    printf("Qual a cotacao do Peso Uruguaio: ");
    scanf("%f", &cotPeso);
    printf("Qual a cotacao do Euro: ");
    scanf("%f", &cotEuro);
    printf("Qual a cotacao da Libra: ");
    scanf("%f", &cotLibra);

    printf("########## CONVERSOES #########\n");
    printf("1. Conversao de Dolar para Peso\n");
    printf("2. Conversao de Euro para Libra\n");
    printf("3. Lista das cotações do dia\n");
    printf("4. Moeda de menor valor\n");

    printf("Selecione uma opcao: ");
    scanf("%i", &opcao);

    switch (opcao) {

        case 1:
            printf("Digite um valor em Dolar: ");
            scanf("%f", &valDolar);
            valReal=valDolar/cotDolar;
            valPeso=valReal*cotPeso;
            printf("em Pesos: %.2f", valPeso);

        break;

        case 2:
            printf("Digite um valor em Euro: ");
            scanf("%f", &valEuro);
            valReal=valEuro/cotEuro;
            valLibra=valReal*cotLibra;
            printf("em Libras: %.2f", valLibra);

        break;

        case 3:

            if(cotDolar > cotPeso) {
                float temp = cotPeso; 
                cotPeso = cotDolar; 
                cotDolar = temp; 
            }
            if(cotDolar > cotEuro) {
                float temp = cotEuro;
                cotEuro = cotDolar;
                cotDolar = temp;
            }
            if(cotDolar > cotLibra) {
                float temp = cotLibra;
                cotLibra = cotDolar;
                cotDolar = temp;
            }
            if(cotPeso > cotEuro) {
                float temp = cotEuro;
                cotEuro = cotPeso;
                cotPeso = temp;
            }
            if(cotPeso > cotLibra) {
                float temp = cotLibra;
                cotLibra = cotPeso;
                cotPeso = temp;
            }
            if(cotEuro > cotLibra) {
                float temp = cotLibra;
                cotLibra = cotEuro;
                cotEuro = temp;
            }
            printf("Cotacoes do dia em ordem decrescente: ");
            printf("%.2f, %.2f, %.2f  e  %.2f", cotLibra, cotEuro, cotPeso, cotDolar);


        break;

        case 4:

            if (cotDolar < cotPeso && cotDolar < cotEuro && cotDolar < cotLibra) {
                printf("A moeda com menor valor e o Dolar com cotacao de %.2f", cotDolar);
            }
            if (cotPeso < cotDolar && cotPeso < cotEuro && cotPeso < cotLibra) {
                printf("A moeda com menor valor e o Peso Uruguaio com cotacao de %.2f", cotPeso);
            }
            if (cotEuro < cotDolar && cotEuro < cotPeso && cotEuro < cotLibra) {
                printf("A moeda com menor valor e o Euro com cotacao de %.2f", cotEuro);
            }
            if (cotLibra < cotDolar && cotLibra < cotPeso && cotLibra < cotEuro) {
                printf("A moeda com menor valor e a Libra com cotacao de %.2f", cotLibra);
            }

        break;

    }

    return 0; 
}