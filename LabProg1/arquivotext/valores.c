#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

int main()
{
    int valores[10];

    printf("Digite 10 valores inteiro: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i. ", i+1);
        scanf("%i", &valores[i]);
    }
    
    arquivo=fopen("valores.txt", "w");

    for (int i = 0; i < 10; i++)
    {
        if (valores[i] % 2 == 0)
        {
            fprintf(arquivo, "%i \n", valores[i]);
        }else
        {
            valores[i] = 0;
            fprintf(arquivo, "%i \n", valores[i]);
        }
        
    }
    
    fclose(arquivo);

    return 0;
}
