/*
 * DATO UN VETTORE DI INTERI IN INGRESSO CON DIMENSIONE RICHIETSA, SI CREI UNA FUNZIONE CHE SPOSTI GLI ELEMENTI DEL
 * VETTORE DI UNA POSIZIONE VERSO DESTRA.
 */


#include<stdio.h>

void shift(int[]);

int main(){
    int v[5] = {1,2,3,4,5};
    shift(v);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", v[i]);
    }
    return 0;
}

void shift(int v[]){
    int temp = v[4];
    for (int i = 5; i > 0; i--){
        v[i] = v[i - 1];
    }
    v[0] = temp;
}