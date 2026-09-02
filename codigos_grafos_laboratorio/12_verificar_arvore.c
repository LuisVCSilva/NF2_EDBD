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
    for (int v = 0; v < N; v++)
        if (A[u][v] && !visitado[v])
            dfs(v);
}

int main(void) {
    int arestas = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            arestas += A[i][j];

    dfs(0);

    int conexo = 1;
    for (int i = 0; i < N; i++)
        if (!visitado[i])
            conexo = 0;

    int arvore = conexo && (arestas == N - 1);

    printf("Arestas = %d\n", arestas);
    printf("E arvore? %s\n", arvore ? "SIM" : "NAO");

    return 0;
}
