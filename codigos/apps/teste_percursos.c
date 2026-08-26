#include <stdio.h>
#include <stdlib.h>
#include "../AVL/avl.h"

int main() {
    NoAVL *arvore = NULL;

    // Inserindo dados na árvore AVL
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for(int i = 0; i < 7; i++) {
        inserir(valores[i], &arvore);
    }

    printf("=== TESTANDO PERCURSOS NA ARVORE AVL ===\n\n");

    // Recursivos tradicionais
    printf("1. Infix (In-Order):   ");
    percurso_infix(arvore);
    printf("\n");

    printf("2. Prefix (Pre-Order):  ");
    percurso_prefix(arvore);
    printf("\n");

    printf("3. Postfix (Post-Order): ");
    percurso_postfix(arvore);
    printf("\n\n");

    // Estruturas auxiliares (Pilha e Fila)
    printf("4. Algoritmos com Pilha e Fila:\n");
    percurso_dfs(arvore); // Usa Pilha
    percurso_bfs(arvore); // Usa Fila

    liberar_arvore(&arvore);
    return 0;
}
