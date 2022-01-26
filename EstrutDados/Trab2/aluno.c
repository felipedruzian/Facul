// Trabalho 02 - Listas encadeadas
// Felipe Barreto Druzian - felipedruzian.aluno@unipampa.edu.br

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[40];
    int matricula;
    float nota;
    struct aluno *next;
} _aluno;

_aluno* scanList(_aluno *head) {
    if(head == NULL)
    {
        head = malloc(sizeof(_aluno));
        fflush(stdin);
        printf("Digite o nome do Aluno: ");
        gets(head->nome);
        fflush(stdin);
        printf("Digite a matricula do Aluno: ");
        scanf("%d", &head->matricula);
        fflush(stdin);
        printf("Digite a nota do Aluno: ");
        scanf("%f", &head->nota);
        fflush(stdin);
        head->next = NULL;
    }else{
        _aluno *cont = head;
        _aluno *aux = malloc(sizeof(_aluno));
        fflush(stdin);
        printf("Digite o nome do Aluno: ");
        gets(aux->nome);
        fflush(stdin);
        printf("Digite a matricula do Aluno: ");
        scanf("%d", &aux->matricula);
        fflush(stdin);
        printf("Digite a nota do Aluno: ");
        scanf("%f", &aux->nota);
        fflush(stdin);

        while(cont != NULL) 
        {
            if(strcmp(aux->nome, cont->nome) < 0)
            {
                aux->next = head;
                head = aux;
                break;
            }else if(strcmp(aux->nome, cont->nome) > 0)
            {
                if (cont->next != NULL)
                {
                    if (strcmp(aux->nome, cont->next->nome) > 0)
                    {
                        cont = cont->next;
                    }else
                    {
                        aux->next = cont->next;
                        cont->next = aux;
                        break;
                    }
                }else
                {
                    aux->next = cont->next;
                    cont->next = aux;
                    break;
                }
            }else
            {
                cont = cont->next;
            }
        }
    }
    return head;
}

void printList (_aluno *head)
{
    if(head == NULL)
    {
        printf("A lista esta vazia!\n");
    }
    _aluno *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("Nome: %s\n", ptr->nome);
        printf("Matricula: %d\n", ptr->matricula);
        printf("Nota: %.2f\n\n", ptr->nota);
        ptr = ptr->next;
    }
}

_aluno* delList(_aluno *head)
{
    if (head == NULL)
    {
        printf("A lista esta vazia!\n");
    }else
    {
        _aluno *cur = head;
        _aluno *prv = head;
        char nome[40];
        fflush(stdin);
        printf("Digite o Nome do Aluno para deletar: ");
        gets(nome);
        fflush(stdin);
        if (strcmp(nome, head->nome) == 0)
        {
            head = head->next;
            free(cur);
            free(prv);
            cur = NULL;
            prv = NULL;
            printf("\nDeletado!");
        }else
        {
            while (strcmp(nome, cur->nome) != 0 && cur->next != NULL)
            {
                prv = cur;
                cur = cur->next;
            }
            if (strcmp(nome, cur->nome) == 0)
            {
                prv->next = cur->next;
                free(cur);
                cur = NULL;
                printf("\nDeletado!");
            }else
            {
                printf("\nAluno inexistente.");
            }
        }
    }
    return head;
}

_aluno* freeList(_aluno *head)
{
    _aluno *tmp = head;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        free(head);
        head = tmp;
    }
    return head;
}