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

    int origem = 0;
    int candidato[N] = {0};

    for (int amigo = 0; amigo < N; amigo++) {
        if (A[origem][amigo]) {
            for (int pessoa = 0; pessoa < N; pessoa++) {
                if (A[amigo][pessoa])
                    candidato[pessoa] = 1;
            }
        }
    }

    candidato[origem] = 0;

    for (int i = 0; i < N; i++)
        if (A[origem][i])
            candidato[i] = 0;

    printf("Amigos dos amigos de %d: ", origem + 1);

    int encontrou = 0;
    for (int i = 0; i < N; i++) {
        if (candidato[i]) {
            printf("%d ", i + 1);
            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("nenhum");

    printf("\n");
    return 0;
}
