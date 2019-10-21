#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char op[10];
} ord;

typedef struct _no {
    ord op;
    struct _no* esq;
    struct _no* dir;
} no;

typedef struct pilha {
    ord vet[1000];
    int topo;
} Pilha;

int isEmpty(Pilha p) {
    return p.topo == -1;
}

int push(Pilha* p, ord x){
    if (p->topo == 999)
        return 1;
    p->topo++;
    p->vet[p->topo] = x;
    return 0;
}

int pop(Pilha* p, ord* x) {
    if (isEmpty(*p))
        return 1;
    *x = p->vet[p->topo];
    p->topo--;
    return 0;
}


int geraArvore(ord exp[]) {
    printf("%s NA ÁRVORE\n", exp);
    int x = 0;
//exp[x++].op != '\0'
    while(x++ < 10) {
        printf("VALOR DE EXP: %s VALOR DE X: %d\n",exp[0].op, x);
        //Verifica se é um operando
        if( strcmp(exp[x].op, "+") == 0 || strcmp(exp[x].op, "-") == 0 || strcmp(exp[x].op, "/") == 0 || strcmp(exp[x].op, "*") == 0 || strcmp(exp[x].op, "**") == 0) {
            //printf("%s É OPERANDO \n", exp[x].op);

        }

        //Verifica se é delimitador
        else if( strcmp(exp[x].op, "{") == 0 || strcmp(exp[x].op, "}") == 0 || strcmp(exp[x].op, "(") == 0 || strcmp(exp[x].op, ")") == 0 || strcmp(exp[x].op, "[") == 0 || strcmp(exp[x].op, "]") == 0) {
            //printf("%s É DELIMITADOR \n", exp[x].op);
            //push(p, exp[x].op);

        }

        //Verifica se é número
        else
            //printf("%s É NÚMERO \n", exp[x].op);

        x=x;
    }
    return 0;
}

int main () {

    ord ordOp[5];
    ord exp[1000];
    //Problema do ** -> são dois caracteres
    scanf("%s %s %s %s %s", ordOp[0].op, ordOp[1].op, ordOp[2].op, ordOp[3].op, ordOp[4].op);
    scanf("%s", exp);
    printf("%s \n", exp);

    geraArvore(exp);

}
