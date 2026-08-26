#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir(No **inicio, No **fim, int valor);
int remover(No **inicio, No **fim);
void imprimir(No *inicio);

#endif // FILA_DINAMICA_H
