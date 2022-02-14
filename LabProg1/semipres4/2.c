#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

int main()
{
    int num;

    arquivo=fopen("file.bin", "rb");

    while(!feof(arquivo))
    {
        fread(&num, sizeof(int), 1, arquivo);
        printf("Valor: %d\n", num);
    }
    
    fclose(arquivo);
    
    return 0;
}