/*
Implemente um programa que popule com valores aleatórios (0-30) uma matriz quadrada de ordem 8. E:
a. Apresente a matriz na tela
b. Apresente na tela os elementos da DP
c. Ordene em ordem crescente os elementos da DP
d. Apresente na tela a matriz com a DP ordenada
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    
    int m[8][8], i=0, u=0;
    srand(time(NULL));

    for (i=0; i<8; i++)
    {
        for (u=0; u<8; u++)
        {
            m[i][u] = rand()%30;
        }

    }
    
    printf("Matriz: \n\n");
    for (i=0; i<8; i++)
    {
        for (u=0; u<8; u++)
        {
            printf("%i\t", m[i][u]);
        }
        printf("\n");
    }
   
   //ctrlc ctrlv pq bugou antes disso q ratiei

   //DP
  printf("\n\n");
  printf("Diagonal Principal \n");
  for(i=0; i<8; i++){
    printf("%i \t", m[i][i]);
  }

  //Ordenar DP
  for(i=0; i<8; i++){
    for(u=0; u<8; u++){
      if(m[i][i]<m[u][u]){
        int troca=m[i][i];
        m[i][i]=m[u][u];
        m[u][u]=troca;
      }
    }
  }

  //DP
  printf("\n\n");
  printf("Diagonal Principal Ordenada\n");
  for(i=0; i<8; i++){
    printf("%i \t", m[i][i]);
  }

  //Mostrar matriz DP ordenada
  printf("\n\n");
  printf("Matriz DP ordenada\n");
  for(i=0; i<8; i++){
    for(u=0; u<8; u++){
      printf("%i \t", m[i][u]);
    }
    printf("\n");
  }
    

    printf("\nFim do programa!\n");
    system("pause");
    return 0;
}