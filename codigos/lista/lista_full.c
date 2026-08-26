#include <stdio.h>
#include <stdlib.h>


typedef struct No{

    int dado;

    struct No *prox;


}No;



void inserir(No **lista,int valor){


    No *novo = malloc(sizeof(No));


    novo->dado = valor;


    novo->prox = *lista;


    *lista = novo;

}



void imprimir(No *lista){


    while(lista){

        printf("%d -> ",lista->dado);

        lista = lista->prox;

    }


    printf("NULL");

}



int main(){


    No *lista = NULL;


    inserir(&lista,30);

    inserir(&lista,20);

    inserir(&lista,10);



    imprimir(lista);



    return 0;

}
