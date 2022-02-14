#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

int main()
{
    int vet[3];

    arquivo=fopen("file.bin", "wb");

    for (int i = 0; i < 3; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    fwrite(&vet, sizeof(int), 3, arquivo);
    fclose(arquivo);

    return 0;
}

