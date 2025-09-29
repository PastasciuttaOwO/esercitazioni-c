/*
 * SIA DATO UNA MATRICE QUADRATICA DI INTERI. 
 IN UN VETTORE SI SALVI LA DIAGONALE PRINCIPALE 
 DELLA MATRICE.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int max = 5;

int main(void){
    srand(time(NULL));
    int m[max][max], v[max];
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++){
            m[i][j] = (rand() % 10) + 1;
            printf("| M[%d][%d] = %d ", i, j, m[i][j]);
        }
        printf(" |\n");
        v[i] = m[i][i];
    }
    printf("\n\n\n");
    for (int i = 0; i < max; i++)
        printf("V[%d] = %d ", i, v[i]);
    
}