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

    int encontrou = 0;

    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++)
            grau += A[i][j];

        if (grau == 0) {
            printf("Vertice isolado: %d\n", i + 1);
            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("Nao existem vertices isolados.\n");

    return 0;
}
