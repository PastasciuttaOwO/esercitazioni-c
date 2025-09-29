/*
 * Realizzare un programma che prende in ingresso un valore in euro e attraverso
 * una funzione restituisce una struttura con la conversione nelle seguenti tre valute e tassi:
 *  DOLLARO EURO 0.89 - 1.00. RUBLO EURO 0.012 - 1.00. YEN EURO 0.0078 - 1.00.
 */


#include<stdio.h>


// Creazione della struttura
typedef struct valute {
    float dollaro;
    float rublo;
    float yen;
}valute;

void conversione(valute*, float);

int main(){
    float euro;
    valute valuta;
    printf("Inserisci il numero di euro da convertire\n");
    scanf("%f", &euro);
    conversione(&valuta, euro);
    printf("%.2f euro corrispondono a %.2f dollari\n%.2f euro corrispondono a %.2f rublo\n%.2f euro corrispondono a %.2f yen", euro, valuta.dollaro, euro, valuta.rublo, euro, valuta.yen);
    return 0;
}

void conversione(valute *valuta, float euro){
    valuta->dollaro = euro / 0.89;
    valuta->rublo = euro / 0.012;
    valuta->yen = euro / 0.0078;
}