/* Funzione ricorsiva che dato un numero i >= 0 calcola il numero di Fibonacci
   i-esimo:

   L'i-esimo numero di Fibonacci F(i) e` definito attraverso la seguente
   definizione induttiva:

     F(i) = 0                 se i = 0
     F(i) = 1                 se i = 1
     F(i) = F(i-1) + F(i-2)   se i >= 2

*/

#include<stdio.h>

int fibonacci(int);

int main(){
  int i;
  printf("Inserisci l'iesimo numero di fibonacci a cui arrivare\n");
  scanf("%d",&i);
  printf("il numero %d della seguenza di fibonacci e': %d", i, fibonacci(i));
  return 0;
}

int fibonacci(int i){
  if (i == 0){
    return 0;
  }else if (i == 1){
    return 1;
  }else{
    return fibonacci(i - 1) + fibonacci(i - 2);
  }
}