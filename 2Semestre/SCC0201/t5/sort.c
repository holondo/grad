#include "sort.h"

/* Parâmetros: lista, campo (se é dia, mês, hora ou minuto) e quantidade de 'baldes' a serem criados
	Função que chama algoritmo "bucket sort" para cada segmento
*/
void bucket_sort(listD* list, int field, int numBuck) {

	listD* buck = calloc(sizeof(list), numBuck);
	no* node = list->beg;

	for (int x = 0; x < list->size; x++) {
		int pos = node->data.dateTime[field];
		create_node(&buck[pos], buck[pos].size, node->data);
		node = node->next;
	}

	no* nodeList = list->beg;
	for (int x = 0; x < numBuck; x++) {
		no* nodeBuck = buck[x].beg;
		while (nodeBuck != NULL) {
			no aux = *nodeBuck;
			free(nodeBuck);
			nodeList->data = aux.data;
			nodeBuck = aux.next;
			nodeList = nodeList->next;
		}
	}
}

/* Parâmetros: lista
	Função que quebra informação em segmentos e chama uma função de ordenação para cada um
*/
void radix_sort(listD* list) {
	//Minutes
	bucket_sort(list, 3, 60);
	//Hours
	bucket_sort(list, 2, 24);
	//Days
	bucket_sort(list, 1, 32);
	//Months
	bucket_sort(list, 0, 13);

}
