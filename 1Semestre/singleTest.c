#include <stdio.h>
#include <stdlib.h>
int main() {
int a = 5, b = 7;
int resto = a % b;
    while(resto != 0) {
        a = b;
        b  = resto;
        resto = a % b;
	}
	printf("%d", b);
}
