/* Faça um programa que receba do usuário um arquivo texto. Crie outro
arquivo texto contendo o texto do arquivo de entrada, mas com as vogais
substituídas por ‘*’. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo;
FILE *arquivo2;

int main()
{
    char ch, filename1[32], filename2[32], buffer[32];

    printf("Digite o nome do arquivo: ");
    scanf("%s", &filename1);
    strcpy(buffer, filename1);
    strcat(strcpy(filename2, "out_"), buffer);

    if ((arquivo = fopen(filename1, "r")) == NULL)
    {
        printf("ERROR 101!\n");
        return 1;
    }
    if ((arquivo2 = fopen(filename2, "w")) == NULL)
    {
        printf("ERROR 102!\n");
        return 1;
    }
    
    while ((ch=fgetc(arquivo)) != EOF)
    {
        if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            fputc('*', arquivo2);
        }else
        {
            fputc(ch, arquivo2);
        }
    }

    fclose(arquivo);
    fclose(arquivo2);

    return 0;
}
