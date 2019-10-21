#include <stdio.h>
#include <stdlib.h>

/*
 1- Entradas: x, expoentes de f(x) em ordem decrescente
 2 - Resolver função de x em x
 3 - g(x, f(X) )
 4 -

*/

typedef struct {
	int coe;
	int exp;
} par;


int main() {
    int x;
	par* eq;
	eq = (par*) malloc(sizeof(par));
    scanf("%d", &x);

    int cont = 0;
	int aloc = 2;
    while( scanf("%d %d", &eq[cont].coe, &eq[cont].exp) != EOF) {
	    printf("PRINT - %d %d \n", eq[cont].coe, eq[cont].exp);
        eq = (par*) realloc(eq,  aloc * sizeof(par) );

		aloc++;
		cont++;
    }

    free(eq);


}
