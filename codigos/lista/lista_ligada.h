#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor);
void inserir_fim(No **lista, int valor);
No* buscar(No *lista, int valor);
void remover_inicio(No **lista);
void imprimir(No *lista);
void liberar_lista(No **lista);

#endif // LISTA_LIGADA_H
