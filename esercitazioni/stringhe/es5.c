/*
 * REALIZZARE UN PROGRAMMA PER IL CONTROLLO PASSWORD SICURA
 * DEVONO ESSERE SODDISFATTE LE SEGUENTI CONDIZIONI:
 * 1 - ALMENO DI 8 CARATTERI.
 * 2 - ALEMENO UN CARATTERE MINUSCOLO.
 * 3 - ALMENO UN CARATTERE MAIUSCOLO.
 * 4 - ALMENO UN NUMERO.
 * 5 - ALMENO UN CARATTERE SPECIALE.
 * UNA VOLTA VALIDATA LA PASSWORD VIENE RICHIESTO NUOVAMENTE L'INSERIMENTO DELLA MEDESIMA
 * SE LE PASSWORD NON SONO UGUALI E' NECESSARIA INSERIRE NUOVAMENTE LA PASSWORD DI CONTROLLO
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main(){
    char password[100], controllo_password[100] = " ";
    bool chardown = false, charup = false, num = false, punct = false, ritenta = true;
    printf("Inserisci la parola\n");
    do{
        scanf(" %[^\n]s", password);
        if(strlen(password) - 1 >= 8){
            for (int i = 0; i < strlen(password); i++){
                if (islower(password[i])){
                    chardown = true;
                    break;
                }
            }
            for (int i = 0; i < strlen(password); i++){
                if (isupper(password[i])){
                    charup = true;
                    break;
                }
            }
            for (int i = 0; i < strlen(password); i++){
                if (isdigit(password[i])){
                    num = true;
                    break;
                }
            }
            for (int i = 0; i < strlen(password); i++){
                if (ispunct(password[i])){
                    punct = true;
                    break;
                }
            } 
        }
        if (chardown && charup && num && punct){
            printf("Password valida, riscrivila ora\n");
            ritenta = false;
        }
        else
            printf("Password non valida, scriverne una differente\n");
    } while (ritenta);
    scanf(" %[^\n]s", controllo_password);
    while (strcmp(password, controllo_password) != 0){
        printf("password non corrispondente, inserire di nuovo la password di controllo\n");
        scanf(" %[^\n]s", controllo_password);
    }
    printf("password corrispondenti");
}