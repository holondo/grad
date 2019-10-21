#ifndef _carro
	#define _carro

    typedef struct _carro {
		int placa, hor_cheg, hor_said;
        float desc;
	} carro;

    carro check_in(int placa, int hor_cheg, int hor_said);
    //check_out(carro car);
    int disp(carro car);
    int rejeita(carro car);
    void registrar_carro();
    void imprimir_carro();
    void sair();

#endif