#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD.h"

int main()
{
    int opc, key=0;

    INFO iC1;
    INFO iC2;
    ADDR eC1;
    ADDR eC2;

    while (opc != 6)
    {
        printf("-----// MENU //-----\n");
        printf("1- Inicializacoes\n");
        printf("2- Printar Informacoes\n");
        printf("3- \n");
        printf("4- \n");
        printf("5- \n");
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

                printf("Informe o numero de conjuntos da Cache de Nivel 1: ");
                scanf("%i", &iC1.Num_Conjs);
                //printf("Informe o numero de conjuntos da Cache de Nivel 2: ");
                //scanf("%i", &iC2.Num_Conjs);
                iC1.Bytes_Palavra = 4;
                //iC2.Bytes_Palavra = 4;
                iC1.Palavra_Bloco = 4;
                //iC2.Palavra_Bloco = 4;

                iC1.Tam_Bloco = iC1.Bytes_Palavra * iC1.Palavra_Bloco;

                printf("Informe o numero de vias da Cache de Nivel 1: ");
                scanf("%i", &iC1.Vias);
                
                iC1.Capac_Conj = iC1.Vias * iC1.Tam_Bloco;
                iC1.Capac_User = iC1.Num_Conjs * iC1.Capac_Conj;

                iC1.Tam_Endereco = 32;
                
                eC1.Byte_Offset = log2(iC1.Bytes_Palavra);
                eC1.Word_Offset = log2(iC1.Palavra_Bloco);
                eC1.Index = log2(iC1.Num_Conjs);
                eC1.V_Bit = 1;
                eC1.Dirt = 1;
                if (iC1.Vias > 1)
                    eC1.LRU = 1;
                else
                    eC1.LRU = 0;

                eC1.Tag = iC1.Tam_Endereco - eC1.Index - eC1.Word_Offset - eC1.Byte_Offset;

                iC1.Tam_Overhead = iC1.Num_Conjs * (iC1.Vias * (eC1.Tag + eC1.V_Bit + eC1.Dirt + eC1.LRU));

                iC1.Tam_MemTotal = iC1.Capac_User + iC1.Tam_Overhead;

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

                printf("Bytes por Palavra: ");
                printf("%i\n", iC1.Bytes_Palavra);
                printf("Palavras por Bloco: ");
                printf("%i\n", iC1.Palavra_Bloco);
                printf("Tamanho do Bloco: ");
                printf("%i\n", iC1.Tam_Bloco);
                printf("Numero de Vias: (Informado)");
                printf("%i\n", iC1.Vias);
                printf("Capacidade de um Conjunto: ");
                printf("%i\n", iC1.Capac_Conj);
                printf("Numero de Conjuntos (Informado): ");
                printf("%i\n", iC1.Num_Conjs);
                printf("Capacidade do Usuario: ");
                printf("%i\n\n", iC1.Capac_User);
                printf("Tamanho do Endereço: ");
                printf("%i\n\n", iC1.Tam_Endereco);


                printf("Byte Offset: ");
                printf("%i\n", eC1.Byte_Offset);
                printf("Word Offset: ");
                printf("%i\n", eC1.Word_Offset);
                printf("Index: ");
                printf("%i\n", eC1.Index);
                printf("Bit de Validade: ");
                printf("%i\n", eC1.V_Bit);
                printf("Bit de LRU (Least Recently Used): ");
                printf("%i\n", eC1.LRU);
                printf("Bit de Dirt (Write-Back): ");
                printf("%i\n", eC1.Dirt);

                printf("Tag: ");
                printf("%i\n", eC1.Tag);

                printf("Tamanho do Overhead: ");
                printf("%i\n", iC1.Tam_Overhead);
                printf("Tamanho da Memoria Total: ");
                printf("%i\n", iC1.Tam_MemTotal);

                fflush(stdin);
                printf("\nPressione Enter para voltar. . . ");
                key = getchar();
            }
            key = 0;
            break;

        case 3:
            
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
