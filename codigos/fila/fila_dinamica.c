#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

// Insere no final da fila (enqueue)
void inserir(No **inicio, No **fim, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    // fila vazia
    if(*fim == NULL) {
        *inicio = novo;
        *fim = novo;
    }
    else {
        // último elemento aponta para o novo
        (*fim)->prox = novo;
        // atualiza o final da fila
        *fim = novo;
    }
}

// Remove o primeiro elemento da fila (dequeue)
int remover(No **inicio, No **fim) {
    if(*inicio == NULL) {
        printf("Fila vazia\n");
        return -1;
    }

    No *aux = *inicio;
    int valor = aux->dado;
    *inicio = aux->prox;

    // se removeu o último elemento
    if(*inicio == NULL) {
        *fim = NULL;
    }

    free(aux);
    return valor;
}

// Imprime a fila
void imprimir(No *inicio) {
    No *atual = inicio;
    while(atual) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}
