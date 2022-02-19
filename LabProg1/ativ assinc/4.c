/* Faça um programa que receba do usuário um arquivo que contenha o nome
e a nota de diversos alunos(da seguinte forma: NOME:JOÃONOTA:8), um
aluno por linha. Mostre na tela o nome e a nota do aluno que possui a maior
nota. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arquivo;

int main()
{
    float nota, maiorNota;
    char nome[16], maiorNome[16];

    if ((arquivo = fopen("alunos.txt", "r")) == NULL)
    {
        printf("ERROR 101!\n");
        return 1;
    }

    while ((fscanf(arquivo, "NOME:%s NOTA:%f\n", &nome, &nota)) != EOF)
    {
        //printf(" %s, %.2f\n", nome, nota);
        if (nota > maiorNota)
        {
            maiorNota = nota;
            strcpy(maiorNome, nome);
        }
    }

    printf("Aluno com maior nota:\n");
    printf("Nome: %s\n", maiorNome);
    printf("Nota: %.2f\n", maiorNota);
    
    fclose(arquivo);
    return 0;
}
