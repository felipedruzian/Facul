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
        printf("Digite o nome do Aluno: ");
        scanf("%s", &head->nome);
        printf("Digite a matricula do Aluno: ");
        scanf("%d", &head->matricula);
        printf("Digite a nota do Aluno: ");
        scanf("%f", &head->nota);
        head->next = NULL;
    }else{
        _aluno *cont = head;
        _aluno *aux = malloc(sizeof(_aluno));
        printf("Digite o nome do Aluno: ");
        scanf("%s", &aux->nome);
        printf("Digite a matricula do Aluno: ");
        scanf("%d", &aux->matricula);
        printf("Digite a nota do Aluno: ");
        scanf("%f", &aux->nota);

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
    if(head == NULL) {
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

void delList(_aluno *head)
{
    
}