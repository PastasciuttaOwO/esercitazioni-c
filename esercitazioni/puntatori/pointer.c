#include <stdio.h>

int main () {

   int  var1;
   char var2[10];

   // attraverso l'operatore & posso accedere all'indirizzo di una qualsiasi variabile o struttura dati
   // per visualizzare un indirizzo esadecimale uso il placeholder %x
   printf("L'indirizzo di var1 e': %x\n", &var1  );
   printf("L'indirizzo di var2 e' : %x\n", &var2  );


   // tipo *nome_puntatore esempi:

   int    *ip;    /* puntatore a integer */
   double *dp;    /* puntatore a double */
   float  *fp;    /* puntatore a float */
   char   *ch;    /* puntatore a character */

   // come si utilizza un puntatore [Esempio]

   int  var = 20;   /* dichiarazione di una variabile primitiva */

   ip = &var;  /* salvo l'indirizzo della variabile val nel puntatore */

   printf("L'indirizzo della variabile var e': %x\n", &var  );

   /* indirizzo memorizzato del puntatore */
   printf("L'indirizzo memorizzato nel puntatore e': %x\n", ip );

   /* accedo al valore della variabile var attraverso il puntatore */
   printf("Il valore della variabile var puntata da ip e': %d\n", *ip );


   // Puntatore nullo

   int  *ptr = NULL;

   printf("Il valore del puntatore e' : %x\n", ptr  );

   // test di un puntatore nullo

   if(ptr) { }    /* vero se il puntatore non è null */
   if(!ptr) { }    /* vero se il puntatore è null  */

   return 0;
}
