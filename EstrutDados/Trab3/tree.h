typedef struct tree
{
    int dado;
    struct tree *left;
    struct tree *right;
} _tree;

_tree *raiz;

_tree *CreateNode(int num);
_tree *Insert(_tree *node, int num);
void tab(int num);
void printTree(_tree *node, int nivel);
void freeTree(_tree *node);
void findNode(_tree *root, int key, _tree *parent);
