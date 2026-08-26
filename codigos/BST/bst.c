#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Insere mantendo a regra da BST (valores menores à esquerda, maiores à direita)
// ATENÇÃO: Como não há balanceamento (sem rotações), dados ordenados geram uma árvore degradada O(n).
void inserir_bst(int valor, NoBST** a_raiz) {
    if(*a_raiz == NULL) {
        *a_raiz = malloc(sizeof(NoBST));
        (*a_raiz) -> valor = valor;
        (*a_raiz) -> esquerda = NULL;
        (*a_raiz) -> direita = NULL;
    }
    else if(valor < (*a_raiz) -> valor) {
        inserir_bst(valor, &((*a_raiz) -> esquerda));
    }
    else if(valor > (*a_raiz) -> valor) {
        inserir_bst(valor, &((*a_raiz) -> direita));
    }
}

// Busca recursiva por um valor na BST
NoBST* buscar_bst(NoBST* raiz, int valor) {
    if(raiz == NULL || raiz -> valor == valor) {
        return raiz;
    }
    if(valor < raiz -> valor) {
        return buscar_bst(raiz -> esquerda, valor);
    }
    return buscar_bst(raiz -> direita, valor);
}

// Imprime os nós em ordem crescente (In-Order Traversal)
void imprimir_em_ordem(NoBST* raiz) {
    if(raiz != NULL) {
        imprimir_em_ordem(raiz -> esquerda);
        printf("[%d] ", raiz -> valor);
        imprimir_em_ordem(raiz -> direita);
    }
}

// Libera toda a memória da árvore recursivamente (Pós-Ordem)
void liberar_bst(NoBST** a_raiz) {
    if(*a_raiz != NULL) {
        liberar_bst(&((*a_raiz) -> esquerda));
        liberar_bst(&((*a_raiz) -> direita));
        free(*a_raiz);
        *a_raiz = NULL;
    }
}

// 1. Infix (In-Order): Esquerda -> Raiz -> Direita
void percurso_infix_bst(NoBST const* raiz) {
    if (raiz != NULL) {
        percurso_infix_bst(raiz->esquerda);
        printf("[%d] ", raiz->valor);
        percurso_infix_bst(raiz->direita);
    }
}

// 2. Prefix (Pre-Order): Raiz -> Esquerda -> Direita
void percurso_prefix_bst(NoBST const* raiz) {
    if (raiz != NULL) {
        printf("[%d] ", raiz->valor);
        percurso_prefix_bst(raiz->esquerda);
        percurso_prefix_bst(raiz->direita);
    }
}

// 3. Postfix (Post-Order): Esquerda -> Direita -> Raiz
void percurso_postfix_bst(NoBST const* raiz) {
    if (raiz != NULL) {
        percurso_postfix_bst(raiz->esquerda);
        percurso_postfix_bst(raiz->direita);
        printf("[%d] ", raiz->valor);
    }
}

// Estruturas auxiliares internas para Pilha e Fila de NoBST*
typedef struct NoPilhaBST {
    NoBST *dado;
    struct NoPilhaBST *prox;
} NoPilhaBST;

typedef struct NoFilaBST {
    NoBST *dado;
    struct NoFilaBST *prox;
} NoFilaBST;

// 4. DFS (Depth-First Search) Iterativo usando Pilha
void percurso_dfs_bst(NoBST const* raiz) {
    if (raiz == NULL) return;

    NoPilhaBST *topo = NULL;
    
    // Push inicial da raiz
    NoPilhaBST *novo = malloc(sizeof(NoPilhaBST));
    novo->dado = (NoBST*)raiz;
    novo->prox = topo;
    topo = novo;

    printf("DFS (Pre-Order Iterativo - BST): ");
    while (topo != NULL) {
        // Pop
        NoPilhaBST *aux = topo;
        NoBST *atual = aux->dado;
        topo = topo->prox;
        free(aux);

        printf("[%d] ", atual->valor);

        // Empilha direita primeiro (LIFO)
        if (atual->direita != NULL) {
            NoPilhaBST *dir = malloc(sizeof(NoPilhaBST));
            dir->dado = atual->direita;
            dir->prox = topo;
            topo = dir;
        }
        if (atual->esquerda != NULL) {
            NoPilhaBST *esq = malloc(sizeof(NoPilhaBST));
            esq->dado = atual->esquerda;
            esq->prox = topo;
            topo = esq;
        }
    }
    printf("\n");
}

// 5. BFS (Breadth-First Search / Largura) usando Fila
void percurso_bfs_bst(NoBST const* raiz) {
    if (raiz == NULL) return;

    NoFilaBST *inicio = NULL;
    NoFilaBST *fim = NULL;

    // Enqueue inicial da raiz
    NoFilaBST *novo = malloc(sizeof(NoFilaBST));
    novo->dado = (NoBST*)raiz;
    novo->prox = NULL;
    inicio = fim = novo;

    printf("BFS (Largura - BST): ");
    while (inicio != NULL) {
        // Dequeue
        NoFilaBST *aux = inicio;
        NoBST *atual = aux->dado;
        inicio = inicio->prox;
        if (inicio == NULL) fim = NULL;
        free(aux);

        printf("[%d] ", atual->valor);

        // Enqueue esquerda
        if (atual->esquerda != NULL) {
            NoFilaBST *esq = malloc(sizeof(NoFilaBST));
            esq->dado = atual->esquerda;
            esq->prox = NULL;
            if (fim == NULL) {
                inicio = fim = esq;
            } else {
                fim->prox = esq;
                fim = esq;
            }
        }

        // Enqueue direita
        if (atual->direita != NULL) {
            NoFilaBST *dir = malloc(sizeof(NoFilaBST));
            dir->dado = atual->direita;
            dir->prox = NULL;
            if (fim == NULL) {
                inicio = fim = dir;
            } else {
                fim->prox = dir;
                fim = dir;
            }
        }
    }
    printf("\n");
}
