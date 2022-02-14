#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

int main()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    arquivo=fopen("file.bin", "wb");

    for (int i = 1; i <= num; i++)
    {
        fwrite(&i, sizeof(int), 1, arquivo);
    }

    fclose(arquivo);

    return 0;
}