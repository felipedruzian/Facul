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

#define VALIDO   1
#define INVALIDO 0

//cores
#define VERMELHO    "\x1b[31m"
#define VERDE       "\x1b[32m"
#define AZUL        "\x1b[34m"
#define MAGENTA     "\033[95m"
#define AMARELO     "\033[33m"
#define CIANO       "\033[96m"
#define RESET       "\x1b[0m"

int players,numSorteado,x,y,z,i,contaAcertos[4],aux=0,contaSorteados=0,numSorteados[99],proxSort;
char cartela[4][5][5],player1[5][5],player2[5][5],player3[5][5],player4[5][5];

int Sorteio(int x) {
    
    int status;

    while(proxSort < contaSorteados) {

        do {
            numSorteados[proxSort] = (rand() % 98)+1;
            status = VALIDO;
            for (int j = 0; j < proxSort; j++) {
                if (numSorteados[proxSort] == numSorteados[j]) {
                    status = INVALIDO;
                }
            }
        } while (status == INVALIDO);   

        /*print pra ver o vetor inteiro dos numeros ja sorteados
        for (int u = 0; u <= proxSort; u++)
        {
            printf("%d ", numSorteados[u]);
        }
        */
       
       x = numSorteados[proxSort];
       proxSort++;
    }
    
    return x;
}
char geraMatriz(char i){
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            cartela[i][x][y]=(rand() % 98)+1;
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(x==2 && y==2){
                cartela[i][2][2]=0;
            }
            printf("%i \t",cartela[i][x][y]);
        }
        printf("\n");
    }
    return 0;
}
char confereAcerto(char i){
  switch (i){
    case 1:
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[1][x][y]==numSorteado){
                cartela[1][x][y]=aux;
                contaAcertos[1]+=1;
            }
        }
    }
      printf(AMARELO "============ CARTELA P1 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[1][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf("Acerto do P1: %i",contaAcertos[1]);
      
    break;

    case 2:
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[1][x][y]==numSorteado){
                cartela[1][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[2][x][y]==numSorteado){
                cartela[2][x][y]=aux;
            }
        }
    }
      printf(AMARELO "============ CARTELA P1 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[1][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(AZUL "============ CARTELA P2 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[2][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
    break;

    case 3:
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[1][x][y]==numSorteado){
                cartela[1][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[2][x][y]==numSorteado){
                cartela[2][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[3][x][y]==numSorteado){
                cartela[3][x][y]=aux;
            }
        }
    }
      printf(AMARELO "============ CARTELA P1 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[1][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(AZUL "============ CARTELA P2 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[2][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(MAGENTA "============ CARTELA P3 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[3][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
    break;

    case 4:
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[1][x][y]==numSorteado){
                cartela[1][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[2][x][y]==numSorteado){
                cartela[2][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[3][x][y]==numSorteado){
                cartela[3][x][y]=aux;
            }
        }
    }
    for (x=0; x<5; x++){
        for (y=0; y<5; y++){
            if(cartela[4][x][y]==numSorteado){
                cartela[4][x][y]=aux;
            }
        }
    }
      printf(AMARELO "============ CARTELA P1 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[1][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(AZUL "============ CARTELA P2 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[2][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(MAGENTA "============ CARTELA P3 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[3][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
      printf(CIANO "============ CARTELA P4 ============\n");
      for (x=0; x<5; x++){
          for (y=0; y<5; y++){
              printf("%i \t",cartela[4][x][y]);
          }
          printf("\n");
      }
      printf("============ ********** ============" RESET "\n");
    break;
  }
    return 0;
}
int sorteiaEnter(int i) {
    int tecla, x;
    
    printf("Pressione enter para sortear um numero | Numeros ja sorteados: %i\n",contaSorteados);
    do{
        tecla = getchar();
        if (tecla !=13) {
            //conta numeros sorteados
            contaSorteados+=1;
            printf("Pressione enter para sortear um novo numero | Numeros ja sorteados: %i\n",contaSorteados);
        
        // sorteio
        numSorteado = Sorteio(x);
        printf("\n\nO numero sorteado foi: %i\n\n",numSorteado);
        //fim sorteio
        //conferencia
        if(i==1){
          confereAcerto(1);
        }else if(i==2){
          confereAcerto(2);
        }else if(i==3){
          confereAcerto(3);
        }else if(i==4){
          confereAcerto(4);
        }
        //fim
        }
    } while(tecla != 13);
    return 0;
}
void mensagem_importante(){
    do
    {
        printf(VERDE "=========== BINGO EC11 ===========" RESET "\n");
        printf("Informe o numero de jogadores: (1 - 4): ");
        scanf("%i",&players);
        printf(VERDE "=========== ********** ===========" RESET "\n");

        //mensagem se informar numero de jogadores incorreto
        if(players>4 || players <1){
        printf(VERMELHO "\t=========== ********** ===========\n");
        printf("Voce informou uma quantidade invalida de jogadores!\n");
        printf("\t=========== ********** ==========="RESET"\n");
    }
    }while(players>4 || players <1);
}
void linhaFim(){
    printf("============ ********** ============" RESET "\n");
}
int main() {
    mensagem_importante();
    srand(time(NULL));
    
    switch (players){
        case 1:
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            linhaFim();
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            sorteiaEnter(1);
        break;
        case 2:
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            linhaFim();
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            linhaFim();
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            sorteiaEnter(2);
        break;
        case 3:
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            linhaFim();
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            linhaFim();
            printf(MAGENTA "============ CARTELA P3 ============\n");
                geraMatriz(3);
            linhaFim();
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");

            sorteiaEnter(3);
        break;
        case 4: 
            printf(VERMELHO "***************** CARTELAS GERADAS *****************" RESET "\n");
            printf(AMARELO "============ CARTELA P1 ============\n");
                geraMatriz(1);
            linhaFim();
            printf(AZUL "============ CARTELA P2 ============\n");
                geraMatriz(2);
            linhaFim();
            printf(MAGENTA "============ CARTELA P3 ============\n");
                geraMatriz(3);
            linhaFim();
            printf(CIANO "============ CARTELA P4 ============\n");
                geraMatriz(4);
            linhaFim();
            printf(VERMELHO "***************** COMECANDO SORTEIO *****************" RESET "\n");
            
            sorteiaEnter(4);
        break;
    }
    system("pause");
    return 0;
}


