#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


void BubbleSort(int *pVetor, int n)
{
  int aux; 
  int i, j;
  
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (pVetor[i] > pVetor[j]) {
        aux = pVetor[i];
        pVetor[i] = pVetor[j];
        pVetor[j] = aux;
      }
    }
  }
}


void ShellSort(int *pVetor, int n)
{ 
  int i, j; 
  int h = 1;
  int aux;
  
  do 
    h = h * 3 + 1; 
  while (h < n);
  do { 
    h /= 3;
    for(i = h; i < n; i++) {
      aux = pVetor[i]; 
      j = i;
      while (pVetor[j-h] > aux) {
        pVetor[j] = pVetor[j-h]; 
        j -= h;
        if (j < h) 
          break;
      }
      pVetor[j] = aux;
    }
  } while (h != 1);
}


void Merge(int *pVetor, int i1, int j1, int i2, int j2)
{
  int i=i1, j=i2, k=0;
  int *temp;     
    
  temp = malloc(sizeof(int) * (j2-i1+1));
  while (i <= j1 && j <= j2) {
    if (pVetor[i] < pVetor[j])
      temp[k++] = pVetor[i++];
    else
      temp[k++] = pVetor[j++];
  }
  while (i <= j1)
    temp[k++] = pVetor[i++];
  while(j <= j2) 
    temp[k++] = pVetor[j++];
  for(i=i1, j=0; i<=j2; i++, j++)
    pVetor[i] = temp[j];
  free(temp);
}


void MergeSort(int *pVetor, int ini, int fim)
{
  int meio;
      
  if (ini < fim) {
    meio = (ini+fim) / 2;
    MergeSort(pVetor, ini, meio);     
    MergeSort(pVetor, meio+1, fim); 
    Merge(pVetor, ini, meio, meio+1, fim); 
  }
}
 

void QuickSort(int *pVetor, int low, int fim)
{
  int pivo, i, j;
  int temp;
  
  if (low < fim) {
    pivo = low; 
    i = low;
    j = fim;
    while (i < j) {
      while (pVetor[i] <= pVetor[pivo] && i <= fim)
        i++;
      while (pVetor[j] > pVetor[pivo] && j >= low)
        j--;
      if (i < j) {
        temp = pVetor[i];
        pVetor[i] = pVetor[j];
        pVetor[j] = temp;
      }
    }
    temp = pVetor[j];
    pVetor[j] = pVetor[pivo];
    pVetor[pivo] = temp;
    QuickSort(pVetor, low, j-1);
    QuickSort(pVetor, j+1, fim);
  }
}


void HeapSort(int *pVetor, int n) 
{
  int i = n / 2, pai, filho, t;

  for (;;) {
    if (i > 0) {
      i--;
      t = pVetor[i];
    } else {
      n--;
      if (n == 0) 
        return;
      t = pVetor[n];
      pVetor[n] = pVetor[0];
    }
    pai = i;
    filho = i * 2 + 1;
    while (filho < n) {
      if ((filho + 1 < n) && (pVetor[filho + 1] > pVetor[filho]))
        filho++;
      if (pVetor[filho] > t) {
        pVetor[pai] = pVetor[filho];
        pai = filho;
        filho = pai * 2 + 1;
      } 
      else break;
    }
    pVetor[pai] = t;
  }
}


void CountingSort(int *pA, int n)
{
  int i, iMaior;
  int *pC = NULL, *pB = NULL;
  
  // Descobre qual o maior elemento do vetor pA
  iMaior = pA[0];
  for (i = 1; i < n; i++)
    if (iMaior < pA[i])
      iMaior = pA[i];
  
  // Aloca memoria para pB e pC
  pB = malloc(sizeof(int) * n);  
  pC = malloc(sizeof(int) * (iMaior + 1));
  
  // Inicializa o vetor pC
  for (i = 0; i <= iMaior; i++)
    pC[i] = 0;
  
  // Faz a contagem dos valores e soma cada quantidade a sua antecessora
  for (i = 0; i < n; i++)
    pC[pA[i]]++;
  for (i = 1; i <= iMaior; i++)
    pC[i] += pC[i-1];
 
  // Grava os valores ordenadamente em pB
  for (i = n-1; i >= 0; i--) {
    pB[pC[pA[i]]-1] = pA[i];
    pC[pA[i]]--;
  }
  
  // Grava o vetor pB de volta em pA
  for (i = 0; i < n; i++)
    pA[i] = pB[i];
    
  // Libera memoria
  free(pB);
  free(pC);
}


int main (int argc, char *argv[])
{
  int *pVetorOriginal = NULL, *pVetorTrabalho = NULL;
  int i, qtde, max, opcao;  
  clock_t clIni, clFim;
  
  // Le a quantidade de registros e aloca memoria para o vetor original e a copia
  if (argc > 1 && argv[1] != NULL && strlen(argv[1]) > 0 && atoi(argv[1]) > 0) {
    qtde = atoi(argv[1]);
    if (argc > 2 && argv[2] != NULL && strlen(argv[2]) > 0 && atoi(argv[2]) > 0)
      max = atoi(argv[2]);
    else
      max = qtde / 100;
  }
  else {
    printf("Digite a quantidade de registros a serem gerados: ");
    i = scanf("%d", &qtde);
    printf("Digite o maior valor possivel no conjunto: ");
    i = scanf("%d", &max);
  }
  pVetorOriginal = malloc(sizeof(int) * qtde);
  pVetorTrabalho = malloc(sizeof(int) * qtde);
  
  // Preenche o vetor com numeros aleatorios e mostra
  srand(time(NULL));
  for (i = 0; i < qtde; i++)
    pVetorOriginal[i] = rand() % max;
  
  // Mostra o vetor original
  if (qtde <= 1000) {
    for (i = 0; i < qtde; i++)
      printf("%d ", pVetorOriginal[i]);
    printf("\n");
  }
  
  do {
    // Faz uma copia do vetor para preservar os dados originais
    for (i = 0; i < qtde; i++)
      pVetorTrabalho[i] = pVetorOriginal[i];
  
    // Verifica a opcao do usuario
    printf("\nSUPER ORDENADOR\n");
    printf("  1. BubbleSort\n");
    printf("  2. ShellSort\n");
    printf("  3. MergeSort\n");
    printf("  4. QuickSort\n");
    printf("  5. HeapSort\n");
    printf("  6. CountingSort\n");
    printf("  0. Sair\n");
    printf("Digite sua opcao: ");
    i = scanf("%d", &opcao);
  
    // Verifica a opcao e chama o algoritmo correto
    clIni = clock();
    switch(opcao) {
      case 1: 
        BubbleSort(pVetorTrabalho, qtde);
        break;
      case 2:
        ShellSort(pVetorTrabalho, qtde);
        break;
      case 3: 
        MergeSort(pVetorTrabalho, 0, qtde-1);
        break;
      case 4: 
        QuickSort(pVetorTrabalho, 0, qtde-1);
        break;
      case 5:
        HeapSort(pVetorTrabalho, qtde);
        break;
      case 6: 
        CountingSort(pVetorTrabalho, qtde);
        break;
      default:
        break;
    }
    clFim = clock();
    
    // Mostra o vetor ordenado
    if (opcao > 0 && qtde <= 1000) {
      printf("Vetor ordenado: ");
      for (i = 0; i < qtde; i++)
        printf("%d ", pVetorTrabalho[i]);
      printf("\n");
    }
      
    // Mostra o tempo de ordenacao na tela
    if (opcao > 0)
      printf("Tempo de ordenacao: %.4fs\n", (float) (clFim - clIni) / CLOCKS_PER_SEC);
  } while (opcao > 0);
  
  // Libera memoria e encerra
  free(pVetorOriginal);
  free(pVetorTrabalho);
  return 0;
}

