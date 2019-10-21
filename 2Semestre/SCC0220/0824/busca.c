#include <stdio.h>
#include <string.h>

typedef struct _saida {
int nro;
char pal1[20], pal2[20], pal3[20];
} saida;

void ordena(FILE *t, FILE *to) {
	char palC[20], pal[20];
	while(scanf("%[a-z A-Z]s", palC) != EOF) {
		while(scanf("%[a-z A-Z]s", pal) != EOF) {
			if(strcmp(palC, pal) < 0)
				fwrite(palC, 20, 1, to);
			else
				fwrite(pal, 20, 1, to);
		}
	}
}

saida busca(FILE *t, char chave[20]) {
	char pal[20], palC[20];
	saida s;
	s.nro = 0;
	int cont = 1;

	while(scanf("%s", pal) != EOF) {

		if( strcmp(pal, chave) == 0 )
			s.nro++;

		else if (s.nro > 0 && cont <= 3)
			switch(cont) {
				case 1:
					strcpy(s.pal1,pal);
					cont++;
					break;
				case 2:
					strcpy(s.pal2,pal);
					cont++;
					break;
				case 3:
					strcpy(s.pal3,pal);
					cont++;
					break;
			}
	}
}

int main() {
	FILE *t, *to;
	int qntPal;
	saida s;
	char arq[20], chave[20];
	scanf("%s %d", arq, &qntPal);
	t = fopen("alice.txt","r");
	to = fopen("arqO.txt", "r+");
	ordena(t, to);
	fclose(t);
	for (int x = 0; x < qntPal; x++) {
		scanf("%s", chave);
		s = busca(to, chave);
		printf("%s %d %s %s %s \n", chave, s.nro, s.pal1, s.pal2, s.pal3);
	}
	fclose(to);

}
