CC = gcc
CFLAGS = -Wall -Wextra -std=c99

PROGRAMS = estoque app_fila validador app_lista app_bst percursos_avl percursos_bst

all: $(PROGRAMS)

estoque: apps/estoque.c AVL/avl.c
	$(CC) $(CFLAGS) $^ -o $@

app_fila: apps/fila_pedidos.c fila/fila_dinamica.c
	$(CC) $(CFLAGS) $^ -o $@

validador: apps/validador_expressao.c pilha/pilha_caractere.c
	$(CC) $(CFLAGS) $^ -o $@

app_lista: apps/historico_navegacao.c lista/lista_ligada.c
	$(CC) $(CFLAGS) $^ -o $@

app_bst: apps/venda_ingressos_bst.c BST/bst.c
	$(CC) $(CFLAGS) $^ -o $@

percursos_avl: apps/teste_percursos.c AVL/avl.c
	$(CC) $(CFLAGS) $^ -o $@

percursos_bst: apps/teste_percursos_bst.c BST/bst.c
	$(CC) $(CFLAGS) $^ -o $@

run-estoque: estoque
	./$<

run-fila: app_fila
	./$<

run-validador: validador
	./$<

run-lista: app_lista
	./$<

run-bst: app_bst
	./$<

run-percursos-avl: percursos_avl
	./$<

run-percursos-bst: percursos_bst
	./$<

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean \
	run-estoque \
	run-fila \
	run-validador \
	run-lista \
	run-bst \
	run-percursos-avl \
	run-percursos-bst
