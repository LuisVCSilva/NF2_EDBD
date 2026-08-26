#include <stdio.h>


void inserir(int lista[], int *tamanho, int pos, int valor){

    for(int i=*tamanho; i>pos; i--){

        lista[i] = lista[i-1];

    }


    lista[pos] = valor;

    (*tamanho)++;

}



int main(){

    int lista[10] = {10,20,30,40};

    int tamanho = 4;


    inserir(lista,&tamanho,1,15);


    for(int i=0;i<tamanho;i++){

        printf("%d ",lista[i]);

    }


    return 0;
}
