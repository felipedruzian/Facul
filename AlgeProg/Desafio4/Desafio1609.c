/*
Implemente um sistema para o armazenamento de números.
Este software poderá armazenar até 100 valores em sua estrutura.
O seguinte menu deverá ser disponibilizado para o usuário:

*** MENU***
1. Inserir valor
2. Listar Valores
3. Sair

Requisitos:
* o sistema deverá permanecer no menu, até a opção Sair ser escolhida.
* O usuário poderá inserir valores a qualquer momento, sem perder valores já informados.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float valores[100], stop=1;
    int menu=0, i=0, u=0;

    
    while (menu != 3)
    {
    
    printf("\n\n*** MENU***\n");
    printf("1. Inserir valor\n");
    printf("2. Listar Valores\n");
    printf("3. Sair\n");

    scanf("%i", &menu);

        switch (menu)
        {
        case 1:
            printf("Digite 0 para voltar ao menu!\n");
            while (stop != 0)
            {
                printf("\nInforme o valor [%i]: ", i+1);
                scanf("%f", &valores[i]); 
                if (valores[i] == 0)
                {
                    stop = valores[i];
                }else{
                    i++;
                    u = i;
                }
            }
            stop=1;
            break;
            

        case 2:
            printf("\nNumeros digitados: \n");
            for (i = 0; i < u; i++) {
                printf("\nValor [%i]:\t %.1f \t", i+1, valores[i]);
            }
            break;

        case 3:
            printf("\nFinalizando o programa. . .\n");
            break;
    
        default:
            printf("\nDigite um numero do menu!\n");
            break;
        }

        
    }


    printf("\nFim do Programa!\n");
    system("pause");
    return 0;
}
