#include<stdio.h>
#include<stdlib.h>

#define N_MAX 100
#define r 3
#define c 4

typedef struct {
    int index;
    int n;
    float elems[N_MAX];
    float range_ratio;
} info_matrice;

void valore_assoluto(int *);
void somma_min(int*, int *);
void somma_max(int, int*);
void Calcolorange_ratio(int m[r][c], info_matrice *matrice);

int main(){
    int max = 0, min = 0, m[r][c] = {
        {1, -1, 2, 3},
        {2, 4, 0, 1},
        {5, -2, 0, 1}
    };
    info_matrice matrice[r];
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] > max)
                max = m[i][j];
            if(m[i][j] < min)
                min = m[i][j];
        }
        somma_max(max, m[i]);
        somma_min(&min, m[i]);
    }
    for (int i = 0; i < r; i++){
        matrice[i].index = i;
        matrice[i].n = c;
        for (int j = 0; j < c; j++){
            matrice[i].elems[j] = m[i][j];
        }
    }
    Calcolorange_ratio(m, matrice);
    for (int i = 0; i < r; i++) {
        printf("Matrice %d:\n", matrice[i].index);
        printf("Numero di elementi: %d\n", matrice[i].n);
        printf("Elementi: ");
        for (int j = 0; j < matrice[i].n; j++) {
            printf("%.2f ", matrice[i].elems[j]);
        }
        printf("\nRange Ratio: %.2f\n", matrice[i].range_ratio);
        printf("\n");
    }
}

void valore_assoluto(int *num){
    if (*num < 0)
        *num = -*num;
}

void somma_max(int max, int *m){
    for(int i = 0; i < c; i++){
        if (m[i] >= 0)
            m[i] = m[i] + max;
    }
}

void somma_min(int *min, int *m){
    valore_assoluto(min);
    for(int i = 0; i < c; i++){
        if (m[i] < 0)
            m[i] = m[i] + *min;
    }
}

void Calcolorange_ratio(int m[r][c], info_matrice *matrice){
    float min = 0, max = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] > max)
                max = m[i][j];
            if(m[i][j] < min)
                min = m[i][j];
        }
        matrice[i].range_ratio = (max - min) / c;
    }
}