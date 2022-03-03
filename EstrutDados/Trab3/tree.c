#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int dado;
    struct tree *left;
    struct tree *right;
} _tree;

_tree *raiz = NULL;

_tree *CreateNode(int num)
{
    _tree *node = malloc(sizeof(_tree));
    if (node != NULL)
    {
        node->left = NULL;
        node->right = NULL;
        node->dado = num;
        return node;
    }
    else
    {
        printf("ERRO!");
        return;
    }
}

_tree *Insert(_tree *node, int num)
{
    if (node == NULL)
    {
        node = CreateNode(num);
        return node;
    }

    if (num == node->dado)
    {
        printf("\nNumero ja adicionado!\n");
        return node;
    }
    
    
    if (num < node->dado)
    {
        node->left = Insert(node->left, num);
    }
    else
    {
        node->right = Insert(node->right, num);
    }
    
    return node;
}

void findNode(_tree *node, int key, _tree *root)
{
    if (node == NULL)
    {
        printf("Key not found");
        return;
    }
 
    if (node->dado == key)
    {
        if (key == root->dado) {
            printf("A celula que contem %d eh a celula raiz", key);
        }
        else if (key < root->dado)
        {
            printf("O valor dado eh da celula esquerda da celula com o valor %d", root->dado);
        }
        else  {
            printf("O valor dado eh da celula direita da celula com o valor %d", root->dado);
        }
 
        return;
    }
    
    if (key < node->dado) {
        findNode(node->left, key, node);
    } else {
        findNode(node->right, key, node);
    }
}

void tab(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\t");
    }
}

void printTree(_tree *node, int nivel)
{
    if (node == NULL)
    {
        tab(nivel);
        printf("--<vazio>--\n");
        return;
    }
    tab(nivel);
    printf("Valor: %d\n", node->dado);

    tab(nivel);
    printf("Esquerda:\n");
    printTree(node->left, nivel+1);

    tab(nivel);
    printf("Direita:\n");
    printTree(node->right, nivel+1);
    
    tab(nivel);
    printf("nivel: %d\n", nivel+1);
}

void freeTree(_tree *node)
{
    if (node == NULL)
        return;
    
    free(node->dado);
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}