#include <stdio.h>
#include <math.h>
int main () {
    int n;
    scanf("%d",&n);




//COM 4 FOR
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < x; y++)
            printf("*");
    printf("\n");
    }
    for (int x = n; x > 0; x--) {
        for (int y = x; y > 0; y--)
            printf("*");
    printf("\n");
    }

}
