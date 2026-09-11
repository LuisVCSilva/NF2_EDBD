#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ============================================================
   GRAFO COM MATRIZ DE ADJACÊNCIA
   ============================================================ */

typedef struct {
    int n;
    int adj[MAX][MAX];
} Grafo;


/* ============================================================
   FILA
   ============================================================ */

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;


void inicializar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}


int fila_vazia(Fila *f) {
    return f->inicio == f->fim;
}


void enfileirar(Fila *f, int v) {
    if (f->fim < MAX) {
        f->dados[f->fim] = v;
        f->fim++;
    }
}


int desenfileirar(Fila *f) {
    return f->dados[f->inicio++];
}


/* ============================================================
   GRAFO
   ============================================================ */

void inicializar_grafo(Grafo *g, int n) {

    g->n = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}


void adicionar_aresta(Grafo *g, int u, int v) {

    /* Grafo não direcionado */

    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}


/* ============================================================
   BFS + 2-COLORAÇÃO
   ============================================================ */
int bipartido_bfs(Grafo *g) {

    int cor[MAX];

    /*
       -1 = ainda não colorido
        0 = Grupo 0
        1 = Grupo 1
    */

    /*
       FALTA:
       Inicializar todos os vértices com cor -1.
    */


    /*
       Percorre todos os vértices.

       Isso permite tratar componentes desconectados.
    */

    for (int s = 0; s < g->n; s++) {

        /*
           FALTA:
           Verificar se o vértice s já foi colorido.
           Se já foi processado, deve ser ignorado.
        */


        /*
           Nova componente

           FALTA:
           1. Criar uma fila.
           2. Inicializar a fila.
           3. Atribuir uma cor inicial ao vértice s.
           4. Inserir s na fila.
        */


        /* BFS */

        /*
           FALTA:
           Repetir enquanto a fila não estiver vazia.
        */

        {

            /*
               FALTA:
               Retirar um vértice u da fila.
            */


            /*
               Percorre todos os possíveis vizinhos
               de u através da matriz.
            */

            for (int v = 0; v < g->n; v++) {

                /*
                   FALTA:
                   Verificar se existe uma aresta entre u e v.

                   Se não existir, v não é vizinho de u
                   e deve ser ignorado.
                */


                /*
                   Vizinho ainda não colorido:
                   recebe a cor oposta.

                   FALTA:
                   1. Verificar se cor[v] == -1.
                   2. Atribuir a v a cor oposta à de u.
                   3. Inserir v na fila.
                */


                /*
                   Vizinho já colorido.

                   FALTA:
                   Verificar se v possui a mesma cor de u.

                   Se possuir, existe um conflito e o grafo
                   NÃO é bipartido.
                */

            }
        }
    }


    /*
       Se todas as componentes forem processadas sem
       encontrar conflitos, o grafo é bipartido.

       FALTA:
       Retornar o valor correspondente a
       "grafo bipartido".
    */
}


/* ============================================================
   MAIN
   ============================================================ */

int main(int argc, char *argv[]) {

    /*
       Esperado:

       ./grupos V E

       Exemplo:

       ./grupos 4 3
    */

    if (argc != 3) {
        return 1;
    }


    int V = atoi(argv[1]);
    int E = atoi(argv[2]);


    if (V < 0 || V > MAX || E < 0) {
        return 1;
    }


    Grafo g;

    inicializar_grafo(&g, V);


    /*
       Lê os E conflitos.

       Cada linha:

       u v

       significa que u e v possuem conflito.
    */

    for (int i = 0; i < E; i++) {

        int u, v;

        if (scanf("%d %d", &u, &v) != 2) {
            return 1;
        }


        /*
           Verifica se os vértices são válidos.
        */

        if (u < 0 || u >= V || v < 0 || v >= V) {
            return 1;
        }


        adicionar_aresta(&g, u, v);
    }


    /*
       Verifica se o grafo é bipartido.
    */

    int resultado = bipartido_bfs(&g);


    if (resultado) {
        printf("DIVISAO_POSSIVEL\n");
    } else {
        printf("DIVISAO_IMPOSSIVEL\n");
    }


    return 0;
}
