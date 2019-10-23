#include "patio1.h"

void p1_criar(p1 *p) {
    p->topo = NULL;
    return;
}

int p1_estaCheio(p1 *p) {
    int cont = 0;
    elem *aux = p->topo;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return(cont == 5 ? 1 : 0);
}

int p1_estaVazio(p1 *p) {
    return(p->topo == NULL ? 1 : 0);
}

int p1_inserir(p1 *p, elem* x) { //elem x deve ser uma variável dinâmica
    if (p1_estaCheio(p))
        return 0; //erro pilha cheia
    elem *aux = p->topo;
    p->topo = x;
    x->prox = aux;
    return 1; //sucesso
}


int p1_remover(p1 *p, elem *x) {
    if (p1_estaVazio(p))
        return 0; //erro pilha vazia
    x = p->topo; //Copia o topo para retornar o valor por argumento da função
    p->topo = p->topo->prox; 
    return 1; //sucesso
}