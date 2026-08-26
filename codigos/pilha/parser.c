#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX 100


// ----------------------------
// Pilha de números
// ----------------------------

typedef struct {

    double dados[MAX];
    int topo;

} PilhaNumero;



void pushNumero(PilhaNumero *p, double valor){

    p->dados[++p->topo] = valor;

}



double popNumero(PilhaNumero *p){

    return p->dados[p->topo--];

}



// ----------------------------
// Pilha de operadores
// ----------------------------

typedef struct {

    char dados[MAX];
    int topo;

} PilhaOperador;



void pushOperador(PilhaOperador *p, char op){

    p->dados[++p->topo] = op;

}



char popOperador(PilhaOperador *p){

    return p->dados[p->topo--];

}



char topoOperador(PilhaOperador *p){

    return p->dados[p->topo];

}



// ----------------------------
// Precedência
// ----------------------------

int prioridade(char op){

    if(op=='+' || op=='-')
        return 1;

    if(op=='*' || op=='/')
        return 2;

    return 0;

}



// ----------------------------
// Executa operação
// ----------------------------

double calcular(double a, double b, char op){

    switch(op){

        case '+':
            return a+b;

        case '-':
            return a-b;

        case '*':
            return a*b;

        case '/':
            return a/b;

    }

    return 0;

}



// ----------------------------
// Aplica operador no topo
// ----------------------------

void aplicarOperacao(
        PilhaNumero *nums,
        PilhaOperador *ops
){

    double b = popNumero(nums);

    double a = popNumero(nums);

    char op = popOperador(ops);


    double resultado =
        calcular(a,b,op);


    pushNumero(nums,resultado);

}



// ----------------------------
// Parser principal
// ----------------------------

double avaliar(char expressao[]){

    PilhaNumero numeros;

    PilhaOperador operadores;


    numeros.topo=-1;

    operadores.topo=-1;



    for(int i=0; expressao[i]!='\0'; i++){


        // Ignora espaços
        if(expressao[i]==' ')
            continue;



        // Número
        if(isdigit(expressao[i])){


            double valor=0;


            while(isdigit(expressao[i])){

                valor =
                valor*10 +
                (expressao[i]-'0');

                i++;

            }


            i--;


            pushNumero(&numeros,valor);

        }



        // Abre parênteses
        else if(expressao[i]=='('){


            pushOperador(
                &operadores,
                '('
            );

        }



        // Fecha parênteses
        else if(expressao[i]==')'){


            while(
            topoOperador(&operadores)
            != '('
            ){

                aplicarOperacao(
                    &numeros,
                    &operadores
                );

            }


            popOperador(&operadores);

        }



        // Operador
        else{


            while(
                operadores.topo!=-1 &&
                prioridade(
                    topoOperador(&operadores)
                )
                >= prioridade(expressao[i])
            ){

                aplicarOperacao(
                    &numeros,
                    &operadores
                );

            }


            pushOperador(
                &operadores,
                expressao[i]
            );

        }

    }



    // Processa operadores restantes

    while(operadores.topo!=-1){

        aplicarOperacao(
            &numeros,
            &operadores
        );

    }



    return popNumero(&numeros);

}



// ----------------------------
// Programa principal
// ----------------------------

int main(){


    char expressao[] =
        "3 + 5 * 2";


    double resultado =
        avaliar(expressao);



    printf("Expressao: %s\n",
            expressao);


    printf("Resultado: %.2lf\n",
            resultado);



    return 0;

}
