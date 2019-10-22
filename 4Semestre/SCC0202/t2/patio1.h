#ifndef _patio1

	#define _patio1
    #define TAM 5
    #include "carro.h"


    typedef struct _elem {
        carro atual;
        carro *prox;
    } elem;

    typedef struct _patio1 {
        elem* topo;
        elem vet[TAM];
    } p1;

    void p1_criar(p1 *p);
    int p1_estaCheio(p1 *p); 
    int p1_estaVazio(p1 *p);
    int p1_inserir(p1 *p, elem *x);
    int p1_remover(p1 *p, elem *x);


#endif