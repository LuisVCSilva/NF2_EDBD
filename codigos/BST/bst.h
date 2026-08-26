#ifndef BST_H
#define BST_H

// Definição do Nó da Árvore Binária de Busca (Sem balanceamento)
typedef struct NoBST {
    int valor;
    struct NoBST* esquerda;
    struct NoBST* direita;
} NoBST;

// Protótipos das Operações Básicas da BST
void inserir_bst(int valor, NoBST** a_raiz);
NoBST* buscar_bst(NoBST* raiz, int valor);
void imprimir_em_ordem(NoBST* raiz);
void liberar_bst(NoBST** a_raiz);

// Percursos (Infix, Prefix, Postfix, DFS e BFS)
void percurso_infix_bst(NoBST const* raiz);
void percurso_prefix_bst(NoBST const* raiz);
void percurso_postfix_bst(NoBST const* raiz);
void percurso_dfs_bst(NoBST const* raiz);
void percurso_bfs_bst(NoBST const* raiz);

#endif // BST_H
