#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>



static inline void log_evento(
    const char *evento,
    int i,
    int j,
    const int A[],
    int n
)
{
    printf(
        "%s;i=%d;j=%d;A=",
        evento,
        i,
        j
    );

    for (int k = 0; k < n; k++) {

        printf("%d", A[k]);

        if (k < n - 1)
            printf(",");
    }

    printf("\n");
}



static inline int ler_vetor(
    const char *arquivo,
    int **A
)
{
    FILE *fp = fopen(
        arquivo,
        "r"
    );

    if (fp == NULL) {

        perror(
            "Erro ao abrir arquivo"
        );

        return -1;
    }


    int capacidade = 10;
    int n = 0;

    int *vetor = malloc(
        capacidade * sizeof(int)
    );

    if (vetor == NULL) {

        perror(
            "Erro ao alocar memoria"
        );

        fclose(fp);

        return -1;
    }


    int valor;

    while (
        fscanf(
            fp,
            "%d",
            &valor
        ) == 1
    ) {

        if (n >= capacidade) {

            capacidade *= 2;

            int *novo = realloc(
                vetor,
                capacidade * sizeof(int)
            );

            if (novo == NULL) {

                perror(
                    "Erro ao realocar memoria"
                );

                free(vetor);

                fclose(fp);

                return -1;
            }

            vetor = novo;
        }

        vetor[n] = valor;

        n++;
    }


    fclose(fp);


    if (n == 0) {

        free(vetor);

        fprintf(
            stderr,
            "Arquivo vazio ou sem valores inteiros.\n"
        );

        return -1;
    }


    *A = vetor;

    return n;
}

#endif
