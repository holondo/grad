#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *nome;
	int *pos;
} comp;

int main() {
	comp* fed, caa;
	char *mem;
	while (scanf("%m[^\n \r]", &mem) != EOF) {
		printf("%s\n", mem);
		getchar();
		free(mem);
	}
}
