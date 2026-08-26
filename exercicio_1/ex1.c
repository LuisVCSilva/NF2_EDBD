
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
Uma escola precisa armazenar informações dos alunos.

Cada aluno possui:

Matrícula;
Nome;
Idade;
Nota final.
O programa deverá armazenar os dados de vários alunos e permitir consultas.
*/

typedef struct Aluno {
    int matricula;
    float nota;
}Aluno;

#include <stdio.h>

int main() {
    Aluno x;
    printf("Entre com a matricula: ");
    scanf("%d",&x.matricula);


    printf("Entre com a nota do aluno #%d: ",x.matricula);
    scanf("%f",&x.nota);
    
    printf("\n Aluno com matricula #%d e nota %f criado!\n",x.matricula,x.nota);
    
    return 0;
}
