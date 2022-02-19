/*Faça um programa que receba dois arquivos do usuário, e crie um terceiro
arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro
seguido do conteúdo do segundo). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo1;
FILE *arquivo2;
FILE *arquivo3;

int main()
{
    char ch, filename1[32], filename2[32], filename3[32], buffer[32];

    printf("Digite o nome dos arquivos que deseja concatenar:\n");
    printf("Arquivo 1: ");
    gets(filename1);
    printf("Arquivo 2: ");
    gets(filename2);
    
    strcpy(buffer, filename1);
    strcat(strcpy(filename3, "out3_"), buffer);

    if ((arquivo1 = fopen(filename1, "r")) == NULL)
    {
        printf("ERROR 101!\n");
        return 1;
    }
    if ((arquivo2 = fopen(filename2, "r")) == NULL)
    {
        printf("ERROR 102!\n");
        return 1;
    }
    if ((arquivo3 = fopen(filename3, "w")) == NULL)
    {
        printf("ERROR 103!\n");
        return 1;
    }

    while ((ch=fgetc(arquivo1)) != EOF)
    {
        fputc(ch, arquivo3);
    }
    while ((ch=fgetc(arquivo2)) != EOF)
    {
        fputc(ch, arquivo3);
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
    
    return 0;
}
