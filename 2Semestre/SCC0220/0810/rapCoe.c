#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _cod {
	float x; 
	float y;
} cod;

int dist(cod raposa, cod coelho, cod buraco) {
	//printf("%f %f", buraco.x, buraco.y);
	float disCoe = sqrt(pow((buraco.x - coelho.x),2) + pow((buraco.y - coelho.y),2));
	float disRap = sqrt(pow((buraco.x - raposa.x),2) + pow((buraco.y - raposa.y),2));
	if (disCoe < disRap/2) {
		printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", buraco.x, buraco.y);
		return 0;
	} else
		return 1;
}

int main() {
	int nroBur;
	cod raposa, coelho, *buraco;
	scanf("%d %f %f %f %f", &nroBur, &coelho.x, &coelho.y, &raposa.x, &raposa.y);
	buraco = (cod *) malloc(nroBur * sizeof(cod));
	
	for (int x = 0; x < nroBur; x++) {
		scanf("%f %f", &buraco[x].x, &buraco[x].y);
		if (dist(raposa, coelho, buraco[x]) == 0)
			break;
		else if (x == nroBur - 1)
			printf("O coelho nao pode escapar.\n");
	}

	free(buraco);
}
