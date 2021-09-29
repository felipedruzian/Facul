/*
2. Implemente um sistema que receba e armazene uma lista de 10 nomes completos, e:
a. Apresente a lista de nomes na tela;
b. Mostre a média de caracteres por nomes;
c. Concatene, em uma variável distinta, o primeiro e ultimo nomes informados;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nomes[10][32];
    float carac[10];
    float somatorio, media;
    char nomefinal[64];

    printf("Digite 10 nomes completos: \n");
    for (int i = 0; i < 10; i++){
        printf("%i. ", i+1);
        gets(nomes[i]);
    }
    
    printf("\nLista dos nomes: \n");
    for (int i = 0; i < 10; i++){ puts(nomes[i]); }

    for (int i = 0; i < 10; i++){ carac[i] = strlen(nomes[i]); }
    //for (int i = 0; i < 10; i++){ somatorio = carac[i] + carac[i+1]; }
    somatorio=carac[0]+carac[1]+carac[2]+carac[3]+carac[4]+carac[5]+carac[6]+carac[7]+carac[8]+carac[9];
    
    //printf("%.2f \n", somatorio);
    media = somatorio/10;
    printf("\nMedia de caracteres por nome: %.2f \n", media);

    nomefinal[64] = strcat(nomes[0], nomes[9]);
    puts(nomefinal);

    printf("\nFim do programa! \n");
    system("pause");
    return 0;
}
