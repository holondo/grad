#ifndef HASH_H


    #define HASH_H
    #define FREE "-1"
    #define DEL "-2"
    
    
    typedef struct _login {
		char name[100]; //name
		char pass[100];  //password
	} login;
	
    typedef struct _Htab {
		int n; //free spaces of hash table
		int m; //size of hash table
		login *t; //hash table 
	} Htab;
	
	
	
	/* Inicializa tabela hash
    	posicoes sao inicializadas com FREE indicando espacos livres
       Parâmetros:
    	int m - tamanho da tabela
	   Retorno:
		Tabela hash
    */
	Htab* init_tab();
	
	/* Insere elemento na tabela Hash
       Parametros:
    	Htab t 		- Estrutura com tabela hash, tamanho e quantidade ocupada
    	login user 	- chave a ser procurada
	   Retorno:
	    0 - Não foi encontrado
	    1 - Foi encontrado
    */
	int insert_tab(Htab* t_hash, login user);
	
	
	/* Deleta elemento da tabela Hash
       Parâmetros:
    	Htab t 		- Estrutura com tabela hash, tamanho e quantidade ocupada
    	login key 	- chave a ser removida
	   Retorno:
	    Sem retorno
    */
    void delete_tab(Htab* t, login key);
    
    /* Procura elemento da tabela Hash
       Parâmetros:
    	Htab t 		- Estrutura com tabela hash, tamanho e quantidade ocupada
    	login key 	- chave a ser procurada
	   Retorno:
	    1 - Elemento encontrado
	    0 - Elemento não encontrado
    */
	int search_tab(Htab* t, login user);
	
	/* Determina posição do elemento a ser inserido na tabela hash
	  * Método da divisão
       Parâmetros:
    	int key - chave a ser inserida
    	int k   - quantidade de colisões
	   Retorno:
	    Retorna posição vaga 
    */
    int hash_division(int key, int m, int k); 
    
    /* Determina posição do elemento a ser inserido na tabela hash
     * Método da multiplicação
       Parametros:
    	int key - chave a ser inserida
    	int m   - tamanho da tabela
    	int k   - quantidade de colisões
       Retorno:
        Retorna posição vaga
    */
    int hash_multi(int key, double A, int m, int k);


    /* Cria tabela hash
    	posicoes sao inicializadas com FREE indicando espacos livres
       Parâmetros:
    	int m - tamanho da tabela
	   Retorno:
		Tabela hash
    */
    Htab* create_tab(Htab* tab);
    
	void exib_tab(Htab* tab);

#endif
