/*
Implemente um programa que receba e armazene 10 palavras.
Ao final o sistema deverá imprimir a lista de palavras na ordem que foi digitada e a mesma 
lista de palavras ordenadas alfabeticamente em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //variaveis
    char palavras[10][26];
    char troca[26];
    int i=0, u=0;

    //entrada de dados
    printf("Escreva 10 palavras: \n");
    for (i = 0; i < 10; i++) {
        printf("%i - ", i+1);
        gets(palavras[i]);
    }

    //saida
    //ordem do usuario
    printf("\nLista de palavras na ordem digitada: \n");
    for (i = 0; i < 10; i++) {
        printf("%i - ", i+1);
        puts(palavras[i]);
    }
    

    //ordem alfabetica
    for (i = 0; i < 10; i++) {
        for (u = i + 1; u < 10; u++) {
            if (strcmp(palavras[u], palavras[i]) < 0) {
            strcpy(troca, palavras[u]);
            strcpy(palavras[u], palavras[i]);
            strcpy(palavras[i], troca);      
            }
        }
    }

    printf("\nLista das palavras na ordem alfabetica: \n");
    for (i = 0; i < 10; i++) {
        printf("%i - ", i+1);
        puts(palavras[i]);
    }
    
    


    printf("\nFim do Programa!\n");
    system("pause");
    return 0;
}
