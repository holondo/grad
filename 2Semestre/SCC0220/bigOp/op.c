#include <stdlib.h>
#include <stdio.h>

typedef struct _bigInt {
	char* num;
	int nroDig;
} bigInt;

bigInt alocaNum(bigInt n) {
	//PARÂMETROS
	printf("-------------------------- \n");
	char num = '1';

	while ( num != '\n') {
		// 1 - getchar
		//2 - getchar
		//
		num = getchar();
		//CASTING
		n.num = realloc(n.num, n.nroDig * sizeof(char));
		n.num[n.nroDig++] = num;

		printf("NRO DIG - %d \n", n.nroDig-1);
		printf("DIG - %d \n", n.num);
	}

return n;
}

int main() {
	char operacao[13];
	bigInt pNum1, pNum2;
	pNum1.num = malloc(1);
	pNum1.nroDig = 1;
	pNum2.num = malloc(1);
	pNum2.nroDig = 1;



	//scanf("%s", &operacao);
	//fflush(stdin);
	pNum1 = alocaNum(pNum1);
	pNum2 = alocaNum(pNum2);

	//printf("DIG - %d", pNum1.nroDig);

/*
	switch(operacao) {

		case 'SOMA':

			break;

		case 'SUBTRACAO':
			break;

		case 'MULTIPLICACAO':
			break;

		case 'DIVISAO':
			break;
	}
*/

}
