/*
 Data in ingresso una stringa con la notazione del cammello 
 (es: notazioneDelCammello) generare in ouput la medesima
 stringa inserendo uno spazio bianco prima di ogni lettera maiuscola
 (risultato: notazione Del Cammello).
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char cammello[100] = " ";
    printf("Inserisci la parola in notazione del cammello\n");
    fgets(cammello, 100, stdin);
    for (int i = 0; i < strlen(cammello); i++){
        if (isupper(cammello[i]) && i!=0){
            for (int j = strlen(cammello); j >= i; j--){
                cammello[j + 1] = cammello[j];
            }
           cammello[i] = ' ';
           i++;
        }
    }
    printf("La parola e' %s",cammello);
}