#include <stdio.h>
#include <stdlib.h>

typedef struct vett
{
    int elements;
    int *v;
    float d1;
    float d2;
}vett;

void RiempiMatrice(float **m, int dim, FILE *input);
void StampaMatrice(float **m, int dim);
void RiempiStruct(vett* array, int dim, FILE *input);
void CalcoloD1(vett* array, float **m, int dim_m);
void CalcoloD2(vett* array, float **m, int num_vett);

int main() {
    FILE* input = fopen("input.txt", "r");
    if(input == NULL){
        printf("Errore apertura file");
        exit(1);
    }
    int dim, num_vett, *v;    
    if (fscanf(input, "%d", &dim) != 1) {
        printf("Errore nella lettura della dimensione della matrice\n");
        fclose(input);
        exit(1);
    }
    float **m = (float**)calloc(dim, sizeof(float*));
    for (int i = 0; i < dim; i++)
        m[i] = (float*)calloc(dim, sizeof(float));
    RiempiMatrice(m, dim, input);
    if (fscanf(input, "%d", &num_vett) != 1) {
        printf("Errore nella lettura del numero di vettori\n");
        fclose(input);
        exit(1);
    }
    vett* array = (vett*)calloc(num_vett, sizeof(vett));
    RiempiStruct(array, num_vett, input);
    CalcoloD1(array, m, num_vett);
    CalcoloD2(array, m, num_vett);
    FILE *output = fopen("output.bin", "wb");
    fwrite(array, sizeof(vett), num_vett, output);
    for (int i = 0; i < dim; i++)
        free(m[i]);
    for (int i = 0; i < num_vett; i++)
        free(array[i].v);
    fclose(input);
    free(m);
    free(array);
    return 0;
}

void RiempiMatrice(float **m, int dim, FILE *input){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++)
        {
            if (fscanf(input, "%f", &m[i][j]) != 1) {
                printf("Errore nella lettura della matrice\n");
                exit(1);
            
            }
        }
    }
}
void StampaMatrice(float **m, int dim){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++)
        {
            printf("| %.2f ", m[i][j]);
        }
        printf("|\n");
    }
}
void RiempiStruct(vett* array, int num_vett, FILE *input){
    for (int i = 0; i < num_vett; i++) {
        if (fscanf(input, "%d", &array[i].elements) != 1) {
            printf("Errore nella lettura della dimensione del vettore %d\n", i);
            exit(1);
        }
        array[i].v = (int*)calloc(array[i].elements, sizeof(int));
        for (int j = 0; j < array[i].elements; j++) {
            if (fscanf(input, "%d", &array[i].v[j]) != 1) {
                printf("Errore nella lettura degli elementi del vettore %d\n", i);
                exit(1);
            }
        }
    }
}
void CalcoloD1(vett* array, float **m, int num_vett){
    for (int i = 0; i < num_vett; i++)
        array[i].d1 = 0;
    
    for (int i = 0; i < num_vett; i++)
    {
        for (int j = 0; j < array[i].elements - 1; j++)
        {
            array[i].d1 = array[i].d1 + m[array[i].v[j]][array[i].v[j + 1]];
        }
    }
}
void CalcoloD2(vett* array, float **m, int num_vett){
    for (int i = 0; i < num_vett; i++)
        array[i].d2 = 0;
    
    for (int i = 0; i < num_vett; i++)
    {
        for (int j = array[i].elements - 1; j > 0; j--)
        {
            array[i].d2 = array[i].d2 + m[array[i].v[j]][array[i].v[j - 1]];
        }
    }
}