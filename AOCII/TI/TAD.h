typedef struct info
{
    int Tam_Endereco;
    int Bytes_Palavra;
    int Palavra_Bloco;
    int Tam_Bloco;
    int Vias;
    int Capac_User;
    int Capac_Conj;
    int Num_Conjs;
    float Tam_Overhead;
    float Tam_MemTotal;
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
