/*
1. Implemente um programa para a simulação do sorteio da MegaSena.
Neste sistema o usuário poderá fazer duas apostas de 6 números
(guardar as apostas nos vetores ap1[6] e ap2[6]).
O programa deverá sortear 6 números (de 0 a 60) e armazenar em um vetor sort[6].

Ao final o programa deve:

a. Mostrar o número de acertos por aposta.

b. Listar as apostas e valores sorteados em ordem crescente.

c. Carregar as apostas e valores do sorteio em uma matriz e apresentar na tela esta matriz. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Variaveis
    int i, u, a=0, ap1[6], ap2[6], sort[6], matriz[3][6];

    printf("\t------// Mega Sena \\------\n\n");

    //Apostas
    printf("Insira 6 numeros para a primeira aposta: \n");
    for (i = 0; i < 6; i++) {
        printf("%i. ", i+1);
        scanf("%i", &ap1[i]);
    }
    
    printf("Numeros da Aposta 1: ");
    for (i = 0; i < 6; i++) {
        printf("\t %i", ap1[i]);
    }
       
    printf("\n\nInsira 6 numeros para a segunda aposta: \n");
    for (i = 0; i < 6; i++) {
        printf("%i. ", i+1);
        scanf("%i", &ap2[i]);
    }
    
    printf("Numeros da Aposta 2: ");
    for (i = 0; i < 6; i++) {
        printf("\t %i", ap2[i]);
    }
    
    //Sorteio e processamento
    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        sort[i] = rand()%60;
    }
    
    for (i = 0; i < 6; i++) {
        for (u = 0; u < 6; u++) {
            if (ap1[i] == sort[u] || ap2[i] == sort[u]) {
                a++;
            }
        }
    }
    
    for(i=0; i<6; i++){
        for(u=i+1; u<6; u++){
            if(ap1[i]>ap1[u]){
              int troca=ap1[u];
              ap1[u]=ap1[i];
              ap1[i]=troca;
            }
        }
    }

    for(i=0; i<6; i++){
        for(u=i+1; u<6; u++){
            if(ap2[i]>ap2[u]){
              int troca=ap2[u];
              ap2[u]=ap2[i];
              ap2[i]=troca;
            }
        }
    }

    for(i=0; i<6; i++){
        for(u=i+1; u<6; u++){
            if(sort[i]>sort[u]){
              int troca=sort[u];
              sort[u]=sort[i];
              sort[i]=troca;
            }
        }
    }

    for (i = 0; i < 6; i++)
    {
        matriz[0][i]=ap1[i];
        matriz[1][i]=ap2[i];
        matriz[2][i]=sort[i];
    }
    


    //Saida

    printf("\nNumeros da Aposta 1: ");
    for (i = 0; i < 6; i++) {
        printf("\t %i", ap1[i]);
    }
    printf("\nNumeros da Aposta 2: ");
    for (i = 0; i < 6; i++) {
        printf("\t %i", ap2[i]);
    }
    printf("\n\nNumeros sorteados: ");
    for (i = 0; i < 6; i++) {
        printf("\t %i", sort[i]);
    }
    printf("\nTotal de acertos: %i", a);
    

    printf("\n\nMatriz dos numeros: \n");
    for (i = 0; i < 3; i++)
    {
        for (u = 0; u < 6; u++)
        {
            printf("%i \t", matriz[i][u]);
        }
        printf("\n");
    }
    

    
    printf("\n\nFim do Programa!\n");
    system("pause");
    return 0;
}
