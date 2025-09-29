/*
 * Data una stringa in ingresso creare un effetto zigzag della medesima (es: giardino diventerà gIaRdInO)
 */

 #include<stdio.h>
 #include<string.h>
 #include<ctype.h>

 int main(){
    char stringa[100];
    printf("Inserisci la parola\n");
    scanf("%[^\n]s", stringa);
    for (int i = 0; i < strlen(stringa); i = i + 2){
        if (i > strlen(stringa))
            break;
        stringa[i] = toupper(stringa[i]);
    }
    printf("%s", stringa);
 }