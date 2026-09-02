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

    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++)
            grau += A[i][j];
        printf("Grau(%d) = %d\n", i + 1, grau);
    }

    return 0;
}
