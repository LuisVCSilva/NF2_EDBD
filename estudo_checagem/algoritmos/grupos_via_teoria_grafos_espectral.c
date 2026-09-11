#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define EPS 1e-8
#define MAX_ITER 10000


/* ============================================================
   MATRIZ DE ADJACÊNCIA
   ============================================================ */

typedef struct {
    int n;
    double adj[MAX][MAX];
} Grafo;


/* ============================================================
   INICIALIZAÇÃO
   ============================================================ */

void inicializar_grafo(Grafo *g, int n) {

    g->n = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0.0;
        }
    }
}


/* ============================================================
   ADICIONAR ARESTA
   ============================================================ */

void adicionar_aresta(Grafo *g, int u, int v) {

    /* Grafo não direcionado */

    g->adj[u][v] = 1.0;
    g->adj[v][u] = 1.0;
}


/* ============================================================
   MÉTODO DE JACOBI
   ============================================================

   Calcula os autovalores de uma matriz simétrica.

   A matriz de adjacência de um grafo não direcionado é
   simétrica, portanto o método pode ser utilizado.
   ============================================================ */

void calcular_autovalores(
    Grafo *g,
    double autovalores[MAX]
) {

    int n = g->n;

    double A[MAX][MAX];


    /* Copia a matriz */

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = g->adj[i][j];
        }
    }


    /* Iterações de Jacobi */

    for (int iter = 0; iter < MAX_ITER; iter++) {

        int p = 0;
        int q = 1;

        double maior = 0.0;


        /*
           Procura o maior elemento fora da diagonal.
        */

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (fabs(A[i][j]) > maior) {

                    maior = fabs(A[i][j]);

                    p = i;
                    q = j;
                }
            }
        }


        /*
           Matriz praticamente diagonal.
           Os elementos da diagonal são os autovalores.
        */

        if (maior < EPS) {
            break;
        }


        /*
           Calcula o ângulo de rotação.
        */

        double theta =
            0.5 * atan2(
                2.0 * A[p][q],
                A[q][q] - A[p][p]
            );


        double c = cos(theta);
        double s = sin(theta);


        /*
           Rotação de Jacobi.
        */

        for (int i = 0; i < n; i++) {

            if (i != p && i != q) {

                double Aip = A[i][p];
                double Aiq = A[i][q];

                A[i][p] = c * Aip - s * Aiq;
                A[p][i] = A[i][p];

                A[i][q] = s * Aip + c * Aiq;
                A[q][i] = A[i][q];
            }
        }


        double App = A[p][p];
        double Aqq = A[q][q];
        double Apq = A[p][q];


        A[p][p] =
            c * c * App
            - 2.0 * s * c * Apq
            + s * s * Aqq;

        A[q][q] =
            s * s * App
            + 2.0 * s * c * Apq
            + c * c * Aqq;


        A[p][q] = 0.0;
        A[q][p] = 0.0;
    }


    /*
       Os elementos da diagonal são os autovalores.
    */

    for (int i = 0; i < n; i++) {
        autovalores[i] = A[i][i];
    }
}


/* ============================================================
   ORDENAÇÃO DOS AUTOVALORES
   ============================================================ */

void ordenar(double valores[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (valores[i] > valores[j]) {

                double temp = valores[i];

                valores[i] = valores[j];
                valores[j] = temp;
            }
        }
    }
}


/* ============================================================
   VERIFICAR SIMETRIA DO ESPECTRO
   ============================================================

   Um grafo é bipartido se, e somente se, o espectro da
   matriz de adjacência é simétrico em relação a zero.

   Depois de ordenar:

       lambda[0] <= lambda[1] <= ... <= lambda[n-1]

   devemos ter:

       lambda[i] ~= -lambda[n-1-i]
   ============================================================ */

int espectro_simetrico(double lambda[], int n) {

    for (int i = 0; i < n; i++) {

        double erro =
            fabs(lambda[i] + lambda[n - 1 - i]);

        if (erro > EPS) {
            return 0;
        }
    }

    return 1;
}


/* ============================================================
   MAIN
   ============================================================ */

int main(int argc, char *argv[]) {

    /*
       Uso:

       ./grupos V E

       Exemplo:

       ./grupos 4 3
    */

    if (argc != 3) {
        printf("Uso: %s V E\n", argv[0]);
        return 1;
    }


    int V = atoi(argv[1]);
    int E = atoi(argv[2]);


    if (V < 1 || V > MAX || E < 0) {
        return 1;
    }


    Grafo g;

    inicializar_grafo(&g, V);


    /*
       Lê os conflitos.
    */

    for (int i = 0; i < E; i++) {

        int u, v;

        if (scanf("%d %d", &u, &v) != 2) {
            return 1;
        }


        if (u < 0 || u >= V ||
            v < 0 || v >= V) {

            return 1;
        }


        adicionar_aresta(&g, u, v);
    }


    /* ========================================================
       AUTOVALORES
       ======================================================== */

    double lambda[MAX];

    /*
       FALTA:
       Calcular os autovalores da matriz de
       adjacência A e armazená-los em lambda.
    */

    /*
       FALTA:
       Ordenar os autovalores para facilitar
       a comparação entre lambda[i] e
       lambda[V - 1 - i].
    */


    printf("Autovalores:\n");

    /*
       FALTA:
       Imprimir os V autovalores armazenados
       no vetor lambda.
    */


    /* ========================================================
       TESTE ESPECTRAL
       ======================================================== */

    /*
       Um grafo não direcionado é bipartido se,
       e somente se, seu espectro é simétrico
       em relação a zero.

       Portanto, deve-se verificar se:

           lambda[i] ≈ -lambda[V-1-i]

       para todos os autovalores.
    */

    if (/* FALTA: verificar simetria espectral */) {

        /*
           FALTA:
           Imprimir DIVISAO_POSSIVEL.
        */

    } else {

        /*
           FALTA:
           Imprimir DIVISAO_IMPOSSIVEL.
        */
    }


    return 0;
}
