struct _telefone
{
    int DDD;
    long int numero;
};
struct _aniversario
{
    int dia;
    int mes;
    int ano;
};
typedef struct _agenda
{
    char nome[32];
    char email[32];
    struct _telefone telefone;
    struct _aniversario aniversario;
    char obs[64];
}cadastro;
cadastro agenda[10];
int i;
void cadastrar();
void buscaNome();
void buscaMes();
void imprimeAgenda();
