#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

void inserir_inicio(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

No* buscar(No *lista, int valor) {
    No *aux = lista;
    while (aux != NULL) {
        if (aux->dado == valor) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void remover_inicio(No **lista) {
    if (*lista != NULL) {
        No *aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}

void imprimir(No *lista) {
    No *aux = lista;
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberar_lista(No **lista) {
    while (*lista != NULL) {
        remover_inicio(lista);
    }
}
