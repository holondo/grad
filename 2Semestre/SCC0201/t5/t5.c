#include "sort.h"
#include "tab.h"

int main () {
	int inst, newPos; //Qual operação a ser efetuado e a nova posição
	tab info; //Informação do nó
	char tit[30]; //Título da aba
	listD list; //Lista
	create_list(&list);

	do {
		scanf("%d", &inst);

		switch(inst) {

			case 1: //Caso 1 - Criar uma nova aba
				scanf("%*[\n\r]%[^\n\r] %s %d %d %d %d", info.tit, info.url, &info.dateTime[0], &info.dateTime[1], &info.dateTime[2], &info.dateTime[3]);
				open_tab(&list, info);
			break;

			case 2: //Caso 2 - Mudar posição da aba
				scanf("%[^\n]", tit);
				scanf("%d", &newPos);
				change_tab(&list, newPos, tit);
			break;

			case 3: //Caso 3 - Ordena abas
				sort_tab(&list);
			break;

			case 4: //Caso 4 - Imprime as informações da aba
				show_tab(&list);
			break;
		}
	} while (inst != 5);
	//Caso 5 - Desaloca memória e sai do programa
	no* node = list.beg;
	for (int x = 0; x < list.size; x++) {
		no aux = *node;
		free(node);
		node = aux.next;
	}
}
