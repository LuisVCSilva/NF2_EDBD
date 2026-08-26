# Algoritmos de Ordenação — Bubble Sort e Merge Sort

Material de apoio para o seminário sobre algoritmos de ordenação, desenvolvido em C, Python e LaTeX Beamer.

O projeto foi estruturado como uma pequena infraestrutura experimental para permitir que os alunos:

* implementem algoritmos de ordenação em C;
* utilizem uma interface comum por meio de arquivos `.h`;
* executem os algoritmos sobre vetores de entrada;
* registrem os estados intermediários da execução;
* gerem automaticamente logs;
* produzam visualizações em PNG;
* gerem tabelas em LaTeX;
* obtenham métricas experimentais;
* gerem uma apresentação em LaTeX Beamer;
* adicionem novos algoritmos sem precisar modificar a lógica de visualização em Python.

A arquitetura foi pensada especialmente para que cada grupo possa criar seu próprio algoritmo de ordenação em C e utilizar a infraestrutura existente para realizar seu experimento. Você pode (**opcional**) usar esse código para seu seminário em NF2.

---

# 1. Objetivo didático

O objetivo do projeto é permitir que o estudo dos algoritmos de ordenação seja baseado na execução real do algoritmo, e não apenas em exemplos construídos manualmente.

O fluxo geral é:

```text
             VETOR DE ENTRADA
                    │
                    ▼
             Algoritmo em C
                    │
                    ▼
             Log de eventos
                    │
                    ▼
        codigo_ordenacao.py
                    │
          ┌─────────┼─────────┐
          │         │         │
          ▼         ▼         ▼
        PNGs     Tabelas   Métricas
          │         │         │
          └─────────┼─────────┘
                    │
                    ▼
             main_auto.tex
                    │
                    ▼
                 PDF
```

Assim, se o algoritmo ou o vetor de entrada forem modificados, é possível gerar novamente os resultados automaticamente.

---

# 2. Arquitetura do projeto

A arquitetura principal foi construída em camadas.

```text
                         ordenacao.h
                       /             \
                      ↓               ↓
              algum_algoritmo.c   outro_algoritmo.c
                    ↓                 ↓
               algum_algoritmo   outro_algoritmo
                    \                 /
                     \               /
                      ↓             ↓
                       logs de eventos
                              │
                              ▼
                    codigo_ordenacao.py
                              │
                    ┌─────────┴─────────┐
                    ↓                   ↓
                  PNGs                tabelas
                    \                   /
                     \                 /
                      ↓               ↓
                       main_auto.tex
                              │
                              ▼
                         PDF/Beamer
```

Essa separação é importante porque cada componente possui uma responsabilidade específica.

## Camada 1 — Algoritmo

Os algoritmos são implementados em C.

Exemplo:

```text
bubble.c
merge.c
quick.c
heap.c
...
```

Cada algoritmo utiliza a interface definida em:

```text
ordenacao.h
```

---

## Camada 2 — Execução

Os programas compilados são armazenados em:

```text
Codigo/bin/
```

Por exemplo:

```text
Codigo/bin/bubble
Codigo/bin/merge
```

Os executáveis recebem o vetor de entrada e executam efetivamente o algoritmo.

---

## Camada 3 — Logs

Durante a execução, o algoritmo registra eventos.

Por exemplo:

```text
INICIO;i=-1;j=-1;A=7,3,5,2
COMPARACAO;i=0;j=0;A=7,3,5,2
TROCA;i=0;j=0;A=3,7,5,2
COMPARACAO;i=0;j=1;A=3,7,5,2
TROCA;i=0;j=1;A=3,5,7,2
FIM;i=-1;j=-1;A=2,3,5,7
```

Os logs são armazenados em:

```text
Codigo/logs/
```

Por exemplo:

```text
Codigo/logs/bubble.log
Codigo/logs/merge.log
```

---

## Camada 4 — Python

O arquivo:

```text
Codigo/codigo_ordenacao.py
```

é responsável por interpretar os logs.

Ele não precisa conhecer a implementação interna do Bubble Sort, Merge Sort ou de qualquer outro algoritmo.

Ele trabalha com os eventos produzidos pelos algoritmos.

A partir desses eventos, pode gerar:

```text
          LOG
           │
           ▼
codigo_ordenacao.py
     │       │       │
     ▼       ▼       ▼
   PNGs   Tabelas  Métricas
```

---

## Camada 5 — Apresentação

Os resultados são utilizados para produzir:

```text
Apresentacao/main_auto.tex
```

que posteriormente é compilado para:

```text
Apresentacao/main_auto.pdf
```

---

# 3. Estrutura do projeto

A estrutura atual é:

```text
.
├── Apresentacao/
│   ├── main_auto.tex
│   ├── main_auto.pdf
│   └── arquivos auxiliares do LaTeX
│
├── Codigo/
│   ├── bin/
│   │   ├── bubble
│   │   └── merge
│   │
│   ├── logs/
│   │   ├── bubble.log
│   │   └── merge.log
│   │
│   ├── bubble/
│   │   ├── bubble_001.png
│   │   ├── bubble_002.png
│   │   └── ...
│   │
│   ├── merge/
│   │   ├── merge_001.png
│   │   ├── merge_002.png
│   │   └── ...
│   │
│   ├── ordenacao.h
│   ├── bubble.c
│   ├── merge.c
│   ├── gerar_vetor.c
│   ├── codigo_ordenacao.py
│   │
│   ├── bubble_table.tex
│   ├── merge_table.tex
│   └── metricas.json
│
├── Makefile
├── README.md
└── requirements.txt
```

Os arquivos dentro de `bin/`, `logs/`, `bubble/`, `merge/` e os arquivos gerados pelo LaTeX são artefatos de execução. Eles podem ser recriados pelo `Makefile`.

---

# 4. Interface `ordenacao.h`

O arquivo:

```text
Codigo/ordenacao.h
```

funciona como uma interface comum para os algoritmos.

A ideia é separar a interface da implementação.

Por exemplo, conceitualmente:

```c
#ifndef ORDENACAO_H
#define ORDENACAO_H

void bubble_sort(int A[], int n);

#endif
```

O arquivo `.c` contém a implementação:

```c
#include "ordenacao.h"

void bubble_sort(int A[], int n)
{
    ...
}
```

Essa organização permite que o aluno concentre seu trabalho na implementação do algoritmo.

---

# 5. Bubble Sort

O Bubble Sort está implementado em:

```text
Codigo/bubble.c
```

Sua função principal de ordenação possui a interface definida no `.h`.

Durante a execução, o algoritmo pode registrar eventos como:

```text
INICIO
COMPARACAO
TROCA
FIM
```

Por exemplo:

```text
INICIO;i=-1;j=-1;A=7,3,5,2
COMPARACAO;i=0;j=0;A=7,3,5,2
TROCA;i=0;j=0;A=3,7,5,2
...
FIM;i=-1;j=-1;A=2,3,5,7
```

Esses eventos posteriormente são utilizados pelo Python.

---

# 6. Merge Sort

O Merge Sort está implementado em:

```text
Codigo/merge.c
```

Sua execução pode produzir eventos como:

```text
INICIO
DIVISAO
COMPARACAO
INSERCAO
FUSAO
FIM
```

Por exemplo:

```text
DIVISAO;i=0;j=1;A=7,3,5,2
DIVISAO;i=2;j=3;A=7,3,5,2
COMPARACAO;i=0;j=0;A=7,3,5,2
...
FIM;i=-1;j=-1;A=2,3,5,7
```

O Python utiliza esses eventos para representar visualmente a execução recursiva do algoritmo.

---

# 7. Geração do vetor de entrada

O arquivo:

```text
Codigo/gerar_vetor.c
```

é responsável pela geração dos vetores utilizados nos experimentos.

O `Makefile` permite configurar, por exemplo:

```make
N = 10
ENTROPIA = 0.5
SEED = 12345
```

e gerar:

```text
Codigo/entrada/vetor.txt
```

Isso permite que Bubble Sort e Merge Sort sejam executados sobre a mesma entrada.

A utilização de uma semente fixa também permite reproduzir um experimento.

Por exemplo:

```text
N = 1000
SEED = 12345
```

pode ser utilizado novamente para produzir exatamente a mesma entrada, dependendo da implementação do gerador.

---

# 8. Makefile

O `Makefile` é o responsável por automatizar o projeto.

Ele realiza tarefas como:

```text
compilação
    ↓
geração do vetor
    ↓
execução
    ↓
logs
    ↓
frames
    ↓
tabelas
    ↓
métricas
    ↓
apresentação
    ↓
PDF
```

A ideia é evitar que o aluno precise executar manualmente dezenas de comandos.

---

# 9. Compilação

Para compilar os algoritmos:

```bash
make compile
```

Isso gera:

```text
Codigo/bin/bubble
Codigo/bin/merge
```

---

# 10. Geração da entrada

Para gerar o vetor:

```bash
make input
```

Os parâmetros podem ser alterados diretamente no comando:

```bash
make input N=100 SEED=12345 ENTROPIA=0.5
```

Por exemplo:

```bash
make input N=1000 SEED=42 ENTROPIA=0
```

gera uma entrada com os parâmetros especificados pelo experimento.

---

# 11. Execução dos algoritmos

Para executar os algoritmos:

```bash
make run
```

O fluxo será aproximadamente:

```text
gerar vetor
      ↓
compilar algoritmos
      ↓
executar Bubble Sort
      ↓
executar Merge Sort
      ↓
gerar logs
```

Os logs ficam em:

```text
Codigo/logs/
```

---

# 12. Geração dos frames

Para gerar as imagens:

```bash
make frames
```

São produzidos arquivos como:

```text
Codigo/bubble/bubble_001.png
Codigo/bubble/bubble_002.png
...
```

e:

```text
Codigo/merge/merge_001.png
Codigo/merge/merge_002.png
...
```

---

# 13. Geração das tabelas

Para gerar as tabelas:

```bash
make tables
```

São produzidos:

```text
Codigo/bubble_table.tex
Codigo/merge_table.tex
```

---

# 14. Métricas

Para gerar as métricas:

```bash
make metrics
```

O resultado é armazenado em:

```text
Codigo/metricas.json
```

Essas métricas podem ser utilizadas posteriormente para comparar experimentalmente os algoritmos.

---

# 15. Benchmark

O alvo:

```bash
make benchmark
```

executa a etapa de benchmark/métricas.

A infraestrutura pode ser expandida para registrar:

* tempo de execução;
* tamanho do vetor;
* número de comparações;
* número de trocas;
* número de inserções;
* quantidade de eventos;
* uso de memória;
* profundidade da recursão;
* outras medidas experimentais.

---

# 16. Apresentação

Para gerar o arquivo Beamer:

```bash
make presentation
```

Isso produz:

```text
Apresentacao/main_auto.tex
```

Para gerar o PDF:

```bash
make pdf
```

Resultado:

```text
Apresentacao/main_auto.pdf
```

---

# 17. Execução completa

Para executar todo o pipeline:

```bash
make
```

O processo é:

```text
make
 │
 ├── compile
 │     ├── bubble.c → bubble
 │     └── merge.c  → merge
 │
 ├── input
 │     └── vetor.txt
 │
 ├── run
 │     ├── bubble → bubble.log
 │     └── merge  → merge.log
 │
 ├── frames
 │     ├── bubble/*.png
 │     └── merge/*.png
 │
 ├── tables
 │     ├── bubble_table.tex
 │     └── merge_table.tex
 │
 ├── metrics
 │     └── metricas.json
 │
 ├── presentation
 │     └── main_auto.tex
 │
 └── pdf
       └── main_auto.pdf
```

---

# 18. Como criar seu próprio algoritmo

Essa é uma das principais propostas do projeto.

Suponha que um grupo queira implementar:

```text
Quick Sort
```

O aluno deve criar, por exemplo:

```text
Codigo/quick.c
```

e implementar sua função de ordenação.

A função deve utilizar a interface definida no projeto.

Por exemplo:

```c
#include "ordenacao.h"

void quick_sort(int A[], int n)
{
    ...
}
```

A implementação específica do Quick Sort fica dentro de:

```text
quick.c
```

enquanto a interface fica em:

```text
ordenacao.h
```

---

# 19. Exemplo de novo algoritmo

Imagine que o grupo queira implementar Selection Sort.

A estrutura poderia ser:

```text
Codigo/
├── ordenacao.h
├── selection.c
├── bubble.c
└── merge.c
```

No header:

```c
#ifndef ORDENACAO_H
#define ORDENACAO_H

void bubble_sort(int A[], int n);

void merge_sort(int A[], int n);

void selection_sort(int A[], int n);

#endif
```

E no novo arquivo:

```c
#include "ordenacao.h"

void selection_sort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < n; j++) {

            if (A[j] < A[menor]) {
                menor = j;
            }
        }

        if (menor != i) {

            int temp = A[i];

            A[i] = A[menor];

            A[menor] = temp;
        }
    }
}
```

O algoritmo em si continua sendo responsabilidade do aluno.

---

# 20. O protocolo de eventos

Para que o algoritmo possa ser visualizado automaticamente pelo Python, é necessário que ele produza eventos no formato esperado.

Por exemplo:

```text
INICIO;i=-1;j=-1;A=7,3,5,2
COMPARACAO;i=0;j=1;A=7,3,5,2
TROCA;i=0;j=1;A=3,7,5,2
FIM;i=-1;j=-1;A=2,3,5,7
```

A ideia é que o Python não precise saber como o algoritmo funciona.

Ele precisa apenas saber:

> "Qual evento ocorreu e qual era o estado do vetor naquele momento?"

Isso torna a arquitetura independente do algoritmo.

---

# 21. Adicionando o algoritmo ao Makefile

Depois de criar, por exemplo:

```text
Codigo/selection.c
```

é necessário informar ao `Makefile` que existe um novo executável.

Por exemplo:

```make
SELECTION = $(BIN_DIR)/selection
SELECTION_SRC = Codigo/selection.c
```

e adicionar sua compilação:

```make
$(SELECTION): $(SELECTION_SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@
```

Também é necessário incluí-lo na regra `compile`:

```make
compile: $(BUBBLE) $(MERGE) $(SELECTION)
```

Agora:

```bash
make compile
```

produzirá:

```text
Codigo/bin/bubble
Codigo/bin/merge
Codigo/bin/selection
```

---

# 22. Executando somente seu algoritmo

Depois de adicionar o executável, o aluno pode executar apenas seu algoritmo.

Por exemplo:

```bash
cd Codigo
python3 codigo_ordenacao.py --algorithm selection --run
```

Para gerar seus frames:

```bash
cd Codigo
python3 codigo_ordenacao.py --algorithm selection --run --frames
```

Para gerar métricas:

```bash
cd Codigo
python3 codigo_ordenacao.py \
    --algorithm selection \
    --run \
    --metrics
```

Para gerar várias coisas de uma vez:

```bash
cd Codigo
python3 codigo_ordenacao.py \
    --algorithm selection \
    --run \
    --frames \
    --tables \
    --metrics
```

---

# 23. Criando um experimento próprio

Cada grupo pode alterar os parâmetros da entrada.

Por exemplo:

```bash
make input N=1000 SEED=12345 ENTROPIA=0.5
```

Depois:

```bash
make compile
```

e executar seu algoritmo.

Por exemplo:

```bash
cd Codigo

python3 codigo_ordenacao.py \
    --algorithm selection \
    --run \
    --frames \
    --tables \
    --metrics
```

Assim, o grupo terá:

```text
selection.log
selection/*.png
selection_table.tex
metricas.json
```

e poderá utilizar os resultados na apresentação.

---

# 24. Comparando seu algoritmo com os existentes

Uma das possibilidades é executar:

```bash
cd Codigo

python3 codigo_ordenacao.py \
    --algorithm bubble merge selection \
    --run \
    --frames \
    --tables \
    --metrics
```

Isso permite comparar:

```text
Bubble Sort
     │
     ├── execução
     ├── visualização
     └── métricas
          │
          ├─────────────┐
          │             │
Merge Sort              Selection Sort
     │                       │
     ├── execução            ├── execução
     ├── visualização        ├── visualização
     └── métricas            └── métricas
```

---

# 25. Arquitetura para expansão

A ideia central pode ser resumida em:

```text
                    ordenacao.h
                         │
             ┌───────────┼───────────┐
             │           │           │
             ▼           ▼           ▼
          bubble.c     merge.c    selection.c
             │           │           │
             ▼           ▼           ▼
          Bubble       Merge      Selection
           Sort         Sort        Sort
             │           │           │
             └───────────┼───────────┘
                         │
                         ▼
                  logs de eventos
                         │
                         ▼
              codigo_ordenacao.py
                         │
             ┌───────────┼───────────┐
             │           │           │
             ▼           ▼           ▼
           PNGs       Tabelas      Métricas
             │           │           │
             └───────────┼───────────┘
                         │
                         ▼
                   main_auto.tex
                         │
                         ▼
                    main_auto.pdf
```

Essa arquitetura permite adicionar algoritmos sem modificar a ideia fundamental do sistema.

---

# 26. Responsabilidade do aluno

Ao adicionar um novo algoritmo, o aluno deve se concentrar principalmente em:

1. implementar o algoritmo em C;
2. incluir a interface necessária em `ordenacao.h`;
3. registrar os eventos relevantes;
4. adicionar o executável ao `Makefile`;
5. executar seus experimentos;
6. analisar os resultados;
7. apresentar a complexidade teórica e os resultados experimentais.

A infraestrutura de Python pode então ser reutilizada para gerar:

```text
logs
↓
frames
↓
tabelas
↓
métricas
↓
slides
```

---

# 27. Reprodutibilidade

Para comparar algoritmos corretamente, é importante controlar as condições experimentais.

Recomenda-se registrar:

```text
Algoritmo
Tamanho do vetor
Semente
Distribuição da entrada
Entropia
Compilador
Flags de compilação
Sistema operacional
Hardware
Número de execuções
```

Por exemplo:

```text
Algoritmo:   Merge Sort
N:           10000
Seed:        12345
Entropia:    0.5
Compilador:  GCC
Flags:       -O2
```

O mesmo vetor pode então ser utilizado por diferentes algoritmos, permitindo uma comparação mais justa.

---

# 28. Dependências

As dependências Python estão em:

```text
requirements.txt
```

Podem ser instaladas com:

```bash
pip install -r requirements.txt
```

O projeto utiliza principalmente:

* Python 3;
* Matplotlib;
* GCC;
* LaTeX;
* Beamer;
* TikZ;
* PGFPlots.

Verifique as instalações:

```bash
gcc --version
python3 --version
pdflatex --version
```

E o Matplotlib:

```bash
python3 -c "import matplotlib; print(matplotlib.__version__)"
```

---

# 29. Limpeza

Para remover os arquivos gerados:

```bash
make clean
```

Isso remove os artefatos de compilação e execução, como:

```text
bin/
logs/
frames
tabelas
métricas
arquivos auxiliares do LaTeX
PDF
```

Os arquivos-fonte permanecem intactos.

---

# 30. Manim

O projeto utiliza Matplotlib para gerar os frames por ser uma solução simples e adequada à visualização dos estados dos algoritmos.

Como extensão, os alunos podem experimentar o [Manim](https://github.com/3b1b/manim) para criar animações mais elaboradas.

O Manim pode ser interessante para representar:

* movimentação dos elementos;
* comparações;
* chamadas recursivas;
* divisão e fusão;
* estruturas de dados;
* árvores de recursão;
* análise de complexidade.

---

# 31. Possíveis algoritmos

A infraestrutura pode ser utilizada para diversos algoritmos, como:

```text
Bubble Sort
Selection Sort
Insertion Sort
Merge Sort
Quick Sort
Heap Sort
Shell Sort
Counting Sort
Radix Sort
```

Também é possível utilizar o projeto para estudar outras técnicas que possam ser representadas por uma sequência de estados.

---

# 32. Experimentos possíveis

Depois de implementar o algoritmo, o grupo pode realizar experimentos variando:

### Tamanho da entrada

```text
N = 10
N = 100
N = 1000
N = 10000
N = 100000
```

### Tipo de entrada

```text
ordenada
parcialmente ordenada
aleatória
inversamente ordenada
```

### Semente

```text
SEED = 1
SEED = 42
SEED = 12345
...
```

### Algoritmo

```text
Bubble
Merge
Quick
Selection
...
```

Os resultados podem então ser utilizados para analisar experimentalmente as diferenças entre os algoritmos.

---

# 33. Ideia central do projeto

O projeto não foi desenvolvido apenas para produzir uma animação.

A proposta é criar uma infraestrutura que conecte:

```text
IMPLEMENTAÇÃO
      +
EXECUÇÃO
      +
INSTRUMENTAÇÃO
      +
VISUALIZAÇÃO
      +
ANÁLISE EXPERIMENTAL
      +
APRESENTAÇÃO
```

O aluno implementa seu algoritmo em C, utiliza a interface definida em `ordenacao.h`, adiciona o programa ao `Makefile` e passa a utilizar a infraestrutura existente para executar seus próprios experimentos.

O resultado é um fluxo automatizado:

```text
                  SEU ALGORITMO
                        │
                        ▼
                    seu_alg.c
                        │
                        ▼
                  seu_algoritmo
                        │
                        ▼
                     LOG
                        │
                        ▼
             codigo_ordenacao.py
                        │
          ┌─────────────┼─────────────┐
          ▼             ▼             ▼
        FRAMES        TABELAS      MÉTRICAS
          │             │             │
          └─────────────┼─────────────┘
                        ▼
                  main_auto.tex
                        │
                        ▼
                       PDF
```

A principal ideia é que cada grupo seja capaz de colocar seu próprio algoritmo dentro dessa arquitetura e utilizar a mesma infraestrutura para realizar, visualizar e apresentar seu experimento.

