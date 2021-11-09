/* 3 - Escreva um programa que leia o raio de um círculo e faça duas funções: uma função
chamada área que calcula e retorna a área do círculo e outra função chamada perímetro
que calcula e retorna o perímetro do círculo. Área = PI * r2. Perímetro = PI * 2 * r. */

#include <stdio.h>
#include <stdlib.h>

pi=3.14;


float area (float r) {
    float s;
    s = pi * (r*r);
    return s;
}

float perimetro (float r) {
    float s;
    s = pi * 2 * r;
    return s;
}

int main(int argc, char const *argv[])
{
    int opc;
    float r, s;

    while (opc != 0) {
        
        printf("\n**********MENU**********\n");
        printf("1. Calculo da area.\n");
        printf("2. Calculo do perimetro.\n");
        printf("0. Sair\n");
        printf("************************\n");
        printf("Digite uma opcao: ");
        scanf("%i", &opc);

        switch (opc) {
        case 1:
            printf("\nDigite um valor para o raio: ");
            scanf("%f", &r);
            s=area(r);
            printf("Valor do raio: %.2f\n", s);
            break;
        
        case 2:
            printf("\nDigite um valor para o raio: ");
            scanf("%f", &r);
            s=perimetro(r);
            printf("Valor do perimetro: %.2f\n", s);
            break;
        
        case 0:
            
            break;

        default:
            printf("Opcao invalida!!\n");
            break;
        }


    }
    



    system("pause");
    return 0;
}
