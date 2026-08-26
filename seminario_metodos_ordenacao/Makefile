# ============================================================
# COMPILADORES E FERRAMENTAS
# ============================================================

CC = gcc
CFLAGS = -Wall -Wextra -O2

PYTHON = python3
LATEX = pdflatex


# ============================================================
# DIRETÓRIOS
# ============================================================

BIN_DIR = Codigo/bin
LOG_DIR = Codigo/logs
INPUT_DIR = Codigo/entrada


# ============================================================
# EXECUTÁVEIS
# ============================================================

BUBBLE = $(BIN_DIR)/bubble
MERGE = $(BIN_DIR)/merge
GERADOR = $(BIN_DIR)/gerar_vetor


# ============================================================
# CÓDIGOS-FONTE
# ============================================================

BUBBLE_SRC = Codigo/bubble.c
MERGE_SRC = Codigo/merge.c
GERADOR_SRC = Codigo/gerar_vetor.c

HEADER = Codigo/ordenacao.h


# ============================================================
# ARQUIVO DE ENTRADA
# ============================================================

INPUT_FILE = $(INPUT_DIR)/vetor.txt


# ============================================================
# CONFIGURAÇÃO DO EXPERIMENTO
#
# Podem ser alterados pela linha de comando:
#
# make input N=100 ENTROPIA=0.5 SEED=12345
#
# ============================================================

N = 10
ENTROPIA = 0.5
SEED = 12345


# ============================================================
# ALGORITMOS
# ============================================================

ALGORITMOS = bubble merge


# ============================================================
# TARGETS
# ============================================================

.PHONY: all \
        compile \
        input \
        run \
        frames \
        tables \
        metrics \
        benchmark \
        presentation \
        pdf \
        clean


# ============================================================
# PADRÃO
# ============================================================

all: pdf


# ============================================================
# COMPILA TODOS OS ALGORITMOS
# ============================================================

compile: $(BUBBLE) $(MERGE)


# ============================================================
# DIRETÓRIO DOS EXECUTÁVEIS
# ============================================================

$(BIN_DIR):
	mkdir -p $(BIN_DIR)


# ============================================================
# BUBBLE SORT
# ============================================================

$(BUBBLE): $(BUBBLE_SRC) $(HEADER) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@


# ============================================================
# MERGE SORT
# ============================================================

$(MERGE): $(MERGE_SRC) $(HEADER) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@


# ============================================================
# GERADOR DE VETORES
# ============================================================

$(GERADOR): $(GERADOR_SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@ -lm


# ============================================================
# DIRETÓRIO DE ENTRADA
# ============================================================

$(INPUT_DIR):
	mkdir -p $(INPUT_DIR)


# ============================================================
# GERA VETOR DE ENTRADA
# ============================================================

input: $(GERADOR) | $(INPUT_DIR)

	@echo ""
	@echo "============================================================"
	@echo "GERANDO VETOR"
	@echo "============================================================"
	@echo "Tamanho:   $(N)"
	@echo "Entropia:  $(ENTROPIA)"
	@echo "Semente:   $(SEED)"
	@echo "Arquivo:   $(INPUT_FILE)"
	@echo ""

	$(GERADOR) \
		$(N) \
		$(ENTROPIA) \
		$(SEED) \
		$(INPUT_FILE)


# ============================================================
# EXECUTA OS ALGORITMOS
# ============================================================

run: compile input

	cd Codigo && \
	$(PYTHON) codigo_ordenacao.py --run


# ============================================================
# GERA FIGURAS
# ============================================================

frames: run

	cd Codigo && \
	$(PYTHON) codigo_ordenacao.py --frames


# ============================================================
# GERA TABELAS
# ============================================================

tables: run

	cd Codigo && \
	$(PYTHON) codigo_ordenacao.py --tables


# ============================================================
# GERA MÉTRICAS
# ============================================================

metrics: run

	cd Codigo && \
	$(PYTHON) codigo_ordenacao.py --metrics


# ============================================================
# BENCHMARK
# ============================================================

benchmark: metrics

	@echo ""
	@echo "Benchmark concluído."
	@echo "Arquivo: Codigo/metricas.json"
	@echo ""


# ============================================================
# GERA APRESENTAÇÃO
# ============================================================

presentation: tables frames

	cd Codigo && \
	$(PYTHON) codigo_ordenacao.py --presentation


# ============================================================
# GERA PDF
# ============================================================

pdf: presentation

	cd Apresentacao && \
	$(LATEX) -interaction=nonstopmode main_auto.tex


# ============================================================
# LIMPEZA
# ============================================================
clean:
	@echo "Limpando arquivos gerados..."

	rm -rf $(BIN_DIR)
	rm -rf $(LOG_DIR)
	rm -rf $(INPUT_DIR)

	rm -f Codigo/bubble/*.png
	rm -f Codigo/merge/*.png

	rm -f Codigo/*_table.tex
	rm -f Codigo/metricas.json

	rm -f Apresentacao/*.aux
	rm -f Apresentacao/*.log
	rm -f Apresentacao/*.nav
	rm -f Apresentacao/*.out
	rm -f Apresentacao/*.snm
	rm -f Apresentacao/*.toc
	rm -f Apresentacao/*.vrb
	rm -f Apresentacao/*.fls
	rm -f Apresentacao/*.fdb_latexmk
	rm -f Apresentacao/*.synctex.gz
	rm -f Apresentacao/*.pdf

	@echo "Limpeza concluída."
