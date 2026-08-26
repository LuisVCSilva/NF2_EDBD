#include <stdio.h>


void remover(int lista[], int *tamanho, int pos){


    for(int i=pos;i<(*tamanho)-1;i++){

        lista[i] = lista[i+1];

    }


    (*tamanho)--;

}



int main(){

    int lista[10]={10,20,30,40};

    int tamanho=4;


    remover(lista,&tamanho,2);


    for(int i=0;i<tamanho;i++){

        printf("%d ",lista[i]);

    }


    return 0;
}
