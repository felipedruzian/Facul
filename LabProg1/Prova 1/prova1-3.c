#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somaCubos(int n, int soma) {
    if (n > 0) {
        soma=soma+pow(n,3);
        return somaCubos(n-1, soma);
    } else {
        return soma;
    }
}

int main()
{
    system("cls");
    int n;
    printf("Informe um numero para fazer a soma dos cubos: ");
    scanf("%i", &n);

    printf("\nSoma dos cubos do numero %i: %i\n", n, somaCubos(n, 0));


    system("pause");
    return 0;
}
