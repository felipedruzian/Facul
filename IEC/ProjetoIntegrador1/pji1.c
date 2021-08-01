/*
• Construção de um algoritmo e um software que calcule o troco
mínimo:
• Usuário deve fornecer valor do produto
• Usuário deve fornecer o valor pago
• Considerar moedas:
0,01 e 0,05
0,10 e 0,25
0,50 e 1,00
• Considerar notas:
2 e 5
10 e 20
50, 100 e 200 R$
• O programa deverá realizar o cálculo do troco do comprador, visando
minimizar o total de notas e moedas fornecidas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //variaveis
    int m01, m05, m10, m25, m50, m1, n2, n5, n10, n20, n50, n100, n200;
    m01=m05=m10=m25=m50=m1=n2=n5=n10=n20=n50=n100=n200=0;
    float moedas[6] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};
    float notas[7] = {200, 100, 50, 20, 10, 5, 2};
    float valorproduto, valorpago;
    
    //inicio
    printf("Insira o valor do produto que deseja: ");
    scanf("%f", &valorproduto);
    printf("Insira o valor que deseja pagar: ");
    scanf("%f", &valorpago);

    //casos sem troco
    if (valorpago == valorproduto) {
        printf("Voce pagou o valor exato do produto, portanto nao tem troco.\n"); 
    }
    if (valorpago < valorproduto){
        printf("O valor de pagamento e menor que o valor do produto!\n");
        printf("Por favor, digite um novo valor: ");
        scanf("%f", &valorpago);
    }

    //troco
    if(valorpago > valorproduto) {

        while (valorpago - valorproduto >= notas[0]) {
            valorpago = valorpago - 200;
            n200++;
        }
        
        printf("\nTroco em notas: \n");
        printf("2, 5, 10, 20, 50, 100, 200\n");
        printf("%i, %i, %i, %i, %i, %i, %i\n", n2, n5, n10, n20, n50, n100, n200);

        printf("Troco em modeas: \n");
        printf("0.01, 0.05, 0.10, 0.25, 0.50, 1.00\n");
        printf("%i, %i, %i, %i, %i, %i\n", m01, m05, m10, m25, m50, m1);
    }
    

    
    
    printf("\nFim do programa! \n");
    system("pause");
    return 0;
}
