#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 200

typedef struct mystruct{
    char parola[NMAX];
    int pos_lettera;
    int lunghezza_parola;
}mystruct;

int main(){
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Errore con l'apertura del file");
        exit(1);
    }
    int i = 0, j = 0;
    char stringa[NMAX], *token;
    fgets(stringa, NMAX, input);
    mystruct *info_stringa = (mystruct*)calloc(NMAX, sizeof(mystruct));
    do
    {
        token = strtok(stringa, " \n");
        while (token)
        {
            strcpy(info_stringa[i].parola, token);
            info_stringa[i].lunghezza_parola = strlen(info_stringa[i].parola);
            if (j > 0)
                info_stringa[i].pos_lettera = info_stringa[i - 1].lunghezza_parola + info_stringa[i - 1].pos_lettera + 1;
            else
                info_stringa[i].pos_lettera = 0;
            i++;
            j++;
            token = strtok(NULL, " \n");
        }
        j = 0;
        printf("ciclo eseguito con i %d\n", i);
    } while ((fgets(stringa, NMAX, input) != NULL));

    for (int j = 0; j < i; j++) {
        printf("Parola: %s, Posizione: %d, Lunghezza: %d\n", info_stringa[j].parola, info_stringa[j].pos_lettera, info_stringa[j].lunghezza_parola);
    }
    FILE *output = fopen("output.bin", "wb");
    fwrite(info_stringa, sizeof(info_stringa), i, output);
    free(info_stringa);
    fclose(input);
    fclose(output);
    return 0;
}