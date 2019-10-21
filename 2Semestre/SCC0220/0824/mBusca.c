#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conta(char** pala, char* chave, int contPala, int indice) {
	int x = 0;
	while(strcmp(pala[indice - x], chave) == 0) {
		if(indice - x < 0)
			break;
		x++;
	
	}
	int pos = indice - x;
	x = 1;
	while(strcmp(pala[pos + x], chave) == 0) {
		if( (pos + x) > (contPala - 1) )
			break;
		x++;
	}	

	printf("%s %d", chave, x-1);
	if ( (pos + x) < contPala - 1)
		printf(" %s", pala[pos + x ]);
	if ( (pos + x + 1) < contPala - 1)
		printf(" %s",pala[pos + x + 1]);
	if ( (pos + x + 2) < contPala - 1)
		printf(" %s\n", pala[pos + x + 2]);
	
}

void troca(char** pala1, char** pala2) {
	char* temp;
	temp = *pala1;
	*pala1 = *pala2;
	*pala2 = temp;
}

int buscaBinaria (char* chave, char** pala, int inicio, int fim)	{
	int meio = (inicio + fim)/2;
	if (strcmp(pala[meio], chave) == 0)
		return meio;
	if (inicio >= fim)
		return -1; // não encontrado
	else
		if (strcmp(pala[meio], chave) < 0)
			return buscaBinaria(chave, pala, meio+1, fim);
		else
			return buscaBinaria(chave, pala, inicio, meio-1);
}

void caixaBaixa(char** pala, int contPala) {
	int y = 0;
	
	for (int x = 0; x < contPala; x++) {
		y = 0;
		while(pala[x][y] != '\0'){
			if (pala[x][y] >= 65 && pala[x][y] <= 90)
				pala[x][y] += 32;
			y++;
		}
	}
}

void ordena(char** pala, int contPala) {
	
    for (int x = 0; x < contPala; x++) {
		for (int y = 0; y < contPala; y++) {
			if (strcmp(pala[x], pala[y]) < 0)
				troca(&pala[x], &pala[y]);
				
		}
	}
}

int main () {

    FILE *pFile;
    char nome[20], *arq, **pala, *pch, chave[20];
    int qntPala, tamChar, contPala = 0;
    
    scanf("%s %d", nome, &qntPala);
	
    pFile = fopen(nome, "r");
    
	fseek (pFile , 0 , SEEK_END);
	tamChar = ftell (pFile);
	rewind (pFile);
	
	arq = (char*) malloc(tamChar * sizeof(char));
	pala = (char**) malloc( tamChar * sizeof(char*));
	
	fread(arq, 1, tamChar, pFile);
	//printf("%s \n", arq);
		
	int x = 0;	
	
	pch = strtok(arq, " ,.\n\t\r");
	
	while (pch != NULL) {
		pala[x++] = pch;
		pch = strtok(NULL, " ,.\n\t\r");
		contPala++;
	}
		
	pala = (char**) realloc(pala, contPala * sizeof(char*));
	caixaBaixa(pala, contPala);
	ordena(pala, contPala);
	
	
    for (int x = 0; x < qntPala; x++) {
        scanf("%s", chave);
        int indice = buscaBinaria(chave, pala, 0, contPala-1);
		conta(pala, chave,  contPala, indice);
    }
	
    fclose(pFile);
}
