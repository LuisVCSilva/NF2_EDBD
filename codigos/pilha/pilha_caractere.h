#ifndef PILHA_CARACTERE_H
#define PILHA_CARACTERE_H

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} PilhaChar;

void inicializar(PilhaChar *p);
int vazia(PilhaChar *p);
int cheia(PilhaChar *p);
void push(PilhaChar *p, char c);
char pop(PilhaChar *p);
int verificar_parenteses(char expressao[]);

#endif // PILHA_CARACTERE_H
