#include <stdio.h>

#define TAM 100


typedef struct{

    int dados[TAM];

    int inicio;

    int fim;

}Fila;



// Inicializa a fila vazia
void inicializar(Fila *fila){

    fila->inicio = 0;

    fila->fim = 0;

}



// Insere elemento no final da fila (enqueue)
void inserir(Fila *fila, int valor){

    if(fila->fim == TAM){

        printf("Fila cheia\n");

        return;

    }


    fila->dados[fila->fim] = valor;

    fila->fim++;

}



// Remove elemento do início da fila (dequeue)
int remover(Fila *fila){

    if(fila->inicio == fila->fim){

        printf("Fila vazia\n");

        return -1;

    }


    int valor = fila->dados[fila->inicio];


    fila->inicio++;


    return valor;

}



// Imprime a fila
void imprimir(Fila *fila){

    for(int i = fila->inicio; i < fila->fim; i++){

        printf("%d -> ", fila->dados[i]);

    }


    printf("NULL");

}



int main(){

    Fila fila;


    inicializar(&fila);



    inserir(&fila,10);

    inserir(&fila,20);

    inserir(&fila,30);



    printf("Fila inicial:\n");

    imprimir(&fila);



    printf("\n\nElemento removido: %d\n", remover(&fila));



    printf("\nFila apos remocao:\n");

    imprimir(&fila);



    return 0;

}
