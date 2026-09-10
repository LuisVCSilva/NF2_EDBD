#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* ============================================================
   TAD GRAFO
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
    Lista *adj;
} Grafo;


/* ============================================================
   TAD FILA
   ============================================================ */

typedef struct NoFila {
    int vertice;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;


/* ============================================================
   TAD GRAFO - CRIAR
   ============================================================ */

Grafo *criar_grafo(int n)
{
    Grafo *g = malloc(sizeof(Grafo));

    if (g == NULL)
        return NULL;

    g->n = n;

    g->adj = malloc(n * sizeof(Lista));

    if (g->adj == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        g->adj[i].inicio = NULL;
    }

    return g;
}


/* ============================================================
   CRIAR NÓ DA LISTA DE ADJACÊNCIA
   ============================================================ */

No *criar_no(int v)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
        return NULL;

    novo->vertice = v;
    novo->prox = NULL;

    return novo;
}


/* ============================================================
   TAD GRAFO - ADICIONAR ARESTA
   ============================================================ */

int adicionar_aresta(Grafo *g, int u, int v)
{
    No *novo;

    /* u -> v */

    novo = criar_no(v);

    if (novo == NULL)
        return 0;

    novo->prox = g->adj[u].inicio;
    g->adj[u].inicio = novo;


    /* v -> u */

    novo = criar_no(u);

    if (novo == NULL)
        return 0;

    novo->prox = g->adj[v].inicio;
    g->adj[v].inicio = novo;

    return 1;
}


/* ============================================================
   TAD FILA - CRIAR
   ============================================================ */

Fila *criar_fila(void)
{
    Fila *f = malloc(sizeof(Fila));

    if (f == NULL)
        return NULL;

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}


/* ============================================================
   FILA VAZIA
   ============================================================ */

int fila_vazia(Fila *f)
{
    return f->inicio == NULL;
}


/* ============================================================
   ENFILEIRAR
   ============================================================ */

void enfileirar(Fila *f, int v)
{
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL)
        return;

    novo->vertice = v;
    novo->prox = NULL;

    if (f->fim == NULL) {

        f->inicio = novo;
        f->fim = novo;

    } else {

        f->fim->prox = novo;
        f->fim = novo;
    }
}


/* ============================================================
   DESENFILEIRAR
   ============================================================ */

int desenfileirar(Fila *f)
{
    NoFila *temp;
    int v;

    temp = f->inicio;

    v = temp->vertice;

    f->inicio = temp->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);

    return v;
}


/* ============================================================
   LIBERAR FILA
   ============================================================ */

void liberar_fila(Fila *f)
{
    while (!fila_vazia(f)) {
        desenfileirar(f);
    }

    free(f);
}


/* ============================================================
   TAD GRAFO - VERIFICAR BIPARTIÇÃO
   ============================================================ */

int bipartido_bfs(Grafo *g)
{
    int cor[MAX];

    /*
       cor[v] = -1
       -> ainda não visitado

       cor[v] = 0
       -> Grupo 0

       cor[v] = 1
       -> Grupo 1
    */

    for (int i = 0; i < g->n; i++) {
        cor[i] = -1;
    }


    /*
       Percorre todos os vértices.

       Isso permite tratar componentes
       desconectados.
    */

    for (int s = 0; s < g->n; s++) {

        if (cor[s] != -1)
            continue;


        /*
           Começa uma nova componente.
        */

        Fila *f = criar_fila();

        if (f == NULL)
            return 0;


        /*
           Primeiro vértice recebe
           o Grupo 0.
        */

        cor[s] = 0;

        enfileirar(f, s);


        /*
           BFS
        */

        while (!fila_vazia(f)) {

            int u = desenfileirar(f);

            No *p = g->adj[u].inicio;


            /*
               Percorre a lista de
               adjacência de u.
            */

            while (p != NULL) {

                int v = p->vertice;


                /*
                   v ainda não possui grupo.
                */

                if (cor[v] == -1) {

                    /*
                       Coloca v no grupo
                       oposto ao de u.
                    */

                    cor[v] = 1 - cor[u];

                    enfileirar(f, v);
                }


                /*
                   v já possui grupo.

                   Se estiver no mesmo grupo
                   de u, existe conflito.
                */

                else if (cor[v] == cor[u]) {

                    liberar_fila(f);

                    return 0;
                }


                p = p->prox;
            }
        }

        liberar_fila(f);
    }


    /*
       Nenhum conflito foi encontrado.
    */

    return 1;
}


/* ============================================================
   TAD GRAFO - LIBERAR
   ============================================================ */

void liberar_grafo(Grafo *g)
{
    for (int i = 0; i < g->n; i++) {

        No *p = g->adj[i].inicio;

        while (p != NULL) {

            No *temp = p;

            p = p->prox;

            free(temp);
        }
    }

    free(g->adj);
    free(g);
}


/* ============================================================
   MAIN
   ============================================================ */

int main(int argc, char *argv[])
{
    int V;
    int E;

    /*
       Uso:

       ./grupos V E

       Exemplo:

       ./grupos 4 3
    */

    if (argc != 3) {
        return 1;
    }

    V = atoi(argv[1]);
    E = atoi(argv[2]);


    /*
       Verificação básica.
    */

    if (V < 0 || V > MAX || E < 0) {
        return 1;
    }


    /*
       Cria o TAD Grafo.
    */

    Grafo *g = criar_grafo(V);

    if (g == NULL) {
        return 1;
    }


    /*
       Lê os conflitos.
    */

    for (int i = 0; i < E; i++) {

        int u;
        int v;

        if (scanf("%d %d", &u, &v) != 2) {

            liberar_grafo(g);

            return 1;
        }


        /*
           Verifica se os vértices existem.
        */

        if (u < 0 || u >= V ||
            v < 0 || v >= V) {

            liberar_grafo(g);

            return 1;
        }


        /*
           Grafo não direcionado:
           adiciona u -> v e v -> u.
        */

        if (!adicionar_aresta(g, u, v)) {

            liberar_grafo(g);

            return 1;
        }
    }


    /*
       Verifica se o grafo é bipartido.
    */

    if (bipartido_bfs(g)) {

        printf("DIVISAO_POSSIVEL\n");

    } else {

        printf("DIVISAO_IMPOSSIVEL\n");
    }


    /*
       Libera toda a memória.
    */

    liberar_grafo(g);

    return 0;
}
