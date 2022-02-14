#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

int main()
{
    int vet[3];

    arquivo=fopen("file.bin", "rb");

    fread(&vet, sizeof(int), 3, arquivo);

    for (int i = 0; i < 3; i++)
    {
        printf("Valor %d: %d\n", i+1, vet[i]);
    }
    
    fclose(arquivo);
    
    return 0;
}
