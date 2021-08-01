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
    int n2, n5, n10, n20, n50, n100, n200;
    float m01, m05, m10, m25, m50, m1;
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
    

    
    
    printf("\nFim do programa! \n");
    system("pause");
    return 0;
}
