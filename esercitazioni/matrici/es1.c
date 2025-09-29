/*
 * SIA DICHIARATO UNA MATRICE 3x3. 
 IN OGNI POSIZIONE DELLA MATRICE SI SOMMINO 
 GLI INDICI DI TALE POSIZIONE.
 */

#include <stdio.h>

int main(void){
    int m[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            m[i][j] = i + j;
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("| M[%d][%d] = %d ", i, j, m[i][j]);
        }
        printf(" |\n");
    }

    return 0;
}