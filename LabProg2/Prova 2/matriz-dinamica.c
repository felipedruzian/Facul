#include <stdio.h>
#include <stdlib.h>

// revisar srand numeros aleartorios

int main()
{
    int i, j, tam, TAM, aux;
    int **p;
    tam = 4; // numero de linhas
    TAM = 5; // tamanho das colunas
    p = (int **)malloc(tam * sizeof(int));
    aux = 0;
    for (i = 0; i < tam; i++)
    {
        p[i] = (int *)malloc(TAM * sizeof(int));
    }
    // matriz dinamica criada
    // preenchendo a matriz
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            p[i][j] = aux;
            aux++;
        }
    }

    // imprimindo a matriz
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n"); //dps tentar entender diferença com e sem esse printf
    }
}