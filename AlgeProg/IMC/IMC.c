/* Crie um programa que receba o nome mais os dados para o calculo do Índice de 
Massa Corporal (IMC) de 2 indivíduos e:

    * Apresente na tela o resultado do IMC para cada indivíduo (com base na Tabela de 
    resultados - IMC mostrar a Classificação).
    * Apresente na tela o nome dos indivíduos que se enquadraram como "Peso normal"

Tabela de resultados - IMC
IMC                                   Classificação (Mostrar na tela)
Menos do que 18,5   ->   Abaixo do peso    (Ap)
Entre 18,5 e 24,9   ->   Peso normal       (Pn)
Entre 25 e 29,9     ->   Sobrepeso         (Sp)
Entre 30 e 34,9     ->   Obesidade grau 1  (Ob)
*/

#include <stdio.h>

int main() {

    float imc1, imc2, p1, p2, a1, a2;
    char nome1[20], nome2[20];

    imc1=imc2=p1=p2=a1=a2=0;

    printf("\n   Tabela de resultados - IMC \n");
    printf("Menos do que 18,5   ->   Abaixo do peso \n");
    printf("Entre 18,5 e 24,9   ->   Peso normal \n");
    printf("Entre 25 e 29,9     ->   Sobrepeso \n");
    printf("Entre 30 e 34,9     ->   Obesidade grau 1 \n");
    
    printf("\n \n");

    printf("Digite o nome da primeira pessoa: ");
    scanf("%s", nome1);
    printf("Digite o peso da primeira pessoa: ");
    scanf("%f", &p1);
    printf("Digite a altura da primeira pessoa: ");
    scanf("%f", &a1);
    printf("Digite o nome, peso e altura da segunda pessoa: ");
    scanf("%s", nome2);
    printf("Digite o peso da segunda pessoa: ");
    scanf("%f", &p2);
    printf("Digite a altura da segunda pessoa: ");
    scanf("%f", &a2);

    imc1 = p1/(a1*a1);
    imc2 = p2/(a2*a2);

    /*condicoes:
    imc1 Ap    imc1 < 18.5
    imc2 Ap    imc2 < 18.5
    imc1 Pn    imc1 >= 18.5 && imc1 <= 24.9 
    imc2 Pn    imc2 >= 18.5 && imc2 <= 24.9
    imc1 Sp    imc1 >= 25 && imc1 <= 29.9
    imc2 Sp    imc2 >= 25 && imc2 <= 29.9
    imc1 Ob    imc1 >= 30 && imc1 <= 34.9
    imc2 Ob    imc2 >= 30 && imc2 <= 34.9
    */

   // imc1 Ap e imc2 Ap/Pn/Sp/Ob
    if (imc1 < 18.5 && imc2 < 18.5) {
        //printf ("imc1 Ap e imc2 Ap");
        printf("%s e %s estao Abaixo do peso.", nome1, nome2);
    }
    if (imc1 < 18.5 && imc2 >= 18.5 && imc2 <= 24.9) {
        //printf ("imc1 Ap e imc2 Pn");
        printf("%s esta Abaixo do peso e %s tem Peso normal.", nome1, nome2);
    }
    if (imc1 < 18.5 && imc2 >= 25 && imc2 <= 29.9) {
        //printf ("imc1 Ap e imc2 Sp");
        printf("%s esta Abaixo do peso e %s tem Sobrepeso.", nome1, nome2);
    }
    if (imc1 < 18.5 && imc2 >= 30 && imc2 <= 34.9) {
        //printf ("imc1 Ap e imc2 Ob");
        printf("%s esta Abaixo do peso e %s tem Obesidade de grau 1.", nome1, nome2);
    }

    // imc1 Pn e imc2 Ap/Pn/Sp/Ob
    if (imc1 >= 18.5 && imc1 <= 24.9 && imc2 < 18.5) {
        //printf ("imc1 Pn e imc2 Ap");
        printf("%s tem Peso normal e %s esta Abaixo do peso.", nome1, nome2);
    }
    if (imc1 >= 18.5 && imc1 <= 24.9 && imc2 >= 18.5 && imc2 <= 24.9) {
        //printf ("imc1 Pn e imc2 Pn");
        printf("%s e %s estao com Peso normal.", nome1, nome2);
    }
    if (imc1 >= 18.5 && imc1 <= 24.9 && imc2 >= 25 && imc2 <= 29.9) {
        //printf ("imc1 Pn e imc2 Sp");
        printf("%s tem Peso normal e %s tem Sobrepeso.", nome1, nome2);
    }
    if (imc1 >= 18.5 && imc1 <= 24.9 && imc2 >= 30 && imc2 <= 34.9) {
        //printf ("imc1 Pn e imc2 Ob");
        printf("%s tem Peso normal e %s tem Obesidade de grau 1.", nome1, nome2);
    }

    // imc1 Sp e imc2 Ap/Pn/Sp/Ob
    if (imc1 >= 25 && imc1 <= 29.9 && imc2 < 18.5) {
        //printf ("imc1 Sp e imc2 Ap");
        printf("%s tem Sobrepeso e %s esta Abaixo do peso.", nome1, nome2);
    }
    if (imc1 >= 25 && imc1 <= 29.9 && imc2 >= 18.5 && imc2 <= 24.9) {
        //printf ("imc1 Sp e imc2 Pn");
        printf("%s tem Sobrepeso e %s tem Peso normal.", nome1, nome2);
    }
    if (imc1 >= 25 && imc1 <= 29.9 && imc2 >= 25 && imc2 <= 29.9) {
        //printf ("imc1 Sp e imc2 Sp");
        printf("%s e %s estao com Sobrepeso.", nome1, nome2);
    }
    if (imc1 >= 25 && imc1 <= 29.9 && imc2 >= 30 && imc2 <= 34.9) {
        //printf ("imc1 Sp e imc2 Ob");
        printf("%s tem Sobrepeso e %s tem Obesidade de grau 1.", nome1, nome2);
    }

    // imc1 Ob e imc2 Ap/Pn/Sp/Ob
    if (imc1 >= 30 && imc1 <= 34.9 && imc2 < 18.5) {
        //printf ("imc1 Ob e imc2 Ap");
        printf("%s tem Obesidade de grau 1 e %s esta Abaixo do peso.", nome1, nome2);
    }
    if (imc1 >= 30 && imc1 <= 34.9 && imc2 >= 18.5 && imc2 <= 24.9) {
        //printf ("imc1 Ob e imc2 Pn");
        printf("%s tem Obesidade de grau 1 e %s tem Peso normal.", nome1, nome2);
    }
    if (imc1 >= 30 && imc1 <= 34.9 && imc2 >= 25 && imc2 <= 29.9) {
        //printf ("imc1 Ob e imc2 Sp");
        printf("%s tem Obesidade de grau 1 e %s tem Sobrepeso.", nome1, nome2);
    }
    if (imc1 >= 30 && imc1 <= 34.9 && imc2 >= 30 && imc2 <= 34.9) {
        //printf ("imc1 Ob e imc2 Ob");
        printf("%s e %s estao com Obesidade de grau 1.", nome1, nome2);
    }




    return 0;
}