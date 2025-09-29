#include <stdio.h>
#include <stdbool.h>


// prototipi delle funzioni
void swap(int *, int *);
void bubbleSort(int *, int);
void printArray(int *, int);


// programma main di test
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]); // recupero la dimensione del vettore
    bubbleSort(arr, n);
    printf("Vettore ordinato: \n");
    printArray(arr, n);
    return 0;
}

// funzione per scambiare due variabili tramite puntatore
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Funzione ottimizzata algoritmo Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }

     // Se non c'è stato almeno uno scambio il vettore è ordinato ed è possibile interrompere
     if (swapped == false)
        break;
   }
}

// Stampa del vettore
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}
