#include <stdio.h>

#define MAX 100

typedef struct {

    int dados[MAX];
    int tamanho;

} Lista;


void inicializar(Lista *l){

    l->tamanho = 0;

}


void inserirFim(Lista *l, int valor){

    if(l->tamanho < MAX){

        l->dados[l->tamanho] = valor;
        l->tamanho++;

    }

}


void imprimir(Lista l){

    for(int i=0; i<l.tamanho; i++){

        printf("%d ", l.dados[i]);

    }

}


int main(){

    Lista lista;

    inicializar(&lista);

    inserirFim(&lista,10);
    inserirFim(&lista,20);
    inserirFim(&lista,30);

    imprimir(lista);

    return 0;
}
