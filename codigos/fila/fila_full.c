#include <stdio.h>
#include <stdlib.h>


typedef struct No{

    int dado;

    struct No *prox;

}No;



// Insere no final da fila (enqueue)
void inserir(No **inicio, No **fim, int valor){

    No *novo = malloc(sizeof(No));


    novo->dado = valor;

    novo->prox = NULL;


    // fila vazia
    if(*fim == NULL){

        *inicio = novo;

        *fim = novo;

    }
    else{

        // último elemento aponta para o novo
        (*fim)->prox = novo;


        // atualiza o final da fila
        *fim = novo;

    }

}



// Remove o primeiro elemento da fila (dequeue)
int remover(No **inicio, No **fim){

    if(*inicio == NULL){

        printf("Fila vazia\n");

        return -1;

    }


    No *aux = *inicio;


    int valor = aux->dado;


    *inicio = aux->prox;


    // se removeu o último elemento
    if(*inicio == NULL){

        *fim = NULL;

    }


    free(aux);


    return valor;

}



// Imprime a fila
void imprimir(No *inicio){

    while(inicio){

        printf("%d -> ", inicio->dado);

        inicio = inicio->prox;

    }


    printf("NULL");

}



int main(){

    No *inicio = NULL;

    No *fim = NULL;



    inserir(&inicio, &fim, 10);

    inserir(&inicio, &fim, 20);

    inserir(&inicio, &fim, 30);



    printf("Fila inicial:\n");

    imprimir(inicio);



    printf("\n\nElemento removido: %d\n", remover(&inicio, &fim));



    printf("\nFila apos remocao:\n");

    imprimir(inicio);



    return 0;

}
