#include <stdio.h>

#define MAX 5


typedef struct {

    int dados[MAX];

    int topo;

} Pilha;



void inicializar(Pilha *p){

    p->topo = -1;

}



int vazia(Pilha *p){

    return p->topo == -1;

}



int cheia(Pilha *p){

    return p->topo == MAX-1;

}



void push(Pilha *p, int valor){

    if(!cheia(p)){

        p->topo++;

        p->dados[p->topo] = valor;

    }

    else{

        printf("Pilha cheia\n");

    }

}



int pop(Pilha *p){

    if(!vazia(p)){


        int valor = p->dados[p->topo];

        p->topo--;


        return valor;

    }


    printf("Pilha vazia\n");

    return -1;

}



int top(Pilha *p){

    if(!vazia(p)){

        return p->dados[p->topo];

    }


    return -1;

}



int main(){


    Pilha p;


    inicializar(&p);



    push(&p,10);

    push(&p,20);

    push(&p,30);



    printf("Topo: %d\n",top(&p));


    printf("Removido: %d\n",pop(&p));


    printf("Topo: %d\n",top(&p));


    return 0;

}
