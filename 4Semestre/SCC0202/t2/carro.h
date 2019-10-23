#ifndef _carro
	#define _carro

    typedef struct _carro {
		int placa, hor_cheg, hor_said;
        float desc;
	} carro;

    carro check_in(int bp[5]);
    void check_out(carro* p_car);
    int disp(carro car);
    int rejeita(carro car);
    void registrar_carro();
    void imprimir_carro();
    void sair();

#endif