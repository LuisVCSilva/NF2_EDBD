#include <stdio.h>
#include "../pilha/pilha_caractere.h"

int main() {
    printf("=== VALIDADOR DE SINTAXE (USANDO PILHA) ===\n\n");

    char expr_valida[] = "((3 + 5) * 2) - (4 / 2)";
    char expr_invalida[] = "((3 + 5 * 2";

    printf("Testando expressao 1: \"%s\"\n", expr_valida);
    if (verificar_parenteses(expr_valida)) {
        printf("-> Status: Expressao CORRETA (parenteses balanceados).\n\n");
    } else {
        printf("-> Status: Expressao INCORRETA.\n\n");
    }

    printf("Testando expressao 2: \"%s\"\n", expr_invalida);
    if (verificar_parenteses(expr_invalida)) {
        printf("-> Status: Expressao CORRETA.\n\n");
    } else {
        printf("-> Status: Expressao INCORRETA (falta fechar parenteses!).\n\n");
    }

    return 0;
}
