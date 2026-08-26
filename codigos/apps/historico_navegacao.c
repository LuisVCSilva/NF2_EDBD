#include <stdio.h>
#include "../lista/lista_ligada.h"

int main() {
    No *historico = NULL;

    printf("=== GERENCIADOR DE HISTORICO DE NAVEGACAO (LISTA LIGADA) ===\n\n");

    // 1. O usuário acessa novas páginas (inserção no início)
    printf("Acessando paginas web...\n");
    inserir_inicio(&historico, 404); // Página mais recente (ex: ID 404)
    inserir_inicio(&historico, 200); // Página anterior
    inserir_inicio(&historico, 101); // Página mais antiga do histórico atual

    printf("Historico atual de navegacao (do mais recente para o mais antigo):\n");
    imprimir(historico);

    // 2. Buscando se o usuário visitou uma página específica pelo ID
    int id_procurado = 200;
    printf("\nBuscando pagina com ID %d no historico...\n", id_procurado);
    No *resultado = buscar(historico, id_procurado);
    if (resultado != NULL) {
        printf("-> Pagina encontrada com sucesso!\n");
    } else {
        printf("-> Pagina nao encontrada.\n");
    }

    // 3. O usuário fecha a aba mais recente (remoção do início)
    printf("\nFechando a aba mais recente...\n");
    remover_inicio(&historico);

    printf("Historico apos fechar a aba:\n");
    imprimir(historico);

    // Limpeza total da memória
    liberar_lista(&historico);
    return 0;
}
