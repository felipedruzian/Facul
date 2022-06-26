/* Lab. Prog II 2022/1 - Prova 1 - Felipe B Druzian & Gabriel Dalmazo */

typedef struct listaGen ListaGen;

ListaGen* lgen_insere (ListaGen* head, void* data);
void lgen_percorre(ListaGen *head, void (*cb)(void*));
ListaGen* lgen_free(ListaGen *head);
void lgen_busca(ListaGen *head, void (*cb)(void*, void*), void *dado);
void lgen_vazia(ListaGen *head, void (*cb)(void*));
