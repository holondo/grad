#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 Struct contém os elementos de uma flor iris.
 */
typedef struct {
	float petCom;
	float petLar;
	float sepCom;
	float sepLar;
	char esp[11];
} iris;

/*
  A função ordena, utiliza o algoritmo insertion sort para organizar
  um dado vetor.
  Parâmetros:
  float *vet -> o vetor para ser ordenado.
  float *tam -> tamanho do vetor.

 */
void ordena(float* vet, int tam) {
	int i, j, atual;

	for (i = 1; i < tam; i++) {
		atual = vet[i];

		for (j = i - 1; (j >= 0) && (atual < vet[j]); j--)
			vet[j + 1] = vet[j];

		vet[j+1] = atual;
	}

}

/*
 A função dist calcula a distância Euclediana das iris do exemplo e das
 do treino.
 Parâmetros:
 iris* tr -> tabela de treino
 iris* ex -> tabela de exemplo
 int lin -> quantidade de iris
 Retorno:
 Um vetor com a distância das linhas do exemplo e do treino
 */
float* dist(iris* tr, iris* ex, int lin) {
	float dif[lin];

	for (int x = 0; x < lin; x++) {
		dif[x] = pow(tr.petCom - ex.petCom, 2);
		dif[x] += pow(tr.petLar - ex.petLar, 2);
		dif[x] += pow(tr.sepCom - ex.sepCom, 2);
		dif[x] += pow(tr.sepLar - ex.sepLar, 2);
		dif[x] = sqrt(dif[x]);
	}

	return(dif);
}

/*
 A função atribui pega a tabela e atribui os elementos a um vetor.
 Parâmetros:
 iris* vet -> o vetor a ser atribuido.
 char* arq -> a tabela com os elementos.
 Retorno:
 quantidade de linhas da tabela.
 */
int atribui(iris* vet, char* arq) {
	char* pch;
	int x = 0, ind;

	vet = (char*) strtok(arq, "\",\n\t\r");

	while (pch != NULL) {
		printf ("PRINT DA STRING: %s\n", pch);

		x++;
		//Modulo indica elemento do vetor
		int mod = x % 5;
		//Lin indica a linha atual (-4 para ignorar o cabeçalho)
		int lin = x - 4;
		vet = (char*) strtok(NULL, "\",\n\t\r");

		//Ignora o cabeçalho
		if (x < 5)
			continue;

		switch(mod) {
			case 0:
			//Indice do vetor, cada linha possui cinco elementos menos a do cabeçalho
			ind = x/5 - 1;
			realloc(vet, (lin) * sizeof(iris) );
			vet[ind].sepCom = atof (pch);
			break;

			case 1:
			vet[ind].sepLar = atof (pch);
			break;

			case 2:
			vet[ind].petCom = atof (pch);
			break;

			case 3:
			vet[ind].petLar = atof (pch);
			break;

			case 4:
			strcpy(vet[ind].esp, pch);
			break;
		}
	}
}

/*
 A função tamArq tem por função determinar a quantidade de bytes do arquivo
 Parâmetros:
 FILE *pFile -> o arquivo a ser contado.
 Retorno:
 A quantidade de bytes do arquivo.
 */
int tamArq(FILE *pFile){
	fseek (pFile, 0, SEEK_END);
	int tamArq = ftell (pFile);
	rewind (pFile);
	return(tamArq);
}


int main () {
	iris *tr, *ex;
	int k, ind;
	char *nArq, *nArq2, *arq, *arq2;
	float dif*;

	//Pega os nomes do arquivos
	FILE *pArq, *pArq2;
	scanf("%m[^ ] %m[^ ] %d", &nArq, &nArq2, &k);

	//Abre os arquivos
	pArq = fopen(nArq,"r");
	pArq2 = fopen(nArq2,"r");

	//Aloca memória para o vetor de treino e de exemplo.
	tr = malloc(sizeof(iris));
	ex = malloc(sizeof(iris));

	//Pega o tamanho do arquivo e atribui ele a um vetor.
	int tam = tamArq(pArq);
	arq = malloc(tam * sizeof(char));
	fread(arq, 1, tam, pArq);

	//Pega o tamanho do arquivo e atribui ele a um vetor.
	tam = tamArq(pArq2);
	arq2 = malloc(tam * sizeof(char));
	fread(arq2, 1, tam, pArq2);
	printf("PRINT TAMANHO: %d\n", tam);

	int lin1 = atribui(tr, arq);
	int lin2 = atribui(ex, arq2);
	dif = dist(tr, ex, lin1);
	ordena(dif, lin1);

	if (k < 1 || k > lin1)
		printf("k is invalid\n");

	int ir[3];
	for (int x = 0; x < k; x++) {

		if(strcmp(ex.esp[x],"setosa"))
			ir[0]++;

		if(strcmp(ex.esp[x],"virginica"))
			ir[1]++;

		if(strcmp(ex.esp[x],"versicolor"))
			ir[2]++;

	}


	//Liberando memória
	free(nArq);
	free(nArq2);
	free(arq);
	free(arq2);
	fclose(pArq);
	fclose(pArq2);

}
