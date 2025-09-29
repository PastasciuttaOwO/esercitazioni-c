#include<stdio.h>

int fattoriale(int n);

int main(){
    int fat;
    printf("Inserisci il numero per il fattoriale\n");
    scanf("%d",&fat);
    printf("Il fattoriale e' %d", fattoriale(fat));
    return 0;
}

int fattoriale(int n){
    if (n != 0){
    return n*fattoriale(n - 1);}
    else{
    return 1;}
}