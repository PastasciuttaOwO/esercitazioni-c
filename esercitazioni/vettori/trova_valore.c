/*
 * SIANO DATI UN VETTORE IN INGRESSO INSIEME ALLA SUA DIMENSIONE ED UNA VALORE DA CERCARE.
 * RESTUTUIRE IN OUTPUT LA PRESENZA O MENO DEL VALORE RICERCATO.
 */
#include<stdio.h>
#include<stdbool.h>

int max = 0;

bool ricerca(int[], int); 

int main(){
    printf("inserisci il numero max del vettore\n");
    scanf("%d",&max);
    int v[max], valore = 0;
    for (int i = 0; i < max; i++){
        printf("inserisci il %d valore\n", i+1);
        scanf("%d",&v[i]);
    }
    printf("inserisci il valore da trovare\n");
    scanf("%d",&valore);
    if(ricerca(v, valore))
        printf("Trovato");
    else
        printf("Valore inesistente");
}

bool ricerca(int v[], int find){
    for (int i = 0; i < max; i++)
        if (v[i] == find)
            return true;
    return false;
}