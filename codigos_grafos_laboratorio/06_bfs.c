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

    int fila[N], inicio = 0, fim = 0;
    int visitado[N] = {0};
    int origem = 0;

    fila[fim++] = origem;
    visitado[origem] = 1;

    printf("BFS: ");

    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%d ", u + 1);

        for (int v = 0; v < N; v++) {
            if (A[u][v] && !visitado[v]) {
                visitado[v] = 1;
                fila[fim++] = v;
            }
        }
    }

    printf("\n");
    return 0;
}
