/* Implemente um sistema em linguagem C para o gerenciamento de carros de uma revenda.
O sistema deverá armazenar o modelo, valor de compra e de venda de 10 veículos - listar todos os dados na tela.
Com estes dados armazenados:

a. Calcular a média de valores de compra dos veículos (Função).
b. Mostrar todos os carros cujo o valor de compra foi maior que o valor médio (Procedimento).
c. A partir do calculo de compra e venda, criar um vetor que armazene o valor de lucro de cada veículo (Função principal).
d. Listar o vetor de lucro na tela, em ordem decrescente (Procedimento). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media (float valores[10], int x) {
    float m=0;
    for (int i = 0; i < x; i++) {
        m+=valores[i];
    }
    m=m/x;
    return m;
}

void acimamedia (float media, float valores[10], char carros[10][32], int x) {
    
    printf("\nVeiculos com valor de compra acima da media:\n");
    for (int i = 0; i < x; i++) {
        if (media<valores[i]) {
        printf("%i. %s\t R$ %.2f\n", i+1, carros[i], valores[i]);
        }
    }
}

void lucrodecr (float lucro[10], char carros[10][32], int x) {
    float temp;
    for (int i = 0; i < x; i++) {
        for (int u = i+1; u < x; u++) {
            if (lucro[i] < lucro [u]) {
                temp=lucro[u];
                lucro[u]=lucro[i];
                lucro[i]=temp;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        printf("%i. %s\t R$ %.2f\n", i+1, carros[i], lucro[i]);
    }
    
}


int main()
{
    int opcao=0, x=0, sair=0, tecla=0;
    char modelo[10][32];
    float valorcompra[10], valorvenda[10], m, lucro[10];

    while (opcao != 5)
    {
        system("cls");
        printf("====<<<< Gerenciamento de carros da Revenda >>>>====\n");
        printf("1. Cadastrar veiculo\n");
        printf("2. Listar veiculos\n");
        printf("3. Media de valores de compra\n");
        printf("4. Lucro de cada veiculo\n");
        printf("5. Sair\n");
        printf("=====================<<<<  >>>>=====================\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("====<<<< Cadastro de veiculos >>>>====\n");
            printf("(Digite 'Sair' no Modelo do carro para voltar ao menu)\n");
            while (sair != 1) {
                printf("Informe os dados do veiculo %i:\n", x+1);
                printf("Modelo do carro: ");
                scanf("%s", &modelo[x]);
                if (strcmp(modelo[x], "Sair")==0) {
                    sair=1;
                }else{
                    printf("Valor da compra: R$ ");
                    scanf("%f", &valorcompra[x]);
                    printf("Valor de venda: R$ ");
                    scanf("%f", &valorvenda[x]);
                    x++;
                }
            }
            sair=0;
            break;

        case 2:
            while (tecla != 10) {
                system("cls");
                printf("====<<<< Lista de veiculos >>>>====\n");
                printf("\t Modelo \t|\t Valor da compra \t|\t Valor de venda \t\n");
                for (int i = 0; i < x; i++) {
                    printf("\t %s \t\t\t R$ %.2f \t\t\t R$ %.2f\n", modelo[i], valorcompra[i], valorvenda[i]);
                }
                printf("\nPressione Enter para voltar. . . ");
                scanf("%c", &tecla);
                tecla = getchar();
                //printf("%i", tecla);
            }
            tecla = 0;
            break;

        case 3:
            while (tecla != 10) {
                system("cls");

                printf("====<<<< Media de valores de compra >>>>====\n");
                m=media(valorcompra, x);
                printf("Media: %.2f\n", m);
                acimamedia(m, valorcompra, modelo, x);
                
                printf("\nPressione Enter para voltar. . . ");
                scanf("%c", &tecla);
                tecla = getchar();
                //printf("%i", tecla);
            }
            tecla = 0;
            break;

        case 4:
            while (tecla != 10) {
                system("cls");

                printf("====<<<< Lucro de cada veiculo >>>>====\n");
                for (int i = 0; i < x; i++) {
                    lucro[i]=valorvenda[i]-valorcompra[i];
                    //printf("%.2f\n", lucro[i]);
                }
                lucrodecr(lucro, modelo, x);

                printf("\nPressione Enter para voltar. . . ");
                scanf("%c", &tecla);
                tecla = getchar();
                //printf("%i", tecla);
            }
            tecla = 0;
            break;

        case 5:
            
            break;
        
        default:
            printf("\nOpcao invalida!!");
            break;
        }
        
            
        

    }
    printf("\nFinalizando o programa. . .\n");
    system("pause");
    return 0;
}


