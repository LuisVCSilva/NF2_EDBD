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

void dfs(int u) {
    visitado[u] = 1;
    printf("%d ", u + 1);

    for (int v = 0; v < N; v++)
        if (A[u][v] && !visitado[v])
            dfs(v);
}

int main(void) {
    int componentes = 0;

    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            componentes++;
            printf("Componente %d: ", componentes);
            dfs(i);
            printf("\n");
        }
    }

    printf("Total de componentes = %d\n", componentes);
    return 0;
}
