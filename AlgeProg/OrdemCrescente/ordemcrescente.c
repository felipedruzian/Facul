/*Implemente um programa que receba 4 números inteiros e apresente na tela:

a. Apresente na tela os valores na ordem que foram digitados.

b. Apresente na tela os valores em ordem crescente.

c. Apresente na tela os valores em ordem decrescente.

* O exercício pode ser resolvido em duplas
* Ambos devem postar a resposta para a atividade no Moodle
* Deve constar na primeira linha do código fonte o nome da dupla
*/
#include <stdio.h>
int v1, v2, v3, v4;

int main() {
    printf("Digite 4 valores inteiros: \n");
    printf("Valor 1: ");
    scanf("%i", &v1);
    printf("Valor 2: ");
    scanf("%i", &v2);
    printf("Valor 3: ");
    scanf("%i", &v3);
    printf("Valor 4: ");
    scanf("%i", &v4);

    printf("\n");
    printf("Valores digitados: ");
    printf("%i, %i, %i e %i", v1, v2, v3, v4);
    printf("\n");
    printf("\n");

    if(v1 > v2) {
      int temp = v2; //define o valor temporario o mesmo de v2
      v2 = v1; //define o valor de v2 o mesmo de v1
      v1 = temp; //defino o valor de v1 o do temporario (antigo valor de v2)
    }
    if(v1 > v3) {
      int temp = v3;
      v3 = v1;
      v1 = temp;
    }
    if(v1 > v4) {
      int temp = v4;
      v4 = v1;
      v1 = temp;
    }
    if(v2 > v3) {
      int temp = v3;
      v3 = v2;
      v2 = temp;
    }
    if(v2 > v4) {
      int temp = v4;
      v4 = v2;
      v2 = temp;
    }
    if(v3 > v4) {
      int temp = v4;
      v4 = v3;
      v3 = temp;
    }
    printf("Valores em ordem crescente: ");
    printf("%i, %i, %i e %i", v1, v2, v3, v4);
    printf("\n");
    printf("Valores em ordem decrescente: ");
    printf("%i, %i, %i e %i", v4, v3, v2, v1);

  return 0;
}