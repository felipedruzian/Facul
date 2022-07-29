#include "arquivo.h"


Grafo *grafo;

int main(void) {
  int op = 1, num_de_vertices, num_de_ligacoes_MAX, v1, v2, p1, orig, dest, x, y;

  printf("\nInforme o numero de vertices do Grafo: ");
  scanf("%d", &num_de_vertices);
  while(num_de_vertices <= 0){
    printf("\nO Grafo nao pode ter numero zero ou menos vertices...\nDigite novamente: ");
    scanf("%d", &num_de_vertices);
  }

  printf("\nInforme o numero de ligacoes do Grafo: ");
  scanf("%d", &num_de_ligacoes_MAX);
  while(num_de_ligacoes_MAX < 0){
    printf("\nO Grafo nao pode ter um numero de ligacoes menor que zero...\nDigite novamente: ");
    scanf("%d", &num_de_ligacoes_MAX);
  }

  //Vetor auxiliar para calculo de insercao com numero limite de arestas
  int vetor[num_de_ligacoes_MAX];

  for(x = 0; x < num_de_vertices; x++){
    vetor[x] = num_de_ligacoes_MAX;
  }

  grafo = CriaGrafo (num_de_vertices, num_de_ligacoes_MAX);
  printf ("\nGrafo criado.\n");


  while(op != 0){
    printf("\n************* MENU ***************\n\n");
    printf("1 - Insere Aresta\n");
	printf("2 - Imprime menor caminho destino fixo\n");
	printf("3 - Imprime menor caminho de todos os destinos\n");
	printf("4 - Imprime Grafo\n");
	printf("0 - Sair\n");
    printf("Escolha a opcao: ");
    scanf("%d", &op);
    while(op < 0 || op > 4){
      printf("Opcao invalida... Digite novamente: ");
      scanf("%d", &op);
    }

    switch(op){
      case 1:
      {
        if(num_de_ligacoes_MAX == 0){
          printf("Nao foi possivel completar essa acaoo... O grafo nao possui ligacoes!\n");
        }else{
          printf ("\nInsira o vertice de origem: ");
          scanf ("%d", &v1);
          while (v1 < 0 || v1 > num_de_vertices-1)
          {
            printf ("\nValor Invalido! Tente novamente entre: [%d - %d]", 0, num_de_vertices-1);
            printf ("\nInsira o vertice de origem: ");
            scanf ("%d", &v1);
          }

          printf ("\nInsira o vetice de destino: ");
          scanf ("%d", &v2);

          while (v2 < 0 || v2 > num_de_vertices-1)
          {
            printf ("\nValor Invalido! Tente novamente entre: [%d - %d]", 0, num_de_vertices-1);
            printf ("\nInsira o vertice de destino: ");
            scanf ("%d", &v2);
          }

          if (grafo->matriz[v1][v2] == 1)
          {
            printf ("Esta aresta ja existe.\n");
          }
          else
          {
          
            printf ("Insira o peso da aresta %d -> %d : ", v1, v2);
            scanf ("%d", &p1);
            while (p1 < 0)
            {
              printf ("\nDistancia invalida. Tente novamente!");
              scanf ("%d", &p1);
            }

            if (vetor[v1] == 0)
            {
              printf ("Nao foi possivel completar a acao. Numero maximo de arestas alcancado. \n");
              break;
            }
            else
            {
              vetor[v1]--;
            }

            InserirAresta (grafo, v1, v2, p1); 
            printf ("\nAresta Inserida com sucesso\n");
          }
        }
        break;
      }
    
      case 2:
      {
        printf ("\nInforme o vertice de origem: ");
        scanf ("%d", &orig);
        while (orig < 0 || orig > num_de_vertices-1)
        {
          printf ("\nValor Invalido! Tente novamente entre: [%d - %d]", 0, num_de_vertices-1);
          printf ("\nInsira o vertice de origem: ");
          scanf ("%d", &orig);
        }
        printf ("\nInforme o vertice de destino: ");
        scanf ("%d", &dest);
        while (dest < 0 || dest > num_de_vertices-1)
        {
          printf ("\nValor Invalido! Tente novamente entre: [%d - %d]", 0, num_de_vertices-1);
          printf ("\nInsira o vertice de origem: ");
          scanf ("%d", &dest);
        }

        MenorCaminho(grafo, num_de_vertices, orig, dest);
        break;
      }

      case 3:
      {
        printf ("\nInforme o vertice de origem: ");
        scanf ("%d", &orig);
         while (orig < 0 || orig > num_de_vertices-1)
        {
          printf ("\nValor Invalido! Tente novamente entre: [%d - %d]", 0, num_de_vertices-1);
          printf ("\nInsira o vertice de origem: ");
          scanf ("%d", &orig);
        }
        for (x=0; x < num_de_vertices; x++)
        {
          MenorCaminho(grafo, num_de_vertices, orig, x);
        }
        break;
      }
      case 4:
      {
        ImprimeGrafo(grafo, num_de_vertices);
        break;
      }
    }
  }
  printf("\nPrograma Encerrado!!!");

  return 0;
}