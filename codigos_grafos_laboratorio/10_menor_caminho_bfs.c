#include <stdio.h>

#define N 7

int main(void) {
    int A[N][N] = {
        {0,1,0,0,0,1,1},
        {1,0,1,0,0,0,1},
        {0,1,0,1,0,0,1},
        {0,0,1,0,1,0,1},
        {0,0,0,1,0,1,1},
        {1,0,0,0,1,0,1},
        {1,1,1,1,1,1,0}
    };

    int origem = 0, destino = 3;
    int fila[N], ini = 0, fim = 0;
    int visitado[N] = {0};
    int dist[N], pai[N];

    for (int i = 0; i < N; i++) {
        dist[i] = -1;
        pai[i] = -1;
    }

    fila[fim++] = origem;
    visitado[origem] = 1;
    dist[origem] = 0;

    while (ini < fim) {
        int u = fila[ini++];

        for (int v = 0; v < N; v++) {
            if (A[u][v] && !visitado[v]) {
                visitado[v] = 1;
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila[fim++] = v;
            }
        }
    }

    if (dist[destino] == -1) {
        printf("Nao existe caminho.\n");
        return 0;
    }

    printf("Distancia entre %d e %d = %d\n",
           origem + 1, destino + 1, dist[destino]);

    int caminho[N], tam = 0;
    for (int v = destino; v != -1; v = pai[v])
        caminho[tam++] = v;

    printf("Caminho: ");
    for (int i = tam - 1; i >= 0; i--)
        printf("%d ", caminho[i] + 1);
    printf("\n");

    return 0;
}
