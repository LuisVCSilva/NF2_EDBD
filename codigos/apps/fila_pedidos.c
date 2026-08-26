#include <stdio.h>
#include <stdlib.h>
#include "../fila/fila_dinamica.h"

int main() {
    No *inicio_fila = NULL;
    No *fim_fila = NULL;

    printf("=== SISTEMA DE DRIVE-THRU (FILA DE PEDIDOS) ===\n\n");

    // 1. Clientes chegam e fazem seus pedidos (IDs dos pedidos)
    printf("Novos pedidos realizados e enviados para a cozinha:\n");
    inserir(&inicio_fila, &fim_fila, 101); // Pedido do Carro 1
    inserir(&inicio_fila, &fim_fila, 102); // Pedido do Carro 2
    inserir(&inicio_fila, &fim_fila, 103); // Pedido do Carro 3
    
    printf("Fila de espera atual na cozinha:\n");
    imprimir(inicio_fila);

    // 2. A cozinha termina o primeiro pedido e ele é entregue no balcão
    printf("\n----------------------------------------\n");
    int pedido_pronto = remover(&inicio_fila, &fim_fila);
    printf(">>> Pedido #%d finalizado e entregue ao cliente!\n\n", pedido_pronto);

    printf("Fila de espera restante:\n");
    imprimir(inicio_fila);

    // 3. Chega um novo cliente durante o processo
    printf("\nChegou um novo cliente...\n");
    inserir(&inicio_fila, &fim_fila, 104);
    
    printf("Fila atualizada:\n");
    imprimir(inicio_fila);

    // Limpeza final da memória
    while(inicio_fila != NULL) {
        remover(&inicio_fila, &fim_fila);
    }

    return 0;
}
