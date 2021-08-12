/*
2. Crie um programa que popule um vetor de inteiros de 10 posições.
Ordene este vetor em ordem crescente e apresente o resultado na tela.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    
    int vet[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        vet[i] = rand()%100;
    }
    
    printf("Vetor: ");
    for (int i = 0; i < 10; i++) {
        printf(" %i ", vet[i]);
    }
    

    for (int i = 0; i < 10; i++)
    {
        for (int u = i+1; u < 10; u++)
        {
            if (vet[i]>vet[u])
            {
                int temp = vet[i];
                vet[i] = vet[u];
                vet[u] = temp;
            }
        }
    }
    

    printf("\nVetor em ordem crescente: ");
    for (int i = 0; i < 10; i++) {
        printf(" %i ", vet[i]);
    }
    
    

    printf("\nFim do programa!\n");
    system("pause");
    return 0;
}
