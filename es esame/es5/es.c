#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 200

typedef struct mystruct{
    char carattere;
    int posizione_r;
    int posizione_c;
    int count;
}mystruct;

void LeggiMatrice(char **m, int r, int c, FILE *input, mystruct *info_matrice);
void StampaMatrice(char **m, int r, int c);
void ContaAsterischi(char **m, int r, int c, mystruct *info_matrice);

int main(){
    FILE *input = fopen("input.txt", "r");
    if (input == NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }
    int r, c, num_caratteri;
    fscanf(input,"%d", &r);
    fscanf(input,"%d", &c);
    num_caratteri = r * c;
    mystruct *info_matrice = (mystruct*)calloc(num_caratteri, sizeof(mystruct));
    char **m = (char**)calloc(r, sizeof(char*));
    for (int i = 0; i < c; i++)
        m[i] = (char*)calloc(c, sizeof(char));
    LeggiMatrice(m, r, c, input, info_matrice);
    ContaAsterischi(m, r, c, info_matrice);
    StampaMatrice(m, r, c);
    printf("\n");
    for (int i = 0; i < num_caratteri; i++)
    {
        printf("%d ", info_matrice[i].count);
        if ((i + 1) % c == 0 && i != 0)
        {
            printf("\n");
        }
    }
    //seconda parte da continuare
}

void LeggiMatrice(char **m, int r, int c, FILE *input, mystruct *info_matrice){
    for (int i = 0, z = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++, z++)
        {

            do {
                fscanf(input, "%c", &m[i][j]);
            } while (m[i][j] == ' ' || m[i][j] == '\n');
            info_matrice[z].carattere = m[i][j];
            info_matrice[z].posizione_r = i;
            info_matrice[z].posizione_c = j;
            info_matrice[z].count = 0;
        }
    }
}
void StampaMatrice(char **m, int r, int c){
    printf("Matrice letta dal file:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}
void ContaAsterischi(char **m, int r, int c, mystruct *info_matrice){
    for (int i = 0, z = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++, z++)
        {
            if (j != 0 && j != c - 1)
            {
                    if (m[i][j - 1] == '*')
                        info_matrice[z].count++;
                    if (m[i][j + 1] == '*')
                        info_matrice[z].count++;
            }
            else if(j == 0){
                if (m[i][j + 1] == '*')
                    info_matrice[z].count++;
            }
            else if(j == c - 1){
                if (m[i][j - 1] == '*')
                info_matrice[z].count++;
            }
            if (i != 0 && i != r - 1)
            {
                if (m[i - 1][j] == '*')
                    info_matrice[z].count++;
                if (m[i + 1][j] == '*')
                    info_matrice[z].count++;
            }
            else if(i == 0){
                if (m[i + 1][j] == '*')
                    info_matrice[z].count++;
            }
            else if(j == r - 1){
                if (m[i - 1][j] == '*')
                info_matrice[z].count++;
            }
        }
    }
}