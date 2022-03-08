#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    int opc = 0, tecla = 0;
    while (opc != 4)
    {
        system("cls");
        printf("1. Incluir\n");
        printf("2. Mostrar\n");
        printf("3. Excluir\n");
        printf("4. Sair\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            while (tecla != 10)
            {
                system("cls");
                incluir(&topo);
                fflush(stdin);
                printf("\nEnter...\n");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 2:
            while (tecla != 10)
            {
                system("cls");
                mostrar(topo);
                fflush(stdin);
                printf("\nEnter...\n");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 3:
            while (tecla != 10)
            {
                system("cls");
                excluir(&topo);
                fflush(stdin);
                printf("\nEnter...\n");
                tecla = getchar();
            }
            tecla = 0;
            break;

        case 4:
            sair(&topo);
            break;

        case 6:
            while (tecla != 10)
            {
                system("cls");
                mostrarFull(topo);
                fflush(stdin);
                printf("\nEnter...\n");
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
