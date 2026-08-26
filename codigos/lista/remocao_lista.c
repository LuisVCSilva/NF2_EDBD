void removerInicio(No **lista){


    if(*lista != NULL){


        No *aux = *lista;


        *lista = (*lista)->prox;


        free(aux);


    }

}
