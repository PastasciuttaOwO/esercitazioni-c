/*
Data in ingresso una stringa verificare se è palindroma. (es: anna, ingegni)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char parola[100];
    printf("Inserisci la parola da controllare\n");
    //fgets(parola, 100, stdin);
    scanf("%[^\n]s", parola); //Utilizzo questa forma così non cattura gli spazi e non verranno considerati come caratteri durante l'esecuzione del programma
    bool palindromo = false;
    for (int i = 0, j = strlen(parola) - 2; i < strlen(parola)/2; i++, j--){
        if (parola[i] == parola[j])
            palindromo = true;
        else{
            palindromo = false;
            break;
        }
    }
    if (palindromo)
        printf("La parola e' palindroma");
    else
        printf("La parola non e' palindroma");
}