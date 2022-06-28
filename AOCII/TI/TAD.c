#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    int Tam_Endereco;
    int Bytes_Palavra;
    int Palavra_Bloco;
    int Tam_Bloco;
    int Vias;
    int Capac_User;
    int Capac_Conj;
    int Tam_Conj;
    int Num_Conjs;
    int Tam_Overhead;
    int Tam_MemTotal;
} INFO;

typedef struct address
{
    int Byte_Offset;
    int Word_Offset;
    int Index;
    int Tag;
    int V_Bit; 
    int LRU;
    int Dirt;
} ADDR;

