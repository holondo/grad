#include "merge.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

login padroniza(login pAtual) {	
	for(int i = 0; pAtual.name[i] != '\0'; i++)
		pAtual.name[i] = tolower(pAtual.name[i]);
		
	return pAtual;
}

void merge(login *v, int ini, int centro, int fim) {
	login *aux = (login*) malloc(sizeof(login) * (fim-ini+1));
	
	int i = ini;
	int j = centro+1;
 	int k = 0;
 	
	while (i <= centro && j <= fim) {
		
		if (strcmp(padroniza(v[i]).name, padroniza(v[j]).name) < 0) {
			aux[k] = v[i]; 
			i++;
		} else {
			aux[k] = v[j];
			j++;
		}
		
		k++;
	}
	
	while (i <= centro) {
		aux[k] = v[i];
		i++; k++;
	}	
	
	while (j <= fim) {
		aux[k] = v[j];
		j++; k++;
	}	

	for (i = ini, k = 0; i <= fim; i++, k++)
		v[i] = aux[k];
		
	free(aux);
}

void mergesort (login *v, int ini, int fim) {
	if (fim <= ini) return;
	int centro = (int) ((fim+ini)/2.0);
	mergesort(v, ini, centro);
	mergesort(v, centro+1, fim);
	merge(v, ini, centro, fim);
}
