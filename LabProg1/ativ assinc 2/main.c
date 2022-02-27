#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main()
{
    int opc=0, tecla=0;
    while (opc != 5)
    {
        system("cls");
        printf("MENU:\n");
        printf("1. Cadastrar\n");
        printf("2. Buscar por nome\n");
        printf("3. Buscar por mes de aniversario\n");
        printf("4. Mostra agenda\n");
        printf("5. Sair\n");
        scanf("%i", &opc);
        fflush(stdin);
        switch (opc)
        {
        case 1:
            while (tecla != 10) {
                system("cls");
                
                cadastrar();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;
        
        case 2:
            while (tecla != 10) {
                system("cls");
                
                buscaNome();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 3:
            while (tecla != 10) {
                system("cls");
                
                buscaMes();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 4:
            while (tecla != 10) {
                system("cls");
                
                imprimeAgenda();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                tecla = getchar();
            }
            tecla = 0;
            break;

        default:
            break;
        }
    }
    

    return 0;
}