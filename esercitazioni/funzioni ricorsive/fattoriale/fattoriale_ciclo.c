#include<stdio.h>

int main(){
    int fat;
    printf("Inserisci il numero per il fattoriale\n");
    scanf("%d",&fat);
    for (int i = fat - 1; i > 0; i--)
    {
        printf("|stato attuale fat: %d, stato attuale di i: %d|\n", fat, i);
        fat = fat * i;
    }
    printf("il risulato e' %d", fat);
    return 0;
}