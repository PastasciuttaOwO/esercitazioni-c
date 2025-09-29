/*
 * DATA UNA MATRICE QUADRATA IN INGRESSO SOMMARE TUTTI
  GLI ELEMENTI TRANNE QUELLI SULLE DUE DIAGONALI.
 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int somma(int max, int m[][max]);

int main(void){
    srand(time(NULL));
    const int max = 4; //+ rand() % 7; //valore minimo 4, valore max 10 (vaore max (10) - valore min (4) + 1(perchè 0 incluso))
    int m[max][max];
    printf("max = %d\n\n", max);
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++){
            m[i][j] = (rand() % 50) + 1;
        }
    }
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++){
            printf("| M[%d][%d] = %d ", i, j, m[i][j]);
        }
        printf("| \n");
    }
   printf("\n\nsomma = %d", somma(max, m));
    return 0;
}

int somma(int max, int m[][max]){
    int somma = 0;
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++){
            if ((i!=j)&&(i+j!=(max-1)))
                somma = somma + m[i][j];
        }
    }
    return somma;
}