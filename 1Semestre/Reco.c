/*
PROGRAMA DE SISTEMAS DE RECOMENDAÇÕES
IGOR CARDOZO MARTINS DISCENTE USP
SÃO PAULO 30/04
*/
#include <stdio.h>
#include <math.h>
int main ( void ) {
  int user, userMovie, matrix[15][15] = {},a = 0 ,b = 0, c = 0;
  double limit, similarityTotal[15][15] = {}, denominator[15] = {}, grade[15][15] = {}, average[15] = {};

  scanf( "%d %d %lf",&user ,&userMovie ,&limit );

  //FLOOPA A MATRIZ
  for ( int x = 0; x < user; x++ )
      for ( int y = 0; y < userMovie; y++ )
        scanf("%d",&matrix[x][y]);

    /*
    CALCULA SIMILARIDADE
    denominator = Denominador da fração
    simlarityTotal = fração
    */
    for ( int x = 0; x < user; x++ ) {
        for ( int y = 0; y < user; y++ ) {
            denominator[y] = 0;
            for (int z = 0; z < userMovie; z++ ) {
                //Eleva os termos do denominador ao quadrado
                denominator[y] += pow(matrix[y][z],2);
                //Calcula o numerador
                similarityTotal[x][y] += matrix[x][z] * matrix[y][z];
            }
            //Fração = numerador/ raiz do denominador x * raiz do denominador y
            similarityTotal[x][y] /= (sqrt(denominator[x]) * sqrt(denominator[y]));
        }
    }

    /*
    CALCULA NOTA MEDIA
    */
    for (int x = 0; x < user; x++) {
    int averageDeno = 0;
        for (int y = 0; y < userMovie; y++) {
            //Média = soma dos termos
            average[x] += matrix[x][y];
            if (matrix[x][y] != 0)
            //Contador de média pós incrimentado nos casos que a matriz é diferente de 0
                averageDeno++;
        }
        // Média é igual a média divida pelo contador
        average[x] /= averageDeno;
    }

    /* CALCULA MÉDIA PONDERADA
    Variáveis a,b,c tem como utilidade apenas formatar a saída
    Grade é a matriz de saída das notas a serem calculadas com base nos usuários similares
    Denominator é o denominador da fração
    */
    for (int x = 0; x < user; x++) {
        for (int y = 0; y < userMovie; y++) {
            denominator[x] = 0;
            if (matrix[x][y] == 0) {
                if ( a != b && c != 0 )
                    printf("\n");
                b = a;
                c++;
                for (int z = 0; z < user; z++) {
                    //Tratando comportamento de comparação do usuário com ele mesmo
                    if ( x == z )
                        continue;
                    if (similarityTotal[x][z] >= limit) {
                        //Tratando comportamento no caso de usuário similar porém que não assistiu ao filme
                        if( matrix[z][y] == 0 )
                            continue;
                        grade[x][y] += similarityTotal[x][z] * (matrix[z][y] - average[z]);
                        denominator[x] += similarityTotal[x][z];
                    }
                }
                //Tratando comportamento no caso de divisão por 0
                if (denominator[x] == 0) {
                    printf("DI ");
                    continue;
                }
                grade[x][y] = average[x] + grade[x][y] / denominator[x] ;
                printf("%.2lf ", grade[x][y]);
            }
        }
    a++;
    }

}
