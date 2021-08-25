/*
Implemente um programa que popule, com valores aleatórios entre 35 e 70, uma matriz quadrada de ordem 9. Ao final:
a. Liste a matriz na tela;
b. Copie os valores armazenados na diagonal principal da matriz para um vetor e apresente este vetor na tela;
c. Apresente a soma dos valores pares presentes na ultima coluna da matriz;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //variaveis
    int matrix[9][9], diagonal[9], coluna[9], soma=0;

    //processamento
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        for (int u = 0; u < 9; u++) {
            matrix[i][u] = (rand()%36) +35;
        }
    }


    for (int i = 0; i < 9; i++) {
            diagonal[i] = matrix[i][i];
    }

    
    for (int i = 0; i < 9; i++) {
        coluna[i]=matrix[i][8];
        if (matrix[i][8]%2==0) {
            soma += matrix[i][8];
        }
    }
    


    //saida
    printf("Matriz gerada com valores aleatorioes entre 35 a 70: \n");
    for (int i = 0; i < 9; i++) {
        for (int u = 0; u < 9; u++) {
            printf("%i \t", matrix[i][u]);
        }
        printf("\n");
    }

    printf("\nVetor da diagonal principal da matriz: \n");
    for (int i = 0; i < 9; i++) {
        printf("%i \t", diagonal[i]);
    }
    
    printf("\n\nSoma dos valores pares da ultima coluna: %i\n", soma);
    


    printf("\nFim do Programa!\n");
    system("pause");
    return 0;
}
