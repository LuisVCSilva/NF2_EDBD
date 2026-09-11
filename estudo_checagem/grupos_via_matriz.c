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

    for (int i = 0; i < g->n; i++) {
        cor[i] = -1;
    }


    /*
       Percorre todos os vértices.

       Isso permite tratar componentes desconectados.
    */

    for (int s = 0; s < g->n; s++) {

        /* Já foi processado */
        if (cor[s] != -1) {
            continue;
        }


        /* Nova componente */

        Fila fila;

        inicializar_fila(&fila);

        cor[s] = 0;

        enfileirar(&fila, s);


        /* BFS */

        while (!fila_vazia(&fila)) {

            int u = desenfileirar(&fila);


            /*
               Percorre todos os possíveis vizinhos
               de u através da matriz.
            */

            for (int v = 0; v < g->n; v++) {

                /* Não existe aresta u -> v */
                if (g->adj[u][v] == 0) {
                    continue;
                }


                /*
                   Vizinho ainda não colorido:
                   recebe a cor oposta.
                */

                if (cor[v] == -1) {

                    cor[v] = 1 - cor[u];

                    enfileirar(&fila, v);
                }


                /*
                   Vizinho com a mesma cor:
                   conflito!
                */

                else if (cor[v] == cor[u]) {

                    return 0;
                }
            }
        }
    }


    /*
       Todas as componentes foram processadas
       sem encontrar conflito.
    */

    return 1;
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
