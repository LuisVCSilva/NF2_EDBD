#include <stdio.h>
#include <stdlib.h>


typedef struct No{

    int dado;

    struct No *prox;

}No;



void push(No **topo, int valor){


    No *novo = malloc(sizeof(No));


    novo->dado = valor;


    novo->prox = *topo;


    *topo = novo;


}



int pop(No **topo){


    if(*topo != NULL){


        No *aux = *topo;


        int valor = aux->dado;


        *topo = aux->prox;


        free(aux);


        return valor;

    }


    return -1;

}



int top(No *topo){


    if(topo != NULL){

        return topo->dado;

    }


    return -1;

}



void imprimir(No *topo){


    while(topo != NULL){

        printf("%d\n",topo->dado);

        topo = topo->prox;

    }

}



int main(){


    No *pilha = NULL;



    push(&pilha,10);

    push(&pilha,20);

    push(&pilha,30);



    printf("Pilha:\n");

    imprimir(pilha);



    printf("Removido: %d\n",
            pop(&pilha));



    printf("Novo topo: %d\n",
            top(pilha));



    return 0;

}
