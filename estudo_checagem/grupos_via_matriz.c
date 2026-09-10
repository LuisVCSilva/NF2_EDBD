#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ============================================================
   ESTRUTURAS
   ============================================================ */

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

typedef struct {
    int n;
    Lista adj[MAX];
} Grafo;

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;


/* ============================================================
   LISTA DE ADJACÊNCIA
   ============================================================ */

No *criar_no(int v) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        exit(1);
    }

    novo->vertice = v;
    novo->prox = NULL;

    return novo;
}


void inicializar_grafo(Grafo *g, int n) {
    g->n = n;

    for (int i = 0; i < n; i++) {
        g->adj[i].inicio = NULL;
    }
}


void adicionar_aresta(Grafo *g, int u, int v) {

    /* u -> v */
    No *novo1 = criar_no(v);

    novo1->prox = g->adj[u].inicio;
    g->adj[u].inicio = novo1;


    /* v -> u */
    No *novo2 = criar_no(u);

    novo2->prox = g->adj[v].inicio;
    g->adj[v].inicio = novo2;
}


/* ============================================================
   FILA
   ============================================================ */

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
    int v = f->dados[f->inicio];
    f->inicio++;

    return v;
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

       Isso é importante para tratar componentes
       desconectados.
    */

    for (int s = 0; s < g->n; s++) {

        /* Já pertence a algum componente processado */
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

            No *p = g->adj[u].inicio;


            while (p != NULL) {

                int v = p->vertice;


                /*
                   Vizinho ainda não colorido:
                   recebe a cor oposta.
                */

                if (cor[v] == -1) {

                    cor[v] = 1 - cor[u];

                    enfileirar(&fila, v);
                }


                /*
                   Vizinho já colorido com a mesma cor:
                   conflito!
                */

                else if (cor[v] == cor[u]) {

                    return 0;
                }


                p = p->prox;
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
   LIBERAÇÃO DA MEMÓRIA
   ============================================================ */

void liberar_grafo(Grafo *g) {

    for (int i = 0; i < g->n; i++) {

        No *p = g->adj[i].inicio;

        while (p != NULL) {

            No *temp = p;

            p = p->prox;

            free(temp);
        }

        g->adj[i].inicio = NULL;
    }
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


    /*
       Verificação básica dos limites.
    */

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

            liberar_grafo(&g);

            return 1;
        }


        /*
           Verifica se os vértices são válidos.
        */

        if (u < 0 || u >= V || v < 0 || v >= V) {

            liberar_grafo(&g);

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


    liberar_grafo(&g);

    return 0;
}
