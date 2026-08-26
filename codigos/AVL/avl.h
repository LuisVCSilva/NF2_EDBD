#ifndef AVL_H
#define AVL_H

#include <stdbool.h>


// Definição do Nó da Árvore AVL
typedef struct NoAVL {
    int valor;
    int altura;
    struct NoAVL* esquerda;
    struct NoAVL* direita;
} NoAVL;

// Protótipos de Percursos na Árvore AVL
void percurso_infix(NoAVL const* raiz);    // In-Order (Esquerda, Raiz, Direita)
void percurso_prefix(NoAVL const* raiz);   // Pre-Order (Raiz, Esquerda, Direita)
void percurso_postfix(NoAVL const* raiz);  // Post-Order (Esquerda, Direita, Raiz)
void percurso_dfs(NoAVL const* raiz);      // DFS iterativo (usando Pilha de nós)
void percurso_bfs(NoAVL const* raiz);      // BFS / Largura (usando Fila de nós)

// Protótipos das Operações Básicas
void inserir(int valor, NoAVL** a_raiz);
void liberar_arvore(NoAVL** a_raiz);

// Protótipos das Rotações e Balanceamento
void rotacionar_anti_horario(NoAVL** a_raiz);
void rotacionar_horario(NoAVL** a_raiz);
void balancear_apos_insercao_esquerda(int valor, NoAVL** a_raiz);
void balancear_apos_insercao_direita(int valor, NoAVL** a_raiz);

// Protótipos de Métricas (Altura e Balanceamento)
int obter_fator_balanceamento(NoAVL const* raiz);
void atualizar_altura(NoAVL* raiz);
int obter_altura(NoAVL const* raiz);
int obter_altura_sem_usar_campo(NoAVL* raiz);

// Protótipos de Utilitários e Testes
void imprimir_nos_arvore(NoAVL const* raiz);
bool esta_perfeitamente_balanceada(NoAVL const* raiz);
void imprimir_arvore(NoAVL const* raiz, char const* rotulo);



#endif // AVL_H
