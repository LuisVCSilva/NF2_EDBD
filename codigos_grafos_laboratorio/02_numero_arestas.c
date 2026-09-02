#include <stdio.h>

int main(void) {
    int n = 7;
    int A[7][7] = {
        {0,1,0,0,0,1,1},
        {1,0,1,0,0,0,1},
        {0,1,0,1,0,0,1},
        {0,0,1,0,1,0,1},
        {0,0,0,1,0,1,1},
        {1,0,0,0,1,0,1},
        {1,1,1,1,1,1,0}
    };

    int arestas = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            arestas += A[i][j];

    printf("Numero de arestas = %d\n", arestas);
    return 0;
}
