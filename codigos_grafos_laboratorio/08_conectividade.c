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

    int fila[N], ini = 0, fim = 0;
    int visitado[N] = {0};

    fila[fim++] = 0;
    visitado[0] = 1;

    while (ini < fim) {
        int u = fila[ini++];
        for (int v = 0; v < N; v++) {
            if (A[u][v] && !visitado[v]) {
                visitado[v] = 1;
                fila[fim++] = v;
            }
        }
    }

    int conexo = 1;
    for (int i = 0; i < N; i++)
        if (!visitado[i])
            conexo = 0;

    printf("Grafo %sconexo.\n", conexo ? "" : "nao ");
    return 0;
}
