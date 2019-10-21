#include <stdio.h>
#include <stdlib.h>
/*
void imprime(int map[9][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++)
            printf("%d ", map[x][y]);
        printf("\n");
    }
    printf("\n");
}
*/
void enche(int posX, int posY, int* posRec, int map[9][9], int nRec, int* cRec) {
    //imprime(map);
    if (map[posX][posY] != 0) {
        return;
    } else{
        map[posX][posY] = 2; //Marca a posição como intransponível (seta valor = 2)
        posRec[2*nRec+1] += *cRec;
        //imprime(map);
        for (int vet = 0; vet < 2*nRec; vet += 2) {
            if (posX == posRec[vet] && posY == posRec[vet+1])
                if (--(*cRec) == 0)
                    return;
            }
        if ( posX+1 < 9 && *cRec > 0) //sul
            enche(posX+1, posY, posRec, map, nRec, cRec);
         if (posX-1 >= 0 && *cRec > 0) //norte
            enche(posX-1, posY, posRec, map, nRec, cRec);
        if (posY-1 >= 0 && *cRec > 0) //oeste
            enche(posX, posY-1, posRec, map, nRec, cRec);
        if (posY+1 < 9 && *cRec > 0) //leste
            enche(posX, posY+1, posRec, map, nRec, cRec);
    }
}

int main () {
     int map[9][9], mapAux[9][9], pos1X, pos1Y, pos2X, pos2Y, nRec, *posRec, p=0, cRec;
     double e1, e2;

     //Floopa o mapa
     for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            scanf("%d", &map[x][y]);
            mapAux[x][y] = map[x][y];
        }
    }

    //Verifica o número de 0's no mapa
        for (int x = 0; x < 9; x++)
            for (int y = 0; y < 9; y++)
                if (map[x][y] == 0)
                    p++;


    //Escaneia posição dos jogadores
    scanf("%d %d", &pos1X, &pos1Y);
    scanf("%d %d", &pos2X, &pos2Y);

    //Escaneia o número de recursos
     scanf("%d", &nRec);
     //Aloca na heap um vetor com o dobro do tamanho do número de recursos, assim é possível guardar coordenada x e y em um vetor só.
     //Ultimo elemento do vetor nRec * 2 + 1 é a soma das coberturas do mapa
     posRec = malloc(sizeof(int) * nRec * 2 + 1);
     //Guarda coordenadas dos recusos na matriz da heap
      for( int x = 0; x < nRec * 2; x += 2)
        scanf("%d %d", &posRec[x], &posRec[x+1]);
    posRec[2*nRec +1] = 0;
    cRec = nRec;
    enche(pos1X, pos1Y, posRec, mapAux, nRec, &cRec);
    e1 =  posRec[nRec*2+1]  / (double) (nRec*p);
    posRec[2*nRec+1] = 0;
    cRec = nRec;
    enche(pos2X, pos2Y, posRec, map, nRec, &cRec);
    e2 =  posRec[nRec*2+1]  / (double)  (nRec*p);
    printf("%lf\n", e1);
    printf("%lf\n", e2);
    if ( (e1 < e2 ? e2-e1 : e1-e2) < 0.001 )
        printf("O mapa eh balanceado");
    else
        printf("O jogador %d possui vantagem\n", e1<e2 ? 1 : 2);
    free(posRec);
}
