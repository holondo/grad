#include <stdio.h>

char bomb (int linha, int coluna, char campo[linha][coluna]) {
	for (int linhaX = linha-1; linhaX != linha+1; linhaX++) {
		for (int colunaX = coluna-1; colunaX < coluna+1; colunaX++) {
			if (campo[linhaX][colunaX] == '*')
				continue;
			else if (campo[linhaX][colunaX] == '.')
				campo[linhaX][colunaX] = 1;
				else
					campo[linhaX][colunaX]++;
		continue;
		}
	}
}

int main () {
	int coluna, linha;
	scanf("%d %d", &linha, &coluna);
	char campo[linha][coluna];
	for (int linhaX = 0; linhaX < linha; linhaX++) {
		for (int colunaX = 0; colunaX < linha; colunaX++) {
			scanf("%c", &campo[linhaX][colunaX]);
			if (campo[linhaX][colunaX] == '*')
				bomb(linhaX, colunaX, campo[linhaX][colunaX]);
		}
	}
}
