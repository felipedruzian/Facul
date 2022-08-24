#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cache.h"

int main()
{
    int opc, key=0;
    int conjs, vias;
    

    while (opc != 7)
    {
        printf("-----// MENU //-----\n");
        printf("1- Inicializacoes\n");
        printf("2- Printar Informacoes\n");
        printf("3- Init Cache, Mips Registers, Instructs, Load RAM\n");
        printf("4- Prints\n");
        printf("5- RAM -> Cache\n");    // --> funcoes de instrucoes
        printf("6- Rodar instrucoes\n");    // --> funcoes de instrucoes
        printf("7- Sair \n");
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
            while (key != 10)
            {
                system("cls");

                init_cache();
                init_mips_regs();
                init_instructions();
                load_RAM();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 4:
            while (key != 10)
            {
                system("cls");

                RAM_print();
                CACHE_print();
                MIPS_print();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 5:
            while (key != 10)
            {
                system("cls");

                processor();
                c1[1].CounteudoData[0] = 20;
                mipsReg[18].valor = 30;

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 6:
            while (key != 10)
            {
                system("cls");

                printf("%d\n", c1[0].ConteudoInstr[0].immed);
                inst_lw(0,0);
                inst_add(0,1);
                //processor2();

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;
        
        default:
            // vetor da struct cache. ou calculo da ram
            // ler arquivo com assembly mips 
            // decimal -> bin?
            // como implementar a comunicacao entre cache e ram (enderecos)

            break;
        }
    }
    
    return 0;
}
