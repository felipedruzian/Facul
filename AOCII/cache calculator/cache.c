#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cache.h"
#define BytePalavra 4
#define PalavraBloco 4
#define TamEndereco 32
#define BitsVeD 1

void init_info(int conjs, int vias)
{
    ic.Bytes_Palavra = PalavraBloco;
    ic.Palavra_Bloco = BytePalavra;
    ic.Tam_Bloco = ic.Bytes_Palavra * ic.Palavra_Bloco;

    ic.Num_Conjs = conjs;
    ic.Vias = vias;
    ic.Capac_Conj = ic.Vias * ic.Tam_Bloco;
    ic.Capac_User = ic.Num_Conjs * ic.Capac_Conj; //Capacidade do User em bytes

    ic.Tam_Endereco = TamEndereco;
    ic.Byte_Offset = log2(ic.Bytes_Palavra);
    ic.Word_Offset = log2(ic.Palavra_Bloco);
    ic.Index = log2(ic.Num_Conjs);
    ic.Bit_Valid = BitsVeD;
    ic.Bit_Dirt = BitsVeD;
    ic.Tag = ic.Tam_Endereco - ic.Index - ic.Word_Offset - ic.Byte_Offset;

    ic.Tam_Overhead = ic.Num_Conjs * (ic.Vias * (ic.Tag + ic.Bit_Valid + ic.Bit_Dirt)); //bits
    ic.Tam_Overhead /= 8; //Overhead em bytes
    ic.Tam_Overhead /= 1024; //Overhead em KB
    ic.Capac_User /= 1024; //Capacidade do User em KB
    ic.Tam_MemTotal = ic.Capac_User + ic.Tam_Overhead; //Memoria Total em KB
}

void infoCachePrint()
{
    printf("Bytes por Palavra: ");
    printf("%i\n", ic.Bytes_Palavra);
    printf("Palavras por Bloco: ");
    printf("%i\n", ic.Palavra_Bloco);
    printf("Tamanho do Bloco: ");
    printf("%i\n", ic.Tam_Bloco);
    printf("Numero de Vias (Informado): ");
    printf("%i\n", ic.Vias);
    printf("Capacidade de um Conjunto: ");
    printf("%i\n", ic.Capac_Conj);
    printf("Numero de Conjuntos (Informado): ");
    printf("%i\n", ic.Num_Conjs);
    printf("Capacidade do Usuario: ");
    printf("%.2f KB - ", ic.Capac_User);
    printf("%.0f bytes\n", ic.Capac_User*1024);
    printf("Tamanho do Overhead: ");
    printf("%.2f KB - ", ic.Tam_Overhead);
    printf("%.0f bytes\n", ic.Tam_Overhead*1024);
    printf("Tamanho da Memoria Total: ");
    printf("%.2f KB - ", ic.Tam_MemTotal);
    printf("%.0f bytes\n\n", ic.Tam_MemTotal*1024);

    printf("Tamanho do Endereco: ");
    printf("%i\n", ic.Tam_Endereco);
    printf("Byte Offset: ");
    printf("%i\n", ic.Byte_Offset);
    printf("Word Offset: ");
    printf("%i\n", ic.Word_Offset);
    printf("Index: ");
    printf("%i\n", ic.Index);
    printf("Tag: ");
    printf("%i\n", ic.Tag);
    printf("Bit de Validade: ");
    printf("%i\n", ic.Bit_Valid);
    printf("Bit de Bit_Dirt (Write-Back): ");
    printf("%i\n", ic.Bit_Dirt);
}