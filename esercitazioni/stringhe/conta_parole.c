/*
DATA UNA STRINGA IN INGRESSO, CONTARE
IL NUMERO DI PAROLE E VISUALIZZARE IL RISULTATO.
 */
#include<stdio.h>
#include<string.h>

int main(){
    char stringa[100] = "Patata Ciao Sesso  Samba", *token = strtok(stringa, " /0");
    int count = 0;
    while (token){
        token = strtok(NULL, stringa);
        count++;
    }
    printf("%d", count);
}