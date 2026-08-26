#include "ordenacao.h"



void bubble_sort(
    int A[],
    int n
)
{
    log_evento(
        "INICIO",
        -1,
        -1,
        A,
        n
    );


    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            log_evento(
                "COMPARACAO",
                i,
                j,
                A,
                n
            );


            if (A[j] > A[j + 1]) {

                int temp = A[j];

                A[j] = A[j + 1];

                A[j + 1] = temp;


                log_evento(
                    "TROCA",
                    i,
                    j,
                    A,
                    n
                );
            }
        }
    }


    log_evento(
        "FIM",
        -1,
        -1,
        A,
        n
    );
}



int main(
    int argc,
    char *argv[]
)
{
    const char *arquivo = "entrada.txt";


    if (argc >= 2) {

        arquivo = argv[1];
    }


    int *A = NULL;

    int n = ler_vetor(
        arquivo,
        &A
    );


    if (n <= 0) {

        return EXIT_FAILURE;
    }


    bubble_sort(
        A,
        n
    );


    free(A);


    return EXIT_SUCCESS;
}
