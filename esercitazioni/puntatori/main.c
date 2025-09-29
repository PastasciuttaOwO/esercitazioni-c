#include <stdio.h>
#include <stdlib.h>

void patata(int *a);

int main()
{
   int v = 10;
   patata(&v);
   printf("%d", v);
}

void patata(int *a){
   *a = *a + 10;
}