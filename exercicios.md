# Lista de Exercícios - Estruturas de Dados em C

## NF2 - Estruturas de Dados

### Curso: Sistemas de Informação

Professor: Prof. Me. Luis Vinicius Costa Silva


---

# Introdução

Esta lista de exercícios tem como objetivo desenvolver o raciocínio lógico e a capacidade de implementação de estruturas de dados utilizando a linguagem C.

Os exercícios estão organizados de forma progressiva, iniciando com:

- Tipos de dados;
- Estruturas (`struct`);
- Vetores;
- Funções;
- Tipos Abstratos de Dados (TAD);
- Listas;
- Pilhas;
- Filas.


O foco da atividade é compreender como representar informações e criar soluções eficientes para problemas computacionais.


---

# Objetivos

Ao final da atividade, o estudante deverá ser capaz de:

- Criar estruturas para representar objetos reais;
- Organizar dados utilizando diferentes estruturas;
- Implementar operações básicas;
- Separar dados e operações utilizando TADs;
- Analisar a eficiência das soluções.


---

# Organização do Projeto

Sugestão:

```
estrutura-dados/

│
├── README.md
│
├── exercicio01_alunos/
│   └── main.c
│
├── exercicio02_produtos/
│   └── main.c
│
├── exercicio03_lista_encadeada/
│   └── main.c
│
├── exercicio04_pilha/
│   └── main.c
│
└── exercicio05_fila/
    └── main.c
```


---

# Exercício 01 - Cadastro de Alunos

## Tema

- Abstração de dados;
- Structs;
- Vetores.


## Descrição

Uma escola precisa armazenar informações dos alunos.

Cada aluno possui:

- Matrícula;
- Nome;
- Idade;
- Nota final.


O programa deverá armazenar os dados de vários alunos e permitir consultas.


---

## Requisitos

Criar uma estrutura:

```c
typedef struct {

    int matricula;

    char nome[50];

    int idade;

    float nota;

} Aluno;
```


O programa deve permitir:

1. Cadastrar alunos;
2. Listar todos os alunos;
3. Buscar aluno pela matrícula;
4. Mostrar o aluno com maior nota.


---

## Conceitos trabalhados

- Representação de dados;
- Abstração;
- Vetores de estruturas.


---

# Exercício 02 - Sistema de Produtos

## Tema

- Structs;
- Organização de dados;
- Busca.


## Descrição

Uma loja deseja controlar seus produtos.


Cada produto possui:

- Código;
- Nome;
- Preço;
- Quantidade em estoque.


---

## Requisitos

Criar um programa que:

1. Cadastre produtos;
2. Exiba todos os produtos;
3. Busque produtos pelo código;
4. Calcule o valor total do estoque.


---

## Estrutura sugerida

```c
typedef struct {

    int codigo;

    char nome[50];

    float preco;

    int quantidade;

} Produto;
```


---

# Exercício 03 - Lista de Compras utilizando Lista Encadeada

## Tema

- Tipo Abstrato de Dados;
- Lista encadeada.


## Descrição

Implemente uma lista de compras utilizando uma lista encadeada.


Cada item possui:

- Nome do produto;
- Quantidade.


---

## Operações obrigatórias

Implementar funções:

```
inserir()
remover()
buscar()
listar()
```

---

## Estrutura sugerida

```c
typedef struct No {

    char produto[50];

    int quantidade;

    struct No *prox;

} No;
```


---

## Conceitos trabalhados

- Ponteiros;
- Alocação dinâmica;
- Listas.


---

# Exercício 04 - Pilha de Livros

## Tema

- Pilhas;
- TAD;
- Operações LIFO.


## Descrição

Uma biblioteca deseja controlar uma pilha de livros.

O último livro inserido será o primeiro removido.


Exemplo:

```
Inserir:

Livro A

Livro B

Livro C


Remover:

Livro C

Livro B

Livro A
```


---

## Operações obrigatórias

Implementar:

```
push()
pop()
top()
isEmpty()
```


---

## Estrutura sugerida

Utilizar vetor:

```c
#define MAX 100

typedef struct {

    char livros[MAX][50];

    int topo;

} Pilha;
```


---

# Exercício 05 - Fila de Atendimento

## Tema

- Filas;
- TAD;
- Operações FIFO.


## Descrição

Um banco deseja organizar sua fila de atendimento.

Os clientes são atendidos na ordem em que chegaram.


Exemplo:

Entrada:

```
Ana
João
Maria
```


Atendimento:

```
Ana
João
Maria
```


---

## Operações obrigatórias

Implementar:

```
enfileirar()
desenfileirar()
frente()
listar()
```


---

## Estrutura sugerida

```c
#define MAX 100

typedef struct {

    char clientes[MAX][50];

    int inicio;

    int fim;

} Fila;
```


---

# Exercício 06 - Agenda de Contatos

## Tema

- Vetores;
- Ordenação;
- Busca.


## Descrição

Criar uma agenda de contatos.


Cada contato possui:

- Nome;
- Telefone;
- Email.


---

## Requisitos

Implementar:

1. Cadastro de contatos;
2. Busca por nome;
3. Ordenação alfabética;
4. Remoção de contatos.


---

# Exercício 07 - Controle de Notas

## Tema

- Vetores;
- Funções;
- Análise de dados.


## Descrição

Uma turma possui várias notas.

O programa deve analisar o desempenho dos estudantes.


---

## Requisitos

Informar:

- Média da turma;
- Maior nota;
- Menor nota;
- Quantidade de alunos aprovados.


---

# Exercício 08 - Comparação de Algoritmos

## Tema

- Complexidade;
- Análise de algoritmos.


## Descrição

Implementar duas soluções para encontrar um elemento em um vetor:


### Busca Linear

Percorrer todos os elementos:

```
O(n)
```


### Busca Binária

Utilizar vetor ordenado:

```
O(log n)
```


---



# Lista de Exercícios - Recapitulação de Estruturas de Dados em C

## NF2 - Estruturas de Dados

Professor: Prof. Luis Vinicius


---

# Exercício 8 - Representação de Dados com Struct

## Tema

- Abstração de dados;
- Estruturas (`struct`).


## Descrição

Uma locadora deseja armazenar informações sobre filmes.

Cada filme possui:

- título;
- ano;
- duração.


Crie uma estrutura em C capaz de representar um filme.


## Exemplo esperado

```c
typedef struct{

    char titulo[100];

    int ano;

    int duracao;

}Filme;
```

## Conceitos trabalhados

* Abstração;
* Organização de informações;
* Tipos compostos.

---

# Exercício 9 - Maior Elemento de um Vetor

## Tema

* Vetores;
* Funções.

## Descrição

Implemente uma função que receba um vetor de números inteiros e retorne o maior valor armazenado.

Assinatura:

```c
int maior(int v[], int n);
```

## Requisitos

O programa deve:

1. Receber um vetor;
2. Percorrer todos os elementos;
3. Encontrar o maior valor;
4. Retornar o resultado.

## Conceitos trabalhados

* Percorrimento de vetores;
* Estruturas de repetição;
* Funções.

---

# Exercício 10 - Teste de Mesa

## Tema

* Execução de algoritmos;
* Rastreamento de variáveis.

## Descrição

Analise o código:

```c
int v[5]={2,4,6,8,10};

int soma=0;

for(int i=0;i<5;i++){

    soma += v[i];

}
```

Complete a tabela:

| i | v[i] | soma |
| - | ---- | ---- |
| 0 |      |      |
| 1 |      |      |
| 2 |      |      |
| 3 |      |      |
| 4 |      |      |

Informe a saída final do programa.

---

# Exercício 11 - Identificação de Erros

## Tema

* Debug;
* Vetores.

## Descrição

Analise o código:

```c
int v[4]={8,5,3,9};

for(int i=0;i<=4;i++){

    printf("%d ",v[i]);

}
```

Identifique o erro e corrija o programa.

---

# Exercício 12 - Complexidade Linear

## Tema

* Análise assintótica.

## Descrição

Determine a complexidade:

```c
for(int i=0;i<n;i++){

    printf("%d",i);

}
```

Explique sua resposta.

---

# Exercício 13 - Complexidade Quadrática

## Tema

* Laços aninhados.

## Descrição

Determine a complexidade:

```c
for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){

        printf("*");

    }

}
```

Explique sua resposta.

---

# Exercício 14 - Inserção em Lista Ligada

## Tema

* Lista encadeada;
* Ponteiros.

## Descrição

Considere a lista:

```
12 → 18 → 25 → NULL
```

Implemente a inserção do valor 8 no início.

Resultado esperado:

```
8 → 12 → 18 → 25 → NULL
```

---

# Exercício 15 - Inserção no Final da Lista

## Tema

* Lista ligada.

## Descrição

Considere:

```
5 → 10 → 15 → NULL
```

Mostre como ficará a lista após inserir o valor 20 no final.

Resultado esperado:

```
5 → 10 → 15 → 20 → NULL
```

---

# Exercício 16 - Operações com Pilha

## Tema

* Pilha;
* LIFO.

## Descrição

Uma pilha inicialmente vazia recebe:

```
push(2)

push(7)

push(9)

pop()

push(15)
```

Responda:

1. Qual o estado final?
2. Qual elemento está no topo?

---

# Exercício 17 - Implementação de Push

## Tema

* Pilha utilizando vetor.

## Descrição

Implemente a operação `push()` considerando:

```c
int pilha[100];

int topo=-1;
```

A função deve inserir um elemento no topo da pilha.

---

# Exercício 18 - Implementação de Pop

## Tema

* Remoção em pilha.

## Descrição

Implemente a operação `pop()` para remover o elemento no topo.

A função deve:

1. Retornar o valor removido;
2. Atualizar o topo.

---

# Exercício 19 - Operações com Fila

## Tema

* Filas;
* FIFO.

## Descrição

Uma fila executa:

```
enqueue("Ana")

enqueue("Carlos")

enqueue("Pedro")

dequeue()

enqueue("Lucas")
```

Informe o estado final da fila.

---

# Exercício 20 - Debug em Vetores

## Tema

* Erros de implementação.

## Descrição

Analise:

```c
int soma=0;


for(int i=1;i<5;i++){

    soma += v[i];

}
```

Identifique o problema e apresente a correção.

---

# Exercício 21 - Busca Sequencial

## Tema

* Busca;
* Complexidade.

## Descrição

Analise:

```c
for(int i=0;i<n;i++){

    if(v[i]==x)

        return i;

}
```

Responda:

1. Qual algoritmo está sendo utilizado?
2. Qual sua complexidade?

---

# Exercício 22 - Comparação entre Estruturas

## Tema

* Escolha de estruturas de dados.

## Descrição

Explique duas vantagens de uma lista ligada em relação a um vetor.

Possíveis respostas:

* Inserção mais simples;
* Remoção mais simples;
* Tamanho dinâmico;
* Não necessita memória contígua.

---


# Exercício 23 - Tipo Abstrato de Dados para Séries Matemáticas

## Tema

- Tipos Abstratos de Dados (TAD);
- Estruturas de dados;
- Funções matemáticas;
- Implementação em C.


---

## Descrição

Uma aplicação científica precisa calcular valores aproximados de funções matemáticas utilizando séries infinitas.

Uma das séries mais conhecidas é a **Série de Leibniz**, utilizada para aproximar o valor de π:


\[
\pi = 4\left(1-\frac{1}{3}+\frac{1}{5}-\frac{1}{7}+\frac{1}{9}-...\right)
\]


Quanto maior o número de termos utilizados, maior a aproximação obtida.


O objetivo é criar um **Tipo Abstrato de Dados (TAD) Série** capaz de armazenar e calcular termos de uma série matemática.


---

# Requisitos

O estudante deve criar uma estrutura capaz de representar uma série.


A estrutura deve armazenar:

- quantidade de termos;
- valor acumulado;
- lista dos termos calculados.


Exemplo:


```c
typedef struct{

    int quantidade;

    double soma;

    double termos[1000];

}Serie;
```

---

# Operações do TAD

Implemente as seguintes funções:

## 1. Inicializar Série

Protótipo:

```c
void inicializar(Serie *s, int quantidade);
```

Responsável por:

* definir a quantidade de termos;
* zerar o acumulador;
* preparar a estrutura.

---

## 2. Gerar termos da Série de Leibniz

Protótipo:

```c
void calcularLeibniz(Serie *s);
```

A função deve armazenar cada termo:

[
1-\frac{1}{3}+\frac{1}{5}-\frac{1}{7}+...
]

Exemplo para 5 termos:

```
1.0

-0.333333

0.2

-0.142857

0.111111
```

---

## 3. Calcular aproximação de π

Protótipo:

```c
double calcularPi(Serie *s);
```

A função deve retornar:

[
\pi \approx 4 \times soma
]

---

## 4. Exibir os termos

Protótipo:

```c
void imprimirSerie(Serie *s);
```

A função deve mostrar todos os termos armazenados.

---

# Programa Principal

Crie um programa que:

1. Solicite ao usuário a quantidade de termos;

2. Crie uma variável do tipo `Serie`;

3. Inicialize a estrutura;

4. Calcule a série;

5. Mostre os termos;

6. Mostre o valor aproximado de π.

Exemplo de saída:

```
Quantidade de termos: 10


Termos:

1.000000

-0.333333

0.200000

-0.142857

...


Valor aproximado de PI:

3.041839
```

---

# Desafio Extra

Modifique o TAD para permitir calcular diferentes séries de Taylor.

Exemplo:

[
e^x =
1+x+\frac{x^2}{2!}+\frac{x^3}{3!}+...
]

Crie uma nova função:

```c
double calcularTaylor(Serie *s, double x);
```

que permita aproximar uma função utilizando diferentes valores de entrada.

---


# Análise de Complexidade

Responda:

1. Qual a complexidade da geração dos termos da série?

2. Como a complexidade muda se forem utilizados 100 termos ou 1 milhão de termos?

3. A estrutura escolhida é adequada para armazenar uma quantidade muito grande de termos?

---

# Objetivo

Desenvolver um TAD capaz de representar um problema matemático real utilizando estruturas de dados, separando:

* representação dos dados;
* operações disponíveis;
* implementação dos algoritmos.

```

Esse exercício faz uma ponte interessante entre a primeira unidade da disciplina (**abstração + TAD**) e estruturas lineares (**vetores/listas**), além de preparar o aluno para aplicações científicas e computacionais.
```




# Regras de Implementação

Todos os exercícios devem ser desenvolvidos em:

```
Linguagem C
```


Compilação:

```bash
gcc main.c -o programa
```


Execução:

```bash
./programa
```


---

# Organização do Código

Os programas devem conter:

- Função `main()`;
- Funções auxiliares;
- Estruturas bem definidas;
- Comentários explicativos.


Exemplo:

```c
void inserirAluno();

void listarAlunos();

void buscarAluno();
```


---

# Critérios de Avaliação

## Código

- Compilação correta;
- Organização;
- Legibilidade.


## Estruturas

- Uso correto de structs;
- Implementação adequada de TADs.


## Algoritmos

- Correção;
- Eficiência;
- Escolha da estrutura adequada.


---

