#include <stdio.h>
#include <stdlib.h>


typedef struct No{

    int dado;

    struct No *prox;


}No;



void inserirInicio(No **lista, int valor){


    No *novo = malloc(sizeof(No));


    novo->dado = valor;


    novo->prox = *lista;


    *lista = novo;


}



void imprimir(No *lista){


    while(lista != NULL){

        printf("%d ",lista->dado);

        lista = lista->prox;

    }

}



int main(){


    No *lista = NULL;


    inserirInicio(&lista,30);

    inserirInicio(&lista,20);

    inserirInicio(&lista,10);



    imprimir(lista);


    return 0;

}
