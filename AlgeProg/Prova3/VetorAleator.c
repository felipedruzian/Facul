/*Crie um programa em C que armazene valores inteiros e aleatórios entre (1 e 100) em um vetor de 20 posições.
O sistema deverá conter:

a. Uma função para identificar e apresentar as posições do vetor que possuem valores repetidos.
Caso não ocorram valores repetidos o sistema deverá apresentar a mensagem: "Vetor sem valores repetidos!".

b. Um procedimento para mostrar o somatório dos valores repetidos. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vetor[20], soma=0, repetidos[20];

int verificacao (int x, int y) {
    int repetido=0;
    
    if (vetor[x]==vetor[y]) {
        repetido=1;
    }

    return repetido;
}

void somatorio() {
    for (int i = 0; i < 20; i++) {
        if (repetidos[i]==1) {
            soma+=vetor[i];
        }
    }
    if (somatorio==0)
    {
        printf("Nenhum valor repitido!!");
    }else{
    printf("Somatorio dos valores repetidos: %i", soma);
    }
}

int main() {
    int repetido;
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        vetor[i]=(rand()%99)+1;
    }
    
    for (int i = 0; i < 20; i++) {
        printf("Valor %i:  %i\n", i+1, vetor[i]);
    }
    
    for (int x = 0; x < 20; x++) {
        for (int y = x+1; y < 20; y++) {
            repetido=verificacao(x, y);
            if (repetido==1) {
                repetidos[x+1]=1;
                repetidos[y+1]=1;
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        if (repetidos[i]==1) {
            printf("Posicao repetida: %i\n", i);
        }
    }

    somatorio();
    

    printf("\nFinalizando o programa...\n");
    system("pause");
    return 0;
}
