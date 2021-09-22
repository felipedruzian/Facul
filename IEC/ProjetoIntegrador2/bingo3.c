/*• Escolha do numero de jogadores (N - máximo 4 jogadores) -- OK
• Sortear e apresentar na tela as tabelas de cada jogador -- OK
• A tecla “enter” sorteia o número -- OK
• Marcar os acertos na tabela de cada jogador -- OK
• Identificar (duque, terno, quadra, quina e bingo)
• O jogo deve usar estruturas de LAÇO que permitam reiniciar o
jogo antes de finalizar o programa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//cores
#define VERMELHO    "\x1b[31m"
#define VERDE       "\x1b[32m"
#define AZUL        "\x1b[34m"
#define MAGENTA     "\033[95m"
#define AMARELO     "\033[33m"
#define CIANO       "\033[96m"
#define RESET       "\x1b[0m"

//estados do numero sorteado
#define VALIDO   1
#define INVALIDO 0

//Variaveis globais
int players, numSorteados[99], contaSorteados=0, proxSorteado=0, numSorteado;
char cartela[4][5][5];


int Sorteio(int x) {
    int status;

    while(proxSorteado < contaSorteados) {

        do {
            numSorteados[proxSorteado] = (rand() % 98)+1;
            status = VALIDO;
            for (int j = 0; j < proxSorteado; j++) {
                if (numSorteados[proxSorteado] == numSorteados[j]) {
                    status = INVALIDO;
                }
            }
        } while (status == INVALIDO);
        /*print pra ver o vetor inteiro dos numeros ja sorteados
        for (int u = 0; u <= proxSorteado; u++)
        {
            printf("%d ", numSorteados[u]);
        }
        */
       x = numSorteados[proxSorteado];
       proxSorteado++;
    }
    return x;
}
void sorteiaEnter() {
    int tecla, x;
    
    printf("Pressione enter para sortear um numero | Numeros ja sorteados: %i\n",contaSorteados);
    scanf("%c", &tecla);
    
    while(contaSorteados<100){
        tecla = getchar();
        if (tecla !=13) {
            
            //conta numeros sorteados
            contaSorteados+=1;
            printf("Pressione enter para sortear um novo numero | Numeros ja sorteados: %i\n",contaSorteados);
            // sorteio

            numSorteado = Sorteio(x);
            printf("\nO numero sorteado foi: %i\n\n",numSorteado);
            //fim sorteio

        }
    } 
    //return 0;
}
char geraMatriz(char i){
    i-=1;
    for (int x=0; x<5; x++){
        for (int y=0; y<5; y++){
            cartela[i][x][y]=(rand() % 98)+1;
        }
    }
    for (int x=0; x<5; x++){
        for (int y=0; y<5; y++){
            if(x==2 && y==2){
                printf("X \t",cartela[i][x][y]);
            }else{
            printf("%i \t",cartela[i][x][y]);
            }
        }
        printf("\n");
    }
    return 0;
}
void mensagem_importante(){
    system("cls");
    do
    {
        printf(VERDE "=========== BINGO EC11 ===========" RESET "\n");
        printf("Informe o numero de jogadores: (1 - 4): ");
        scanf("%i",&players);
        printf(VERDE "=========== ********** ===========" RESET "\n");

        //mensagem se informar numero de jogadores incorreto
        if(players>4 || players <1){
            system("cls");
            printf(VERMELHO "\t=========== ********** ===========\n");
            printf("Voce informou uma quantidade invalida de jogadores!\n");
            printf("\t=========== ********** ==========="RESET"\n");
        }
    }while(players>4 || players <1);
}


int main() {

    mensagem_importante();
    srand(time(NULL));
    
    switch (players){
        case 1:
            system("cls");
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            printf("============ ********** ============" RESET "\n");
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            sorteiaEnter();
        break;
        case 2:
            system("cls");
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            printf("============ ********** ============" RESET "\n");
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            printf("============ ********** ============" RESET "\n");
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            //sorteiaEnter(2);
        break;
        case 3:
            system("cls");
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            printf("============ ********** ============" RESET "\n");
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            printf("============ ********** ============" RESET "\n");
            printf(MAGENTA "============ CARTELA P3 ============\n");
                geraMatriz(3);
            printf("============ ********** ============" RESET "\n");
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            //sorteiaEnter(3);
        break;
        case 4: 
            system("cls");
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            printf("============ ********** ============" RESET "\n");
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            printf("============ ********** ============" RESET "\n");
            printf(MAGENTA "============ CARTELA P3 ============\n");
                geraMatriz(3);
            printf("============ ********** ============" RESET "\n");
            printf(CIANO "============ CARTELA P4 ============\n");
                geraMatriz(4);
            printf("============ ********** ============" RESET "\n");
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");
            
            //sorteiaEnter(4);
        break;
    }
    system("pause");
    return 0;
}
