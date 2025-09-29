/*
 * ALL'INTERNO DI UN VETTORE VENGANO SALVATI 6 VALORI COMPRESI TRA 1 E 90 NON RIPETUTI.
 * I NUMERI SONO GENERATI CASUALMENTE (SIMULAZIONE DI UNA ESTRAZIONE DEL SUPERNALOTTO).
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define max 6

int main(){
    srand(time(NULL));
    int risultati[max], guess[max];
    bool doppione = false;
    for (int i = 0; i < max; i++){
        risultati[i] = (rand() % 90) + 1;
    }
    for (int i = 0; i < 6; ++i) {
        printf("%d\n", risultati[i]);
    }
    for (int i = 0; i < max; i++){
        printf("Inserisci il %d numero\n", i+1);
        scanf("%d", &guess[i]);
    }
    
}