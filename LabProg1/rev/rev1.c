/* 1 - Criar uma função que retorna o seguinte: 
a função recebe 3 valores e retornar o quadrado do 1o + a soma dos outros dois. */

#include <stdio.h> 
#include <stdlib.h>


int calculo (int a, int b, int c) {
    int r;
    r = (a*a)+b+c;
    return r;
}

int main() {

    int x[3], result;
    printf("Digite 3 numeros para o calculo: \n");
    for (int i = 0; i < 3; i++) {
        printf("%i. ", i+1);
        scanf("%i", &x[i]);
    }
    result = calculo(x[0], x[1], x[2]);
    printf("\nResultado: %i\n", result);

    system("pause");
    return 0;
}