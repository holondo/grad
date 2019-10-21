#include <stdio.h>
#include <stdlib.h>

int main() {
    int qntDia, qntRec, arqDia, *p, sumRec = 0, contOver = 0;
    //Pega quantidade de dias e recursos individuais
    scanf("%d %d", &qntDia, &qntRec);
    //Inicializa p
    p = (int *) malloc(1);
    //Roda a quantidade de dias
    for (int x = 0; x < qntDia; x++) {
        sumRec = 0;
        scanf("%d", &arqDia);
        p = realloc(p, sizeof(int) * (arqDia + contOver));

        //Roda a quantidade de arquivos
        for (int y = contOver; y < (arqDia + contOver); y++)
            scanf("%d", &p[y]);

        //Procura overflow do final pro começo
        int newContover = 0;
        for (int y = arqDia + contOver - 1; y >= 0; y--) {
            sumRec += p[y];

            if (sumRec > qntRec)
                newContover++;
            else if (y == 0)
                contOver = 0;
        }

        contOver = newContover;

        if (contOver == 0)
            printf("Todos os arquivos foram processados.\n");
        else if (contOver == 1)
            printf("Resta 1 arquivo.\n");
        else
            printf("Restam %d arquivos.\n", contOver);


    }
    free(p);
}
