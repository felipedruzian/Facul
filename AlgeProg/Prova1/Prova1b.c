#include <stdio.h>
#include <stdlib.h>

int main() {

    float c1, c2, c3, c4, f1, f2, f3, f4;
    int opcao;

    printf(" \n ");
    printf("Informe as 4 temperaturas em Celsius: \n");
    printf("Temperatura da madrugada: ");
    scanf("%f", &c1);
    printf("Temperatura da manha: ");
    scanf("%f", &c2);
    printf("Temperatura da tarde: ");
    scanf("%f", &c3);
    printf("Temperatura da noite: ");
    scanf("%f", &c4);


    printf("        ***** MENU **** \n");
    printf("1. Temperaturas em Fahrenheit (F) \n");
    printf("2. Menor temperatura do dia (C)\n");
    printf("3. Listagem das temperaturas em F (ordem crescente)\n");
    printf("        ****************\n");
    printf(" \n");
    printf("Selecione uma opcao: ");
    scanf("%i", &opcao);


    switch (opcao) {

        case 1:
            
            f1 = ((c1*9)/5)+32;
            f2 = ((c2*9)/5)+32;
            f3 = ((c3*9)/5)+32;
            f4 = ((c4*9)/5)+32;

            printf("Temperaturas em Fahrenheit: \n");
            printf("Madrugada\t Manha \t\t Tarde \t\t  Noite \n");
            printf("%.2f F \t %.2f F \t %.2f F \t %.2f F", f1, f2, f3, f4);
            
        break;

        case 2:

            if (c1 < c2 && c1 < c3 && c1 < c4) {
                printf("A menor temperatura foi durante a madrugada: %.2f C", c1);
            }
            if (c2 < c1 && c2 < c3 && c2 < c4) {
                printf("A menor temperatura foi durante a manha: %.2f C", c2);
            }
            if (c3 < c1 && c3 < c2 && c3 < c4) {
                printf("A menor temperatura foi durante a tarde: %.2f C", c3);
            }
            if (c4 < c1 && c4 < c2 && c4 < c3) {
                printf("A menor temperatura foi durante a noite: %.2f C", c4);
            }

        break;

        case 3:
            
            f1 = ((c1*9)/5)+32;
            f2 = ((c2*9)/5)+32;
            f3 = ((c3*9)/5)+32;
            f4 = ((c4*9)/5)+32;
            
            if(f1 > f2) {
                float temp = f2; //cria e define o valor temporario o mesmo de f2
                f2 = f1; //define o valor de f2 o mesmo de f1
                f1 = temp; //defino o valor de f1 o do temporario (antigo valor de f2)
            }
            if(f1 > f3) {
                float temp = f3;
                f3 = f1;
                f1 = temp;
            }
            if(f1 > f4) {
                float temp = f4;
                f4 = f1;
                f1 = temp;
            }
            if(f2 > f3) {
                float temp = f3;
                f3 = f2;
                f2 = temp;
            }
            if(f2 > f4) {
                float temp = f4;
                f4 = f2;
                f2 = temp;
            }
            if(f3 > f4) {
                float temp = f4;
                f4 = f3;
                f3 = temp;
            }
            printf("Temperaturas em Fahrenheit em ordem crescente: ");
            printf("%.2f F, %.2f F, %.2f F  e  %.2f F", f1, f2, f3, f4);
        break;
    }
    
    printf("\n");
    system("pause");
    return 0;
}