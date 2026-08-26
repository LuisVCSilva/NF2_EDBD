#include <stdio.h>
#include <stdlib.h>
#include "../BST/bst.h"

int main() {
    NoBST* bilheteria = NULL;

    printf("=== SISTEMA DE BILHETERIA ONLINE (O PERIGO DA BST) ===\n\n");

    // 1. Fase normal: vendas esporádicas e aleatórias (A BST aguenta bem)
    printf("Fase 1: Vendas antecipadas (IDs aleatorios)...\n");
    int vendas_antecipadas[] = {5000, 2000, 8000, 1000, 3500};
    for (int i = 0; i < 5; i++) {
        inserir_bst(vendas_antecipadas[i], &bilheteria);
    }
    printf("-> Sistema estavel. A busca binaria esta rapida O(log n).\n\n");

    // 2. O pico de vendas abre! (O problema acontece NO MEIO DA EXECUÇÃO)
    printf("Fase 2: O site abre para o publico geral (Pico de acessos sequenciais)...\n");
    printf("-> Inserindo IDs em ordem estritamente crescente: 9001, 9002, 9003, 9004, 9005...\n");
    
    int pico_vendas[] = {9001, 9002, 9003, 9004, 9005};
    for (int i = 0; i < 5; i++) {
        inserir_bst(pico_vendas[i], &bilheteria);
    }

    printf("\n[ALERTA CRITICO DE ENGENHARIA]:\n");
    printf("- O pico de acessos ordenados destruiu a estrutura da BST no meio da execucao!\n");
    printf("- A arvore perdeu o equilibrio e se transformou em uma LISTA LIGADA linear.\n");
    printf("- Resultado na catraca: O tempo de validacao do ingresso 9005 saltou de\n");
    printf("  instante logaritmico para o pior caso O(n), travando as validacoes!\n");

    // Limpeza da memória
    liberar_bst(&bilheteria);
    return 0;
}
