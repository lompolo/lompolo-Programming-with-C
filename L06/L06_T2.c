/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06_T2
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 5.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

typedef struct Ajoneuvot{
    char merkki[MAX_LEN];
    int vuosimalli;
    struct Ajoneuvot *seuraava;
} Ajoneuvo;

Ajoneuvo *lisaaSolmu(char *merkki, int vuosimalli){
    Ajoneuvo *solmu = (Ajoneuvo *)malloc(sizeof(Ajoneuvo));
    if(solmu == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    };

    strcpy(solmu->merkki, merkki);
    solmu->vuosimalli = vuosimalli;
    solmu->seuraava = NULL;

    return solmu;
}

void tulostaList(Ajoneuvo *alku){
    Ajoneuvo *pointteri = alku;
    int laskuri = 1;

    if (alku == NULL)
        printf("Ajoneuvoja ei löytynyt.\n");
    else
    {
        while (pointteri != NULL)
        {
            printf("%d. ajoneuvo: %s vuosimalli %d.\n", laskuri, pointteri->merkki, pointteri->vuosimalli);
            laskuri++;
            pointteri = pointteri->seuraava;
        }
    }
}

void vapautaMuisti(Ajoneuvo *alku){
    Ajoneuvo *p = alku;

    while (p != NULL)
    {
        alku = p->seuraava;
        free(p);
        p = alku;
    }
}

int main(int argc, char *argv[]) {
    FILE *tiedosto = NULL;
    Ajoneuvo *alku = NULL, *loppu = NULL, *p = NULL;
    char rivi[MAX_LEN] = "", *merkki = NULL, tNimi[MAX_LEN] = "";
    int vuosimalli = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Et antanut tiedoston nimeä.\n");
        exit(0);
    }

    strcpy(tNimi, argv[1]);

	printf("Luetaan tiedot tiedostosta %s.\n", tNimi);
    if((tiedosto = fopen(tNimi, "r")) == NULL){
        fprintf(stderr, "Tiedoston avaus epäonnistui.\n");
        exit(0);
    }

    while (fgets(rivi, MAX_LEN, tiedosto) != NULL)
    {
        if(strlen(rivi) < 7)
            break;
        merkki = strtok(rivi, " ");
        vuosimalli = atoi(strtok(NULL, " "));
        p = lisaaSolmu(merkki, vuosimalli);
        if (alku == NULL) {
            alku = p;
            loppu = p;
        } else {
            loppu->seuraava = p;
            loppu = p;
        }
    }
    printf("Tiedot luettu linkitettyyn listaan.\n");
    fclose(tiedosto);
    tulostaList(alku);
    vapautaMuisti(alku);
    printf("Muisti vapautettu.\n");

    return 0;
}
/*******************************************************************/
/* eof */