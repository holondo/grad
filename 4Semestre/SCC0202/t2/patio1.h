#ifndef _patio1
	#define _patio1

    #include "carro.h"


    typedef struct _elem {
        carro atual;
        carro *prox;
    } elem;

    typedef struct _patio1 {
        elem* topo;
        elem tam[5];
    } p1;

    void p1_criar(p1 p, elem x);
    void p1_inserir(p1 p, elem x);
    elem p1_remover(p1 p, elem x);


#endif