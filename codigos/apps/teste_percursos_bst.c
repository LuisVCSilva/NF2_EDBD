#include <stdio.h>
#include <stdlib.h>
#include "../BST/bst.h"

int main() {
    NoBST *arvore = NULL;

    // Inserindo dados na BST
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for(int i = 0; i < 7; i++) {
        inserir_bst(valores[i], &arvore);
    }

    printf("=== TESTANDO PERCURSOS NA ARVORE BST ===\n\n");

    // Recursivos tradicionais
    printf("1. Infix (In-Order):   ");
    percurso_infix_bst(arvore);
    printf("\n");

    printf("2. Prefix (Pre-Order):  ");
    percurso_prefix_bst(arvore);
    printf("\n");

    printf("3. Postfix (Post-Order): ");
    percurso_postfix_bst(arvore);
    printf("\n\n");

    // Algoritmos utilizando Pilha e Fila auxiliares
    printf("4. Algoritmos com Pilha e Fila:\n");
    percurso_dfs_bst(arvore); // Usa Pilha
    percurso_bfs_bst(arvore); // Usa Fila

    liberar_bst(&arvore);
    return 0;
}
