#include <stdio.h>
/* ESTUDO DE PONTEIROS */
int main () {
    int a[2], b[3], c[4], d[5], *p[4];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    for(int x = 0; x < 4; x++)
        for(int y = 0; y < x+1; y++)
            *(p[x]+y) = 1;
    for(int x = 0; x < 4; x++)
            printf("%p \n", p[x]);
    for(int x = 0; x < 4; x++)
            printf("%d \n", sizeof(*p[x]));        


}
