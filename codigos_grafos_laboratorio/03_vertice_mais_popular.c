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

    int vertice = 0;
    int maior = -1;

    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++)
            grau += A[i][j];

        if (grau > maior) {
            maior = grau;
            vertice = i;
        }
    }

    printf("Vertice mais popular = %d\n", vertice + 1);
    printf("Grau = %d\n", maior);

    return 0;
}
