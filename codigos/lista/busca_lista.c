No* buscar(No *lista, int valor){


    while(lista != NULL){


        if(lista->dado == valor){

            return lista;

        }


        lista = lista->prox;

    }


    return NULL;

}
