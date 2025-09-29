/*strcpy(carrello->nome, "Provola");
    carrello->prezzo = 10;
    printf("Prima della riallocazione:\nNome:%s\nPrezzo:%.2f\n\n", carrello->nome, carrello->prezzo);
    num_prodotti++;
    carrello = (prodotto*) realloc(carrello, num_prodotti * sizeof(prodotto));
    strcpy(carrello[1].nome, "Cipolla");
    carrello[1].prezzo = 20;
    printf("Dopo la riallocazione:\nPrima cella:\nNome:%s\nPrezzo:%.2f\n", carrello[0].nome, carrello[0].prezzo);
    printf("Seconda cella:\nNome:%s\nPrezzo:%.2f", carrello[1].nome, carrello[1].prezzo);*/

/*
 * Realizzare un programma che simuli un e-commerce attraverso un vettore di strutture
 * La struttura è la descrizone di un singolo prodotto (nome prodotto e prezzo prodotto)
 * Il menù del programma deve prevedere l'inserimento di un nuovo prodotto, la visualizzazione dei prodotti inseriti
 * il calcolo del totale e l'uscita con la stampa del saldo finale.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>


typedef struct prodotto{
    float prezzo;
    char nome[100];
}prodotto;

int main(){
    prodotto *carrello = NULL;
    int num_prodotti = 0, scelta_menu = 0, i = -1;
    float totale = 0;
    bool continua = true, carrello_vuoto = true;
    printf("Benvenuto nel mio e-commerce!\n");
    do{
        printf("Cosa desideri fare?\n");
        printf("1 - Aggiungi un prodotto\n");
        printf("2 - Visualizza il carrello e calcola il totale parziale\n");
        printf("3 - Esci e paga\n");
        scanf("%d", &scelta_menu);
        if ((scelta_menu == 2 || scelta_menu == 3) && carrello_vuoto){
            printf("Il carrello e' vuoto");
            break;
        }
        switch (scelta_menu){
        case 1:
            carrello_vuoto = false;
            num_prodotti++;
            i++;
            carrello = (prodotto*)realloc(carrello, num_prodotti * (sizeof(prodotto)));
            printf("Inserisci il nome del prodotto\n");
            scanf("%s", &carrello[i].nome);
            printf("Inserisci il prezzo del prodotto\n");
            scanf("%f", &carrello[i].prezzo);
            totale = totale + carrello[i].prezzo;
            break;
        case 2:
            printf("Ecco gli articoli nel carrello");
            for (int j = 0; j < num_prodotti; j++){
                printf("\nArticolo %d: %s al prezzo di %.2f\n", j + 1, carrello[j].nome, carrello[j].prezzo);
            }
            printf("Per un totale di: %.2f\n\n", totale);
            break;
        case 3:
            printf("Dovrai pagare un totale di: %.2f\n", totale);
            continua = false;
            break;
        default:
            printf("Scelta non valida, riprova\n");
            break;
        }
    } while (continua);
    free(carrello);
    return 0;
}