LABORATORIO - GRAFOS NAO DIRIGIDOS
===================================

Os programas usam o mesmo grafo de 7 vertices apresentado nos slides.

Vertices: 1, 2, 3, 4, 5, 6, 7
Arestas: 12

Matriz de adjacencia:

0 1 0 0 0 1 1
1 0 1 0 0 0 1
0 1 0 1 0 0 1
0 0 1 0 1 0 1
0 0 0 1 0 1 1
1 0 0 0 1 0 1
1 1 1 1 1 1 0

ARQUIVOS
---------
01_grau_vertices.c
02_numero_arestas.c
03_vertice_mais_popular.c
04_vertices_isolados.c
05_densidade.c
06_bfs.c
07_dfs.c
08_conectividade.c
09_componentes_conexas.c
10_menor_caminho_bfs.c
11_detectar_ciclo.c
12_verificar_arvore.c
13_bipartido.c
14_amigos_dos_amigos.c

COMPILACAO
----------
gcc -Wall -Wextra -std=c11 arquivo.c -o programa
./programa

Os programas sao exemplos-base para estudo. Para o laboratorio,
os alunos podem adaptar o algoritmo e justificar a complexidade.
