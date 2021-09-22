#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VALIDO   1
#define INVALIDO 0

int contaSorteados=0;
int numSorteados[99];
int i=0;


int Sorteio(int x) {
    
    int status;

    while(i < contaSorteados) {

        do {
            numSorteados[i] = (rand() % 98)+1;
            status = VALIDO;
            for (int j = 0; j < i; j++) {
                if (numSorteados[i] == numSorteados[j]) {
                    status = INVALIDO;
                }
            }
        } while (status == INVALIDO);   

        /*print pra ver o vetor inteiro dos numeros ja sorteados
        for (int u = 0; u <= i; u++)
        {
            printf("%d ", numSorteados[u]);
        }
        */
       
       x = numSorteados[i];
       i++;
    }
    
    return x;
}

void sorteiaEnter() {
    int tecla, numSorteado, x;
    
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
        
        }
    } while(tecla != 13);
    //return 0;
}

int main()
{

    srand(time(NULL));
    sorteiaEnter();

    return 0;
}
