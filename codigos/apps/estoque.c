#include <stdio.h>
#include <stdlib.h>
#include "../AVL/avl.h"

int main(int argc, char* argv[]) {
    NoAVL* estoque = NULL;

    printf("=== SISTEMA CRUD DE ESTOQUE (COM ARVORE AVL) ===\n\n");

    // 1. CREATE (Inserindo novos produtos via Código de Barras)
    printf("Cadastrando produtos no estoque (codigos desordenados)...\n");
    inserir(789102, &estoque); // Ex: Camisa
    inserir(451230, &estoque); // Ex: Tenis
    inserir(998811, &estoque); // Ex: Bone
    inserir(123456, &estoque); // Ex: Meia
    inserir(555444, &estoque); // Ex: Calca

    // 2. READ (Lendo/Listando todos os produtos ordenados por codigo interno da loja em O(log n))
    printf("\nInventario completo ordenado por codigo interno (Leitura rapida):\n");
    imprimir_arvore(estoque, "codigos internos cadastrados: ");

    // Verificando métricas da AVL
    printf("\nA arvore esta balanceada? %s\n", 
           esta_perfeitamente_balanceada(estoque) ? "SIM" : "NAO");
    printf("Altura da arvore (garante busca O(log n)): %d\n", obter_altura(estoque));

    // 3. Limpeza de memória
    liberar_arvore(&estoque);
    printf("\nEstoque limpo com sucesso da memoria.\n");

    return EXIT_SUCCESS;
}
