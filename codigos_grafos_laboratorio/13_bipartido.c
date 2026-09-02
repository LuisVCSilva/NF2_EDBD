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

    int cor[N];
    for (int i = 0; i < N; i++)
        cor[i] = -1;

    int fila[N];

    for (int inicio = 0; inicio < N; inicio++) {
        if (cor[inicio] != -1)
            continue;

        int ini = 0, fim = 0;
        fila[fim++] = inicio;
        cor[inicio] = 0;

        while (ini < fim) {
            int u = fila[ini++];

            for (int v = 0; v < N; v++) {
                if (!A[u][v])
                    continue;

                if (cor[v] == -1) {
                    cor[v] = 1 - cor[u];
                    fila[fim++] = v;
                } else if (cor[v] == cor[u]) {
                    printf("O grafo NAO e bipartido.\n");
                    return 0;
                }
            }
        }
    }

    printf("O grafo e bipartido.\n");
    return 0;
}
