/* Faça um programa que recebe um vetor de 10 números, converta cada um
desses números para binário e grave a sequência de 0s e 1s em um arquivo
texto. Cada número deve ser gravado em uma linha. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo;

int main()
{
    int dec[10], bin[10][10], t=0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bin[i][j] = 0;
        }
    }
    
    
    printf("Digite 10 numeros (inteiros): \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i: ", i+1);
        scanf("%i", &dec[i]);
    }

    if ((arquivo = fopen("bin.txt", "w")) == NULL)
    {
        printf("ERROR 101!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        fprintf(arquivo, "%d = ", dec[i]);
        for (int j = 0; dec[i] > 0; j++)
        {
            bin[i][j] = dec[i] % 2;
            dec[i] = dec[i] / 2;
            //fprintf(arquivo, "%i", bin[i][j]);
            //printf("%i", bin[i][j]);
        }
        //printf("\n");
        t=0;
        for (int h = 10; h >= 0; h--)
        {
            if (bin[i][h] == 1)
            {
                t = 1;
            }
            if (t == 1)
            {
                fprintf(arquivo, "%i", bin[i][h]);
                //printf("%i", bin[i][h]);
            }
        }
        //printf("\n\n");
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    return 0;
}
