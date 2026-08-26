#include <stdio.h>
#include "pilha_caractere.h"

void inicializar(PilhaChar *p) {
    p->topo = -1;
}

int vazia(PilhaChar *p) {
    return p->topo == -1;
}

int cheia(PilhaChar *p) {
    return p->topo == MAX - 1;
}

void push(PilhaChar *p, char c) {
    if (!cheia(p)) {
        p->dados[++p->topo] = c;
    }
}

char pop(PilhaChar *p) {
    if (!vazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';
}

int verificar_parenteses(char expressao[]) {
    PilhaChar p;
    inicializar(&p);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            push(&p, '(');
        } else if (expressao[i] == ')') {
            if (vazia(&p)) {
                return 0; // Fechou um parêntese que nunca abriu
            }
            pop(&p);
        }
    }

    return vazia(&p); // Se a pilha estiver vazia, todos os parênteses fecharam corretamente
}
