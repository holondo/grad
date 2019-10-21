#include <stdio.h>

typedef struct {
    char op[10];
} ord;

typedef struct _no {
    ord op;
    struct _no* esq;
    struct _no* dir;
} no;

int main () {

    ord ordOp[5];
    ord exp[1000];
    //Problema do ** -> são dois caracteres
    scanf("%s %s %s %s %s", ordOp[0].op, ordOp[1].op, ordOp[2].op, ordOp[3].op, ordOp[4].op);
    scanf("%s", exp);
    printf("%s %s %s %s %s\n", ordOp[0].op, ordOp[1].op, ordOp[2].op, ordOp[3].op, ordOp[4].op);
    printf("%s \n", exp);
}
