/* Defina a função conta que recebe como argumentos uma lista de números inteiros w e um número inteiro k
 e devolve o número de vezes que k ocorre em w.
*/

#include <stdio.h>
#include <stdlib.h>

int conta(int w[6], int k, int tam, int n) {
    
        if (tam==0) {
            return n;
        } else {
            if (k==w[tam-1]) {
                return conta(w, k, tam-1, n+1);
            } else {
                return conta(w, k, tam-1, n);
            }
        }
    
}

int main()
{
    int vet[6], x, y;
    system("cls");
    
    printf("Digite os numeros (inteiros) de um vetor de 6 posicoes: \n");
    for (int i = 0; i < 6; i++) {
        printf("%i. ", i+1);
        scanf("%i", &vet[i]);
    }
    printf("\nAgora digite outro numero para saber quantas vezes ele ocorre no vetor anterior: \n");
    scanf("%i", &x);


    y=conta(vet, x, 6, 0);
    printf("\nNumero de vezes que o numero %i ocorre no vetor: %i", x, y);

    printf("\n\nFinalizando programa. . .\n");
    system("pause");
    return 0;
}
