#include <stdio.h>
#include <stdlib.h>
typedef struct dati{
    float aumento;
    float cifra;
}dati;
int main() {
    dati array[10000];
    int i;
    float x = 0;
    int giorni;
    printf("\nInserisci il numero di giorni: ");
    scanf("%d", &giorni);
    float numeroiniziale;
    printf("\nInserisci il numero iniziale: ");
    scanf("%f", &numeroiniziale);
    float numeroaggiornato = numeroiniziale;
    float numerofinale;
    printf("Inserisci il numero finale: ");
    scanf("%f", &numerofinale);
    //PerInc sta per Percentuale Incremento
    float percInc = ((numerofinale - numeroiniziale) / numeroiniziale) * 100;
    float perIncMedio = percInc / giorni;
    printf("\nLa cifra e' aumentata del %.2f percento\n", percInc);
    for (i = 0; i < giorni; i++) {
        //x equivale alla percentuale dell'incremento rispetto al valore precedente
        x = (numeroiniziale * perIncMedio) / (numeroaggiornato);
        numeroaggiornato = numeroaggiornato + (numeroaggiornato * x / 100);
        array[i].aumento = x;
        array[i].cifra = numeroaggiornato;
        //printf("\nLa percentuale di incremento nel giorno %d e' %f",i+1,x);
        //printf("\nCifra giorno %d = %f",i+1,numeroaggiornato);

    }
    while (1) {
        char c;
        printf("\n\n\tMENU': \n1)Visualizza tutto\n2)Visualizza giorno specifico\nQ)Esci");
        printf("\nSeleziona:");
        scanf(" %c", &c);
        switch (c) {
            case '1':
                for (i = 0; i < giorni; i++) {
                    printf("\nLa percentuale di incremento nel giorno %d e' %f", i, array[i].aumento);
                    printf("\nCifra giorno %d = %f", i , array[i].cifra);
                }
                break;
            case '2':
                int giorno;
                printf("\nInserisci il giorno in cui vuoi visualizzare i dati: ");
                scanf("%d", &giorno);
                printf("\nLa percentuale di incremento nel giorno %d e' %f", giorno, array[giorno].aumento);
                printf("\nCifra giorno %d = %f", giorno, array[giorno].cifra);
                break;
            case 'Q':
                printf("\nGrazie!\n\n\tgithub.com/dsilix\n\n");
                exit(0);

        }
 }
}