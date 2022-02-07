#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo1;
FILE *arquivo2;

int main()
{
    char nome1[32], nome2[32];
    char ch;

    printf("Digite o nome do arquivo que deseja copiar: (sem .txt)\n");
    scanf("%s", &nome1);
    strcpy(nome2, nome1);

    arquivo1=fopen(strcat(nome1, ".txt"), "r");
    arquivo2=fopen(strcat(strcat(nome2, "_cpy"), ".txt"), "w");

    while ((ch=fgetc(arquivo1)) != EOF)
    {
        fputc(ch, arquivo2);
    }

    fclose(arquivo1);
    fclose(arquivo2);
    

    return 0;
}
