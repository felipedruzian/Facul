#include <stdio.h>
#include <stdlib.h>

FILE *arquivo;

void proc(int N, int i)
{
    fprintf(arquivo, "%i x %i = %i\n", N, i, N*i);
    printf("%i x %i = %i\n", N, i, N*i);
    if (N == i)
        return;
    else 
        return proc(N, i+1);
}

void tabuada(int Num)
{
    proc(Num, 1);
}

int main()
{
    int num;

    if ((arquivo = fopen("tabuada.txt", "w")) == NULL)
    {
        printf("ERROR!");
        return 1;
    }
    
    printf("Digite um numero para mostrar a tabela da Tabuada e salvar em um arquivo txt.\n");
    printf("Numero para Tabuada: ");
    scanf("%i", &num);

    tabuada(num);

    fclose(arquivo);

    return 0;
}
