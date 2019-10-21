#include "hash.h"
#include "merge.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Htab* init_tab() {
	Htab *tab;
	tab = malloc(sizeof(Htab));
	tab->t = malloc(16 * sizeof(login));
	
	for (int i = 0; i < 16; i++) 
		strcpy(tab->t[i].name, FREE);
		
	tab->m = 16;
	tab->n = 0;
	
	return tab;
}

int insert_tab(Htab* t_hash, login user) {
	
	t_hash->n++;
	double A = (sqrt(5)-1)/2.0;
	int pos, k = -1;
	
	int i = 0, id_user = 0;
	
	while(user.name[i] != '\0')
		id_user += user.name[i];
		
	do {
		k++;
		//pos = hash_division(key, m, k);
		
		
		pos = hash_multi(id_user, A, t_hash->m, k);
		
		if (strcmp(t_hash->t[pos].name, user.name) != 0) 
			return 0;
		
	} while (strcmp(t_hash->t[pos].name, FREE) != 0 && strcmp(t_hash->t[pos].name, DEL) != 0);

	strcpy(t_hash->t[pos].name, user.name);
	strcpy(t_hash->t[pos].pass, user.pass);
	
	return 1;
}

void delete_tab(Htab* tab, login key) {
	int pos = search_tab(tab, key);
	if (pos < 0) return;
	strcpy(tab->t[pos].name, DEL);
	strcpy(tab->t[pos].pass, DEL); 
}

int search_tab(Htab* tab, login user) {

	double A = (sqrt(5)-1)/2.0;
	int pos, k = -1;
	int i = 0, id_user = 0;
	
	while(user.name[i] != '\0')
		id_user += user.name[i];
		
	do {
		k++;
		//pos = hash_division(key, m, k);
		pos = hash_multi(id_user, A, tab->m, k);
		if (strcmp(tab->t[pos].name, FREE) == 0) return -1;

	} while (strcmp(tab->t[pos].name, user.name) != 0 && strcmp(tab->t[pos].pass, user.pass) != 0);

	return pos;
}

int hash_division(int key, int m, int k) {
	return (int)( (key+(k*k)) % m);
}

int hash_multi(int key, double A, int m, int k) {
	double val = (key+(k*k))*A;
	val = val - ((int)val);
	return (int)(val*m);
}

Htab* create_tab(Htab* tab) {
	Htab* tab_copy = malloc(sizeof(Htab));
	tab_copy->t = malloc(2 * tab->m * sizeof(login));
	for (int i = 0; i < 2 * tab->m; i++) 
		strcpy(tab_copy->t[i].name, FREE);
	
	tab_copy->m = 2 * tab->m;
	tab_copy->n = 0;
	
	for (int i = 0; i < tab->m; i++) {
		if (strcmp(tab->t[i].name, FREE) != 0 && strcmp(tab->t[i].name, DEL) != 0)
			insert_tab(tab_copy, tab->t[i]);
	}
	
	tab = tab_copy;
	return tab;
}

void exib_tab(Htab* tab) {
	mergesort(tab->t, 0, tab->m);
	for (int i = 0; i < tab->m; i++) 
		if(strcmp(tab->t[i].name, FREE) != 0 && strcmp(tab->t[i].name, DEL) != 0)
			printf("%s %s \n", tab->t[i].name, tab->t[i].pass);
	
}
