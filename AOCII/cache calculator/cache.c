#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    int Tam_Endereco;
    int Bytes_Palavra;
    int Palavra_Bloco;
    int Tam_Bloco;
    int Vias;
    float Capac_User;
    int Capac_Conj;
    int Num_Conjs;
    float Tam_Overhead;
    float Tam_MemTotal;
} INFO;

typedef struct address
{
    int Byte_Offset; //00 - 01 - 10 - 11  ->  0 - 3
    int Word_Offset;
    int Index;
    int Tag;
    int V_Bit; 
    int Dirt;
} ADDR;

typedef struct cache_data
{
    int Byte_Offset;
    int Word_Offset;
    int Index;
    int Tag;
    int V_Bit; 
    int Dirt;
} cache_d;

typedef struct cache_instr
{
    int Byte_Offset;
    int Word_Offset;
    int Index;
    int Tag;
    int V_Bit; 
    int Dirt;
} cache_i;

typedef struct RAM
{
    int Byte_Offset;
    int Word_Offset;
    int Bloco;
} ram;
