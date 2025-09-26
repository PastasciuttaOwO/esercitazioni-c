#include<stdio.h>
#include<stdlib.h>

#define r 3
#define c 4

int main(){
    int **m = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        m[i] = (int *)malloc(c * sizeof(int));
    }
    int temp[r][c] = {
        {1, 1, 2, 3},
        {2, 4, 0, 1},
        {5, 2, 0, 1}
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = temp[i][j];
        }
    }
    for (int j = 1; j < c - 1; j++){
        for (int i = 0; i < r; i++){
            m[i][j] = m[i][j + 1];
        }
    }
    for (int i = 0; i < r; i++){
        m[i] = (int *)realloc(m[i], (c - 1) * sizeof(int));
    }
    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("| %d ", m[i][j]);
        }
        printf("|\n");
    }
}