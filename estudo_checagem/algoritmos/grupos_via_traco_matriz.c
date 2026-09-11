#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
    Calcula C = A * B
*/
void multiplicar_matrizes(
    long long A[MAX][MAX],
    long long B[MAX][MAX],
    long long C[MAX][MAX],
    int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            C[i][j] = 0;

            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/*
    Calcula o traco da matriz:
    
        tr(A) = A[0][0] + A[1][1] + ...

    O traco de A^k corresponde ao numero
    de passeios fechados de comprimento k.
*/
long long traco(long long A[MAX][MAX], int n)
{
    long long soma = 0;

    for (int i = 0; i < n; i++) {
        soma += A[i][i];
    }

    return soma;
}

/*
    Verifica se existe ciclo de comprimento impar.

    Se existir algum ciclo impar de comprimento k,
    entao tr(A^k) > 0 para algum k impar.

    Basta testar:

        k = 3, 5, 7, ..., n
*/
int possui_ciclo_impar(long long A[MAX][MAX], int n)
{
    long long potencia[MAX][MAX];
    long long proxima[MAX][MAX];

    /*
        Inicialmente:

            potencia = A

        Portanto estamos em A^1.

        FALTA:
        Copiar todos os elementos de A para potencia.
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // FALTA:
            // copiar A[i][j] para potencia[i][j]

        }
    }

    /*
        Construímos:

            A^2
            A^3
            A^4
            ...
            A^n

        Quando k for ímpar, verificamos o traço.
    */
    for (int k = 2; k <= n; k++) {

        /*
            FALTA:
            Calcular:

                proxima = potencia * A

            usando a função multiplicar_matrizes().
        */


        /*
            Atualiza:

                potencia = A^k

            FALTA:
            Copiar a matriz proxima para potencia.
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // FALTA:
                // copiar proxima[i][j] para potencia[i][j]

            }
        }

        /*
            Somente comprimentos ímpares interessam.

            FALTA:
            Verificar se k é ímpar.
        */
        if (/* FALTA */) {

            /*
                FALTA:
                Calcular o traço de potencia:

                    t = tr(A^k)
            */

            long long t = /* FALTA */;

            printf("tr(A^%d) = %lld\n", k, t);

            /*
                Se:

                    tr(A^k) > 0

                então existe um ciclo ímpar.

                FALTA:
                Fazer o teste e retornar 1.
            */
            if (/* FALTA */) {

                // FALTA:
                // retornar 1;

            }
        }
    }

    /*
        Se nenhum ciclo ímpar foi encontrado,
        o grafo é bipartido.

        FALTA:
        retornar o valor correspondente.
    */
    // FALTA:
    // return 0;
}

int main()
{
    int V, E;

    long long A[MAX][MAX] = {0};

    /*
        Entrada:

            V E

        seguida de E conflitos:

            u v
    */
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        /*
            Grafo nao direcionado.
        */
        A[u][v] = 1;
        A[v][u] = 1;
    }

    printf("Analise espectral por tracos:\n\n");

    if (possui_ciclo_impar(A, V)) {

        printf("\nDIVISAO_IMPOSSIVEL\n");

    } else {

        printf("\nDIVISAO_POSSIVEL\n");
    }

    return 0;
}
