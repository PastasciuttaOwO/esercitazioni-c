#include<stdio.h>
#include<stdlib.h>

/*salvare una matrice con fwrite*/

int main(){
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Errore! file non aperto correttamente");
        exit(1);
    }
    int r, c;
    fscanf(input, "%d", &r);
    fscanf(input, "%d", &c);
    int **m = (int**)calloc(r, sizeof(int*));
    for (int i = 0; i < r; i++)
        m[i] = (int*)calloc(c, sizeof(int));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fscanf(input, "%d", &m[i][j]);
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    FILE *output = fopen("output.bin", "w");
    fwrite(m, sizeof(int), r * c, output);
}