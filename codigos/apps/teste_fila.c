#include <stdio.h>
#include <stdlib.h>
#include "../fila/fila_dinamica.h"

int main() {
    No *inicio = NULL;
    No *fim = NULL;

    printf("=== TESTE DE FILA DINAMICA ===\n\n");

    inserir(&inicio, &fim, 10);
    inserir(&inicio, &fim, 20);
    inserir(&inicio, &fim, 30);

    printf("Fila inicial:\n");
    imprimir(inicio);

    printf("\nElemento removido: %d\n", remover(&inicio, &fim));

    printf("\nFila apos remocao:\n");
    imprimir(inicio);

    // Limpando o restante da memória
    while(inicio != NULL) {
        remover(&inicio, &fim);
    }

    return 0;
}
