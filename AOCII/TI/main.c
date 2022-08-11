#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cache.h"

int main()
{
    int opc, key=0;
    int conjs, vias;
    

    while (opc != 6)
    {
        printf("-----// MENU //-----\n");
        printf("1- Inicializacoes\n");
        printf("2- Printar Informacoes\n");
        printf("3- \n");    // --> vetor da cache e RAM     // como ler diferentes informacoes (cat?)
        printf("4- \n");    // --> registradores do MIPS    // como relacionar a cache com registradores mips?
        printf("5- \n");    // --> funcoes de instrucoes
        printf("6- Sair \n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%i", &opc);
        
        switch (opc)
        {
        case 1:
            while (key != 10)
            {
                system("cls");

                printf("Informe o numero de conjuntos da Cache: "); // de 2 a 8  (8 recom.)
                scanf("%i", &conjs);
                printf("Informe o numero de vias da Cache: "); // 1 a 2 recomendado
                scanf("%i", &vias);

                init_info(conjs, vias);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 2:
            while (key != 10)
            {
                system("cls");

                infoCachePrint(); 

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 3:
            
            // vetor da struct cache. ou calculo da ram
            // ler arquivo com assembly mips 
            // decimal -> bin?
            // como implementar a comunicacao entre cache e ram (enderecos)

            break;

        case 4:
            
            break;

        case 5:
            
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}
