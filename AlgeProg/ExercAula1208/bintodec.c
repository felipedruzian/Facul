/*
1. Implemente um programa que receba um valor binário de 8bits (vetor)
e realize a conversão deste para decimal
– apresente o resultado na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    
    int bin[8], dec[8], num=0;

    //entrada
    printf("Digite um numero em binario de 8 bits: \n");
    for (int i = 7; i > -1; i--) {
        scanf("%i", &bin[i]);
    }
    
    //processamento
    for (int i = 7; i > -1; i--) {
        dec[i] = (bin[i]*(pow(2,i)));
    }
    for (int i = 0; i < 8; i++) {
        num += dec[i];
    }
    
    
    
    //saida
    printf("\nNumero Binario Digitado: ");
    for (int i = 7; i > -1; i--) {
        printf(" %i ", bin[i]);
    }
    
    printf("\nNumero em Decimal:  ");
    printf("%i\n", num);
    


    printf("\nFim do programa!\n");
    system("pause");
    return 0;
}
