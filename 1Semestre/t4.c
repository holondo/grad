#include <stdio.h>
#include <stdlib.h>

typedef struct _coe{
    long int num, deno;
} coe;

//Printa os elementos da matriz
void printa(coe** pCoe, int nroEq, int nroCoe) {
    for (int lin = 0; lin < nroEq; lin++) {
        for(int col = 0; col < nroCoe; col++) {
            if(pCoe[lin][col].num % pCoe[lin][col].deno == 0)
                printf("%ld\t", pCoe[lin][col].num / pCoe[lin][col].deno);
            else
                printf("%ld/%ld \t ", pCoe[lin][col].num, pCoe[lin][col].deno);
        }
        printf("\n");
    }
}

// Calcula o mmc
int mmc(int num1, int num2) {
    long int resto, a, b;
    a = num1;
    b = num2;

    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);

    return ( num1 * num2) / a;
}


//Calcula a diferença entre dois números
coe sub_coe(coe a, coe b) {
    coe c;
    long int mmc1 = mmc(a.deno, b.deno);
    c.num = (mmc1/a.deno)*a.num - (mmc1/b.deno)*b.num;
    return c;
}

//Calcula a multiplicação entre dois números
coe mul_coe(coe a, coe b) {
    coe c;
    c.num = a.num * b.num;
    c.deno = a.deno * b.deno;
    return c;
}

//Calcula a divisão entre dois números
coe div_coe(coe a, coe b) {
    coe c;
    c.num = a.num * b.deno;
    c.deno = a.deno * b.num;
    return c;
}

void escal(coe **ppCoe, int nroEq, int nroCoe, int linP, int colP) {

    //Condição de parada
    if (linP == nroEq-1 || colP == nroCoe-2)
        return;

    //Swap
    for (int lin = linP ; lin < nroEq; lin++) {
        //Swap de linhas
        if (ppCoe[lin][colP].num != 0) {
            coe *pTemp = ppCoe[0];
            ppCoe[0] = ppCoe[lin];
            ppCoe[lin] = pTemp;
            break;
        }
    }

    //Faz as subtrações
    for (int lin = linP + 1; lin < nroEq; lin++) {
        coe razao = div_coe(ppCoe[lin][colP], ppCoe[linP][colP]);
        for (int col = colP; col < nroCoe; col++) {
            ppCoe[lin][col] = sub_coe(ppCoe[lin][col], mul_coe(ppCoe[linP][col], razao));
        }
    }

    //Passa para uma porção menor da matriz
    escal(ppCoe, nroEq, nroCoe, linP + 1, colP + 1);
}

int main() {
    int nroEq, nroCoe, numZ;
    coe **pCoe;

    scanf("%d %d", &nroEq, &nroCoe);
    //Guarda os numeradores e denominadores dos coeficientes das equações
    pCoe = (coe**) malloc( nroEq * sizeof(coe*) );
    for ( int x = 0; x < nroEq; x++)
        pCoe[x] = (coe*) malloc( nroCoe * sizeof(coe) );


    for (int x = 0; x < nroEq; x++)
        for (int y = 0; y < nroCoe; y++) {
            //Ignora as entradas não numéricas
            scanf("%*[^0-9]");
            scanf("%d %d", &pCoe[x][y].num, &pCoe[x][y].deno);
        }

    //Chama função de escalonamento
    escal(pCoe, nroEq, nroCoe, 0, 0);

    //Verifica se são coincidentes ou não
    for (int x = 0; x < nroEq; x++) {
        for (int y = 0; y < nroCoe; y++) {
            if(pCoe[x][y].num == 0)
                numZ++;
            if(numZ == nroCoe-1 && pCoe[x][nroCoe].num != 0) {
                printf("nao\n");
                break;
            }
        }
        if(x == nroEq - 1)
            printf("sim\n");
    }



    printa(pCoe, nroEq, nroCoe);

    //Liberando a memória heap
    for (int x = 0; x < nroEq; x++)
        free(pCoe[x]);
    free(pCoe);

    return 0;
}
