/* Defina a função quadrados_inv que recebe como argumento um número natural n 
e devolve a lista dos quadrados perfeitos até n, por ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>

quadrados_inv(int n) {
    if (n > 1) {
        printf("%d, ", n*n);
        quadrados_inv(n-1);
    } else {
        printf("1");
    }
}

int main() {
    int x;
    
    system("cls");
    printf("Digite um numero inteiro para ver os quadrados perfeitos dele: ");
    scanf("%i", &x);
    
    printf("[ ");
    quadrados_inv(x);
    printf(" ]\n\n");

    system("pause");    
    return 0;
}
