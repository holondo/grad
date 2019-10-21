#include <stdio.h>
#include <math.h>

float ang(int dim, float *vetorU, float *vetorV) {
	float vetorPEscalar = 0, resU = 0, resV = 0;
	for (int x = 0; x < dim; x++) {
		vetorPEscalar += vetorU[x] * vetorV[x];
		resU += pow(vetorU[x],2);
		resV += pow(vetorV[x],2);
	}
	return((acos(vetorPEscalar / (sqrt(resU) * sqrt(resV))) * 180) / acos(-1));
}


int main () {
	int dim;
	scanf("%d", &dim);
	float vetorU[dim], vetorV[dim];
	for (int x = 0; x < dim; x++)
		scanf("%f", &vetorU[x]);
	for (int x = 0; x < dim; x++)
		scanf("%f", &vetorV[x]);
	printf("%.2f graus.", ang(dim, vetorU, vetorV));
}

