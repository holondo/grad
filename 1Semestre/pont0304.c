#include <stdio.h>
int main (void) {
    int N = 3;
    float* endf;
    double* endd;
    double vet[4] = {4.4, 3.3, 2.2, 1.1};
    float mat[2][2] = {{4.0, 3.0}, {2.0, 1.0}};
    endd = vet+1;
    endf = (float*) mat; // converte endereco float** em float*
    printf("%p \n",vet);
    printf("%lf",*vet);
    return 0;
}
