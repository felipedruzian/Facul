/* Implemente um programa que, através da passagem de parâmetros, realize as funções para o seguinte menu:

 << CALCULADORA GERAL >>
1. Calculo da Hipotenusa
2. Área do Cilindro (área total)
3. Distância > R$
4. Sair

 Requisitos:

* O sistema só deverá ser encerrado ao digitar a opção 4.
* Para cada opção o sistema deverá passar parâmetros para uma função específica.
* Os resultados deverão ser apresentados ao usuário através de Procedimentos específicos para isso.
* Não devem ser utilizadas variáveis globais.
* No item 3 a resposta deverá ser o custo em reais para se realizar um determinado trajeto de carro,
 conhecendo-se a distância, consumo do veículo e valor do combustível. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float hipotenusa(float a, float b) {
    float x;
    
    x=sqrt(pow(a, 2) + pow(b, 2));

    return x;
}
float cilindro(float r, float h) {
    float Ab, Al, At, pi=3.14;

    Ab=pi*pow(r, 2);
    Al=pi*r*h;
    At=2*Ab+2*Al;

    return At;
}
float trajeto(float distancia, float consumo, float combustivel) {
    float x;

    x=(distancia/consumo)*combustivel;

    return x;
}

int main()
{
    int opcao;
    float a, b, hipot; //variaveis da hipotenusa
    float r, h, At; //variaveis do cilindro
    float distancia, consumo, combustivel, valor; //variaveis da viagem

    while (opcao != 4) {
    
    printf("\n\n<< CALCULADORA GERAL >>\n");
    printf("1. Calculo da Hipotenusa\n");
    printf("2. Area do Cilindro (area total)\n");
    printf("3. Distancia > R$\n");
    printf("4. Sair\n");
    printf("-----------<<>>------------\n");
    printf("Escolha uma opcao: ");
    scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n<< Calculo da Hipotenusa >>\n");
            printf("Digite o tamanho de um dos lados de um triangulo: ");
            scanf("%f", &a);
            printf("Digite o tamanho do outro lado: ");
            scanf("%f", &b);
            hipot=hipotenusa(a, b);
            printf("\nValor da hipotenusa: %.1f\n", hipot);

        break;
    
        case 2:
            printf("\n<< Area do Cilindro >>\n");
            printf("Digite o raio do cilindro: ");
            scanf("%f", &r);
            printf("Digite a altura do cilindro: ");
            scanf("%f", &h);
            At=cilindro(r, h);
            printf("\nValor da Area Total do Cilindro: %.1f\n", At);
        
        break;

        case 3:
            printf("\n<< Custo da viagem >>\n");
            printf("Informe o valor do combustivel: ");
            scanf("%f", &combustivel);
            printf("Qual o consumo do veiculo: ");
            scanf("%f", &consumo);
            printf("Digite a distancia do trajeto: ");
            scanf("%f", &distancia);
            valor = trajeto(distancia, consumo, combustivel);
            printf("\nValor em reais para a viagem: %.1f\n", valor);
        
        break;

        case 4:
        
        break;
    
        default:

        break;
        }
    }


    printf("\nFinalizando o programa...\n");
    system("pause");
    return 0;
}
