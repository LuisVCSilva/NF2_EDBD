#include <stdio.h>

#define N 7

int A[N][N] = {
    {0,1,0,0,0,1,1},
    {1,0,1,0,0,0,1},
    {0,1,0,1,0,0,1},
    {0,0,1,0,1,0,1},
    {0,0,0,1,0,1,1},
    {1,0,0,0,1,0,1},
    {1,1,1,1,1,1,0}
};

int visitado[N];

int dfs(int u, int pai) {
    visitado[u] = 1;

    for (int v = 0; v < N; v++) {
        if (!A[u][v])
            continue;

        if (!visitado[v]) {
            if (dfs(v, u))
                return 1;
        } else if (v != pai) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    int ciclo = 0;

    for (int i = 0; i < N; i++) {
        if (!visitado[i] && dfs(i, -1)) {
            ciclo = 1;
            break;
        }
    }

    printf("O grafo %stem ciclo.\n", ciclo ? "" : "nao ");
    return 0;
}
