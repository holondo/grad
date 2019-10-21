#ifndef TAB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	#define TAB_H
	//Define uma aba tendo título, url, data e hora.
	typedef struct _tab {
		char tit[30];
		char url[1024];
		int dateTime[4]; //month, day, hour and minute
	} tab;

	//Define um nó tendo informação e um ponteiro para o próximo nó
	typedef	struct _no {
		tab data;
		struct _no *next;
	} no;

	//Define uma lista tendo um certo tamanho, um ponteiro para inicio e para final
	typedef struct _list {
		int size;
		no *beg, *end;
	} listD;

	void open_tab(listD* list, tab info);
	void change_tab(listD* list, int newPos, char* tit);
	void sort_tab(listD* list);
	void show_tab(listD* list);
	tab return_tab(listD* list);

	void create_list(listD* list);
	no* remove_node(listD* list, int pos);
	void create_node(listD* list, int pos, tab info);
	int search_node(listD* list, char* tit);
#endif
