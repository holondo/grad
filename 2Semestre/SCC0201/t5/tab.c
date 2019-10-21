#include "tab.h"
#include "sort.h"

/* Parâmetros: Lista
 * Função que inicializa tamanho, ponteiro de inicio e fim de uma lista.
 */
void create_list(listD* list) {
	list->size = 0;
	list->beg = NULL;
	list->end = NULL;
}

/* Parâmetros: lista e conteúdo dos nós da lista(tab)
	Função que chama a função create_node para um primeiro nó
*/
void open_tab(listD* list, tab info) {
	create_node(list, list->size+1, info);
}


/* Parâmetros: lista, posição e informação do nó a ser inserido
	Função que troca um nó da lsita de posição
*/
void change_tab(listD* list, int newPos, char* tit) {

	int pos = search_node(list, tit);

	if (pos == -1)
		return;

	no* newNode = remove_node(list, pos);
	create_node(list, newPos, newNode->data);
}
/* Parâmetros: lista a ser imprimida
	Função que imprime informações do nó
*/
void show_tab(listD* list) {
	no* node = list->beg;
		for (int x = 0; x < list->size; x++) {
			printf("%s %s %02d/%02d %02d:%02d\n", node->data.tit, node->data.url, node->data.dateTime[0], node->data.dateTime[1], node->data.dateTime[2], node->data.dateTime[3]);
			node = node->next;
		}
		printf("\n");
}

/* Parâmetros: lista a ser organizada
	Função que chama a função radix para organizar uma dada lista
*/
void sort_tab(listD* list) {
	radix_sort(list);
}

/* Parâmetros: lista e posição do nó a ser removido
	Função que remove um nó de uma determinada lista e o retorna
	Retorno: nó removido
*/
no* remove_node(listD* list, int pos) {
	no* aux;

	if (pos > list->size)
		return NULL;

	else if (list->size == 1) {
		aux = list->beg;
		list->end = NULL;
		list->beg = NULL;
		list->size--;
		return(aux);

	} else {
		if(pos == 1) {
			aux = list->beg;
			list->beg = list->beg->next;
			list->size--;
			return(aux);

		} else if (pos == list->size) {
			aux = list->end;

			no* pen = list->beg;
			for (int x = 0; x != list->size - 2; x++)
				pen = pen->next;

			pen->next = NULL;
			list->end = pen;
			list->size--;
			return(aux);

		} else {
			no* posX = list->beg;
			for (int x = 1; x != pos-1; x++)
				posX = posX->next;

			aux = posX->next;
			posX->next = posX->next->next;
			list->size--;
			return(aux);
		}
	}
}

/* Parâmetros: lista, posição e informação do nó a ser inserido
	Função que cria um nó em uma determinada posição
*/
void create_node(listD* list, int pos, tab info) {
	no* node = malloc(sizeof(no));
	node->data = info;

	if (list->size == 0) {
		list->beg = node;
		list->end = node;

		node->next = NULL;

	} else if (pos == 1) {
		node->next = list->beg;
		list->beg = node;

	} else if (pos > list->size) {
		if(list->end == NULL) {
			list->end = node;
			node->next = NULL;

		} else {
			list->end->next = node;
			list->end = node;
			node->next = NULL;
		}

	} else {

		no* nodeAux = list->beg;
		for (int x = 0; x < pos-1; x++)
			nodeAux = nodeAux->next;

		node->next = nodeAux->next;
		nodeAux->next = node;

	}
	list->size++;
}

/* Parâmetros: lista e seu título de nó a ser procurado
	Função que procura um nó por seu título e retorna sua posição
	Retorno: posição do nó procurado
*/
int search_node(listD* list, char* tit) {
	no* node = list->beg;
	int x = 1;

	while (strcmp(node->data.tit, tit) != 0 ) {
		if (node == list->end)
			return -1;
		node = node->next;
		x++;
	}
	return x;
}
