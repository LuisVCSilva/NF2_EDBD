#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define T_MIN 0.001
#define T_MAX 100000.0

#define PASSOS_POR_ELEMENTO 1000



static void trocar(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}



static long long energia(const int *A, int n)
{
    long long E = 0;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (A[i] > A[j])
                E++;
        }
    }

    return E;
}



static double aleatorio(void)
{
    return (double) rand() / (double) RAND_MAX;
}



static double temperatura(double entropia)
{
    return T_MIN *
           pow(
               T_MAX / T_MIN,
               entropia
           );
}



static void gerar_vetor(
    int *A,
    int n,
    double entropia
)
{

    for (int i = 0; i < n; i++)
        A[i] = i + 1;



    if (entropia <= 0.0)
        return;



    if (entropia >= 1.0) {

        for (int i = n - 1; i > 0; i--) {

            int j = rand() % (i + 1);

            trocar(A, i, j);
        }

        return;
    }



    double T = temperatura(entropia);



    long long E = energia(
        A,
        n
    );



    long long passos =
        (long long) n *
        PASSOS_POR_ELEMENTO;


    for (long long passo = 0;
         passo < passos;
         passo++) {



        int i = rand() % n;
        int j = rand() % n;


        if (i == j)
            continue;



        long long E_antes = E;



        trocar(
            A,
            i,
            j
        );



        long long E_depois =
            energia(
                A,
                n
            );


        long long deltaE =
            E_depois - E_antes;



        int aceitar = 0;


        if (deltaE <= 0) {

            aceitar = 1;

        } else {

            double probabilidade =
                exp(
                    -(double) deltaE / T
                );


            if (aleatorio() < probabilidade)
                aceitar = 1;
        }



        if (aceitar) {

            E = E_depois;

        } else {

            trocar(
                A,
                i,
                j
            );
        }
    }
}



static int salvar_vetor(
    const char *arquivo,
    const int *A,
    int n
)
{
    FILE *f = fopen(
        arquivo,
        "w"
    );


    if (f == NULL) {

        perror(
            "Erro ao abrir arquivo"
        );

        return 0;
    }



    fprintf(
        f,
        "%d\n",
        n
    );



    for (int i = 0; i < n; i++) {

        fprintf(
            f,
            "%d",
            A[i]
        );

        if (i < n - 1)
            fprintf(
                f,
                " "
            );
    }


    fprintf(
        f,
        "\n"
    );


    fclose(f);

    return 1;
}



static void uso(const char *programa)
{
    fprintf(
        stderr,
        "\nUso:\n"
        "  %s N ENTROPIA SEED ARQUIVO\n\n"
        "Parâmetros:\n"
        "  N          tamanho do vetor\n"
        "  ENTROPIA   valor entre 0 e 1\n"
        "  SEED       semente aleatória\n"
        "  ARQUIVO    arquivo TXT de saída\n\n"
        "Exemplos:\n"
        "  %s 10 0.0 12345 entrada.txt\n"
        "  %s 10 0.5 12345 entrada.txt\n"
        "  %s 10 1.0 12345 entrada.txt\n\n",
        programa,
        programa,
        programa,
        programa
    );
}



int main(
    int argc,
    char *argv[]
)
{

    if (argc != 5) {

        uso(argv[0]);

        return EXIT_FAILURE;
    }



    int n = atoi(
        argv[1]
    );

    double entropia = atof(
        argv[2]
    );

    unsigned int seed =
        (unsigned int) strtoul(
            argv[3],
            NULL,
            10
        );

    const char *arquivo =
        argv[4];



    if (n <= 0) {

        fprintf(
            stderr,
            "Erro: N deve ser maior que zero.\n"
        );

        return EXIT_FAILURE;
    }


    if (entropia < 0.0 ||
        entropia > 1.0) {

        fprintf(
            stderr,
            "Erro: ENTROPIA deve estar entre 0 e 1.\n"
        );

        return EXIT_FAILURE;
    }



    srand(seed);



    int *A = malloc(
        n * sizeof(int)
    );


    if (A == NULL) {

        fprintf(
            stderr,
            "Erro: memória insuficiente.\n"
        );

        return EXIT_FAILURE;
    }



    gerar_vetor(
        A,
        n,
        entropia
    );



    if (!salvar_vetor(
        arquivo,
        A,
        n
    )) {

        free(A);

        return EXIT_FAILURE;
    }



    long long E =
        energia(
            A,
            n
        );


    long long E_max =
        ((long long) n * (n - 1)) / 2;


    double desordem =
        E_max > 0
        ? (double) E / (double) E_max
        : 0.0;


    printf(
        "Vetor gerado\n"
        "-------------\n"
        "Tamanho       : %d\n"
        "Entropia      : %.4f\n"
        "Seed          : %u\n"
        "Energia       : %lld\n"
        "Energia máxima: %lld\n"
        "Desordem      : %.4f\n"
        "Arquivo       : %s\n",
        n,
        entropia,
        seed,
        E,
        E_max,
        desordem,
        arquivo
    );



    free(A);


    return EXIT_SUCCESS;
}
