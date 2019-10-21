#include <stdio.h>
#include <string.h>


typedef struct _part {
	char nome[31];
	int	 hH, mM, sS;
} part;

part calcTempo (char nome[31], int hH, int mM, int sS, part horPart[100], int nPart, int* ctl) {
	int segTotal;
	for (int y = 0; y < nPart; y++) {

		if (strcmp(nome, horPart[y].nome) == 0) {

			if ( (3600*horPart[y].hH + 60*horPart[y].mM + horPart[y].sS) < (3600*hH + 60*mM + sS) )
			 	segTotal = ( (3600*hH + 60*mM + sS) - (3600*horPart[y].hH + 60*horPart[y].mM + horPart[y].sS) );
			else
				segTotal = ( 24*3600 - (3600*horPart[y].hH + 60*horPart[y].mM + horPart[y].sS) + (3600*hH + 60*mM + sS) );

			horPart[y].hH = segTotal / 3600;
			horPart[y].mM = (segTotal % 3600) / 60;
			horPart[y].sS = segTotal % 60;
			*ctl++;
			return(horPart[y]);

		}
		if (y == nPart-1) {
			strcpy(horPart[*ctl].nome, nome);
			horPart[*ctl].hH = hH;
			horPart[*ctl].mM = mM;
			horPart[*ctl].sS = sS;
			return(horPart[*ctl++]);
		}

	}

}


int main () {
	int nPart, hH, mM, sS, segTotal, ctl = 0;
	char nome[31];
	part horPart[100] = {};
	scanf("%d", &nPart);
	for (int x = 0; x < 2*nPart; x++) {
		scanf("%s %d:%d:%d", nome, &hH, &mM, &sS);
		horPart[x] =  calcTempo(nome, hH, mM, sS, horPart, nPart, &ctl);
	}


	for (int x = 0; x < nPart ; x++)
		printf("%s levou %.2d:%.2d:%.2d.\n", horPart[x].nome, horPart[x].hH, horPart[x].mM, horPart[x].sS);

}
