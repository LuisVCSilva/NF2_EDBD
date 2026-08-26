#include <stdio.h>


#define MAX 100


typedef struct {

    char dados[MAX];

    int topo;

}Pilha;



void push(Pilha *p,char c){

    p->dados[++p->topo]=c;

}



char pop(Pilha *p){

    return p->dados[p->topo--];

}



int verificar(char expressao[]){


    Pilha p;

    p.topo=-1;



    for(int i=0; expressao[i]!='\0'; i++){


        if(expressao[i]=='('){

            push(&p,'(');

        }


        else if(expressao[i]==')'){


            if(p.topo==-1)

                return 0;


            pop(&p);

        }

    }


    return p.topo==-1;

}



int main(){


    char expr[]="((3+5)*2)";


    if(verificar(expr))

        printf("Expressao correta");

    else

        printf("Expressao incorreta");


    return 0;

}
