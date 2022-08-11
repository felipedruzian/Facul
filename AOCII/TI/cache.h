typedef struct INFO_CACHE
{
    int Tam_Endereco;
    int Bytes_Palavra;
    int Palavra_Bloco;
    int Tam_Bloco;
    int Vias;
    int Capac_Conj;
    int Num_Conjs;
    float Capac_User;
    float Tam_Overhead;
    float Tam_MemTotal;
    int Byte_Offset;
    int Word_Offset;
    int Index;
    int Tag;
    int Bit_Valid; 
    int Bit_Dirt;
} info_c;

typedef struct CACHE
{
    int Byte_Offset;
    int Word_Offset;
    int Index;
    int Tag;
    int V_Bit; 
    int Dirt;
} cache;

typedef struct RAM
{
    int Byte_Offset;
    int Word_Offset;
    int Bloco;
} ram;

info_c ic; //infos da cache

//cache c1[ic.Num_Conjs];

void init_info(int conjs, int vias);
void infoCachePrint();
