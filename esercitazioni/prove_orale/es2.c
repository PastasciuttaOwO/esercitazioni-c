#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define n 5

void StampaVett(int *v);
void BubbleSort(int *v);

int main(){
    FILE *input = fopen("input.txt", "r");
    srand(time(NULL));
    int *v = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 50;
    }
    StampaVett(v);
    BubbleSort(v);
    StampaVett(v);
}

void StampaVett(int *v){
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void BubbleSort(int *v){
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}