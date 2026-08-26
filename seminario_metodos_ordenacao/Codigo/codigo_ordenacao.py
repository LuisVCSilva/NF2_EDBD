import os
import subprocess
import sys
import time
import matplotlib.pyplot as plt

import json
import os
import subprocess
import sys
import time
from pathlib import Path
import argparse

from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent



def criar_parser():

    parser = argparse.ArgumentParser(
        description=(
            "Geração de material didático para "
            "algoritmos de ordenação."
        )
    )


    parser.add_argument(
        "--run",
        action="store_true",
        help="Executa os algoritmos C e gera os logs."
    )

    parser.add_argument(
        "--frames",
        action="store_true",
        help="Gera os frames PNG."
    )

    parser.add_argument(
        "--tables",
        action="store_true",
        help="Gera as tabelas LaTeX."
    )

    parser.add_argument(
        "--metrics",
        action="store_true",
        help="Gera as métricas em JSON."
    )

    parser.add_argument(
        "--presentation",
        action="store_true",
        help="Gera o arquivo main_auto.tex."
    )


    parser.add_argument(
        "--algorithm",
        nargs="+",
        metavar="ALGORITMO",
        help=(
            "Algoritmos a processar. "
            "Se omitido, todos os algoritmos encontrados "
            "em Codigo/bin serão utilizados."
        )
    )

    return parser
    
def obter_acoes(args):

    acoes = []

    if args.frames:
        acoes.append("frames")

    if args.tables:
        acoes.append("tables")

    if args.metrics:
        acoes.append("metrics")

    if args.presentation:
        acoes.append("presentation")


    if not acoes:

        acoes = [
            "frames",
            "tables",
            "metrics",
            "presentation"
        ]

    return acoes

def descobrir_algoritmos():

    bin_dir = BASE_DIR / "bin"

    if not bin_dir.exists():
        return []

    return sorted(
        arquivo.name
        for arquivo in bin_dir.iterdir()
        if arquivo.is_file()
        and os.access(arquivo, os.X_OK)
    )

def executar(executavel, arquivo_log):


    inicio = time.perf_counter()

    resultado = subprocess.run(
        [str(executavel)],
        capture_output=True,
        text=True,
        check=True
    )

    fim = time.perf_counter()

    saida = resultado.stdout


    arquivo_log.parent.mkdir(
        parents=True,
        exist_ok=True
    )


    with open(
        arquivo_log,
        "w",
        encoding="utf-8"
    ) as arquivo:

        arquivo.write(saida)


    metricas = {

        "algoritmo": executavel.name,

        "tempo_execucao_segundos":
            fim - inicio,

        "codigo_retorno":
            resultado.returncode,

        "arquivo_log":
            str(arquivo_log),
    }

    return saida, metricas
        
def ler_log(arquivo):

    with open(
        arquivo,
        "r",
        encoding="utf-8"
    ) as f:

        return f.read()




def salvar_metricas(
    metricas,
    arquivo
):

    with open(
        arquivo,
        "w",
        encoding="utf-8"
    ) as f:

        json.dump(
            metricas,
            f,
            indent=4,
            ensure_ascii=False
        )


    print(
        f"Métricas: {arquivo}"
    )

def gerar_apresentacao_latex(algoritmos, arquivo):

    linhas = []


    linhas.extend([
        r"\documentclass[aspectratio=169,11pt]{beamer}",
        r"\usepackage[utf8]{inputenc}",
        r"\usepackage[T1]{fontenc}",
        r"\usepackage[brazil]{babel}",
        r"\usepackage{amsmath}",
        r"\usepackage{amssymb}",
        r"\usepackage{booktabs}",
        r"\usepackage{array}",
        r"\usepackage{graphicx}",
        r"\usepackage{xcolor}",
        r"\usetheme{Madrid}",
        r"\setbeamertemplate{navigation symbols}{}",
        "",
        r"\definecolor{azul}{RGB}{30,90,160}",
        r"\setbeamercolor{structure}{fg=azul}",
        r"\setbeamercolor{frametitle}{fg=azul,bg=white}",
        "",
        r"\title{Algoritmos de Ordenação}",
        r"\subtitle{Visualização dos algoritmos}",
        r"\author{Prof. Me. Luis Vinicius}",
        r"\institute{Estruturas de Dados e Algoritmos}",
        r"\date{}",
        "",
        r"\begin{document}",
        "",
        r"\begin{frame}",
        r"\titlepage",
        r"\end{frame}",
        "",
    ])



    for algoritmo in algoritmos:

        nome = algoritmo.title()

        tabela = (
            f"../Codigo/{algoritmo}_table.tex"
        )


        linhas.append(
            rf"\section{{{nome} Sort}}"
        )

        linhas.append("")



        linhas.extend([
            rf"\begin{{frame}}{{Teste de mesa — {nome} Sort}}",
            "",
            rf"\input{{{tabela}}}",
            "",
            r"\end{frame}",
            "",
        ])



        gerar_frame_animacao(
            linhas,
            algoritmo
        )



    linhas.extend([
        r"\end{document}",
        "",
    ])



    with open(
        arquivo,
        "w",
        encoding="utf-8"
    ) as f:

        f.write(
            "\n".join(linhas)
        )    

def interpretar_evento(linha):

    campos = linha.strip().split(";")

    evento = campos[0]

    i = int(
        campos[1].split("=")[1]
    )

    j = int(
        campos[2].split("=")[1]
    )

    valores = campos[3].split("=")[1]

    A = [
        int(x)
        for x in valores.split(",")
    ]

    return {
        "evento": evento,
        "i": i,
        "j": j,
        "A": A
    }


def gerar_frame_animacao(linhas, algoritmo):

    nome = algoritmo.title()

    pasta = BASE_DIR / algoritmo

    imagens = sorted(
        pasta.glob("*.png")
    )

    if not imagens:

        print(
            f"Nenhuma imagem encontrada para "
            f"{algoritmo}"
        )

        return



    linhas.extend([
        rf"\begin{{frame}}{{{nome} Sort — execução}}",
        "",
        r"\begin{center}",
        "",
    ])



    for indice, imagem in enumerate(
        imagens,
        start=1
    ):

        caminho = (
            f"../Codigo/"
            f"{algoritmo}/"
            f"{imagem.name}"
        )


        linhas.extend([
            rf"\only<{indice}>{{",
            rf"\includegraphics[width=0.85\textwidth]{{{caminho}}}",
            r"}",
            "",
        ])



    linhas.extend([
        r"\end{center}",
        "",
        r"\end{frame}",
        "",
    ])


class FrameWriter:

    def __init__(
        self,
        pasta,
        prefixo
    ):

        self.pasta = pasta
        self.prefixo = prefixo
        self.contador = 0

        os.makedirs(
            pasta,
            exist_ok=True
        )


    def salvar(
        self,
        A,
        titulo,
        destaque=None
    ):

        self.contador += 1

        fig, ax = plt.subplots(
            figsize=(10, 3)
        )

        x = range(len(A))


        ax.bar(
            x,
            A
        )



        if destaque:

            ax.bar(
                destaque,
                [A[i] for i in destaque]
            )



        ax.set_title(
            titulo,
            fontsize=14
        )

        ax.set_xlabel("Índice")
        ax.set_ylabel("Valor")

        ax.set_xticks(
            list(x)
        )



        maior = max(A)

        for i, valor in enumerate(A):

            ax.text(
                i,
                valor + maior * 0.04,
                str(valor),
                ha="center",
                fontsize=12
            )


        ax.set_ylim(
            0,
            maior * 1.25
        )

        ax.grid(
            axis="y",
            alpha=0.2
        )



        nome = (
            f"{self.prefixo}_"
            f"{self.contador:03d}.png"
        )

        caminho = os.path.join(
            self.pasta,
            nome
        )


        fig.savefig(
            caminho,
            dpi=150,
            bbox_inches="tight"
        )


        plt.close(fig)

        print(
            f"  {caminho}"
        )



def gerar_frames(algoritmo, saida):

    pasta = BASE_DIR / algoritmo
    pasta.mkdir(
        parents=True,
        exist_ok=True
    )

    for arquivo in pasta.glob(
        f"{algoritmo}_*.png"
    ):
        arquivo.unlink()

    contador = 0

    for linha in saida.splitlines():

        linha = linha.strip()

        if not linha:
            continue

        estado = interpretar_evento(linha)

        A = estado.get("A")

        if A is None:
            continue

        contador += 1

        fig, ax = plt.subplots(
            figsize=(10, 3)
        )

        x = range(len(A))

        ax.bar(x, A)

        ax.set_title(
            f"{algoritmo.title()} Sort",
            fontsize=14
        )

        ax.set_xlabel("Índice")
        ax.set_ylabel("Valor")
        ax.set_xticks(list(x))

        if A:

            maior = max(A)

            for i, valor in enumerate(A):

                ax.text(
                    i,
                    valor + maior * 0.04,
                    str(valor),
                    ha="center",
                    fontsize=12
                )

            ax.set_ylim(
                0,
                maior * 1.25
            )

        ax.grid(
            axis="y",
            alpha=0.2
        )

        caminho = (
            pasta
            / f"{algoritmo}_{contador:03d}.png"
        )

        fig.savefig(
            caminho,
            dpi=150,
            bbox_inches="tight"
        )

        plt.close(fig)

        print(caminho)

    return contador


def latex_vetor(A):

    return (
        r"$["
        + r",\;".join(
            str(x)
            for x in A
        )
        + r"]$"
    )



def gerar_tabela_latex(saida, arquivo):

    eventos = []

    for linha in saida.splitlines():

        if not linha.strip():
            continue

        estado = interpretar_evento(linha)

        if "A" not in estado:
            continue

        A = estado["A"].copy()


        if not eventos or A != eventos[-1]:

            eventos.append(A)



    linhas = []

    linhas.append(
        r"\begin{center}"
    )

    linhas.append("")

    linhas.append(
        r"\scriptsize"
    )

    linhas.append("")

    linhas.append(
        r"\begin{tabular}{c|c}"
    )

    linhas.append(
        r"\toprule"
    )

    linhas.append(
        r"Etapa & Vetor \\"
    )

    linhas.append(
        r"\midrule"
    )

    linhas.append("")



    for etapa, A in enumerate(eventos):

        vetor = latex_vetor(A)

        linhas.append(
            f"{etapa} & {vetor} \\\\"
        )

        linhas.append("")

        if etapa < len(eventos) - 1:

            linhas.append(
                r"\pause"
            )

            linhas.append("")



    linhas.append(
        r"\bottomrule"
    )

    linhas.append("")

    linhas.append(
        r"\end{tabular}"
    )

    linhas.append("")

    linhas.append(
        r"\end{center}"
    )



    with open(
        arquivo,
        "w",
        encoding="utf-8"
    ) as f:

        f.write(
            "\n".join(linhas)
        )


    print(
        f"Tabela LaTeX: {arquivo}"
    )
def main():


    parser = criar_parser()

    args = parser.parse_args()

    acoes = obter_acoes(args)



    if args.algorithm:

        algoritmos = args.algorithm

    else:

        algoritmos = descobrir_algoritmos()



    if not algoritmos:

        print(
            "Nenhum algoritmo encontrado em:"
        )

        print(
            BASE_DIR / "bin"
        )

        return 1



    algoritmos_processados = []

    metricas_algoritmos = []



    for algoritmo in algoritmos:

        executavel = (
            BASE_DIR
            / "bin"
            / algoritmo
        )

        arquivo_log = (
            BASE_DIR
            / "logs"
            / f"{algoritmo}.log"
        )



        if not executavel.is_file():

            print(
                f"Executável não encontrado: "
                f"{executavel}"
            )

            continue


        if not os.access(
            executavel,
            os.X_OK
        ):

            print(
                f"Executável sem permissão: "
                f"{executavel}"
            )

            continue



        print()

        print("=" * 60)

        print(
            f"PROCESSANDO "
            f"{algoritmo.upper()} SORT"
        )

        print("=" * 60)




        if (
            "run" in acoes
            or "metrics" in acoes
        ):

            try:

                saida, metricas = executar(
                    executavel,
                    arquivo_log
                )

            except Exception as erro:

                print(
                    f"Erro ao executar "
                    f"{algoritmo}: {erro}"
                )

                continue


        else:


            if not arquivo_log.is_file():

                print(
                    f"Log não encontrado: "
                    f"{arquivo_log}"
                )

                print(
                    "Execute primeiro com --run."
                )

                continue


            try:

                saida = ler_log(
                    arquivo_log
                )

            except Exception as erro:

                print(
                    f"Erro ao ler log de "
                    f"{algoritmo}: {erro}"
                )

                continue


            metricas = None



        if "metrics" in acoes:

            if metricas is not None:

                metricas_algoritmos.append(
                    metricas
                )

            else:

                print(
                    f"Métricas não disponíveis "
                    f"para {algoritmo}."
                )



        if "tables" in acoes:

            arquivo_tabela = (
                BASE_DIR
                / f"{algoritmo}_table.tex"
            )

            try:

                gerar_tabela_latex(
                    saida,
                    arquivo_tabela
                )

            except Exception as erro:

                print(
                    f"Erro ao gerar tabela "
                    f"de {algoritmo}: {erro}"
                )

                continue



        if "frames" in acoes:

            try:

                quantidade = gerar_frames(
                    algoritmo,
                    saida
                )

                print(
                    f"Frames gerados: "
                    f"{quantidade}"
                )

            except Exception as erro:

                print(
                    f"Erro ao gerar frames "
                    f"de {algoritmo}: {erro}"
                )

                continue



        algoritmos_processados.append(
            algoritmo
        )



    if not algoritmos_processados:

        print()

        print(
            "Nenhum algoritmo foi processado."
        )

        return 1



    if "metrics" in acoes:

        arquivo_metricas = (
            BASE_DIR
            / "metricas.json"
        )

        try:

            salvar_metricas(
                metricas_algoritmos,
                arquivo_metricas
            )

        except Exception as erro:

            print(
                f"Erro ao salvar métricas: "
                f"{erro}"
            )

            return 1

        print(
            f"Métricas: "
            f"{arquivo_metricas}"
        )



    if "presentation" in acoes:

        arquivo_apresentacao = (
            BASE_DIR.parent
            / "Apresentacao"
            / "main_auto.tex"
        )

        try:

            gerar_apresentacao_latex(
                algoritmos_processados,
                arquivo_apresentacao
            )

        except Exception as erro:

            print(
                f"Erro ao gerar apresentação: "
                f"{erro}"
            )

            return 1

        print(
            f"Apresentação: "
            f"{arquivo_apresentacao}"
        )



    print()

    print("=" * 60)

    print(
        "PROCESSAMENTO CONCLUÍDO"
    )

    print("=" * 60)

    print(
        f"Ações: "
        f"{', '.join(acoes)}"
    )

    print(
        f"Algoritmos: "
        f"{', '.join(algoritmos_processados)}"
    )

    print()

    return 0



if __name__ == "__main__":

    sys.exit(
        main()
    )
