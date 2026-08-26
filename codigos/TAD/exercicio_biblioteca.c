#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[100];
    bool disponivel;
} Livro;

void emprestar(Livro *livro) {
    if (livro->disponivel) {
        livro->disponivel = false;
        printf("Livro emprestado com sucesso.\n");
    } else {
        printf("Livro indisponivel.\n");
    }
}

void devolver(Livro *livro) {
    livro->disponivel = true;
    printf("Livro devolvido.\n");
}

void mostrarLivro(Livro livro) {
    printf("ID: %d\n", livro.id);
    printf("Titulo: %s\n", livro.titulo);
    printf("Disponivel: %s\n",
           livro.disponivel ? "Sim" : "Nao");
}

int main() {

    Livro livro;

    livro.id = 1;
    strcpy(livro.titulo, "Estruturas de Dados");
    livro.disponivel = true;

    mostrarLivro(livro);

    printf("\n");

    emprestar(&livro);

    printf("\n");

    mostrarLivro(livro);

    printf("\n");

    devolver(&livro);

    printf("\n");

    mostrarLivro(livro);

    return 0;
}