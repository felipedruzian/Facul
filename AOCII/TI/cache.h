#define BytePalavra 4
#define PalavraBloco 4
#define TamEndereco 32
#define BitsVeD 1

///////////mips
typedef struct MipsInstruct
{
    char opcode[4];
    char rs[4];
    char rt[4]; 
    char rd[4];
    int immed;
} instruct;

typedef struct Registradores
{
	char nome[3];
    int valor;
} regs;

///////////cache
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
    int Byte_Offset[BytePalavra];
    int Word_Offset[PalavraBloco];
    int Index; 
    int Tag;
    int Bit_Valid; 
    int Bit_Dirt; 
    int CounteudoData[PalavraBloco];
    instruct ConteudoInstr[PalavraBloco];
} cache;

typedef struct INFO_RAM
{
    int Byte_Offset;
    int Word_Offset; 
    int Num_Conjs;
    int Bloco_Offset;
    int Tag_Offset;
    int Index_Offset;
} info_r;

typedef struct RAM
{
    int Byte_Offset[BytePalavra];
    int Word_Offset[PalavraBloco];
    int Bloco;
    int CounteudoData[PalavraBloco];
    instruct ConteudoInstr[PalavraBloco];
} ram;

info_c ic; //infos da cache
info_r ir; // infos da ram
cache* c1;
ram* r1;

FILE* instructionsFile;

regs mipsReg[32];
int quant_instruc, pc;
instruct* Instructions;

//mips
void init_mips_regs();
void MIPS_print();
void init_instructions();
//caches
void init_info(int conjs, int vias);
void infoCachePrint();
void init_cache();
void load_RAM();
void RAM_print();
void CACHE_print();
void pull(int i);
void processor();
void inst_lw(int bloco, int word);
void inst_add(int bloco, int word);
void processor2();
