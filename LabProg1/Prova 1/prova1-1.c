#include <stdio.h>
#include <stdlib.h>

struct alunos
{
    int matricula;
    char nome [32];
    float nota1;
    float nota2;
} fulano[5];



int main() {
    system("cls");
    printf("Informe os dados dos alunos: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nInfos do aluno %i. \n", i+1);
        //printf("Matricula: ");
        //scanf("%i", &fulano[i].matricula);
        printf("Nome: ");
        scanf("%s", &fulano[i].nome);
        printf("Nota da prova 1: ");
        scanf("%f", &fulano[i].nota1);
        printf("Nota da prova 2: ");
        scanf("%f", &fulano[i].nota2);
    }

    float media [5];
    int maiormedia;
    for (int i = 0; i < 5; i++) {
        media[i] = (fulano[i].nota1 + fulano[i].nota2)/2;
        printf("%.2f\n", media[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int u = i+1; u < i; u++)
        {
            if (media[i] >= media[u]) {
                maiormedia = i;
            }
        }
    }

    printf ("\nMaior media foi a do aluno %i\n", maiormedia);
    
    printf("\nConsiderando a media 6 para ser aprovado: \n");
    for (int i = 0; i < 5; i++) {
        if (media[i] >= 6) {
            printf("O aluno %s foi aprovado!\n", fulano[i].nome);
        } else {
            printf("O aluno %s foi reprovado!\n", fulano[i].nome);
        }
    }
    
    system("pause");
    return 0;
}
