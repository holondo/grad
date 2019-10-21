#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char pal[46];
} vetPal;

/*
geraDicionario(char *pStr, char *pTok) {
	static int
}
*/

int separa_palavras(char *pStr, vetPal* dic) {
	int qntPal = 1;
	char* pTok;

	pTok = strtok(pStr," ,.-");

	while (pTok != NULL) {
		pTok = strtok(NULL, " ,.-");
		strcpy(dic->pal, pTok);
		qntPal++;
	}

	return(qntPal);
}

int tamanho_arquivo(FILE *pArq) {
	fseek(pArq, 0, SEEK_END);
	int tamArq = ftell(pArq);
	rewind(pArq);
	return(tamArq);
}

int main() {
	FILE *lArq, *tArq;
	char lNome[10], tNome[10], *pLiv, *pTwe;
	vetPal* dic = NULL;
	int tamArq;

	scanf("%s %s", lNome, tNome);

	lArq = fopen(lNome, "r");
	tamArq = tamanho_arquivo(lArq);
	pLiv = (char*) malloc( tamArq * sizeof(char) );
	fread(pLiv, 1, tamArq, lArq);

	tArq = fopen(tNome, "r");
	tamArq = tamanho_arquivo(tArq);
	pTwe = (char*) malloc( tamArq * sizeof(char) );
	fread(pTwe, 1, tamArq, lArq);

	int qntPal = separa_palavras(pLiv, dic);
	for(int x = 0; x < qntPal; x++)
		printf("%s \n", dic[x].pal);


	fclose(lArq);
	fclose(tArq);
	free(pTwe);
	free(pLiv);


}
