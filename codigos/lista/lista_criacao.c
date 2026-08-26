#include <stdio.h>
#include <stdlib.h>


typedef struct No{

    int dado;

    struct No *prox;


}No;



int main(){


    No *n1;
    No *n2;
    No *n3;


    n1 = malloc(sizeof(No));
    n2 = malloc(sizeof(No));
    n3 = malloc(sizeof(No));


    n1->dado = 10;
    n2->dado = 20;
    n3->dado = 30;


    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;



    No *aux = n1;


    while(aux != NULL){

        printf("%d\n",aux->dado);

        aux = aux->prox;

    }


    return 0;
}
