#include <stdio.h>
#include "carro.h"
#include "patio1.h"
#include <time.h>
#include <stdlib.h>

carro check_in(int bp[5]) {
    carro x;
    scanf("%d %d %d", x.placa, x.hor_cheg, x.hor_said);

    for (int i = 0; i < 5; i++)  //Verifica se a placa é duplicada no banco
      if(x.placa == bp[i])
        printf("Carro já estacionado no pátio /n");
    
    return(x);
}
int disp(carro car, p1 pi, p2 fi) {
    if(pi->topo == NULL)            //Caso o patio 1 estiver VAZIO 
        return 0;         //Estacionar no patio 1
    else                            //Caso o patio 1 NÃO estiver VAZIO
        if(fi->calda == NULL)       //Caso o patio 2 estiver VAZIO
            return 1;     //Estacionar no patio 2
        else {                      //Caso o patio 1 e o 2 NÃO estiverem VAZIOS
            if(p1_estaCheio(pi) && pi->topo.hor_said > car.hor_said) // patio 1 lotado e o novo carro vai sair depois do último estácionado
                return 1; //Estacionar no patio 2
            if(p2_estaCheio(fi))    //Caso o patio 2 esteja CHEIO
                return 0; //Estacionar no patio 1
        }   
        
    }        
    

}
int rejeita(carro car) {

}
void registrar_carro(){

}
void imprimir_carro(){

}
void sair(){

}
