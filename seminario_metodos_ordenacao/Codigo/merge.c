#include "ordenacao.h"



void merge(
    int A[],
    int inicio,
    int meio,
    int fim,
    int n
)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;


    int *E = malloc(
        n1 * sizeof(int)
    );

    int *D = malloc(
        n2 * sizeof(int)
    );


    if (E == NULL || D == NULL) {

        free(E);
        free(D);

        return;
    }


    for (int i = 0; i < n1; i++) {

        E[i] = A[inicio + i];
    }


    for (int j = 0; j < n2; j++) {

        D[j] = A[meio + 1 + j];
    }


    int i = 0;
    int j = 0;
    int k = inicio;


    while (
        i < n1 &&
        j < n2
    ) {

        log_evento(
            "COMPARACAO",
            i,
            j,
            A,
            n
        );


        if (E[i] <= D[j]) {

            A[k] = E[i];

            i++;

        } else {

            A[k] = D[j];

            j++;
        }


        log_evento(
            "ATRIBUICAO",
            k,
            -1,
            A,
            n
        );


        k++;
    }


    while (i < n1) {

        A[k] = E[i];

        log_evento(
            "ATRIBUICAO",
            k,
            -1,
            A,
            n
        );

        i++;
        k++;
    }


    while (j < n2) {

        A[k] = D[j];

        log_evento(
            "ATRIBUICAO",
            k,
            -1,
            A,
            n
        );

        j++;
        k++;
    }


    free(E);
    free(D);
}



void merge_sort_rec(
    int A[],
    int inicio,
    int fim,
    int n
)
{
    if (inicio >= fim) {
        return;
    }

    int meio =
        inicio +
        (fim - inicio) / 2;

    log_evento(
        "SPLIT",
        inicio,
        fim,
        A,
        n
    );

    merge_sort_rec(
        A,
        inicio,
        meio,
        n
    );

    merge_sort_rec(
        A,
        meio + 1,
        fim,
        n
    );

    log_evento(
        "MERGE",
        inicio,
        fim,
        A,
        n
    );

    merge(
        A,
        inicio,
        meio,
        fim,
        n
    );
}



void merge_sort(
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


    merge_sort_rec(
        A,
        0,
        n - 1,
        n
    );


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

    const char *arquivo = "entrada/vetor.txt";


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


    merge_sort(
        A,
        n
    );


    free(A);


    return EXIT_SUCCESS;
}
