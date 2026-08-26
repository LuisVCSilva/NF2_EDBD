void inserirFim(No **lista, int valor){


    No *novo = malloc(sizeof(No));

    novo->dado = valor;

    novo->prox = NULL;



    if(*lista == NULL){

        *lista = novo;

    }

    else{

        No *aux = *lista;


        while(aux->prox != NULL){

            aux = aux->prox;

        }


        aux->prox = novo;

    }

}
