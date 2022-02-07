#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo1;
FILE *arquivo2;


int main()
{
    char nome[32], nome2[32], string[20], string2[20];
    printf("Digite o nome do arquivo que deseja verificar: (sem .txt)\n");
    scanf("%s", &nome);
    printf("Digite o nome do segundo arquivo que deseja verificar: (sem .txt)\n");
    scanf("%s", &nome2);

    arquivo1=fopen(strcat(nome, ".txt"), "r");
    arquivo2=fopen(strcat(nome2, ".txt"), "r");

    while (fscanf(arquivo1, "%s", &string) != EOF)
    {
        if (strcmp(fscanf(arquivo1, "%s", &string), fscanf(arquivo2, "%s", &string2)) != 0)
        {
            printf("Arquivos diferentes!!!!!");
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);
    
    return 0;
}
