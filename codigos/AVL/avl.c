#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


///////////////////////////////////////////////////////////////////////
// PERCURSOS (DFS, BFS, INFIX, PREFIX, POSTFIX)
///////////////////////////////////////////////////////////////////////

// 1. Infix (In-Order): Esquerda -> Raiz -> Direita
void percurso_infix(NoAVL const* raiz) {
    if (raiz != NULL) {
        percurso_infix(raiz->esquerda);
        printf("[%d] ", raiz->valor);
        percurso_infix(raiz->direita);
    }
}

// 2. Prefix (Pre-Order): Raiz -> Esquerda -> Direita
void percurso_prefix(NoAVL const* raiz) {
    if (raiz != NULL) {
        printf("[%d] ", raiz->valor);
        percurso_prefix(raiz->esquerda);
        percurso_prefix(raiz->direita);
    }
}

// 3. Postfix (Post-Order): Esquerda -> Direita -> Raiz
void percurso_postfix(NoAVL const* raiz) {
    if (raiz != NULL) {
        percurso_postfix(raiz->esquerda);
        percurso_postfix(raiz->direita);
        printf("[%d] ", raiz->valor);
    }
}

// Estruturas auxiliares internas para Pilha e Fila de NoAVL*
typedef struct NoPilhaAVL {
    NoAVL *dado;
    struct NoPilhaAVL *prox;
} NoPilhaAVL;

typedef struct NoFilaAVL {
    NoAVL *dado;
    struct NoFilaAVL *prox;
} NoFilaAVL;

// 4. DFS (Depth-First Search) Iterativo usando Pilha
void percurso_dfs(NoAVL const* raiz) {
    if (raiz == NULL) return;

    NoPilhaAVL *topo = NULL;
    
    // Push inicial da raiz
    NoPilhaAVL *novo = malloc(sizeof(NoPilhaAVL));
    novo->dado = (NoAVL*)raiz;
    novo->prox = topo;
    topo = novo;

    printf("DFS (Pre-Order Iterativo): ");
    while (topo != NULL) {
        // Pop
        NoPilhaAVL *aux = topo;
        NoAVL *atual = aux->dado;
        topo = topo->prox;
        free(aux);

        printf("[%d] ", atual->valor);

        // Empilha direita primeiro para que a esquerda seja processada antes (LIFO)
        if (atual->direita != NULL) {
            NoPilhaAVL *dir = malloc(sizeof(NoPilhaAVL));
            dir->dado = atual->direita;
            dir->prox = topo;
            topo = dir;
        }
        if (atual->esquerda != NULL) {
            NoPilhaAVL *esq = malloc(sizeof(NoPilhaAVL));
            esq->dado = atual->esquerda;
            esq->prox = topo;
            topo = esq;
        }
    }
    printf("\n");
}

// 5. BFS (Breadth-First Search / Largura) usando Fila
void percurso_bfs(NoAVL const* raiz) {
    if (raiz == NULL) return;

    NoFilaAVL *inicio = NULL;
    NoFilaAVL *fim = NULL;

    // Enqueue inicial da raiz
    NoFilaAVL *novo = malloc(sizeof(NoFilaAVL));
    novo->dado = (NoAVL*)raiz;
    novo->prox = NULL;
    inicio = fim = novo;

    printf("BFS (Largura): ");
    while (inicio != NULL) {
        // Dequeue
        NoFilaAVL *aux = inicio;
        NoAVL *atual = aux->dado;
        inicio = inicio->prox;
        if (inicio == NULL) fim = NULL;
        free(aux);

        printf("[%d] ", atual->valor);

        // Enqueue esquerda
        if (atual->esquerda != NULL) {
            NoFilaAVL *esq = malloc(sizeof(NoFilaAVL));
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
            NoFilaAVL *dir = malloc(sizeof(NoFilaAVL));
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

///////////////////////////////////////////////////////////////////////
// OPERAÇÕES BÁSICAS DA ÁRVORE
///////////////////////////////////////////////////////////////////////

void inserir(int valor, NoAVL** a_raiz) {
    if(*a_raiz == NULL) {
        *a_raiz = malloc(sizeof **a_raiz);
        **a_raiz = (NoAVL) { .valor = valor, .esquerda = NULL, .direita = NULL, .altura = 0 };
    }
    else if(valor < (*a_raiz) -> valor) {
        inserir(valor, &((*a_raiz) -> esquerda));
        atualizar_altura(*a_raiz);
        balancear_apos_insercao_esquerda(valor, a_raiz);
    }
    else if(valor > (*a_raiz) -> valor) {
        inserir(valor, &((*a_raiz) -> direita));
        atualizar_altura(*a_raiz);
        balancear_apos_insercao_direita(valor, a_raiz);
    }
}

void liberar_arvore(NoAVL** a_raiz) {
    if(*a_raiz != NULL) {
        liberar_arvore(&((*a_raiz) -> esquerda));
        liberar_arvore(&((*a_raiz) -> direita));
        free(*a_raiz);
        *a_raiz = NULL;
    }
}

///////////////////////////////////////////////////////////////////////
// ROTAÇÕES AVL
///////////////////////////////////////////////////////////////////////

void rotacionar_anti_horario(NoAVL** a_raiz) {  // Rotação para a direita com a raiz
    NoAVL* raiz_antiga = *a_raiz;
    NoAVL* nova_raiz = raiz_antiga -> direita;
    raiz_antiga -> direita = nova_raiz -> esquerda;
    nova_raiz -> esquerda = raiz_antiga;
    *a_raiz = nova_raiz;
    atualizar_altura(raiz_antiga);
    atualizar_altura(nova_raiz);
}

void rotacionar_horario(NoAVL** a_raiz) {  // Rotação para a esquerda com a raiz
    NoAVL* raiz_antiga = *a_raiz;
    NoAVL* nova_raiz = raiz_antiga -> esquerda;
    raiz_antiga -> esquerda = nova_raiz -> direita;
    nova_raiz -> direita = raiz_antiga;
    *a_raiz = nova_raiz;
    atualizar_altura(raiz_antiga);
    atualizar_altura(nova_raiz);
}

void balancear_apos_insercao_esquerda(int valor, NoAVL** a_raiz) {
    if(obter_fator_balanceamento(*a_raiz) == 2) {
        if(valor < (*a_raiz) -> esquerda -> valor) {
            // Rotação simples -- inserção na subárvore esquerda-esquerda
            rotacionar_horario(a_raiz);
        }
        else {
            // Rotação dupla -- inserção na subárvore esquerda-direita
            rotacionar_anti_horario(&((*a_raiz) -> esquerda));
            rotacionar_horario(a_raiz);
        }
    }
}

void balancear_apos_insercao_direita(int valor, NoAVL** a_raiz) {
    if(obter_fator_balanceamento(*a_raiz) == -2) {
        if(valor > (*a_raiz) -> direita -> valor) {
            // Rotação simples -- inserção na subárvore direita-direita
            rotacionar_anti_horario(a_raiz);
        }
        else {
            // Rotação dupla -- inserção na subárvore direita-esquerda
            rotacionar_horario(&((*a_raiz) -> direita));
            rotacionar_anti_horario(a_raiz);
        }
    }
}

///////////////////////////////////////////////////////////////////////
// MÉTRICAS (altura e balanceamento)
///////////////////////////////////////////////////////////////////////

int obter_fator_balanceamento(NoAVL const* raiz) {
    return obter_altura(raiz -> esquerda) - obter_altura(raiz -> direita);
}

void atualizar_altura(NoAVL* raiz) {
    int altura_esquerda = obter_altura(raiz -> esquerda);
    int altura_direita = obter_altura(raiz -> direita);
    raiz -> altura = 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
}

int obter_altura(NoAVL const* raiz) {
    return raiz == NULL ? -1 : raiz -> altura;
}

int obter_altura_sem_usar_campo(NoAVL* raiz) {
    if(raiz == NULL) {
        return -1;
    }
    int altura_esquerda = obter_altura_sem_usar_campo(raiz -> esquerda);
    int altura_direita = obter_altura_sem_usar_campo(raiz -> direita);
    return 1 + (altura_esquerda < altura_direita ? altura_esquerda : altura_direita);
}

///////////////////////////////////////////////////////////////////////
// UTILITÁRIOS DE TESTE
///////////////////////////////////////////////////////////////////////

void imprimir_nos_arvore(NoAVL const* raiz) {
    if(raiz != NULL) {
        imprimir_nos_arvore(raiz -> esquerda);
        printf("[%d] ", raiz -> valor);
        imprimir_nos_arvore(raiz -> direita);
    }
}

bool esta_perfeitamente_balanceada(NoAVL const* raiz) {
    if(raiz != NULL) {
        int fator = obter_fator_balanceamento(raiz);
        return fator >= -1 && fator <= 1
            && esta_perfeitamente_balanceada(raiz -> esquerda)
            && esta_perfeitamente_balanceada(raiz -> direita);
    }
    else {
        return true;
    }
}

void imprimir_arvore(NoAVL const* raiz, char const* rotulo) {
    printf("%s", rotulo);
    imprimir_nos_arvore(raiz);
    printf("\n");
}
