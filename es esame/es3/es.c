#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NMAX 200

typedef struct mystruct{
    int linea;
    int token;
    char str[NMAX];
    int value;
}mystruct;

void StampaStruct(mystruct* array, int count);
void bubbleSort(mystruct *sottostringa, int count);

int main() {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Errore! file non aperto correttamente");
        exit(1);
    }
    int count = 0, sottostringa_counter = 0, riga = 0;
    char stringa[NMAX];
    mystruct sottostringa [NMAX];
    while(fgets(stringa, NMAX, input)!=NULL) {
        char *token = strtok(stringa, " \n");
        sottostringa[count].linea = 0;
        while (token) {
            strcpy(sottostringa[count].str, token);
            //printf("%s ", sottostringa[count].str);
            sottostringa[count].token = sottostringa_counter;
            if (atoi(sottostringa[count].str) != 0)
                sottostringa[count].value = atoi(sottostringa[count].str);
            else
                sottostringa[count].value = -1;
            token = strtok(NULL, " \n");
            count++;
            sottostringa_counter++;
        }
        sottostringa_counter = 0;
    }
    bubbleSort(sottostringa, count);
    StampaStruct(sottostringa, count);
    FILE *output = fopen("output.bin", "wb");
    fwrite(sottostringa, sizeof(mystruct), count, output);
    fclose(input);
    fclose(output);
    return 0;
}

void StampaStruct(mystruct* array, int count){
    for (int i = 0; i < count; i++) {
        printf("Linea: %d, Token: %d, Str: %s, Value: %d\n", array[i].linea, array[i].token, array[i].str, array[i].value);
    }
}

void bubbleSort(mystruct *sottostringa, int count){
    mystruct temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (sottostringa[j].value < sottostringa[j + 1].value)
            {
                temp = sottostringa[j];
                sottostringa[j] = sottostringa[j + 1];
                sottostringa[j + 1] = temp;
            }
        }
    }
}